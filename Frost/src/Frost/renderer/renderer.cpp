#include "pch.h"

#include "renderer.h"

namespace Frost
{
    Renderer::SceneData* Renderer::sceneData = new Renderer::SceneData();

    void Renderer::beginScene(OrthographicCamera& camera)
    {
        sceneData->viewPrjectionMatrix = camera.getViewProjectionMatrix();
    }
    
    void Renderer::endScene()
    {
        
    }

    void Renderer::submit(const std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexArray> &vertexArray)
    {
        shader->bind();
        shader->uploadUniformMat4("u_ViewProjection", sceneData->viewPrjectionMatrix);
        vertexArray->bind();
        RenderCommand::drawIndexed(vertexArray);
    }
}