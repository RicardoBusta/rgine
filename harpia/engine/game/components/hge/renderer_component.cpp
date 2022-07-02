//
// Created by Ricardo Bustamante <ricardo@busta.dev> on 10/06/2022.
//

#include "renderer_component.h"

namespace Harpia {
    void RendererComponent::SetMesh(MeshAsset *mesh) {
        _mesh = mesh;
    }

    void RendererComponent::SetMaterial(MaterialAsset *material) {
        _material = material;
    }

    Transform *RendererComponent::GetTransformInternal() {
        return &GetObject()->transform;
    }
}// namespace Harpia