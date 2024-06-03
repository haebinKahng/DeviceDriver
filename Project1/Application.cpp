#include "DeviceDriver.h"
#include <stdexcept>

class Application {
public:
	Application(DeviceDriver* dd) : dd{ dd } {}
	void readandprint(long startaddress, long endaddress) {
		for (long addr = startaddress; addr <= endaddress; addr++) dd->read(addr);
	}

	void writeall(unsigned char value) {
		for (int addr = 0x00; addr <= 0x04; addr++) dd->write(addr, value);
	}
private:
	DeviceDriver* dd;
};