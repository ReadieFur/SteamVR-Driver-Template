# SteamVR Driver Template
A Visual Studio template for creating SteamVR drivers.

## Setup
- Recursively clone this repository
- Edit `Rename.ps1` and change the `replace` variable to the name of your project
- Run the `Rename.ps1` script
- Open the visual studio project and change the launch target to `<STEAM_INSTALL_DIR>/steamapps/common/SteamVR/bin/win64/vrstartup.exe`

## Driver usage
To get the driver to be recognized by SteamVR, you can use one of three methods:
- Copy the driver folder to `<STEAM_INSTALL_DIR>/steamapps/common/SteamVR/drivers/`
- Create a symbolic link from `<OUTPUT_DIR>/<PROJECT_NAME>` to `<STEAM_INSTALL_DIR>/steamapps/common/SteamVR/drivers/<PROJECT_NAME>`
- Add the driver folder to the `openvrpaths.vrpath` file located in the `<APPDATA_LOCAL>/openvr` folder
