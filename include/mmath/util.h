#ifndef MMATH_UTIL_H_
#define MMATH_UTIL_H_

#include <algorithm>
#include <cmath>

namespace mmath
{

// limit value into range [min, max]
inline double clamp(double value, double min, double max)
{
    return std::max(min, std::min(max, value));
}

// wrap radians to coterminal angles in range (-π, π]
inline double radiansWrap(double r)
{
    for (; r > M_PI;)
    {
        r -= (M_PI * 2.0);
    }
    for (; r <= -M_PI;)
    {
        r += (M_PI * 2.0);
    }
    return r;
}

// is the different of v1 and v2 less than range
inline bool closeEnough(double v1, double v2, double range)
{
    return abs(v1 - v2) <= range;
}

} // namespace mmath

#endif