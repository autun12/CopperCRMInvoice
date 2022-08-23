include "Dependencies.lua"

workspace "CopperCRMInvoice"
	architecture "x86_64"
	startproject "CopperCRMApplication"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Dependencies"
	include "vendor/premake"
	include "CopperCRMRenderer/vendor/GLFW"
	include "CopperCRMRenderer/vendor/Glad"
	include "CopperCRMRenderer/vendor/imgui"
group ""

include "CopperCRMRenderer"
include "CopperCRMApplication"