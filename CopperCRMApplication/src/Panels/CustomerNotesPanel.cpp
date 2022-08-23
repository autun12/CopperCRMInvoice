#include "CustomerNotesPanel.h"
#include <CopperCRMRenderer/Utils/PlatformUtils.h>
#include <filesystem>
#include <cstring>
#include "imgui/imgui.h"

namespace CopperCRMRenderer {
void CustomerNotesPanel::OnImGuiRender(bool* open) {
    ImGui::Begin("Customer Notes", open);
    ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4{ 0.15f, 0.15f, 0.15f, 1.0f });
    ImGui::BeginChild("ScrollRegion", ImVec2(0, 0), false, ImGuiWindowFlags_HorizontalScrollbar);
    char buffer[256];
    memset(buffer, 0, sizeof(buffer));
    std::strncpy(buffer, GetCustomerNotes().c_str(), sizeof(buffer));
    float size_height = ImGui::GetWindowHeight();
    float size_width = ImGui::GetWindowWidth();
    if(ImGui::InputTextMultiline("##Customer", buffer, IM_ARRAYSIZE(buffer),ImVec2(size_width, size_height))) {
        SetCustomerNotes(std::string(buffer));
        // CR_INFO(GetCustomerNotes());
    }
    ImGui::EndChild();
 
    ImGui::PopStyleColor();
    ImGui::End();

}
}