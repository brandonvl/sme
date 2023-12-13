#include "Sarene.h"
#include "Platform/OpenGL/OpenGLShader.h"

#include "imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Sarene
{
    class ExampleLayer : public Layer
    {
        public:
            ExampleLayer()
            : Layer("Example"), m_Camera(-1.6f, 1.6f, -0.9f, 0.9f), m_CameraPosition(0.0f)
            {
                m_VertexArray.reset(Sarene::VertexArray::Create());

                float vertices[3 * 7] = {
                    -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
                    0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
                    0.0f,  0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f
                };

                Sarene::Ref<Sarene::VertexBuffer> vertexBuffer;
                vertexBuffer.reset(Sarene::VertexBuffer::Create(vertices, sizeof(vertices)));

                Sarene::BufferLayout layout = {
                    { Sarene::ShaderDataType::Float3, "a_Position" },
                    { Sarene::ShaderDataType::Float4, "a_Color" }
                };

                vertexBuffer->SetLayout(layout);
                m_VertexArray->AddVertexBuffer(vertexBuffer);

                unsigned int indices[3] = { 0, 1, 2 };
                Sarene::Ref<Sarene::IndexBuffer> indexBuffer;
                indexBuffer.reset(Sarene::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
                m_VertexArray->SetIndexBuffer(indexBuffer);

                m_SquareVA.reset(Sarene::VertexArray::Create());

                float squareVertices[5 * 4] = {
                    -0.75f, -0.75f, 0.0f, 0.0f, 0.0f,
                    0.75f, -0.75f, 0.0f, 1.0f, 0.0f,
                    0.75f,  0.75f, 0.0f, 1.0f, 1.0f,
                    -0.75f,  0.75f, 0.0f, 0.0f, 1.0f
                };

                Sarene::Ref<Sarene::VertexBuffer> squareVB;
                squareVB.reset(Sarene::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));
                squareVB->SetLayout({
                        { Sarene::ShaderDataType::Float3, "a_Position" },
                        { Sarene::ShaderDataType::Float2, "a_TexCoord" }
                    });
                m_SquareVA->AddVertexBuffer(squareVB);

                uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
                Sarene::Ref<Sarene::IndexBuffer> squareIB;
                squareIB.reset(Sarene::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
                m_SquareVA->SetIndexBuffer(squareIB);

                std::string vertexSrc = R"(
                    #version 330 core

                    layout(location = 0) in vec3 a_Position;
                    layout(location = 1) in vec4 a_Color;

                    uniform mat4 u_ViewProjection;
                    uniform mat4 u_Transform;

                    out vec3 v_Position;
                    out vec4 v_Color;

                    void main()
                    {
                        v_Position = a_Position;
                        v_Color = a_Color;
                        gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
                    }
                )";

                std::string fragmentSrc = R"(
                    #version 330 core

                    layout(location = 0) out vec4 color;

                    in vec3 v_Position;
                    in vec4 v_Color;

                    void main()
                    {
                        color = vec4(v_Position * 0.5 + 0.5, 1.0);
                        color = v_Color;
                    }
                )";

                m_Shader.reset(Sarene::Shader::Create(vertexSrc, fragmentSrc));

                std::string flatColorShaderVertexSrc = R"(
                    #version 330 core
                    
                    layout(location = 0) in vec3 a_Position;
                    uniform mat4 u_ViewProjection;
                    uniform mat4 u_Transform;
                    out vec3 v_Position;
                    void main()
                    {
                        v_Position = a_Position;
                        gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);	
                    }
                )";

                std::string flatColorShaderFragmentSrc = R"(
                    #version 330 core
                    
                    layout(location = 0) out vec4 color;
                    in vec3 v_Position;
                    
                    uniform vec3 u_Color;
                    void main()
                    {
                        color = vec4(u_Color, 1.0);
                    }
                )";

                m_FlatColorShader.reset(Sarene::Shader::Create(flatColorShaderVertexSrc, flatColorShaderFragmentSrc));

                //std::dynamic_pointer_cast<Sarene::OpenGLShader>(m_TextureShader)->Bind();
                //std::dynamic_pointer_cast<Sarene::OpenGLShader>(m_TextureShader)->UploadUniformInt("u_Texture", 0);
            }

            void OnUpdate(Sarene::Timestep ts) override
            {
                if (Sarene::Input::IsKeyPressed(SAR_KEY_LEFT))
                    m_CameraPosition.x -= m_CameraMoveSpeed * ts;
                else if (Sarene::Input::IsKeyPressed(SAR_KEY_RIGHT))
                    m_CameraPosition.x += m_CameraMoveSpeed * ts;

                if (Sarene::Input::IsKeyPressed(SAR_KEY_UP))
                    m_CameraPosition.y += m_CameraMoveSpeed * ts;
                else if (Sarene::Input::IsKeyPressed(SAR_KEY_DOWN))
                    m_CameraPosition.y -= m_CameraMoveSpeed * ts;

                if (Sarene::Input::IsKeyPressed(SAR_KEY_A))
                    m_CameraRotation += m_CameraRotationSpeed * ts;
                else if (Sarene::Input::IsKeyPressed(SAR_KEY_D))
                    m_CameraRotation -= m_CameraRotationSpeed * ts;

                Sarene::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
                Sarene::RenderCommand::Clear();

                m_Camera.SetPosition(m_CameraPosition);
                m_Camera.SetRotation(m_CameraRotation);

                Sarene::Renderer::BeginScene(m_Camera);

                glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));

                std::dynamic_pointer_cast<Sarene::OpenGLShader>(m_FlatColorShader)->Bind();
                std::dynamic_pointer_cast<Sarene::OpenGLShader>(m_FlatColorShader)->UploadUniformFloat3("u_Color", m_SquareColor);

                for (int y = 0; y < 20; y++)
                {
                    for (int x = 0; x < 20; x++)
                    {
                        glm::vec3 pos(x * 0.16f, y * 0.16f, 0.0f);
                        glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * scale;
                        Sarene::Renderer::Submit(m_FlatColorShader, m_SquareVA, transform);
                    }
                }

                //m_Texture->Bind();
                //Sarene::Renderer::Submit(m_TextureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.0f)));

                Sarene::Renderer::Submit(m_Shader, m_VertexArray);

                Sarene::Renderer::EndScene();
            }

            virtual void OnImGuiRender() override
            {
                ImGui::Begin("Settings");
                ImGui::ColorEdit3("Square Color", glm::value_ptr(m_SquareColor));
                ImGui::End();
            }

            void OnEvent(Sarene::Event& event) override
            {

            }

        private:
        Sarene::Ref<Sarene::Shader> m_Shader;
        Sarene::Ref<Sarene::VertexArray> m_VertexArray;

        Sarene::Ref<Sarene::Shader> m_FlatColorShader, m_TextureShader;
        Sarene::Ref<Sarene::VertexArray> m_SquareVA;

        Sarene::Ref<Sarene::Texture2D> m_Texture;

        Sarene::OrthographicCamera m_Camera;
        glm::vec3 m_CameraPosition;
        float m_CameraMoveSpeed = 5.0f;

        float m_CameraRotation = 0.0f;
        float m_CameraRotationSpeed = 180.0f;

        glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };

    };

    class SMEApp : public Application
    {
        public:
            SMEApp()
            {
                PushLayer(new ExampleLayer());
            }

            ~SMEApp()
            {
            }
    };

    Application* CreateApplication()
    {
        return new SMEApp();
    }
}
