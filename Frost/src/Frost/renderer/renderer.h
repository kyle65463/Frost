#pragma once

#include "frost/renderer/vertex_array.h"
#include "frost/renderer/shader.h"
#include "frost/renderer/renderer_api.h"
#include "frost/renderer/render_command.h"
#include "frost/renderer/orthographic_camera.h"

namespace Frost
{
    class FROST_API Renderer
    {
    public:
        static void beginScene(OrthographicCamera& camera);
        static void endScene();
        static void submit(const std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexArray>& vertexArray);
        inline static RendererAPI::API getAPI() { return RendererAPI::getAPI(); }
    private:
        struct SceneData
        {
            glm::mat4 viewPrjectionMatrix;
        };

        static SceneData* sceneData;
    };
}