#pragma once

#include <tyra>

class Model {

    public:

        Model(Tyra::Engine* t_engine, const char modelPath[], const char texturePath[], float scale);
        ~Model();

        void render();

        Tyra::StaticMesh* getMesh() {
            return mesh.get();
        };

        void setPosition(Tyra::Vec4 position) {
            mesh.get()->setPosition(position);
        };

    private:

        Tyra::Engine* engine;

        Tyra::StaticPipeline stapip;

        Tyra::StaPipOptions renderOptions;

        std::unique_ptr<Tyra::StaticMesh> mesh;

};