#include "components/animatedModel.hpp"
#include "game.hpp"

AnimatedModel::AnimatedModel(const char modelPath[], const char texturePath[], float scale) {

    dynpip.setRenderer(&Cs::GetEngine()->renderer.core);

    Tyra::MD2LoaderOptions options;

    options.scale = scale;

    auto data = Tyra::MD2Loader::load(Tyra::FileUtils::fromCwd(modelPath), options);

    mesh = std::make_unique<Tyra::DynamicMesh>(data.get());

    mesh->animation.speed = 0.25f;

    mesh->animation.setCallback([this](const Tyra::AnimationSequenceCallback& callback) {
        this->animationCallback(callback);
    });

    Cs::GetEngine()->renderer.getTextureRepository().addByMesh(mesh.get(), Tyra::FileUtils::fromCwd(texturePath), "png");
}

AnimatedModel::~AnimatedModel() {

    Cs::GetEngine()->renderer.getTextureRepository().freeByMesh(mesh.get());
    TYRA_LOG("Release: Animated Model Component");
}

void AnimatedModel::render() {
    
    Cs::GetEngine()->renderer.renderer3D.usePipeline(dynpip);

    mesh->update();

    dynpip.render(mesh.get(), renderOptions);
}

void AnimatedModel::animationCallback(const Tyra::AnimationSequenceCallback& callback) {
    animationFinished = callback == Tyra::AnimationSequenceCallback_Loop;
}