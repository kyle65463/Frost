#include "pch.h"

#include "opengl_buffer.h"
#include "glad/glad.h"

namespace Frost
{
    OpenGLVertexBuffer::OpenGLVertexBuffer(float *vertices, uint32_t size)
    {
        glGenBuffers(1, &rendererId);
        glBindBuffer(GL_ARRAY_BUFFER, rendererId);
        glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
    }

    OpenGLVertexBuffer::~OpenGLVertexBuffer()
    {
        glDeleteBuffers(1, &rendererId);
    }

    void OpenGLVertexBuffer::bind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, rendererId);
    }

    void OpenGLVertexBuffer::unbind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    // Index Buffer

    OpenGLIndexBuffer::OpenGLIndexBuffer(uint32_t *indices, uint32_t count)
        : count(count)
    {
        glGenBuffers(1, &rendererId);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rendererId);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(uint32_t), indices, GL_STATIC_DRAW);
    }

    OpenGLIndexBuffer::~OpenGLIndexBuffer()
    {
        glDeleteBuffers(1, &rendererId);
    }

    void OpenGLIndexBuffer::bind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, rendererId);
    }

    void OpenGLIndexBuffer::unbind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }
}