#ifndef CORE_HPP
#define CORE_HPP

#include "precision.hpp"

namespace surreal {
    /* Holds a vector in three dimensions. Four data memebers are allocated
    to ensure alignment in an array. 
    */
    class Vector3
    {
        public:
            // The default ctor creates a zero vector
            Vector3();

            // Explicit ctor creates vector with given components
            Vector3(const real x, const real y, const real z);

            // Holds the value along the x axis
            real x;

            // Holds the value along the y axis
            real y;

            // Holds the value along the z axis
            real z;

            // Flips all components of the vector
            void invert();

        private:
            // Padding to ensure four word alignment
            real pad;
    };
}

#endif