#ifndef TEST_UTILS_HPP
#define TEST_UTILS_HPP

namespace surreal::testing{

// Returns the appropriate tolerance for floating-point comparisons based on the type.
template <typename T>
constexpr T get_tolerance() {
    if constexpr (sizeof(T) == sizeof(float)) {
        return static_cast<T>(1e-6);
    } else {
        return static_cast<T>(1e-12);
    }
}

}

#endif // TEST_UTILS_HPP