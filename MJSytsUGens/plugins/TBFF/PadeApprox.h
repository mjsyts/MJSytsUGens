#pragma once

#include <algorithm>

namespace Pade {

template<typename T> T tanh(T x) {
    const T a1 = 3.0; //bounds
    const T a2 = 9.0; //a squared
    const T a3 = 27.0; //a cubed
    x = std::clamp(x, -a1, a1);
    x *= ( a3 + x * x ) / ( a3 + a2 * x * x );
    return x;
}

} //end namespace Pade
