#pragma once

#include <CopperCRMRenderer/Core/Base.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <imgui/imgui.h>

namespace CopperCRMRenderer {
class MenuPanel {
public:
    MenuPanel() = default;
    void OnImGuiRender(bool* open);
    
private:
    // std::string m_CustomerNotes = "";
};
}