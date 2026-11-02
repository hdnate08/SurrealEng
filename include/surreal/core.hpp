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
            // The default ctor creates a zero vector
            Vector3();

            // Explicit ctor creates vector with given components
            Vector3(const real x, const real y, const real z);

            // Scales the vector by a scalar value and returns a new vector
            auto operator*(const real scalar) const -> Vector3;

            // Scales the vector by a scalar value
            auto operator*=(const real scalar) -> void;

            // Returns the dot product of this vector and another vector
            auto operator*=(const Vector3& rhs) -> void;

            // Adds another vector to this vector and returns a new vector
            auto operator+(const Vector3& rhs) const -> Vector3;

            // Adds another vector to this vector
            auto operator+=(const Vector3& rhs) -> void;

            // Subtracts another vector from this vector and returns a new vector
            auto operator-(const Vector3& rhs) const -> Vector3;

            // Subtracts another vector from this vector
            auto operator-=(const Vector3& rhs) -> void;

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

            // Returns the scalar (dot) product of this vector and another vector
            auto dot(const Vector3& rhs) const -> real;

            // Returns the cross product of this vector and another vector
            auto cross(const Vector3& rhs) const -> Vector3;
    };
}

#endif // CORE_HPP_