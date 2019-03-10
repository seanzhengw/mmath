#ifndef MMATH_TRANSFORM_H_
#define MMATH_TRANSFORM_H_

#include "Vector3.h"
#include "EulerAngles.h"

namespace mmath
{

template <typename T>
class Transform
{
public:
    Vector<3, T> pos;
    Vector<3, T> rot;

    constexpr Transform() = default;
    constexpr Transform(Transform const &t) = default;
    constexpr Transform(T x, T y, T z, T a, T b, T c);
    constexpr Transform(Vector<3, T> pos, Vector<3, T> rot);

    static constexpr size_t length() { return 6; }
    constexpr T &operator[](uint8_t i);
    constexpr T const &operator[](uint8_t i) const;

    template <typename U>
    constexpr Transform<T> &operator=(const Transform<U> &t);
    template <typename U>
    constexpr Transform<T> &operator+=(const Transform<U> &t);
    template <typename U>
    constexpr Transform<T> &operator-=(const Transform<U> &t);
};

template <typename T>
constexpr Transform<T> operator+(const Transform<T> &v);
template <typename T>
constexpr Transform<T> operator-(const Transform<T> &v);

template <typename T, typename U>
constexpr Transform<T> operator+(const Transform<T> &t1, const Transform<U> &t2);
template <typename T, typename U>
constexpr Transform<T> operator-(const Transform<T> &t1, const Transform<U> &t2);

template <typename T>
constexpr Transform<T>::Transform(T x, T y, T z, T a, T b, T c)
    : pos(x, y, z), rot(a, b, c)
{
}

template <typename T>
constexpr Transform<T>::Transform(Vector<3, T> pos, Vector<3, T> rot)
    : pos(pos), rot(rot)
{
}

template <typename T>
constexpr T &Transform<T>::operator[](uint8_t i)
{
    switch (i)
    {
    default:
    case 0:
        return pos.x;
    case 1:
        return pos.y;
    case 2:
        return pos.z;
    case 3:
        return rot.x;
    case 4:
        return rot.y;
    case 5:
        return rot.z;
    }
}

template <typename T>
constexpr T const &Transform<T>::operator[](uint8_t i) const
{
    switch (i)
    {
    default:
    case 0:
        return pos.x;
    case 1:
        return pos.y;
    case 2:
        return pos.z;
    case 3:
        return rot.x;
    case 4:
        return rot.y;
    case 5:
        return rot.z;
    }
}

template <typename T>
template <typename U>
constexpr Transform<T> &Transform<T>::operator=(const Transform<U> &t)
{
    pos = t.pos;
    rot = t.rot;
}

template <typename T>
template <typename U>
constexpr Transform<T> &Transform<T>::operator+=(const Transform<U> &t)
{
    pos += t.pos;
    rot += t.rot;
}

template <typename T>
template <typename U>
constexpr Transform<T> &Transform<T>::operator-=(const Transform<U> &t)
{
    pos -= t.pos;
    rot -= t.rot;
}

template <typename T, typename U>
constexpr Transform<T> operator+(const Transform<T> &t1, const Transform<U> &t2)
{
    return Transform<T>(t1.pos + t2.pos, t1.rot + t2.rot);
}

template <typename T, typename U>
constexpr Transform<T> operator-(const Transform<T> &t1, const Transform<U> &t2)
{
    return Transform<T>(t1.pos - t2.pos, t1.rot - t2.rot);
}

using TransformF = Transform<float>;
using TransformD = Transform<float>;
using TransformF32 = Transform<float>;
using TransformLF = Transform<double>;
using TransformF64 = Transform<double>;

} // namespace mmath

#endif
