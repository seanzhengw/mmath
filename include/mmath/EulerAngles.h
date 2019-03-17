// BSD 2-Clause License
//
// Copyright (c) 2019, Sean Zheng
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, this
//    list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef MMATH_EULERANGLES_H_
#define MMATH_EULERANGLES_H_

#include <cstdint>
#include <cmath>
#include "Vector3.h"
#include "Quaternion.h"

namespace mmath
{

class EulerAngles
{
public:
    template <typename T>
    static constexpr void SimplifyXYZ(Vector<3, T> &v);
    template <typename T>
    static constexpr T AngleXYZ(const Vector<3, T> &v1, const Vector<3, T> &v2);
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

template <typename T>
constexpr T EulerAngles::AngleXYZ(const Vector<3, T> &v1, const Vector<3, T> &v2)
{
    Quaternion<T> q1, q2;
    q1.FromEulerXYZ(v1);
    q2.FromEulerXYZ(v2);
    return q1.Angle(q2);
}

using Euler = EulerAngles;

} // namespace mmath

#endif
