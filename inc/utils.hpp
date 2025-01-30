#pragma once

#include <tyra>

static float degreesToRadians(float degrees) {
    return degrees * (Tyra::Math::PI / 180);
}

static float lerp(float a, float b, float x) {
    return a + x * (b - a);
}