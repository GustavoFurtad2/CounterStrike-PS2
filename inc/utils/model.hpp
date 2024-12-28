#pragma once

#include <tyra>

class Model {

    public:

        Model(Tyra::Engine* t_engine);
        ~Model();

    private:

        Tyra::Engine* engine;

        Tyra::StaticPipeline stapip;

        Tyra::StaPipOptions renderOptions;

        std::unique_ptr<Tyra::StaticMesh> mesh;


}