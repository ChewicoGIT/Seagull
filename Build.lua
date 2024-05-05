workspace "SeagullCore"
   architecture "x64"
   configurations { "Debug", "Release"}
   startproject "Sandbox"

   -- Workspace-wide build options for MSVC
   filter "system:windows"
      buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus" }

OutputDir = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"

group "Sandbox"
	include "Sandbox/Sandbox.lua"
group ""

include "SeagullCore/SeagullCore.lua"
include "VoxelStream/VoxelStream/VoxelStream.lua"