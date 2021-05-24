#pragma once

#include "frost/renderer/vertex_array.h"
#include "frost/renderer/renderer_api.h"
#include "frost/renderer/render_command.h"

namespace Frost
{
    class Renderer
    {
    public:
        static void beginScene();
        static void endScene();
        static void submit(const std::shared_ptr<VertexArray>& vertexArray);
        inline static RendererAPI::API getAPI() { return RendererAPI::getAPI(); }
    };
}