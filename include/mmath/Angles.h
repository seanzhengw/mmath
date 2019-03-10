#ifndef MMATH_ANGLES_H_
#define MMATH_ANGLES_H_

#include <cmath>

namespace mmath
{

class Angles
{
public:
    static constexpr double RadToDeg();
    static constexpr double DegToRad();

    template <typename T>
    static constexpr T RadToDeg(T rad);
    template <typename T>
    static constexpr T DegToRad(T deg);
};

constexpr double Angles::RadToDeg()
{
    return 180.0 / M_PI;
}

constexpr double Angles::DegToRad()
{
    return M_PI / 180.0;
}

template <typename T>
constexpr T Angles::RadToDeg(T rad)
{
    return rad * 180.0 / M_PI;
}

template <typename T>
constexpr T Angles::DegToRad(T deg)
{
    return deg * M_PI / 180.0;
}

} // namespace mmath

#endif
