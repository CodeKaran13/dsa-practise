//
// Created by Karan Nandkar on 01/06/26.
//

#ifndef DSA_PRATISE_VECTOR_H
#define DSA_PRATISE_VECTOR_H

struct Vector2
{
    float x;
    float y;

    Vector2();
    Vector2(float x, float y);

    Vector2 operator+(const Vector2& other) const;
    Vector2 operator-(const Vector2& other) const;
    Vector2 operator*(float value) const;

    float Length() const;
    Vector2 Normalized();
    static float Distance(const Vector2& a, const Vector2& b);
    static Vector2 Lerp(const Vector2& a, const Vector2& b, float t);
};


#endif //DSA_PRATISE_VECTOR_H
