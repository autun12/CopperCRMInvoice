#pragma once

#include <CopperCRMRenderer/Core/Base.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <imgui/imgui.h>

namespace CopperCRMRenderer {
class CustomerNotesPanel {
public:
    CustomerNotesPanel() = default;
    void OnImGuiRender(bool* open);
    
    // Getters
    inline std::string GetCustomerNotes() { return m_CustomerNotes; }

    // Setters
    inline void SetCustomerNotes(std::string CustomerNotes) {m_CustomerNotes = CustomerNotes; }
private:
    std::string m_CustomerNotes = "";
};
}