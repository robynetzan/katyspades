

<img align="left" src="resources.override/png/splash_icon.png"> <b>ButterSpades</b>
---------------
**Windows**: [64bit](https://butter.penguins.win/download/) - [32bit](https://butter.penguins.win/download32/)


ButterSpades is a fork which aims to improve the overall UI and feel of [BetterSpades](https://github.com/xtreme8000/BetterSpades).

AND KatySpades is the same as that but when you kill someone it plays a ding sound :D

## What's different
- In-game settings/controls menu
- Better UI scaling (HUD/Main UI)
- Configurable UI background and color accents
- Chat colors and killfeed (OpenSpades compatible)
- Adaptive chat size
- HUD shadows
- Spectator Y-Clamp

## Building 

thank you utf in the aloha.pk server
```
compiled it successfully, here's the process i wrote down:
install msys2 and run MSYS2 MINGW64
install git with pacman -S git
run git clone https://github.com/utf-4096/butterspades.git
run pacman -S mingw-w64-x86_64-cmake mingw-w64-x86_64-make mingw-w64-x86_64-gcc mingw-w64-x86_64-enet mingw-w64-x86_64-glfw  mingw-w64-x86_64-glew mingw-w64-x86_64-openal mingw-w64-x86_64-libdeflate mingw-w64-x86_64-mesa
restart msys2
run: cd butterspades && mkdir build && cd build && cmake ..
compile with: ninja
run: wget https://raw.githubusercontent.com/mpreisler/mingw-bundledlls/master/mingw-bundledlls && chmod +x mingw-bundledlls
run ./mingw-bundledlls --copy BetterSpades/client.exe
client.exe and the required dlls should now be in C:\msys64\home\<your username>\butterspades\build\BetterSpades 
```


## Previews

| <img src="/docs/apoc.png" width="250px"><br />*Apocalypse on Babel* | <img src="/docs/babel.png" width="250px"><br />*Babel* | <img src="/docs/chat.png" width="250px"><br />*Chat* |
| :-: | :-: | :-: |
| <img src="/docs/playerlist.png" width="250px"><br />***Player list*** | <img src="/docs/custom_def.png" width="250px"><br />***Customizable UI*** | <img src="/docs/custom.png" width="250px"><br />***Background and color scheme*** |

## System requirements

| Type    | min. requirement                                     |
| ------- | ---------------------------------------------------- |
| OS      | Windows 98 or Linux                                  |
| CPU     | 1 GHz single core processor                          |
| GPU     | 64MB VRAM, Mobile Intel 945GM or equivalent          |
| RAM     | 256MB                                                |
| Display | 800x600px                                            |
| Others  | Keyboard and mouse<br />Dial up network connection   |


## Build requirements

This project uses the following libraries and files:

| Name         | License         | Usage                  | GitHub                                             |
| ------------ | --------------- | ---------------------- | :------------------------------------------------: |
| GLFW3        | *ZLib*          | OpenGL context         | [Link](https://github.com/glfw/glfw)               |
| OpenAL soft  | *LGPL-2.1*      | 3D sound environment   | [Link](https://github.com/kcat/openal-soft)        |
| inih         | *BSD-3.Clause*  | .INI file parser       | [Link](https://github.com/benhoyt/inih)            |
| stb_truetype | *Public domain* | TrueType font renderer | [Link](https://github.com/nothings/stb)            |
| dr_wav       | *Public domain* | wav support            | [Link](https://github.com/mackron/dr_libs/)        |
| http         | *Public domain* | http client library    | [Link](https://github.com/mattiasgustavsson/libs)  |
| LodePNG      | *MIT*           | png support            | [Link](https://github.com/lvandeve/lodepng)        |
| libdeflate   | *MIT*           | decompression of maps  | [Link](https://github.com/ebiggers/libdeflate)     |
| enet         | *MIT*           | networking library     | [Link](https://github.com/lsalzman/enet)           |
| parson       | *MIT*           | JSON parser            | [Link](https://github.com/kgabis/parson)           |
| log.c        | *MIT*           | logger                 | [Link](https://github.com/xtreme8000/log.c)        |
| GLEW         | *MIT*           | OpenGL extensions      | [Link](https://github.com/nigels-com/glew)         |
| hashtable    | *MIT*           | hashtable              | [Link](https://github.com/goldsborough/hashtable/) |
| libvxl       | *MIT*           | access VXL format      | [Link](https://github.com/xtreme8000/libvxl/)      |
| microui      | *MIT*           | user interface         | [Link](https://github.com/rxi/microui)             |

You will need to compile the following by yourself, or get hold of precompiled binaries:

* GLFW3
* GLEW
* OpenAL soft *(only needed on Windows)*
* libdeflate
* enet

Follow the instructions on their project page, then place produced static libraries in `deps/`.

All other requirements of the above list (like single file libs) will be downloaded by CMake automatically and **don't** need to be taken care of. Because state of copyright of 0.75 assets is unknown, CMake will also download additional assets from [*here*](http://aos.party/bsresources.zip) which are not part of this repository.

#### Windows

This project uses CMake to generate all Makefiles automatically. It's best to use MinGW-w64 for GCC on Windows. You can generate the required files by opening `cmd.exe` in the `build/` directory and typing:
```
cmake -G "MinGW Makefiles" ..
mingw32-make
```

If everything went well, the client should be in the `build/BetterSpades/` subfolder.

When starting `client.exe`, you will be greeted by a server list. Select a server on it to start playing!
You can also start the client the same way as you did with the voxlap version by opening cmd and putting an `aos://` link in as the first argument:

```
client.exe -aos://16777343:32887 //Connects to a local server
```

#### Linux

Compilation now works the same on Linux. Just change the build system to `Unix Makefiles` or leaving it as default will work too (`cmake ..`).

You can build each library yourself, or install them with your distro's package manager:
```
sudo apt install libgl1-mesa libgl1-mesa-dev libopenal1 libopenal-dev libglfw-dev libenet-dev libglew-dev
```
(this does not include [libdeflate](https://github.com/ebiggers/libdeflate) which is a requirement too, see [_Wiki/Building_](https://github.com/xtreme8000/BetterSpades/wiki/Building) for more details)

Start the client e.g. with the following inside the `build/bin/` directory:
```
./client
```
Or connect directly to localhost:
```
./client -aos://16777343:32887
```


#### macOS

The same instructions for Linux work on macOS aside from some minor differences. First, use Homebrew or MacPorts to grab dependencies:
```
brew install glfw enet
```
The development headers for OpenAL and OpenGL don't have to be installed since they come with macOS by default. [libdeflate](https://github.com/ebiggers/libdeflate) should be installed and placed manually in a way similar to Linux. See [_Wiki/Building_](https://github.com/xtreme8000/BetterSpades/wiki/Building) for more details.
