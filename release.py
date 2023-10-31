import os
from distutils.dir_util import copy_tree
import shutil

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

copy_tree("project/addons/", "release/temp/divine_tools/addons")

shutil.make_archive("release/divine_tools", "zip", "release/temp/")

shutil.rmtree("release/temp/")
