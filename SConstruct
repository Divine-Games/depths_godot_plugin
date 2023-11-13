#!python
import os
import sys
import shutil

# Asks if the addon should be exported directly
def export(target, source, env):
    yes = {'yes', 'y', 'ye', ''}
    no = {'no', 'n'}

    if len(sys.argv) > 1:
        choice = sys.argv[1].removeprefix("-")
    else:
        sys.stdout.write("Do you want to directly export the addon to a zip file after building? ([y]es/[n]o): ")
        choice = input().lower()

    if choice in yes:
        version = input("Enter the release version: ")
        with open("project/addons/divine_tools/plugin.cfg", "r") as cfg_file:
            lines = cfg_file.readlines()

        with open("project/addons/divine_tools/plugin.cfg", "w") as cfg_file:
            for line in lines:
                if line.startswith("version="):
                    cfg_file.write(f'version="{version}"\n')
                else:
                    cfg_file.write(line)

        if os.path.exists("release/divine_tools/addons"):
            shutil.rmtree("release/divine_tools/addons", ignore_errors=True)

        copy_tree("project/addons/", "release/temp/addons")
        shutil.make_archive("release/divine_tools", "zip", "release/temp/")
        shutil.rmtree("release/temp/")


env = SConscript("src/lib/godot-cpp/SConstruct")

if env["platform"] in ("linuxbsd", "linux"):
    divine_tools_library = ""
    libexportfolder = "/linux/"

elif env["platform"] == "windows":
    divine_tools_library = ""
    libexportfolder = "/windows/"

elif env["platform"] == "macos":
    divine_tools_library = ""
    libexportfolder = "/macos/"

if env["target"] == "template_debug":
    debugsuffix = "_debug"
else:
    debugsuffix = ""

env.Append(LIBPATH=["src/lib/divine_tools/"])
env.Append(LIBS=["mapgen"])

env.Append(CPPPATH=["src/"])
sources = Glob("src/*.cpp")

library = env.SharedLibrary(
    target="project/addons/divine_tools/bin/"
    + libexportfolder
    + "divine_tools"
    + debugsuffix,
    source=sources,
)

Default(library)

