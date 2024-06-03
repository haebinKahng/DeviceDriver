#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../Project1/DeviceDriver.cpp"

using namespace ::testing;

TEST(DeviceDriver, read1) {
	EXPECT_THAT(1, Eq(1));
}

TEST(DeviceDriver, read2) {
	EXPECT_THAT(1, Eq(1));
}