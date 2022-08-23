#pragma once

#include "CopperCRMRenderer/Core/Base.h"

// This ignores all warnings raised inside External headers
#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#pragma warning(pop)

namespace CopperCRMRenderer {

class Log {
public:
    static void Init();

    static Ref<spdlog::logger>& GetCoreLogger() {
        return s_CoreLogger;
    }
    static Ref<spdlog::logger>& GetClientLogger() {
        return s_ClientLogger;
    }

private:
    static Ref<spdlog::logger> s_CoreLogger;
    static Ref<spdlog::logger> s_ClientLogger;
};

}  // namespace CopperCRMRenderer

// Core log macros
#define CR_CORE_TRACE(...) ::CopperCRMRenderer::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CR_CORE_INFO(...) ::CopperCRMRenderer::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CR_CORE_WARN(...) ::CopperCRMRenderer::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CR_CORE_ERROR(...) ::CopperCRMRenderer::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CR_CORE_CRITICAL(...) ::CopperCRMRenderer::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define CR_TRACE(...) ::CopperCRMRenderer::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CR_INFO(...) ::CopperCRMRenderer::Log::GetClientLogger()->info(__VA_ARGS__)
#define CR_WARN(...) ::CopperCRMRenderer::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CR_ERROR(...) ::CopperCRMRenderer::Log::GetClientLogger()->error(__VA_ARGS__)
#define CR_CRITICAL(...) ::CopperCRMRenderer::Log::GetClientLogger()->critical(__VA_ARGS__)