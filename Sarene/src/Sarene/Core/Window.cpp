#include "sarpch.h"
#include "Sarene/Core/Window.h"

#ifdef SAR_PLATFORM_WINDOWS
    #include "Platform/Windows/WindowsWindow.h"
#endif

namespace Sarene
{
    Scope<Window> Window::Create(const WindowProps& props)
    {
        #ifdef SAR_PLATFORM_WINDOWS
            return CreateScope<WindowsWindow>(props);
        #else
            SAR_CORE_ASSERT(false, "Unknown platform!");
            return nullptr;
        #endif
    }
}