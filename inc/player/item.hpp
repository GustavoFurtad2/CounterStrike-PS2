#pragma once

#include <tyra>

#include <string>

#include "components/staticModel.hpp"

enum class ItemType {
    Gun,
    Knife,
    Grenade,
    Shield
};

class Item {

    public:

        Item(Tyra::Engine* t_engine, const std::string& name, ItemType type, const char modelPath[], const char texturePath[], float scale)
            : name(name), type(type), itemModel(t_engine, modelPath, texturePath, scale) {};
        virtual ~Item() = default;

        std::string getName() const {
            return name;
        }

        ItemType getType() const {
            return type;
        }

    protected:

        std::string name;
        ItemType type;

        Model itemModel;

};

class Gun : public Item {

    public:

        Gun(Tyra::Engine* t_engine, const std::string& name, int baseDamage, const char modelPath[], const char texturePath[]);
        ~Gun();

        void render(Tyra::Vec4 cameraPosition);

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

        int baseDamage;

        int bulletsGun = 12;
        int bulletsPerCartridge = 12;
        int cartridges = 2;

};