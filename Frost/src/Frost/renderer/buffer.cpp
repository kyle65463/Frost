#include "pch.h"

#include "buffer.h"
#include "platform/opengl/opengl_buffer.h"

namespace Frost
{
    VertexBuffer *VertexBuffer::create(float *vertices, uint32_t size)
    {
        FS_INFO("hi");
        return new OpenGLVertexBuffer(vertices, size);
    }

    IndexBuffer *IndexBuffer::create(uint32_t* indices, uint32_t size)
    {
        return new OpenGLIndexBuffer(indices, size);
    }
}