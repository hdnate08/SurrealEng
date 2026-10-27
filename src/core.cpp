#include <iostream>

#include "core.hpp"

namespace surreal {

Vector3::Vector3() : x(0), y(0), z(0) {}

Vector3::Vector3(const real x, const real y, const real z) : x(x), y(y), z(z) {}

auto Vector3::invert() -> void
{
    x = -x;
    y = -y;
    z = -z;
}
}