project "CopperCRMApplication"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"%{wks.location}/CopperCRMRenderer/vendor/spdlog/include",
		"%{wks.location}/CopperCRMRenderer/src",
		"%{wks.location}/CopperCRMRenderer/vendor",
		"{IncludeDir.glm}"
	}

	links
	{
		"CopperCRMRenderer"
	}

	filter "system:linux"
		links
		{
			"GLFW",
			"Glad",
			"ImGui",
			"Xrandr",
			"Xxf86vm",
			"Xinerama",
			"Xcursor",
			"Xi",
			"GLU",
			"GL",
			"X11",
			"dl",
			"pthread",
			"stdc++fs",	--GCC versions 5.3 through 8.x need stdc++fs for std::filesystem

			"vulkan"
		}

	filter "system:windows"
		systemversion "latest"
	
		defines
		{
		}

    filter "configurations:Debug"
		defines "CR_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "CR_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "CR_DIST"
		optimize "on"
		runtime "Release"