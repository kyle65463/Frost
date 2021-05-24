#include "pch.h"

#include "render_command.h"
#include "frost/renderer/renderer_api.h"
#include "platform/opengl/opengl_renderer_api.h"

namespace Frost
{
    RendererAPI* RenderCommand::rendererAPI = new OpenGLRendererAPI();
}