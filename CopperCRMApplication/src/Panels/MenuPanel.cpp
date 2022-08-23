#include "MenuPanel.h"
#include <CopperCRMRenderer/Utils/PlatformUtils.h>
#include <filesystem>
#include <cstring>
#include "imgui/imgui.h"

namespace CopperCRMRenderer {
void MenuPanel::OnImGuiRender(bool* open) {
    ImGui::Begin("Application Menus", open);
    ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4{ 0.15f, 0.15f, 0.15f, 1.0f });
    ImGui::BeginChild("ScrollRegion", ImVec2(0, 0), false, ImGuiWindowFlags_HorizontalScrollbar);
    
    ImGui::EndChild();
 
    ImGui::PopStyleColor();
    ImGui::End();

}
}