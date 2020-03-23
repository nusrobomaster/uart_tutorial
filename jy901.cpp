#include "jy901_constants.h"
#include "jy901.h"

#include <cstring>
#include <cassert>
#include <iostream>

void CJY901::CopeSerialData(const unsigned char ucData[], unsigned int ucLength)
{
    // Implementation

}


void CJY901::publishData()
{
    data_buffer.seq = data.seq + 1;
    data = data_buffer;
}