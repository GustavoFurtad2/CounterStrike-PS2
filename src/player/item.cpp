#include "player/item.hpp"
#include "utils.hpp"
#include "game.hpp"

Item::Item() : type(ItemType::Gun) {}

void Item::init(const std::string& name, ItemType type, const std::vector<AnimatedModel*>& itemModels) {

    this->name = name;
    this->type = type;

    this->itemModels = itemModels;
}

Gun::Gun() : Item() {}

Gun::~Gun() {

    for (auto *model : itemModels) {
        delete model;
    }

    itemModels.clear();

    TYRA_LOG("Release: Gun " + name);
}

void Gun::init(const std::string& name, int baseDamage, const std::vector<AnimatedModel*> gunModels) {

    Item::init(name, ItemType::Gun, gunModels);
    setAnimationIdle();
}

void Gun::update(const Camera &playerCamera) {


    if (!gunSwinging && playerCamera.getIsMoving()) {

        gunSwinging = true;

        timerSincePlayerIsWalking = std::chrono::high_resolution_clock::now();
    }
    else if (gunSwinging && !playerCamera.getIsMoving()) {

        gunSwinging = false;
    }
    else {

        bobbingOffset.z = Cs::Utils::lerp(bobbingOffset.z, 0.0f, 0.1);
    }

    if (Cs::GetEngine()->pad.getPressed().R2 && !isShooting && isShootable) {

        isShooting = true;
        setAnimationShoot();
    }

    if (itemModels[0]->animationFinished) {
        setAnimationIdle();

        isShooting = false;
    }
}

Tyra::Vec4 Gun::calculateBobbingOffsetInDirection(const Camera &playerCamera) {

    if (isShooting) {

        bobbingOffset.z = Cs::Utils::lerp(bobbingOffset.z, 0.0f, 0.2);
        return Tyra::Vec4(bobbingOffset.x, bobbingOffset.y, bobbingOffset.z);
    }
    else if (gunSwinging && playerCamera.getIsMoving()) {

        std::chrono::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();
        std::chrono::milliseconds elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - timerSincePlayerIsWalking);

        bobbingOffset.z = Cs::Utils::lerp(bobbingOffset.z, ((static_cast<int>(elapsed.count() / 1000)) % 2 == 1) ? -200.0f : 10.0f, 0.05);

        return Tyra::Vec4(bobbingOffset.x, bobbingOffset.y, bobbingOffset.z);
    }

    return Tyra::Vec4(0.0f, 0.0f, 0.0f);
}

void Gun::render(const Camera &playerCamera, const Tyra::Vec4 &gunPositionOffset, const Tyra::Vec4 &gunAngleOffset) {

    cameraDirection = (playerCamera.lookAt - playerCamera.position).getNormalized();

    calculateBobbingOffsetInDirection(playerCamera);

    for (auto model : itemModels) {

        rotationAngles = Cs::Utils::calculateRotationFromDirection(cameraDirection);
        position = playerCamera.position + Cs::Utils::getOffsetByDirection(cameraDirection, gunPositionOffset + bobbingOffset);

        rotationAngles.x = rotationAngles.x - gunAngleOffset.x;
        rotationAngles.y = rotationAngles.y - gunAngleOffset.y;
        rotationAngles.z = rotationAngles.z - gunAngleOffset.z;

        model->setPosition(Tyra::Vec4(position.x, position.y, position.z, 1));

        model->setAngle(rotationAngles); 
        model->render();
    }
}

void Gun::setAnimationIdle() {

    for (auto model : itemModels) {
        model->getMesh()->animation.setSequence(idleAnimationKeyframe);
    }

    currentAnimation = AnimationType::Idle;
}

void Gun::setAnimationShoot() {

    for (auto model : itemModels) {
        model->getMesh()->animation.setSequence(shootAnimationKeyframe);
    }

    currentAnimation = AnimationType::Shoot;
}