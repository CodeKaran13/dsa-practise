//
// Created by Karan Nandkar on 01/06/26.
//


#include "Vector.h"
#include <algorithm>

Vector2::Vector2() : x(0), y(0) {}

Vector2::Vector2(float x, float y) : x(x), y(y) {}

Vector2 Vector2::operator+(const Vector2& other) const
{
    return {x + other.x, y + other.y};
}

Vector2 Vector2::operator-(const Vector2& other) const
{
    return {x - other.x, y - other.y};
}

Vector2 Vector2::operator*(float scalar) const
{
    return {x * scalar, y * scalar};
}

float Vector2::Length() const
{
    return std::sqrt(x * x + y * y);
}

Vector2 Vector2::Normalized()
{
    float length = Length();
    if (length == 0)
    {
        return Vector2();
    }

    return Vector2(x / length, y / length);
}

float Vector2::Distance(const Vector2& a, const Vector2& b)
{
    return (a - b).Length();
}

Vector2 Vector2::Lerp(const Vector2& a, const Vector2& b, float t)
{
    t = std::clamp(t, 0.0f, 1.0f);
    return a + (b - a) * t;
}
