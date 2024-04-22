#pragma once

#include <algorithm>

namespace FastMath {

template <typename T> static T tan (T x) noexcept {
    const T min = -M_PI_2;
    const T max = M_PI_2;
    x = std::clamp(x, min, max);
    T x2 = x * x;
    T numerator = x * (-135135 + x2 * (17325 + x2 * (-378 + x2)));
    T denominator = -135135 + x2 * (62370 + x2 * (-3150 + 28 * x2));
    return numerator / denominator;
}

template <typename T> static T tanh (T x) noexcept {
    const T min = -5.0;
    const T max = 5.0;
    x = std::clamp(x, min, max);
    T x2 = x * x;
    T numerator = x * (135135 + x2 * (17325 + x2 * (378 + x2)));
    T denominator = 135135 + x2 * (62370 + x2 * (3150 + 28 * x2));
    return numerator / denominator;
}

template<typename T> T tanhXdX(T x) {
    const T a = x * x;
    return ((a + 105)*a + 945) / ((15*a + 420)*a + 945);
}

} //end namespace FastMath
