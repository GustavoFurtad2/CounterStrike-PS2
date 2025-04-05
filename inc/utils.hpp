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

    inline Tyra::Vec4 calculateRotationFromDirection(const Tyra::Vec4& direction) {

        float pitch = Tyra::Math::atan2(direction.y, sqrt(direction.x * direction.x + direction.z * direction.z));
        float yaw = Tyra::Math::atan2(direction.x, direction.z);
    
        return Tyra::Vec4(-pitch, yaw, 0.0f);
    }

    inline Tyra::Vec4 crossProduct(const Tyra::Vec4& a, const Tyra::Vec4& b) {
        return Tyra::Vec4(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x, 1);
    }
    
    inline Tyra::Vec4 getOffsetByDirection(const Tyra::Vec4& direction, const Tyra::Vec4& gunOffset) {
    
        Tyra::Vec4 forward = direction.getNormalized();
    
        Tyra::Vec4 up(0.0f, 1.0f, 0.0f);
        Tyra::Vec4 right = crossProduct(forward, up).getNormalized();
        Tyra::Vec4 correctedUp = crossProduct(right, forward).getNormalized();
    
        Tyra::Vec4 offsetGlobal = (right * gunOffset.x) + (correctedUp * gunOffset.y) + (forward * gunOffset.z);
    
        return offsetGlobal;
    }
}