#include "components/staticModel.hpp"
#include "game.hpp"

Model::Model() {}

Model::~Model() {

    Cs::GetEngine()->renderer.getTextureRepository().freeByMesh(mesh.get());
    TYRA_LOG("Release: Static Model Component");
}

void Model::init(const char modelPath[], const char texturePath[], float scale) {

    stapip.setRenderer(& Cs::GetEngine()->renderer.core);

    Tyra::ObjLoaderOptions options;

    options.scale = scale;
    options.flipUVs = true;

    auto data = Tyra::ObjLoader::load(Tyra::FileUtils::fromCwd(modelPath), options);

    mesh = std::make_unique<Tyra::StaticMesh>(data.get());

    renderOptions.frustumCulling = Tyra::PipelineFrustumCulling_None;
    
    Cs::GetEngine()->renderer.getTextureRepository().addByMesh(mesh.get(), Tyra::FileUtils::fromCwd(texturePath), "png");
}

void Model::render() {

    Cs::GetEngine()->renderer.renderer3D.usePipeline(stapip);

    stapip.render(mesh.get(), renderOptions);
}