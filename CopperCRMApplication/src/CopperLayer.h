#pragma once

#include <CopperCRMRenderer.h>
#include "Panels/ConsolePanel.h"
#include "Panels/CustomerNotesPanel.h"
#include "Panels/InternalNotesPanel.h"
#include "Panels/MenuPanel.h"
#include <string>

namespace CopperCRMRenderer {
class CopperLayer : public Layer {
public:
    CopperLayer();
    virtual ~CopperLayer() = default;

    virtual void OnAttach() override;
    virtual void OnDetach() override;
    void OnUpdate(Timestep ts) override;
    virtual void OnImGuiRender() override;
    void OnEvent(Event& e) override;
    
private:
    bool OnKeyPressed(KeyPressedEvent& e);

private:
    bool m_ViewportFocused = false;
    bool m_ViewportHovered = false;
    glm::vec2 m_ViewportSize = { 0.0f, 0.0f };

    // Debug Panel
    ConsolePanel m_ConsolePanel;

    // Panels
    CustomerNotesPanel m_CustomerNotesPanel;
    InternalNotesPanel m_InternalNotesPanel;
    MenuPanel m_MenuPanel;

};
}