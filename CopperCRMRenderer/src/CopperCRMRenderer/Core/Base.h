#pragma once

#include <memory>

#include "CopperCRMRenderer/Core/PlatformDetection.h"

// Debug settings
#ifdef CR_DEBUG
#if defined(CR_PLATFORM_WINDOWS)
#define CR_DEBUGBREAK() __debugbreak()
#elif defined(CR_PLATFORM_LINUX)
#include <signal.h>
#define CR_DEBUGBREAK() raise(SIGTRAP)
#else
#endif
#define CR_ENABLE_ASSERTS
#else
#define CR_DEBUGBREAK()
#endif

#define CR_EXPAND_MACRO(x) x
#define CR_STRINGIFY_MACRO(x) #x

#define BIT(x) (1 << x)

#define CR_BIND_EVENT_FN(fn)                                    \
    [this](auto&&... args) -> decltype(auto) {                  \
        return this->fn(std::forward<decltype(args)>(args)...); \
    }

namespace CopperCRMRenderer {

template <typename T>
using Scope = std::unique_ptr<T>;
template <typename T, typename... Args>
constexpr Scope<T> CreateScope(Args&&... args) {
    return std::make_unique<T>(std::forward<Args>(args)...);
}

template <typename T>
using Ref = std::shared_ptr<T>;
template <typename T, typename... Args>
constexpr Ref<T> CreateRef(Args&&... args) {
    return std::make_shared<T>(std::forward<Args>(args)...);
}

}  // namespace CopperCRMRenderer

#include "CopperCRMRenderer/Core/Assert.h"
#include "CopperCRMRenderer/Core/Log.h"