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

#ifndef MMATH_VECTOR3_H_
#define MMATH_VECTOR3_H_

#include "Vector.h"

namespace mmath
{

template <typename T>
class Vector<3, T>
{
public:
    union {
        T buf[3];
        struct
        {
            T x, y, z;
        };
    };

    constexpr Vector() = default;
    constexpr Vector(Vector const &v) = default;
    constexpr Vector(T x, T y, T z);

    static constexpr size_t length() { return 3; }
    constexpr T &operator[](uint8_t i);
    constexpr T const &operator[](uint8_t i) const;
    constexpr T *data();

    constexpr Vector<3, T> &operator=(const Vector<3, T> &v) = default;
    template <typename U>
    constexpr Vector<3, T> &operator=(const Vector<3, U> &v);
    template <typename U>
    constexpr Vector<3, T> &operator+=(U scalar);
    template <typename U>
    constexpr Vector<3, T> &operator+=(const Vector<3, U> &v);
    template <typename U>
    constexpr Vector<3, T> &operator-=(U scalar);
    template <typename U>
    constexpr Vector<3, T> &operator-=(const Vector<3, U> &v);
    template <typename U>
    constexpr Vector<3, T> &operator*=(U scalar);
    template <typename U>
    constexpr Vector<3, T> &operator*=(const Vector<3, U> &v);
    template <typename U>
    constexpr Vector<3, T> &operator/=(U scalar);
    template <typename U>
    constexpr Vector<3, T> &operator/=(const Vector<3, U> &v);
};

template <typename T>
constexpr Vector<3, T> operator+(const Vector<3, T> &v, T scalar);
template <typename T>
constexpr Vector<3, T> operator+(T scalar, const Vector<3, T> &v);
template <typename T>
constexpr Vector<3, T> operator+(const Vector<3, T> &v1, const Vector<3, T> &v2);
template <typename T>
constexpr Vector<3, T> operator-(const Vector<3, T> &v, T scalar);
template <typename T>
constexpr Vector<3, T> operator-(T scalar, const Vector<3, T> &v);
template <typename T>
constexpr Vector<3, T> operator-(const Vector<3, T> &v1, const Vector<3, T> &v2);
template <typename T, typename U>
constexpr Vector<3, T> operator*(const Vector<3, T> &v, U scalar);
template <typename T, typename U>
constexpr Vector<3, T> operator*(U scalar, const Vector<3, T> &v);
template <typename T>
constexpr Vector<3, T> operator*(const Vector<3, T> &v1, const Vector<3, T> &v2);
template <typename T>
constexpr Vector<3, T> operator/(const Vector<3, T> &v, T scalar);
template <typename T>
constexpr Vector<3, T> operator/(T scalar, const Vector<3, T> &v);
template <typename T>
constexpr Vector<3, T> operator/(const Vector<3, T> &v1, const Vector<3, T> &v2);
template <typename T>
constexpr bool operator==(const Vector<3, T> &v1, const Vector<3, T> &v2);
template <typename T>
constexpr bool operator!=(const Vector<3, T> &v1, const Vector<3, T> &v2);

template <typename T>
constexpr Vector<3, T>::Vector(T x, T y, T z)
    : x(x), y(y), z(z)
{
}

template <typename T>
constexpr T &Vector<3, T>::operator[](uint8_t i)
{
    switch (i)
    {
    default:
    case 0:
        return x;
    case 1:
        return y;
    case 2:
        return z;
    }
}

template <typename T>
constexpr T const &Vector<3, T>::operator[](uint8_t i) const
{
    switch (i)
    {
    default:
    case 0:
        return x;
    case 1:
        return y;
    case 2:
        return z;
    }
}

template <typename T>
constexpr T *Vector<3, T>::data()
{
    return buf;
}

template <typename T>
template <typename U>
constexpr Vector<3, T> &Vector<3, T>::operator=(const Vector<3, U> &v)
{
    this->x = static_cast<T>(v.x);
    this->y = static_cast<T>(v.y);
    this->z = static_cast<T>(v.z);
    return *this;
}

template <typename T>
template <typename U>
constexpr Vector<3, T> &Vector<3, T>::operator+=(U scalar)
{
    this->x += static_cast<T>(scalar);
    this->y += static_cast<T>(scalar);
    this->z += static_cast<T>(scalar);
    return *this;
}

template <typename T>
template <typename U>
constexpr Vector<3, T> &Vector<3, T>::operator+=(const Vector<3, U> &v)
{
    this->x += static_cast<T>(v.x);
    this->y += static_cast<T>(v.y);
    this->z += static_cast<T>(v.z);
    return *this;
}

template <typename T>
template <typename U>
constexpr Vector<3, T> &Vector<3, T>::operator-=(U scalar)
{
    this->x -= static_cast<T>(scalar);
    this->y -= static_cast<T>(scalar);
    this->z -= static_cast<T>(scalar);
    return *this;
}

template <typename T>
template <typename U>
constexpr Vector<3, T> &Vector<3, T>::operator-=(const Vector<3, U> &v)
{
    this->x -= static_cast<T>(v.x);
    this->y -= static_cast<T>(v.y);
    this->z -= static_cast<T>(v.z);
    return *this;
}

template <typename T>
template <typename U>
constexpr Vector<3, T> &Vector<3, T>::operator*=(U scalar)
{
    this->x *= static_cast<T>(scalar);
    this->y *= static_cast<T>(scalar);
    this->z *= static_cast<T>(scalar);
    return *this;
}

template <typename T>
template <typename U>
constexpr Vector<3, T> &Vector<3, T>::operator*=(const Vector<3, U> &v)
{
    this->x *= static_cast<T>(v.x);
    this->y *= static_cast<T>(v.y);
    this->z *= static_cast<T>(v.z);
    return *this;
}

template <typename T>
template <typename U>
constexpr Vector<3, T> &Vector<3, T>::operator/=(U v)
{
    this->x /= static_cast<T>(v);
    this->y /= static_cast<T>(v);
    this->z /= static_cast<T>(v);
    return *this;
}

template <typename T>
template <typename U>
constexpr Vector<3, T> &Vector<3, T>::operator/=(const Vector<3, U> &v)
{
    this->x /= static_cast<T>(v.x);
    this->y /= static_cast<T>(v.y);
    this->z /= static_cast<T>(v.z);
    return *this;
}

template <typename T>
constexpr Vector<3, T> operator+(const Vector<3, T> &v, T scalar)
{
    return Vector<3, T>(v.x + scalar, v.y + scalar, v.z + scalar);
}

template <typename T>
constexpr Vector<3, T> operator+(T scalar, const Vector<3, T> &v)
{
    return Vector<3, T>(scalar + v.x, scalar + v.y, scalar + v.z);
}

template <typename T>
constexpr Vector<3, T> operator+(const Vector<3, T> &v1, const Vector<3, T> &v2)
{
    return Vector<3, T>(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

template <typename T>
constexpr Vector<3, T> operator-(const Vector<3, T> &v, T scalar)
{
    return Vector<3, T>(v.x - scalar, v.y - scalar, v.z - scalar);
}

template <typename T>
constexpr Vector<3, T> operator-(T scalar, const Vector<3, T> &v)
{
    return Vector<3, T>(scalar - v.x, scalar - v.y, scalar - v.z);
}

template <typename T>
constexpr Vector<3, T> operator-(const Vector<3, T> &v1, const Vector<3, T> &v2)
{
    return Vector<3, T>(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

template <typename T, typename U>
constexpr Vector<3, T> operator*(const Vector<3, T> &v, U scalar)
{
    return Vector<3, T>(v.x * scalar, v.y * scalar, v.z * scalar);
}

template <typename T, typename U>
constexpr Vector<3, T> operator*(U scalar, const Vector<3, T> &v)
{
    return Vector<3, T>(scalar * v.x, scalar * v.y, scalar * v.z);
}

template <typename T>
constexpr Vector<3, T> operator*(const Vector<3, T> &v1, const Vector<3, T> &v2)
{
    return Vector<3, T>(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);
}

template <typename T>
constexpr Vector<3, T> operator/(const Vector<3, T> &v, T scalar)
{
    return Vector<3, T>(v.x / scalar, v.y / scalar, v.z / scalar);
}

template <typename T>
constexpr Vector<3, T> operator/(T scalar, const Vector<3, T> &v)
{
    return Vector<3, T>(scalar / v.x, scalar / v.y, scalar / v.z);
}

template <typename T>
constexpr Vector<3, T> operator/(const Vector<3, T> &v1, const Vector<3, T> &v2)
{
    return Vector<3, T>(v1.x / v2.x, v1.y / v2.y, v1.z / v2.z);
}

template <typename T>
constexpr bool operator==(const Vector<3, T> &v1, const Vector<3, T> &v2)
{
    return (v1.x == v2.x) && (v1.y == v2.y) && (v1.z == v2.z);
}

template <typename T>
constexpr bool operator!=(const Vector<3, T> &v1, const Vector<3, T> &v2)
{
    return !(v1 == v2);
}

using Vector3B = Vector<3, int8_t>;
using Vector3i8 = Vector<3, int8_t>;
using Vector3UB = Vector<3, uint8_t>;
using Vector3u8 = Vector<3, int8_t>;
using Vector3S = Vector<3, int16_t>;
using Vector3i16 = Vector<3, int16_t>;
using Vector3US = Vector<3, uint16_t>;
using Vector3u16 = Vector<3, uint16_t>;
using Vector3I = Vector<3, int32_t>;
using Vector3i32 = Vector<3, int32_t>;
using Vector3U = Vector<3, uint32_t>;
using Vector3u32 = Vector<3, uint32_t>;
using Vector3L = Vector<3, int32_t>;
using Vector3UL = Vector<3, uint32_t>;
#ifdef INT64_MAX
using Vector3LL = Vector<3, int64_t>;
using Vector3i64 = Vector<3, int64_t>;
using Vector3ULL = Vector<3, uint64_t>;
using Vector3u64 = Vector<3, uint64_t>;
#endif
using Vector3F = Vector<3, float>;
using Vector3D = Vector<3, float>;
using Vector3f32 = Vector<3, float>;
using Vector3LF = Vector<3, double>;
using Vector3f64 = Vector<3, double>;

} // namespace mmath

#endif
