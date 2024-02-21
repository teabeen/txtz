workspace "TextStatz"
    configurations { "Debug", "Release" }
    language "C"
    architecture "x86_64"

    location "build"

    filter "configurations:Debug"
        symbols "On"
        optimize "Off"

    filter "configurations:Release"
        optimize "Full"

project "txtz"
    kind "ConsoleApp"
    targetdir "bin/%{cfg.buildcfg}"

    files { "src/**.c" }

    filter "system:windows"
        defines { "WINDOWS" }

    filter "system:linux"
        defines { "LINUX" }

    filter {}

