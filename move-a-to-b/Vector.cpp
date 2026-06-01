//
// Created by Karan Nandkar on 01/06/26.
//


#include "Vector.h"
#include <algorithm>

Vector2 Lerp(const Vector2& start, const Vector2& end, float t)
{
    t = std::clamp(t, 0.0f, 1.0f);
    return start + (end - start) * t;
}
