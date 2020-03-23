## Instructions
- `raw_imu_data.hex` contains the raw bytes read from the IMU sensor over serial port.
- Implement `CJY901::CopeSerialData` to parse the bytes, according to the pdf datasheet given.

## Save Raw Bytes from /dev/USB0 to file
``` bash
stty -F /dev/ttyUSB0 raw # Set to read raw bytes without manipulation
cat /dev/ttyUSB0 > raw_imu_data.hex # dump to file
```