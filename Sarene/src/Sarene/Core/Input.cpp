#include "sarpch.h"
#include "Sarene/Core/Input.h"

#ifdef SAR_PLATFORM_WINDOWS
    #include "Platform/Windows/WindowsInput.h"
#endif

namespace Sarene
{
    Scope<Input> Input::s_Instance = Input::Create();

    Scope<Input> Input::Create()
    {
        #ifdef SAR_PLATFORM_WINDOWS
            return CreateScope<WindowsInput>();
        #else
            SAR_CORE_ASSERT(false, "Unknown platform!");
            return nullptr;
        #endif
    }
}