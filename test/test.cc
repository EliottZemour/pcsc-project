#include <cmath>
#include <gtest/gtest.h>

TEST(sqrt, integer) { EXPECT_EQ(2, std::sqrt(4)); }

TEST(sqrt, decimal) { EXPECT_EQ(2.15, std::sqrt(5.0625)); }