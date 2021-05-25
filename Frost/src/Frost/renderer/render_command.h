#pragma once

#include "frost/renderer/renderer_api.h"

namespace Frost
{
    class FROST_API RenderCommand
    {
    public:
        inline static void setClearColor(const glm::vec4& color) {  rendererAPI->setClearColor(color); }
        inline static void clear() { rendererAPI->clear(); }
        inline static void drawIndexed(const std::shared_ptr<VertexArray>& vertexArray) { rendererAPI->drawIndexed(vertexArray); }

    private:
        static RendererAPI* rendererAPI;
    };
}