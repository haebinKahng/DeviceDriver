#include "DeviceDriver.h"

DeviceDriver::DeviceDriver(FlashMemoryDevice* hardware) : m_hardware(hardware) {}

int DeviceDriver::read(long address) {

    return (int)(m_hardware->read(address));
}

void DeviceDriver::write(long address, int data) {

    m_hardware->write(address, (unsigned char)data);
}