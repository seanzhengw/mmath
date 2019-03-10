#ifndef MMATH_LENGTH_H_
#define MMATH_LENGTH_H_

#include "Vector3.h"
#include <cmath>

namespace mmath
{

template <typename T, typename U>
constexpr T Length(const Vector<3, U> &v)
{
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

} // namespace mmath

#endif
