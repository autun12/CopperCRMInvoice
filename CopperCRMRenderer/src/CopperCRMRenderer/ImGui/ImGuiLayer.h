#pragma once

#include "CopperCRMRenderer/Core/Layer.h"

#include "CopperCRMRenderer/Events/ApplicationEvent.h"
#include "CopperCRMRenderer/Events/KeyEvent.h"
#include "CopperCRMRenderer/Events/MouseEvent.h"

namespace CopperCRMRenderer {

class ImGuiLayer : public Layer {
public:
    ImGuiLayer();
    ~ImGuiLayer() = default;

    virtual void OnAttach() override;
    virtual void OnDetach() override;
    virtual void OnEvent(Event& e) override;

    void Begin();
    void End();

    void BlockEvents(bool block) { m_BlockEvents = block; }

    void SetDarkThemeColors();

private:
    bool m_BlockEvents = true;
    float m_Time = 0.0f;
};

}  // namespace CopperCRMRenderer