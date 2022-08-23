#pragma once

#include "CopperCRMRenderer/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace CopperCRMRenderer {

class OpenGLContext : public GraphicsContext {
public:
    OpenGLContext(GLFWwindow* windowHandle);

    virtual void Init() override;
    virtual void SwapBuffers() override;

private:
    GLFWwindow* m_WindowHandle;
};

}  // namespace CopperCRMRenderer