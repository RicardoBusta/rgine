//
// Created by Ricardo Bustamante <ricardo@busta.dev> on 03/06/2022.
//

#ifndef HARPIAGAMEENGINE_RENDERINGSYSTEMGL_H
#define HARPIAGAMEENGINE_RENDERINGSYSTEMGL_H

#include "RenderingSystem.h"

#include "GLTypes.h"

namespace Harpia::Internal {
    class Configuration;

    class RenderingSystemGL : public RenderingSystem {
    private:
        GLuint _programID = 0;
        GLint _vertexPos2DLocation = -1;
        GLuint _vertexBufferObject = 0;
        GLuint _indexBufferObject = 0;
        SDL_GLContext _context = nullptr;
    public:
        int GetWindowFlags() override;
        void RenderFrame() override;
        void Quit() override;
    private:
        int RenderingInitialize() override;
        bool InitGL();
        static void PrintProgramLog(GLuint program);
        static void PrintShaderLog(GLuint shader);

        MeshAsset *LoadMesh(int shape) override;
        void DrawMesh(MeshAsset *mesh) override;
        void UpdateMesh(GLuint *vertexBufferId, GLuint vertexCount, GLfloat *vertexData,
                        GLuint *indexBufferId, GLuint indexCount, GLint *indexData) override;
        void ReleaseMesh(MeshAsset *mesh) override;
        MaterialAsset *LoadMaterial(const Color &color) override;
        void ReleaseMaterial(MaterialAsset *material) override;
    };
} // Harpia::Internal


#endif //HARPIAGAMEENGINE_RENDERINGSYSTEMGL_H
