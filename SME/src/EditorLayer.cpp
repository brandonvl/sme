#include "EditorLayer.h"

#include "imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Sarene
{
    EditorLayer::EditorLayer()
        : Layer("EditorLayer"), m_CameraController(1280.0f / 720.0f)
    {
        
    }

    void EditorLayer::OnAttach()
    {
        m_CheckerboardTexture = Texture2D::Create("assets/textures/Checkerboard.png");
    }

    void EditorLayer::OnDetach()
    {
        
    }

    void EditorLayer::OnUpdate(Timestep ts)
    {
        // Update
        m_CameraController.OnUpdate(ts);

        // Render
        Renderer2D::ResetStats();
        RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
        RenderCommand::Clear();

        Renderer2D::BeginScene(m_CameraController.GetCamera());
        //Renderer2D::DrawQuad( { -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
        //Renderer2D::DrawQuad( { 0.5f, -0.5f }, { 0.5f, 0.75f }, { 0.2f, 0.3f, 0.8f, 1.0f });
        //Renderer2D::DrawQuad( { -5.0f, -5.0f, -0.1f }, { 20.0f, 20.0f }, m_CheckerboardTexture, 10.0f);

        for(float y = -5.0f; y < 5.0f; y += 0.5f)
        {
            for(float x = -5.0f; x < 5.0f; x += 0.5f)
            {
                glm::vec4 color = { (x + 5.0f) / 10.0f, 0.4f, (y + 5.0f) / 10.0f, 0.5f };
                Renderer2D::DrawQuad( { x, y }, { 0.45f, 0.45f }, color);
            }
        }

        Renderer2D::EndScene();
    }

    void EditorLayer::OnImGuiRender()
    {
        ImGui::Begin("Settings");

        auto stats = Renderer2D::GetStats();
        ImGui::Text("Renderer2D Stats:");
        ImGui::Text("Draw Calls: %d", stats.DrawCalls);
        ImGui::Text("Quad Count: %d", stats.QuadCount);
        ImGui::Text("Vertex Count: %d", stats.GetTotalVertexCount());
        ImGui::Text("Index Count: %d", stats.GetTotalIndexCount());

        ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
        ImGui::End();
    }

    void EditorLayer::OnEvent(Event& e)
    {
        m_CameraController.OnEvent(e);
    }
}