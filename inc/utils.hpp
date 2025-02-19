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

    inline void transitionColor(Tyra::Color& currentColor, const Tyra::Color& targetColor, float speed) {

        currentColor.r += (targetColor.r - currentColor.r) * speed;
        currentColor.g += (targetColor.g - currentColor.g) * speed;
        currentColor.b += (targetColor.b - currentColor.b) * speed;
        currentColor.a += (targetColor.a - currentColor.a) * speed;
    }
}