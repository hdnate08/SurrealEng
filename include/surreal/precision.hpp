#ifndef PRECISION_HPP_
#define PRECISION_HPP_

#include <cmath>

namespace surreal {

    // Defines a real number precision. Surreal can be compiled in single or double precision versions.
    // by default, single precision is provided.
    typedef float real;

    // Defines the precision of the power operator
    #define real_pow powf

    // Defines the precision of the absolute magnitude operator
    #define real_abs fabsf
}

#endif // PRECISION_HPP_