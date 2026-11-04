#include <cmath>

#include "surreal/core.hpp"

namespace surreal {

Vector3::Vector3() : x(0), y(0), z(0) {}

Vector3::Vector3(const real x, const real y, const real z) : x(x), y(y), z(z) {}

auto Vector3::operator*(const real scalar) const -> Vector3
{
    return Vector3(x * scalar, y * scalar, z * scalar);
}

auto Vector3::operator*=(const real scalar) -> void
{
    x *= scalar;
    y *= scalar;
    z *= scalar;
}

auto Vector3::operator*=(const Vector3& rhs) -> void
{
    x *= rhs.x;
    y *= rhs.y;
    z *= rhs.z;
}

auto Vector3::operator+(const Vector3& rhs) const -> Vector3
{
    return Vector3(x + rhs.x, y + rhs.y, z + rhs.z);
}

auto Vector3::operator+=(const Vector3& rhs) -> void
{
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
}

auto Vector3::operator-(const Vector3& rhs) const -> Vector3
{
    return Vector3(x - rhs.x, y - rhs.y, z - rhs.z);
}

auto Vector3::operator-=(const Vector3& rhs) -> void
{
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
}

auto Vector3::operator%(const Vector3& rhs) const -> Vector3
{
    return cross(rhs);
}

auto Vector3::operator%=(const Vector3& rhs) -> void
{
    *this = cross(rhs);
}

auto Vector3::negate() -> void
{
    x = -x;
    y = -y;
    z = -z;
}

auto Vector3::normalize() -> void
{
    real mag = magnitude();
    if (mag > 0) {
        (*this) *= ((real)1)/mag;
    }
}

auto Vector3::magnitude() const -> real
{
    return std::sqrt(x * x + y * y + z * z);
}

auto Vector3::magnitude_squared() const -> real
{
    return x * x + y * y + z * z;
}

auto Vector3::component_product(const Vector3& rhs) const -> Vector3
{
    return Vector3(x * rhs.x, y * rhs.y, z * rhs.z);
}

auto Vector3::dot(const Vector3& rhs) const -> real
{
    return x * rhs.x + y * rhs.y + z * rhs.z;
}

auto Vector3::cross(const Vector3& rhs) const -> Vector3
{
    return Vector3(
        y * rhs.z - z * rhs.y,
        z * rhs.x - x * rhs.z,
        x * rhs.y - y * rhs.x
    );
}

} // surreal namespace