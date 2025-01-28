#include "components/animatedModel.hpp"

AnimatedModel::AnimatedModel(Tyra::Engine* t_engine, const char modelPath[], const char texturePath[], float scale) : engine(t_engine) {

    dynpip.setRenderer(&engine->renderer.core);

    Tyra::MD2LoaderOptions options;

    options.scale = scale;

    auto data = Tyra::MD2Loader::load(Tyra::FileUtils::fromCwd(modelPath), options);

    mesh = std::make_unique<Tyra::DynamicMesh>(data.get());

    mesh->animation.speed = 0.25f;

    mesh->animation.setCallback([this](const Tyra::AnimationSequenceCallback& callback) {
        this->animationCallback(callback);
    });

    engine->renderer.getTextureRepository().addByMesh(mesh.get(), Tyra::FileUtils::fromCwd(texturePath), "png");
}

AnimatedModel::~AnimatedModel() {

    engine->renderer.getTextureRepository().freeByMesh(mesh.get());
    TYRA_LOG("Release: Animated Model Component");
}

void AnimatedModel::render() {
    
    engine->renderer.renderer3D.usePipeline(dynpip);

    mesh->update();

    dynpip.render(mesh.get(), renderOptions);
}

void AnimatedModel::animationCallback(const Tyra::AnimationSequenceCallback& callback) {
    animationFinished = callback == Tyra::AnimationSequenceCallback_Loop;
}