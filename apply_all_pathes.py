import os


PATHES_DIR = "patches"

ALL_PATCHES_NAMES = [
    "install-layout.patch",
    "relocatable-wx-config.patch",
    "nanosvg-ext-depend.patch",
    "fix-libs-export.patch",
    "fix-pcre2.patch",
    "gtk3-link-libraries.patch",
    "sdl2.patch",
    "add-locale-install.patch",
    "hotfix-aui-minimize.patch"
]


for  path in ALL_PATCHES_NAMES:
    # Run git apply
    print("Applying {}".format(path))
    success=  os.system("git apply {}/{}".format(PATHES_DIR, path))

    if success != 0:
        print("Failed to apply {}".format(path))
        break
