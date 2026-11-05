#include <gtest/gtest.h>
#include <cmath>

#include <surreal/tolerance.hpp>
#include <surreal/core.hpp>

class Vector3Test : public ::testing::Test {
    protected:
        // Tolerance for floating-point or double precision comparisons in tests
        static constexpr auto TOLERANCE = surreal::tolerance::get_tolerance<surreal::real>();

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
        surreal::Vector3 v3{
            static_cast<surreal::real>(7.0),
            static_cast<surreal::real>(8.0),
            static_cast<surreal::real>(9.0)
        };
        surreal::Vector3 zero{
            static_cast<surreal::real>(0.0),
            static_cast<surreal::real>(0.0),
            static_cast<surreal::real>(0.0)
        };
};

TEST_F(Vector3Test, default_constructor) {
    surreal::Vector3 v;

    EXPECT_NEAR(v.x, 0.0, TOLERANCE);
    EXPECT_NEAR(v.y, 0.0, TOLERANCE);
    EXPECT_NEAR(v.z, 0.0, TOLERANCE);
}

TEST_F(Vector3Test, parameterized_constructor) {
    EXPECT_NEAR(v1.x, 1.0, TOLERANCE);
    EXPECT_NEAR(v1.y, 2.0, TOLERANCE);
    EXPECT_NEAR(v1.z, 3.0, TOLERANCE);

    EXPECT_NEAR(v2.x, 4.0, TOLERANCE);
    EXPECT_NEAR(v2.y, 5.0, TOLERANCE);
    EXPECT_NEAR(v2.z, 6.0, TOLERANCE);

    EXPECT_NEAR(zero.x, 0.0, TOLERANCE);
    EXPECT_NEAR(zero.y, 0.0, TOLERANCE);
    EXPECT_NEAR(zero.z, 0.0, TOLERANCE);
}

TEST_F(Vector3Test, zero_vector) {
    surreal::Vector3 result = v1 - v1;

    EXPECT_NEAR(result.x, 0.0, TOLERANCE);
    EXPECT_NEAR(result.y, 0.0, TOLERANCE);
    EXPECT_NEAR(result.z, 0.0, TOLERANCE);
}

TEST_F(Vector3Test, add_operator) {
    surreal::Vector3 result = v1 + v2;

    EXPECT_NEAR(result.x, 5.0, TOLERANCE);
    EXPECT_NEAR(result.y, 7.0, TOLERANCE);
    EXPECT_NEAR(result.z, 9.0, TOLERANCE);
}

TEST_F(Vector3Test, add_and_assign_operator) {
    surreal::Vector3 v = v1;
    v += v2;

    EXPECT_NEAR(v.x, 5.0, TOLERANCE);
    EXPECT_NEAR(v.y, 7.0, TOLERANCE);
    EXPECT_NEAR(v.z, 9.0, TOLERANCE);
}

TEST_F(Vector3Test, subtract_operator) {
    surreal::Vector3 result = v1 - v2;

    EXPECT_NEAR(result.x, -3.0, TOLERANCE);
    EXPECT_NEAR(result.y, -3.0, TOLERANCE);
    EXPECT_NEAR(result.z, -3.0, TOLERANCE);
}

TEST_F(Vector3Test, subtract_and_assign_operator) {
    surreal::Vector3 v = v1;
    v -= v2;

    EXPECT_NEAR(v.x, -3.0, TOLERANCE);
    EXPECT_NEAR(v.y, -3.0, TOLERANCE);
    EXPECT_NEAR(v.z, -3.0, TOLERANCE);
}

TEST_F(Vector3Test, multiply_operator) {
    surreal::Vector3 result = v1 * static_cast<surreal::real>(2.0);

    EXPECT_NEAR(result.x, 2.0, TOLERANCE);
    EXPECT_NEAR(result.y, 4.0, TOLERANCE);
    EXPECT_NEAR(result.z, 6.0, TOLERANCE);
}

TEST_F(Vector3Test, multiply_and_assign_operator_scalar) {
    surreal::Vector3 v = v1;
    v *= static_cast<surreal::real>(2.0);

    EXPECT_NEAR(v.x, 2.0, TOLERANCE);
    EXPECT_NEAR(v.y, 4.0, TOLERANCE);
    EXPECT_NEAR(v.z, 6.0, TOLERANCE);
}

