#pragma once

#include "frost/renderer/vertex_array.h"

namespace Frost
{
    class OpenGLVertexArray : public VertexArray
    {
    public:
        OpenGLVertexArray();
        ~OpenGLVertexArray();

        void bind() const override;
        void unbind() const override;
        void addVertexBuffer(const std::shared_ptr<VertexBuffer> &vertexBuffer) override;
        void setIndexBuffer(const std::shared_ptr<IndexBuffer> &indexBuffer) override;

        const std::vector<std::shared_ptr<VertexBuffer>>& getVertexBuffers() const override { return vertexBuffers; }
        const std::shared_ptr<IndexBuffer>& getIndexBuffer() const override { return indexBuffer; }

    private:
        uint32_t rendererId;
        std::vector<std::shared_ptr<VertexBuffer>> vertexBuffers;
        std::shared_ptr<IndexBuffer> indexBuffer;
    };
}