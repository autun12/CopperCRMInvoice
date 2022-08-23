# CopperCRMInvoice
A random tool that I will be working on when I feel like it. It will probably be more of a CRM, invoice tool with note taking. I have never made something like this so I do not know if it will even be that.

## How to build 
Clone the repository with `git clone --recursive https://github.com/autun12/CopperCRMInvoice`.

If the repository was cloned non-recursively previously, use `git submodule update --init` to clone the necessary submodules.

## Installing and setup

Start by cloning the repository with `git clone --recursive https://github.com/autun12/CopperCRMInvoice`.

If the repository was cloned non-recursively previously, use `git submodule update --init` to clone the necessary submodules.
CopperCRMInvoice uses _Premake 5_ as a build generation tool. Visit the [Premake website](https://premake.github.io/download.html) to download and install it.

Next: Follow the steps relevant to your operating system.

### Linux Platforms

- `libxcursor`
- `libxrandr`
- `libxinerama`
- `libxi`
- `zenity`

To compile CopperCRMInvoice:
```bash
premake5 gmake2
make
```

#### Arch

On Arch and Arch derivative distributions

`sudo pacman -S libxcursor libxrandr libxinerama libxi zenity`

#### Debian

On Debian and Debian derivative distributions

`sudo apt install libxcursor-dev libxrandr-dev libxinerama-dev libxi-dev libglu1-mesa-dev zenity`

### Windows

Currently does not support the Windows operating system.