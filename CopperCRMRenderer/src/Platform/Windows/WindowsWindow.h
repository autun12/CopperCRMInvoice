#pragma once

#include <GLFW/glfw3.h>

#include "CopperCRMRenderer/Renderer/GraphicsContext.h"
#include "CopperCRMRenderer/Core/Window.h"

namespace CopperCRMRenderer {

class WindowsWindow : public Window {
public:
    WindowsWindow(const WindowProps& props);
    virtual ~WindowsWindow();

    void OnUpdate() override;

    unsigned int GetWidth() const override { return m_Data.Width; }
    unsigned int GetHeight() const override { return m_Data.Height; }

    // Window attributes
    void SetEventCallback(const EventCallbackFn& callback) override {
        m_Data.EventCallback = callback;
    }
    void SetVSync(bool enabled) override;
    bool IsVSync() const override;

    inline virtual void* GetNativeWindow() const { return m_Window; }

private:
    virtual void Init(const WindowProps& props);
    virtual void Shutdown();

private:
    GLFWwindow* m_Window;
    Scope<GraphicsContext> m_Context;

    struct WindowData {
        std::string Title;
        unsigned int Width, Height;
        bool VSync;

        EventCallbackFn EventCallback;
    };

    WindowData m_Data;
};

}  // namespace CopperCRMRenderer