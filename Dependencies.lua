-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "%{wks.location}/CopperCRMRenderer/vendor/GLFW/include"
IncludeDir["Glad"] = "%{wks.location}/CopperCRMRenderer/vendor/Glad/include"
IncludeDir["ImGui"] = "%{wks.location}/CopperCRMRenderer/vendor/imgui"
IncludeDir["glm"] = "%{wks.location}/CopperCRMRenderer/vendor/glm"

filter "system:windows"
	VULKAN_SDK = os.getenv("VULKAN_SDK")

	IncludeDir["VulkanSDK"] = "%{VULKAN_SDK}/Include"

	LibraryDir = {}

	LibraryDir["VulkanSDK"] = "%{VULKAN_SDK}/Lib"
	LibraryDir["VulkanSDK_Debug"] = "%{wks.location}/Hazel/vendor/VulkanSDK/Lib"
	LibraryDir["VulkanSDK_DebugDLL"] = "%{wks.location}/Hazel/vendor/VulkanSDK/Bin"

	Library = {}
	Library["Vulkan"] = "%{LibraryDir.VulkanSDK}/vulkan-1.lib"
	Library["VulkanUtils"] = "%{LibraryDir.VulkanSDK}/VkLayer_utils.lib"

filter {}