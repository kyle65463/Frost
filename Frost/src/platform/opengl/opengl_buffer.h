#pragma once

#include "frost/renderer/buffer.h"

namespace Frost
{
    class OpenGLVertexBuffer : public VertexBuffer
    {
    public:
        OpenGLVertexBuffer(float* vertices, uint32_t size);
        ~OpenGLVertexBuffer();

        void bind() const override;
        void unbind() const override;

    private:
        uint32_t rendererId;
    };

    class OpenGLIndexBuffer : public IndexBuffer
    {
    public:
        OpenGLIndexBuffer(uint32_t* indices, uint32_t count);
        ~OpenGLIndexBuffer();

        void bind() const override;
        void unbind() const override;

        uint32_t getCount() const override { return count; }

    private:
        uint32_t rendererId;
        uint32_t count;
    };
}