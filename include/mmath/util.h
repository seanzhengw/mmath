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
