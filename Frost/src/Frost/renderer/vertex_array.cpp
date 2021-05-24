#include "pch.h"

#include "vertex_array.h"
#include "frost/renderer/buffer.h"
#include "platform/opengl/opengl_vertex_array.h"

namespace Frost
{
    VertexArray* VertexArray::create() {
        return new OpenGLVertexArray();
    }
}