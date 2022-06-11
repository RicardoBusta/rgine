//
// Created by Ricardo Bustamante <ricardo@busta.dev> on 06/06/2022.
//

#ifndef HARPIAGAMEENGINE_CAMERACOMPONENT_H
#define HARPIAGAMEENGINE_CAMERACOMPONENT_H

#include "Component.h"
#include "Camera_Internal.h"

namespace Harpia {
    class CameraComponent : public Component, private Internal::Camera_Internal {
    public:
        CameraComponent();

        void SetViewport(const RectInt &viewport);
        void SetClearColor(const Color &color);
    };
} // Harpia

#endif //HARPIAGAMEENGINE_CAMERACOMPONENT_H
