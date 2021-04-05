workspace "Frost"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

includeDir = {}
includeDir["GLFW"] = "Frost/vendor/GLFW/include"

include "Frost/vendor/GLFW"

project "Frost"
    location "Frost"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "pch.h"
    pchsource "Frost/src/pch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{includeDir.GLFW}"
    }

    links
    {
        "GLFW",
        "opengl32.lib",
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "FS_PLATFORM_WINDOWS",
            "FS_BUILD_DLL"
        }

        postbuildcommands 
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }
    
        filter "configurations:Debug"
            defines "FS_DEBUG"
            symbols "On"
        
        filter "configurations:Release"
            defines "FS_RELEASE"
            optimize "On"

        filter "configurations:Dist"
            defines "FS_DIST"
            optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs
    {
        "Frost/vendor/spdlog/include",
        "Frost/src"
    }

    links
    {
        "Frost"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "FS_PLATFORM_WINDOWS",
        }

        filter "configurations:Debug"
            defines "FS_DEBUG"
            symbols "On"
        
        filter "configurations:Release"
            defines "FS_RELEASE"
            optimize "On"

        filter "configurations:Dist"
            defines "FS_DIST"
            optimize "On"
    