TEST_F(Vector3Test, multiply_and_assign_operator_vector) {
    surreal::Vector3 v = v1;
    v *= v2;

    EXPECT_NEAR(v.x, 4.0, TOLERANCE);
    EXPECT_NEAR(v.y, 10.0, TOLERANCE);
    EXPECT_NEAR(v.z, 18.0, TOLERANCE);
}

TEST_F(Vector3Test, cross_product_operator) {
    surreal::Vector3 result = v1 % v2;

    EXPECT_NEAR(result.x, -3.0, TOLERANCE);
    EXPECT_NEAR(result.y, 6.0, TOLERANCE);
    EXPECT_NEAR(result.z, -3.0, TOLERANCE);
}

TEST_F(Vector3Test, cross_product_and_assign_operator) {
    surreal::Vector3 v = v1;
    v %= v2;

    EXPECT_NEAR(v.x, -3.0, TOLERANCE);
    EXPECT_NEAR(v.y, 6.0, TOLERANCE);
    EXPECT_NEAR(v.z, -3.0, TOLERANCE);
}

TEST_F(Vector3Test, negation) {
    surreal::Vector3 v = v1;
    v.negate();

    EXPECT_NEAR(v.x, -1.0, TOLERANCE);
    EXPECT_NEAR(v.y, -2.0, TOLERANCE);
    EXPECT_NEAR(v.z, -3.0, TOLERANCE);
}

TEST_F(Vector3Test, normalization) {
    surreal::Vector3 v = v1;
    v.normalize();

    surreal::real magnitude = v.magnitude();
    EXPECT_NEAR(magnitude, 1.0, TOLERANCE);
}

TEST_F(Vector3Test, magnitude) {
    surreal::real magnitude = v1.magnitude();
    EXPECT_NEAR(magnitude, std::sqrt(14.0), TOLERANCE);
}

TEST_F(Vector3Test, magnitude_squared) {
    surreal::real magnitude_squared = v1.magnitude_squared();
    EXPECT_NEAR(magnitude_squared, 14.0, TOLERANCE);
}

TEST_F(Vector3Test, component_product) {
    surreal::Vector3 result = v1.component_product(v2);

    EXPECT_NEAR(result.x, 4.0, TOLERANCE);
    EXPECT_NEAR(result.y, 10.0, TOLERANCE);
    EXPECT_NEAR(result.z, 18.0, TOLERANCE);
}

TEST_F(Vector3Test, dot_product) {
    surreal::real dot_product = v1.dot(v2);
    EXPECT_NEAR(dot_product, 32.0, TOLERANCE);
}

TEST_F(Vector3Test, cross_product) {
    surreal::Vector3 result = v1.cross(v2);

    EXPECT_NEAR(result.x, -3.0, TOLERANCE);
    EXPECT_NEAR(result.y, 6.0, TOLERANCE);
    EXPECT_NEAR(result.z, -3.0, TOLERANCE);
}

TEST_F(Vector3Test, vector_padding) {
    EXPECT_EQ(sizeof(surreal::Vector3), sizeof(surreal::real) * 4);
}

TEST_F(Vector3Test, make_orthonormal_basis) {
    surreal::Vector3 a = v1;
    surreal::Vector3 b = v2;
    surreal::Vector3 c = v3;

    a.makeOrthonormalBasis(&a, &b, &c);

    EXPECT_NEAR(a.magnitude(), 1.0, TOLERANCE);
    EXPECT_NEAR(b.magnitude(), 1.0, TOLERANCE);
    EXPECT_NEAR(c.magnitude(), 1.0, TOLERANCE);

    EXPECT_NEAR(a.dot(b), 0.0, TOLERANCE);
    EXPECT_NEAR(b.dot(c), 0.0, TOLERANCE);
    EXPECT_NEAR(c.dot(a), 0.0, TOLERANCE);
}

TEST_F(Vector3Test, make_orthonormal_basis_parallel_vectors) {
    surreal::Vector3 a = v1;
    surreal::Vector3 b = v1;
    surreal::Vector3 c = v2;
    
    EXPECT_THROW(a.makeOrthonormalBasis(&a, &b, &c), std::runtime_error);
}