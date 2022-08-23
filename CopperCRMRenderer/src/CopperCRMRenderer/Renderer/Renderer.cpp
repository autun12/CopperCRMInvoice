#include "crpch.h"
#include "CopperCRMRenderer/Renderer/Renderer.h"

namespace CopperCRMRenderer {
void Renderer::Init() {
    RenderCommand::Init();
}

void Renderer::OnWindowResize(uint32_t width, uint32_t height) {
    RenderCommand::SetViewport(0, 0, width, height);
}
}