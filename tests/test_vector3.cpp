#include <gtest/gtest.h>
#include <surreal/core.hpp>

TEST(Vector3Test, Addition) {
    surreal::Vector3 a(1.0, 2.0, 3.0);
    surreal::Vector3 b(4.0, 5.0, 6.0);
    surreal::Vector3 result = a + b;
    EXPECT_DOUBLE_EQ(result.x, 5.0);
    EXPECT_DOUBLE_EQ(result.y, 7.0);
    EXPECT_DOUBLE_EQ(result.z, 9.0);
}