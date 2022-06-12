//
// Created by Ricardo Bustamante <ricardo@busta.dev> on 11/06/2022.
//

#ifndef HARPIAGAMEENGINE_MATERIALASSET_H
#define HARPIAGAMEENGINE_MATERIALASSET_H

#include "Asset.h"

namespace Harpia {
    class MaterialAsset : public Asset {
    private:
        Internal::RenderingSystem *_renderingSystem = nullptr;
    public:
        explicit MaterialAsset(Internal::RenderingSystem *renderingSystem);
        MaterialAsset() = delete;
        void Release() override;
    };
} // Harpia

#endif //HARPIAGAMEENGINE_MATERIALASSET_H