#include "sarpch.h"
#include "Platform/OpenGL/OpenGLContext.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Sarene
{
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		SAR_CORE_ASSERT(windowHandle, "Window handle is null!");
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		SAR_CORE_ASSERT(status, "Failed to initialize Glad!");

		SAR_CORE_INFO("OpenGL Info:");
		SAR_CORE_INFO(" Vendor: {0}", (const char*)glGetString(GL_VENDOR));
		SAR_CORE_INFO(" Renderer: {0}", (const char*)glGetString(GL_RENDERER));
		SAR_CORE_INFO(" Version: {0}", (const char*)glGetString(GL_VERSION));

		#ifdef SAR_ENABLE_ASSERTS
			int versionMajor;
			int versionMinor;
			glGetIntegerv(GL_MAJOR_VERSION, &versionMajor);
			glGetIntegerv(GL_MINOR_VERSION, &versionMinor);

			SAR_CORE_ASSERT(versionMajor > 4 || (versionMajor == 4 && versionMinor >= 5), "Sarene requires at least OpenGL version 4.5!");
		#endif
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}