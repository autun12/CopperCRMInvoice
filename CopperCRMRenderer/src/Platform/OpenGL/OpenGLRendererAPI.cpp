#include "crpch.h"
#include "Platform/OpenGL/OpenGLRendererAPI.h"

#include <glad/glad.h>

namespace CopperCRMRenderer {
void OpenGLMessageCallback(unsigned source, unsigned type, unsigned id, unsigned severity, int length,	const char* message, const void* userParam) {
    switch (severity) {
        case GL_DEBUG_SEVERITY_HIGH:         CR_CORE_CRITICAL(message); return;
        case GL_DEBUG_SEVERITY_MEDIUM:       CR_CORE_ERROR(message); return;
        case GL_DEBUG_SEVERITY_LOW:          CR_CORE_WARN(message); return;
        case GL_DEBUG_SEVERITY_NOTIFICATION: CR_CORE_TRACE(message); return;
    }
    
    CR_CORE_ASSERT(false, "Unknown severity level!");
}


void OpenGLRendererAPI::Init() {
#ifdef HZ_DEBUG
    glEnable(GL_DEBUG_OUTPUT);
    glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
    glDebugMessageCallback(OpenGLMessageCallback, nullptr);
    
    glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DEBUG_SEVERITY_NOTIFICATION, 0, NULL, GL_FALSE);
#endif

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_DEPTH_TEST);
}

void OpenGLRendererAPI::SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) {
    glViewport(x, y, width, height);
}

void OpenGLRendererAPI::SetClearColor(const glm::vec4& color) {
    glClearColor(color.r, color.g, color.b, color.a);
}

void OpenGLRendererAPI::Clear() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

}