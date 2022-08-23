#include "InternalNotesPanel.h"
#include <CopperCRMRenderer/Utils/PlatformUtils.h>
#include <filesystem>
#include <cstring>
#include "imgui/imgui.h"

namespace CopperCRMRenderer {
void InternalNotesPanel::OnImGuiRender(bool* open) {
    ImGui::Begin("Internal Notes", open);
    ImGui::PushStyleColor(ImGuiCol_ChildBg, ImVec4{ 0.15f, 0.15f, 0.15f, 1.0f });
    ImGui::BeginChild("ScrollRegion", ImVec2(0, 0), false, ImGuiWindowFlags_HorizontalScrollbar);
    char buffer[256];
    memset(buffer, 0, sizeof(buffer));
    std::strncpy(buffer, GetInternalNotes().c_str(), sizeof(buffer));
    float size_height = ImGui::GetWindowHeight();
    float size_width = ImGui::GetWindowWidth();
    if(ImGui::InputTextMultiline("##Internal", buffer, IM_ARRAYSIZE(buffer),ImVec2(size_width, size_height))) {
        SetInternalNotes(std::string(buffer));
        // CR_INFO(GetInternalNotes());
    }
    ImGui::EndChild();
 
    ImGui::PopStyleColor();
    ImGui::End();

}
}