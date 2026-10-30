#ifndef TEST_UTILS_HPP
#define TEST_UTILS_HPP

namespace surreal::testing{

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

}

#endif // TEST_UTILS_HPP