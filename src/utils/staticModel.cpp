#include <cmath>
#include "utils/staticModel.hpp"


Model::Model(Tyra::Engine* t_engine, const char modelPath[], const char texturePath[], float scale) : engine(t_engine) {

    stapip.setRenderer(&engine->renderer.core);

    Tyra::ObjLoaderOptions options;

    options.scale = scale;

    auto data = Tyra::ObjLoader::load(Tyra::FileUtils::fromCwd(modelPath), options);

    mesh = std::make_unique<Tyra::StaticMesh>(data.get());

    renderOptions.frustumCulling = Tyra::PipelineFrustumCulling_None;

    engine->renderer.getTextureRepository().addByMesh(mesh.get(), Tyra::FileUtils::fromCwd(texturePath), "png");
}

Model::~Model() {
    engine->renderer.getTextureRepository().freeByMesh(mesh.get());
}

void Model::draw() {

    engine->renderer.renderer3D.usePipeline(stapip);

    stapip.render(mesh.get(), renderOptions);
}