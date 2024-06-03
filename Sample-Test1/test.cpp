#include <stdexcept>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../Project1/DeviceDriver.cpp"
using namespace ::testing;

class FlashMock : public FlashMemoryDevice {
public:
	MOCK_METHOD(unsigned char, read, (long address));
	MOCK_METHOD(void, write, (long address), int data);
};

class FlashFixture : public testing::Test {
public:
	FlashMock fMock;
	DeviceDriver dd{ &fMock };
};

TEST_F(FlashFixture, read1) {
	EXPECT_CALL(fMock, read).Times(5);

	DeviceDriver dd{ &fMock };
	dd.read(0x0A);
}

TEST_F(FlashFixture, read2) {
	EXPECT_CALL(fMock, read)
		.Times(5)
		.WillOnce(Return((unsigned char)0xA))
		.WillOnce(Return((unsigned char)0xA))
		.WillOnce(Return((unsigned char)0xA))
		.WillOnce(Return((unsigned char)0xA))
		.WillOnce(Return((unsigned char)0xF));

	EXPECT_THROW(dd.read(0x0A), std::exception);
}

TEST_F(FlashFixture, test4) {
	EXPECT_CALL(fMock, read);
	dd.write(0x0A, 0xAB);
}