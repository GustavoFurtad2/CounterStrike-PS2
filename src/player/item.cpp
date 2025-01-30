#include "player/item.hpp"

Gun::Gun(Tyra::Engine* t_engine, const std::string& name, int baseDamage, const std::vector<AnimatedModel*> gunModels)
  : Item(t_engine, name, ItemType::Gun, gunModels), baseDamage(baseDamage) {

    setAnimationIdle();
}

Gun::~Gun() {

    for (auto *model : itemModels) {
        delete model;
    }

    itemModels.clear();

    TYRA_LOG("Release: Gun " + name);
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

        bobbingOffset.z = lerp(bobbingOffset.z, 0.0f, 0.1);
    }

    if (engine->pad.getPressed().R2 && !isShooting) {

        isShooting = true;
        setAnimationShoot();
    }

    if (itemModels[0]->animationFinished && isShooting) {

        setAnimationIdle();
        isShooting = false;
    }
}

Tyra::Vec4 Gun::calculateBobbingOffsetInDirection(const Camera &playerCamera) {

    if (gunSwinging && playerCamera.getIsMoving()) {

        std::chrono::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();
        std::chrono::milliseconds elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - timerSincePlayerIsWalking);

        bobbingOffset.z = lerp(bobbingOffset.z, ((static_cast<int>(elapsed.count() / 1000)) % 2 == 1) ? -200.0f : 10.0f, 0.05);

        return Tyra::Vec4(bobbingOffset.x, bobbingOffset.y, bobbingOffset.z);
    }

    return Tyra::Vec4(0.0f, 0.0f, 0.0f);
}

void Gun::render(const Camera &playerCamera, const Tyra::Vec4 &gunPositionOffset, const Tyra::Vec4 &gunAngleOffset) {

    cameraDirection = (playerCamera.lookAt - playerCamera.position).getNormalized();

    calculateBobbingOffsetInDirection(playerCamera);

    for (auto model : itemModels) {

        rotationAngles = calculateRotationFromDirection(cameraDirection);
        position = playerCamera.position + getOffsetInDirection(cameraDirection, gunPositionOffset + bobbingOffset);

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

Tyra::Vec4 Gun::calculateRotationFromDirection(const Tyra::Vec4& direction) {

    float pitch = Tyra::Math::atan2(direction.y, sqrt(direction.x * direction.x + direction.z * direction.z));
    float yaw = Tyra::Math::atan2(direction.x, direction.z);

    return Tyra::Vec4(-pitch, yaw, 0.0f);
}

Tyra::Vec4 Gun::getOffsetInDirection(const Tyra::Vec4& direction, const Tyra::Vec4& gunOffset) {

    Tyra::Vec4 forward = direction.getNormalized();

    Tyra::Vec4 up(0.0f, 1.0f, 0.0f);
    Tyra::Vec4 right = crossProduct(forward, up).getNormalized();
    Tyra::Vec4 correctedUp = crossProduct(right, forward).getNormalized();

    Tyra::Vec4 offsetGlobal = (right * gunOffset.x) + (correctedUp * gunOffset.y) + (forward * gunOffset.z);

    return offsetGlobal;
}

Tyra::Vec4 Gun::crossProduct(const Tyra::Vec4& a, const Tyra::Vec4& b) {
    return Tyra::Vec4(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x, 1);
}