import os
import sys

os.system("pip install scons")

if sys.platform.startswith("linux"):
    os.system(
        "pip install pyston_lite_autoload"
    )  # makes scons faster but only works on linux

os.system("git submodule update --init")
