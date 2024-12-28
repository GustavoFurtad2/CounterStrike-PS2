#include "utils/model.hpp"

Model::Model(Tyra::Engine* t_engine) : engine(t_engine) {

    stapip.setRenderer(&engine->renderer.core);

    ObjLoaderOptions options;

    options.scale = 200.0f;

    auto data = ObjLoader::load(FileUtils::fromCwd("assets/gameplay/de_dust2/de_dust2.obj"), options);
}

Model::~Model() {

}