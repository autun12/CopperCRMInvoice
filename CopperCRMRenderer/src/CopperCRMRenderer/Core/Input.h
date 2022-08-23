#pragma once

#include <glm/glm.hpp>
#include "CopperCRMRenderer/Core/KeyCodes.h"
#include "CopperCRMRenderer/Core/MouseCodes.h"

namespace CopperCRMRenderer {

class Input {
public:
    static bool IsKeyPressed(KeyCode key);

    static bool IsMouseButtonPressed(MouseCode button);
    static glm::vec2 GetMousePosition();
    static float GetMouseX();
    static float GetMouseY();
};

}  // namespace CopperCRMRenderer