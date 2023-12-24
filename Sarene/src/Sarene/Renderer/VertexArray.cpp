#include "sarpch.h"
#include "Sarene/Renderer/VertexArray.h"

#include "Sarene/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Sarene
{
	Ref<VertexArray> VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    SAR_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:  return CreateRef<OpenGLVertexArray>();
		}

		SAR_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}