#ifndef TOLERANCE_HPP_
#define TOLERANCE_HPP_

namespace surreal::tolerance{

constexpr float FLOAT_TOLERANCE = 1e-6f;
constexpr double DOUBLE_TOLERANCE = 1e-12;

// Returns the appropriate tolerance for floating-point comparisons based on the type.
template <typename T>
constexpr T get_tolerance() {
    if constexpr (sizeof(T) == sizeof(float)) {
        return static_cast<T>(FLOAT_TOLERANCE);
    } else {
        return static_cast<T>(DOUBLE_TOLERANCE);
    }
}

} // namespace tolerance

#endif // TOLERANCE_HPP_