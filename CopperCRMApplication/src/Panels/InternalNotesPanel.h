#pragma once

#include <CopperCRMRenderer/Core/Base.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <imgui/imgui.h>

namespace CopperCRMRenderer {
class InternalNotesPanel {
public:
    InternalNotesPanel() = default;
    void OnImGuiRender(bool* open);
    
    // Getters
    inline std::string GetInternalNotes() { return m_InternalNotes; }

    // Setters
    inline void SetInternalNotes(std::string internalNotes) {m_InternalNotes = internalNotes; }
private:
    std::string m_InternalNotes = "";
};
}