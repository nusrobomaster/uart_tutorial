
#include <cmath>

#include "jy901.h"


#include <iostream>
#include <fstream>

#include <time.h>       /* time */


struct Range{
    int accel = 4;
    int gyro = 1000;
    const double g = 9.8;
    const int k = 32768;
}imu_range;

void publish(CJY901::Data &data)
{
    float x = (float)data.stcAcc.a[0]/32768*imu_range.accel*imu_range.g;
    float y = (float)data.stcAcc.a[1]/32768*imu_range.accel*imu_range.g;
    float z = (float)data.stcAcc.a[2]/32768*imu_range.accel*imu_range.g;
    printf("%f %f %f \n", x, y, z);
    // data.stcAcc, data.stcGyro, data.stcQuater
    // data.stcMag
}

void print_hex(unsigned char* buffer, int size)
{

    for (int i = 0; i < size; i++)
        std::cout  << std::hex << (unsigned int)buffer[i] << " ";
    std::cout << std::endl;
}

int main (void){

    srand (time(NULL));

    std::ifstream hexdump;
    hexdump.open("../raw_imu_data.hex", std::ios::binary);
    
    CJY901 jy901;

    unsigned char buffer[1024];

    while(hexdump){
        static int last_seq = 0;

        // read random number of bytes, simulating hardware
        int size = std::rand() % 16 + 8;

        hexdump.read(reinterpret_cast<char *>(buffer), size);

        // print_hex(buffer,size);

        jy901.CopeSerialData(buffer,size);

        if (last_seq != jy901.data.seq){
            last_seq = jy901.data.seq;
            publish(jy901.data);
        }
    }

    std::cout << "All Parsed!" << std::endl;

    return 0;
}