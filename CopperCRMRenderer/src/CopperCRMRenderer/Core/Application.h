#pragma once

#include "CopperCRMRenderer/Core/Base.h"
#include "CopperCRMRenderer/Events/ApplicationEvent.h"
#include "CopperCRMRenderer/Events/Event.h"
#include "CopperCRMRenderer/ImGui/ImGuiLayer.h"
#include "CopperCRMRenderer/Core/LayerStack.h"
#include "CopperCRMRenderer/Core/Window.h"
#include "CopperCRMRenderer/Core/Timestep.h"

int main(int argc, char** argv);

namespace CopperCRMRenderer {

class Application {
public:
    Application(std::string, const std::string& name = "Copper CRM Invoice");
    virtual ~Application();

    void OnEvent(Event& e);

    void PushLayer(Layer* layer);
    void PushOverlay(Layer* layer);

    inline Window& GetWindow() { return *m_Window; }

    void Close();

    ImGuiLayer* GetImGuiLayer() { return m_ImGuiLayer; }
    inline static Application& Get() { return *s_Instance; }
    std::string CorrectFilePath(const std::string&);

private:
    void Run();
    bool OnWindowClose(WindowCloseEvent& e);
    bool OnWindowResize(WindowResizeEvent& e);

    std::unique_ptr<Window> m_Window;
    ImGuiLayer* m_ImGuiLayer;
    bool m_Running = true;
    bool m_Minimized = false;
    LayerStack m_LayerStack;
    float m_LastFrameTime = 0.0f;

private:
    static Application* s_Instance;
    std::string m_BaseDirectory;
    friend int ::main(int argc, char** argv);
};

// To be defined in CLIENT
Application* CreateApplication();

}  // namespace CopperCRMRenderer