#!python
import os

# Gets the standard flags CC, CCX, etc.
env = SConscript("src/lib/godot-cpp/SConstruct")

if env["platform"] in ("linuxbsd", "linux"):
    divine_tools_library = "libmapgen.so"
    libexportfolder = "/linux/"

elif env["platform"] == "windows":
    divine_tools_library = "mapgen.dll"
    libexportfolder = "/windows/"

if env["target"] == "template_debug":
    debugsuffix = "_debug"
else:
    debugsuffix = ""

# make sure our binding library is properly includes
env.Append(LIBPATH=["src/lib/divine_tools/"])
env.Append(LIBS=["mapgen"])

# tweak this if you want to use different folders, or more folders, to store your source code in.
env.Append(CPPPATH=["src/"])
sources = Glob("src/*.cpp")

# The finished exports
library = env.SharedLibrary(
    target="project/addons/divine_tools/bin/"
    + libexportfolder
    + "divine_tools"
    + debugsuffix,
    source=sources,
)

Default(library)
