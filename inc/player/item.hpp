#pragma once

#include <tyra>

#include <cmath>
#include <string>
#include <iostream>

#include "utils.hpp"
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
    Shoot
};

class Item {

    public:

        Item(Tyra::Engine* t_engine, const std::string& name, ItemType type, const std::vector<AnimatedModel*> itemModels)
            : engine(t_engine), name(name), type(type), itemModels(itemModels) {};
        virtual ~Item() = default;

        std::string getName() const {
            return name;
        }

        ItemType getType() const {
            return type;
        }

    protected:

        Tyra::Engine* engine;

        std::string name;
        ItemType type;

        std::vector<AnimatedModel*> itemModels;

};

class Gun : public Item {

    public:

        Gun(Tyra::Engine* t_engine, const std::string& name, int baseDamage, const std::vector<AnimatedModel*> gunModels);
        ~Gun();

        void update();
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

    private:

        Tyra::Vec4 calculateRotationFromDirection(const Tyra::Vec4 &direction);
        Tyra::Vec4 getOffsetInDirection(const Tyra::Vec4& direction, const Tyra::Vec4& gunOffset);
        Tyra::Vec4 crossProduct(const Tyra::Vec4& a, const Tyra::Vec4& b);

        bool isShooting = false;
        
        void setAnimationIdle();
        void setAnimationShoot();

        unsigned int currentFrame = 0;

        const std::vector<unsigned int>idleAnimationKeyframe = {0};
        const std::vector<unsigned int>shootAnimationKeyframe = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};

        AnimationType currentAnimation = AnimationType::Idle;

        int baseDamage;

        int bulletsGun = 12;
        int bulletsPerCartridge = 12;
        int cartridges = 2;

};