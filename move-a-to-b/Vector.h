//
// Created by Karan Nandkar on 01/06/26.
//

#ifndef DSA_PRATISE_VECTOR_H
#define DSA_PRATISE_VECTOR_H

struct Vector2
{
    float x;
    float y;

    Vector2 operator+(const Vector2& other) const
    {
        return {x + other.x, y + other.y};
    }

    Vector2 operator-(const Vector2& other) const
    {
        return {x - other.x, y - other.y};
    }

    Vector2 operator*(float scalar) const
    {
        return {x * scalar, y * scalar};
    }
};

Vector2 Lerp(const Vector2& a, const Vector2& b, float t);

#endif //DSA_PRATISE_VECTOR_H
