#include <gtest/gtest.h>
#include <surreal/core.hpp>

#include "test_utils.hpp"

// Tolerance for floating-point or double precision comparisons in tests
constexpr auto TOLERANCE = surreal::testing::get_tolerance<surreal::real>();

TEST(Vector3Test, Addition) {
    surreal::Vector3 a(1.0, 2.0, 3.0);
    surreal::Vector3 b(4.0, 5.0, 6.0);
    surreal::Vector3 result = a + b;

    EXPECT_NEAR(result.x, 5.0, TOLERANCE);
    EXPECT_NEAR(result.y, 7.0, TOLERANCE);
    EXPECT_NEAR(result.z, 9.0, TOLERANCE);
}