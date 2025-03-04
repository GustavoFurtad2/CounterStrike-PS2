#pragma once

#include <tyra>

class Model {

    public:

        Model(const char modelPath[], const char texturePath[], float scale);
        ~Model();

        void render();

        Tyra::StaticMesh* getMesh() {
            return mesh.get();
        };

        void setPosition(Tyra::Vec4 newPosition) {

            position = Tyra::Vec4(newPosition.x - position.x, newPosition.y - position.y, newPosition.z - position.z, 1);
            mesh.get()->translation.translate(position);
        }

        void setAngle(Tyra::Vec4 newAngle) {

            angle = Tyra::Vec4(newAngle.x - angle.x, newAngle.y - angle.y, newAngle.z - angle.z, 1);
            mesh.get()->rotation.rotate(angle);
        }

    private:

        Tyra::Vec4 position = Tyra::Vec4(0.0f, 0.0f, 0.0f, 1);
        Tyra::Vec4 angle = Tyra::Vec4(0.0f, 0.0f, 0.0f, 1);

        Tyra::StaticPipeline stapip;

        Tyra::StaPipOptions renderOptions;

        std::unique_ptr<Tyra::StaticMesh> mesh;

};