
workspace " Seagull"  
    configurations { "Debug", "Release" } 

project "Seagull"  
    kind "StaticLib"   
    location "Seagull"
    language "C++"   
    targetdir "bin/Seagull/%{cfg.buildcfg}" 
    objdir "bin-int/Seagull/%{cfg.buildcfg}"

    files { "Seagull/**.h", "Seagull/**.cpp" } 

    links {"glfw3.lib",
        "opengl32.lib",
        "user32.lib", 
        "gdi32.lib", 
        "shell32.lib"}

    libdirs {"vendor/glwf/lib-vc2022"} 


    includedirs {"vendor/glwf/include",
        "src",
        "vendor/glwf/include",
        "Seagull"}

    filter "configurations:Debug"
        defines { "DEBUG" }  
        symbols "On" 

    filter "configurations:Release"  
        defines { "NDEBUG" }    
        optimize "On" 

        
project "SandBox"  
    kind "ConsoleApp"   
    location "SandBox"
    language "C++"   

    targetdir "bin/SandBox/%{cfg.buildcfg}" 
    objdir "bin-int/SandBox/%{cfg.buildcfg}"

    files { "SandBox/**.h", "SandBox/**.cpp" } 

    links { "Seagull",
            "SandBox"}
    
    includedirs {
        "src",
        "Seagull"}

    filter "configurations:Debug"
        defines { "DEBUG" }  
        symbols "On" 

    filter "configurations:Release"  
        defines { "NDEBUG" }    
        optimize "On" 
