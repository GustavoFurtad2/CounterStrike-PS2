#pragma once

#include <chrono>
#include <string>
#include <iostream>

#include "player/camera.hpp"
#include "components/staticModel.hpp"
#include "components/animatedModel.hpp"

enum class ItemType {
    Gun,
    Knife,
    Grenade,
    Shield
};

enum class AnimationType {
    Idle,
    Shoot,
};

class Item {

    public:

        Item();
        virtual ~Item() = default;

        void init(const std::string& name, ItemType type, const std::vector<AnimatedModel*>& itemModels);

        std::string getName() const {
            return name;
        }

        ItemType getType() const {
            return type;
        }

    protected:

        std::string name;
        ItemType type;

        std::vector<AnimatedModel*> itemModels;

};

class Gun : public Item {

    public:

        Gun();
        ~Gun();

        void init(const std::string& name, int baseDamage, const std::vector<AnimatedModel*> gunModels);
        void update(const Camera &playerCamera);
        void render(const Camera &playerCamera, const Tyra::Vec4 &gunPositionOffset, const Tyra::Vec4 &gunAngleOffset);

        int getBulletsInGun() {
            return bulletsGun;
        }

        int getBulletsPerCartridge() {
            return bulletsPerCartridge;
        }

        int getCartridges() {
            return cartridges;
        }

        bool getIsShooting() {
            return isShooting;
        }

        bool isShootable = true;

        void setIdleAnimationKeyframe(const std::vector<unsigned int> &animationKeyframe) {
            idleAnimationKeyframe = animationKeyframe;
        }

        void setShootAnimationKeyframe(const std::vector<unsigned int> &animationKeyframe) {
            shootAnimationKeyframe = animationKeyframe;
        }

    private:

        std::chrono::high_resolution_clock::time_point timerSincePlayerIsWalking;

        Tyra::Vec4 calculateBobbingOffsetInDirection(const Camera &playerCamera);

        Tyra::Vec4 cameraDirection, rotationAngles, position, bobbingOffset;

        bool gunSwinging = false;

        bool isShooting = false;

        std::vector<unsigned int>idleAnimationKeyframe = {0};
        std::vector<unsigned int>shootAnimationKeyframe = {0};
        
        void setAnimationIdle();
        void setAnimationShoot();

        unsigned int currentFrame = 0;

        AnimationType currentAnimation = AnimationType::Idle;

        int baseDamage;

        int bulletsGun = 12;
        int bulletsPerCartridge = 12;
        int cartridges = 2;

};