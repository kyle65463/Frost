#pragma once

#include "frost/renderer/vertex_array.h"
#include "glm/glm.hpp"

namespace Frost
{
    class RendererAPI
    {
    public:
        enum class API
        {
            None = 0,
            OpenGL = 1,
        };

        virtual void setClearColor(const glm::vec4& color) = 0;
        virtual void clear() = 0;

        virtual void drawIndexed(const std::shared_ptr<VertexArray>& vertexArray) = 0;
        inline static API getAPI() { return api; }

    private:
        static API api;
    };
}