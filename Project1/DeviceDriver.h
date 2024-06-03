#pragma once
#include "FlashMemoryDevice.h"


class DeviceDriver {
public:
    DeviceDriver(FlashMemoryDevice* hardware);
    int read(long address);
    void write(long address, int data);
    void readandprint(long startaddress, long endaddress);
    void writeall(int value);

protected:
    FlashMemoryDevice* m_hardware;
};