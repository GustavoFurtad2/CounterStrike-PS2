#include "player/gun.hpp"

Gun::Gun(Tyra::Engine* t_engine, const char modelPath[], const char texturePath[]) : engine(t_engine), gunModel(t_engine, modelPath, texturePath, 10.0f) {}

Gun::~Gun() {
    delete &gunModel;
}

void Gun::draw(Tyra::Vec4 cameraPosition) {

    gunModel.setPosition(cameraPosition);

    gunModel.draw();
}