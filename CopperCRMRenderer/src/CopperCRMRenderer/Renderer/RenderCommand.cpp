#include "crpch.h"
#include "CopperCRMRenderer/Renderer/RenderCommand.h"

namespace CopperCRMRenderer {
Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();
}