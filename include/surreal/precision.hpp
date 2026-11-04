#ifndef PRECISION_HPP_
#define PRECISION_HPP_

namespace surreal {

    // Defines a real number precision. Surreal can be compiled in single or double precision versions.
    // by default, single precision is provided.
    typedef float real;

    // Defines the precision of the power operator
    #define real_pow powf
}

#endif // PRECISION_HPP_