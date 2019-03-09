#ifndef MMATH_EULERANGLES_H_
#define MMATH_EULERANGLES_H_

#include <cstdint>
#include "Vector3.h"

namespace mmath
{

class EulerAngles
{
public:
    template <typename T>
    static constexpr void SimplifyXYZ(Vector<3, T> &v);
};

template <typename T>
constexpr void EulerAngles::SimplifyXYZ(Vector<3, T> &v)
{
    v.x = radiansWrap(v.x);
    v.y = radiansWrap(v.y);
    v.z = radiansWrap(v.z);

    if (closeEnough(v.y, M_PI_2, 1e-6))
    {
        v.x = radiansWrap(v.x + v.z);
        v.z = 0;
        return;
    }

    if (closeEnough(v.y, -M_PI_2, 1e-6))
    {
        v.x = radiansWrap(v.x - v.z);
        v.z = 0;
        return;
    }

    // (x, y, z) -> (x + PI, -y + PI, z - PI)
    if ((v.y > M_PI_2) || (v.y < -M_PI_2))
    {
        v.y = radiansWrap(M_PI - v.y);
        v.x = radiansWrap(v.x + M_PI);
        v.z = radiansWrap(v.z - M_PI);
        return;
    }
}

using Euler = EulerAngles;

} // namespace mmath

#endif
