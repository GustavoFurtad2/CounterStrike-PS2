#include "player/item.hpp"

Gun::Gun(Tyra::Engine* t_engine, const std::string& name, int baseDamage, const char modelPath[], const char texturePath[])
  : Item(t_engine, name, ItemType::Gun, modelPath, texturePath, 10.0f), baseDamage(baseDamage) {}

Gun::~Gun() {
    delete &itemModel;
}

void Gun::draw(Tyra::Vec4 cameraPosition) {


    itemModel.setPosition(cameraPosition);

    itemModel.draw();
}