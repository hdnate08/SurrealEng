#include <gtest/gtest.h>
#include <surreal/core.hpp>

#include "test_utils.hpp"

class Vector3Test : public ::testing::Test {
    protected:
        // Tolerance for floating-point or double precision comparisons in tests
        static constexpr auto TOLERANCE = surreal::testing::get_tolerance<surreal::real>();

        //static_cast ensures the vector is initialized with the correct surreal::real type
        surreal::Vector3 v1{
            static_cast<surreal::real>(1.0),
            static_cast<surreal::real>(2.0),
            static_cast<surreal::real>(3.0)
        };
        surreal::Vector3 v2{
            static_cast<surreal::real>(4.0),
            static_cast<surreal::real>(5.0),
            static_cast<surreal::real>(6.0)
        };
        surreal::Vector3 zero{
            static_cast<surreal::real>(0.0),
            static_cast<surreal::real>(0.0),
            static_cast<surreal::real>(0.0)
        };
};

TEST_F(Vector3Test, Addition) {
    surreal::Vector3 result = v1 + v2;

    EXPECT_NEAR(result.x, 5.0, TOLERANCE);
    EXPECT_NEAR(result.y, 7.0, TOLERANCE);
    EXPECT_NEAR(result.z, 9.0, TOLERANCE);
}

TEST_F(Vector3Test, Subtraction) {
    surreal::Vector3 result = v1 - v2;

    EXPECT_NEAR(result.x, -3.0, TOLERANCE);
    EXPECT_NEAR(result.y, -3.0, TOLERANCE);
    EXPECT_NEAR(result.z, -3.0, TOLERANCE);
}

TEST_F(Vector3Test, ZeroVector) {
    surreal::Vector3 result = v1 - v1;

    EXPECT_NEAR(result.x, 0.0, TOLERANCE);
    EXPECT_NEAR(result.y, 0.0, TOLERANCE);
    EXPECT_NEAR(result.z, 0.0, TOLERANCE);
}

TEST_F(Vector3Test, Multiplication) {
    surreal::Vector3 result = v1 * static_cast<surreal::real>(2.0);

    EXPECT_NEAR(result.x, 2.0, TOLERANCE);
    EXPECT_NEAR(result.y, 4.0, TOLERANCE);
    EXPECT_NEAR(result.z, 6.0, TOLERANCE);
}
