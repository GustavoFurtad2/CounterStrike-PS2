#include "player/item.hpp"

Gun::Gun(Tyra::Engine* t_engine, const std::string& name, int baseDamage, const std::vector<AnimatedModel*> gunModels)
  : Item(t_engine, name, ItemType::Gun, gunModels), baseDamage(baseDamage) {}

Gun::~Gun() {

    for (auto *model : itemModels) {
        delete model;
    }

    itemModels.clear();

    TYRA_LOG("Release: Gun " + name);
}

void Gun::render(Camera playerCamera, Tyra::Vec4 gunOffset) {

    for (auto* model : itemModels) {
        
        model->setPosition(gunOffset);        
        model->render();
    }
}