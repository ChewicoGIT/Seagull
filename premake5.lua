
workspace " Seagull"  
    configurations { "Debug", "Release" } 

project "Seagull"  
    kind "ConsoleApp"   
    location "Seagull"
    language "C++"   
    targetdir "bin/%{cfg.buildcfg}" 
    objdir "bin-int/%{cfg.buildcfg}"

    files { "Seagull/**.h", "Seagull/**.cpp" } 

    links {"glfw3.lib",
        "opengl32.lib",
        "user32.lib", 
        "gdi32.lib", 
        "shell32.lib"}

    libdirs {"vendor/glwf/lib-vc2022"} 


    includedirs {"vendor/glwf/include",
        "src",
        "vendor/glwf/include"}

    filter "configurations:Debug"
        defines { "DEBUG" }  
        symbols "On" 

    filter "configurations:Release"  
        defines { "NDEBUG" }    
        optimize "On" 
