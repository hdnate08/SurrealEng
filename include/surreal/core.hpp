#ifndef CORE_HPP
#define CORE_HPP

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

            // Scales the vector by a scalar value
            void operator*=(const real scalar);

            // Scales the vector by a scalar value and returns a new vector
            Vector3 operator*(const real scalar) const;

            // Adds another vector to this vector
            void operator+=(const Vector3& rhs);

            // Adds another vector to this vector and returns a new vector
            Vector3 operator+(const Vector3& rhs) const;

            // Subtracts another vector from this vector
            void operator-=(const Vector3& rhs);

            // Subtracts another vector from this vector and returns a new vector
            Vector3 operator-(const Vector3& rhs) const;

            // Holds the value along the x axis
            real x;

            // Holds the value along the y axis
            real y;

            // Holds the value along the z axis
            real z;

            // Flips all components of the vector
            void invert();

            // Normalizes the vector to unit length
            void normalize();

            // Returns the magnitude of the vector
            real getMagnitude() const;

            // Returns the magnitude squared of the vector
            real getMagnitudeSquared() const;
            
            // Returns component-wise product of this vector and another vector
            Vector3 componentProduct(const Vector3& rhs) const;

            // Updates this vector to be the component-wise product of this vector and another vector
            void componentProductUpdate(const Vector3& rhs);

    };
}

#endif