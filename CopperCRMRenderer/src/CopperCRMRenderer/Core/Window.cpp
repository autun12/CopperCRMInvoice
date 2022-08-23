#include "crpch.h"
#include "CopperCRMRenderer/Core/Window.h"

#if defined(CR_PLATFORM_WINDOWS) || defined(CR_PLATFORM_LINUX)
	#include "Platform/Windows/WindowsWindow.h"
#endif

namespace CopperCRMRenderer {
Scope<Window> Window::Create(const WindowProps& props) {
    #if defined(CR_PLATFORM_WINDOWS) || defined(CR_PLATFORM_LINUX)
        return CreateScope<WindowsWindow>(props);
    #else
        CR_CORE_ASSERT(false, "Unknown platform!");
        return nullptr;
    #endif
}
}