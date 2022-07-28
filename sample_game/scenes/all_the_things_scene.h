//
// Created by Ricardo Bustamante <ricardo@busta.dev> on 28/07/2022.
//

#ifndef HARPIAGAMEENGINE_ALL_THE_THINGS_SCENE_H
#define HARPIAGAMEENGINE_ALL_THE_THINGS_SCENE_H

#include <hge/global_defines.h>
#include <hge/rect.h>
#include <hge/scene.h>

using namespace Harpia;

namespace SampleGame {
    class AllTheThingsScene: public Scene {
    public:
        void Load(Application *application) override;

    private:
        Object *
        CreateRotatingShape(const Vector3 &position, const Vector3 &rotatingSpeed, const Vector3 &scale, const Color &color,
                            ShaderAsset *shader, TextureAsset *texture, MeshAsset *mesh);
        void CreateAudioObjects();
        void CreateCameraObject(const Application *application, const RectInt &viewport, Object *parent);
    };
}// namespace SampleGame

#endif//HARPIAGAMEENGINE_ALL_THE_THINGS_SCENE_H