# Numbers To Words
20465 System Programming Laboratory - Assignment 23 (Grade 100)


### Overview
- For detailed description, see [Assignment 23](doc/assignment_23.pdf)


### Requirements
C Standard
- ANSI C(89/90)

Linux
- Ubuntu >= 16.04
- Install gcc and make
```
sudo apt update
sudo apt install build-essential
```

Windows
- Windows 10/11
- MSVC 2022


### Build Instructions
Linux
```
make clean
make
```

Windows
```
# Activate the Visual Studio build environment for x64 architecture.
call "C:\Program Files\Microsoft Visual Studio\2022\Enterprise\VC\Auxiliary\Build\vcvarsall.bat" x64

# Compile all C sources into numbers.exe
cl /nologo /W4 /EHsc /std:c89 numbers.c utils.c
```


### Usage
- Use command line:

Linux
```
./numbers
./numbers < test/rw_input.txt
```

Windows
```
numbers.exe
numbers.exe < test/rw_input.txt
```