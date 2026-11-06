#include <cmath>
#include <stdexcept>

#include <surreal/core.hpp>
#include <surreal/tolerance.hpp>

namespace surreal {

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

auto Vector3::add_scaled_vector(const Vector3& rhs, const real scale) -> void
{
    x += rhs.x * scale;
    y += rhs.y * scale;
    z += rhs.z * scale;
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

auto Vector3::makeOrthonormalBasis(Vector3 *a, Vector3 *b, Vector3 *c) const -> void
{
    a->normalize();
    (*c) = (*a) % (*b);

    constexpr auto tol = surreal::tolerance::get_tolerance<surreal::real>();
    if (c->magnitude_squared() <= tol * tol) { // TODO: We may not want to throw here in the future
        throw std::runtime_error("Cannot create orthonormal basis: input vectors are parallel");
    }
   
    c->normalize();
    (*b) = (*c) % (*a);
}

} // surreal namespace