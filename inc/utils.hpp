#pragma once

#include <tyra>

namespace Cs::Utils
{
    inline float degreesToRadians(float degrees) {
        return degrees * (Tyra::Math::PI / 180);
    }

    inline float lerp(float a, float b, float x) {
        return a + x * (b - a);
    }
}