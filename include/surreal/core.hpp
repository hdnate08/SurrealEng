#ifndef CORE_HPP_
#define CORE_HPP_

#include "surreal/precision.hpp"

namespace surreal {
    /* Holds a vector in three dimensions. Four data memebers are allocated
    to ensure alignment in an array. 
    */
    class Vector3
    {
        private:
            // Padding to ensure four word alignment
            real pad;

        public:
            // The default ctor creates a vector with all components set to zero
            Vector3();

            // The parameterized ctor creates a vector with the given x, y, and z values
            Vector3(const real x, const real y, const real z);

            // Scales the vector by a scalar value and returns a new vector
            auto operator*(const real scalar) const -> Vector3;

            // Updates this vector by scaling it by a scalar value
            auto operator*=(const real scalar) -> void;

            // Updates this vector by multiplying it component-wise with another vector
            auto operator*=(const Vector3& rhs) -> void;

            // Adds another vector to this vector and returns a new vector
            auto operator+(const Vector3& rhs) const -> Vector3;

            // Updates this vector by adding another vector to it
            auto operator+=(const Vector3& rhs) -> void;

            // Subtracts another vector from this vector and returns a new vector
            auto operator-(const Vector3& rhs) const -> Vector3;

            // Updates this vector by subtracting another vector from it
            auto operator-=(const Vector3& rhs) -> void;

            // Returns the cross product of this vector and another vector
            auto operator%(const Vector3& rhs) const -> Vector3;

            // Updates this vector to be the cross product of this vector and another vector
            auto operator%=(const Vector3& rhs) -> void;

            // Holds the value along the x axis
            real x;

            // Holds the value along the y axis
            real y;

            // Holds the value along the z axis
            real z;

            // Flips all components of the vector
            auto negate() -> void;

            // Normalizes the vector to unit length
            auto normalize() -> void;

            // Returns the magnitude of the vector
            auto magnitude() const -> real;

            // Returns the magnitude squared of the vector
            auto magnitude_squared() const -> real;
            
            // Returns component-wise product of this vector and another vector
            auto component_product(const Vector3& rhs) const -> Vector3;

            // Returns the dot product of this vector and another vector
            auto dot(const Vector3& rhs) const -> real;

            // Returns the cross product of this vector and another vector
            auto cross(const Vector3& rhs) const -> Vector3;

            // Creates an orthonormal basis from this vector and another vector
            auto makeOrthonormalBasis(Vector3 *a, Vector3 *b, Vector3 *c) const -> void;
    };
}

#endif // CORE_HPP_