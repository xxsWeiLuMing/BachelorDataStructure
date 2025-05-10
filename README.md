# DataStructureOnGit

## 一.运行

    ~~1.用Visual Studio打开DataStructureOnGit.sln即可运行。~~

    ~~2.不建议用VsCode运行。因为本项目使用了Visual Studio的筛选器功能。~~

### 1.运行说明

    (1)C语言的特点是可移植性强，而Visual Studio用sln破坏了这一优点，所有我把项目完全修改为CMake项目。

    (2)如果没有CMake，参看[Download CMake](https://cmake.org/download/)。建议下载.msi文件，因为可以自动添加环境变量。建议下载最新版。

    (3)我没有测试过在Windows以外的操作系统上实施项目。

### 2.在IDE或编辑器中运行

(1)在VS Code中运行，建议在BachelorDataStructure/cmake/build中打开控制台，输入make编译；
```cmd
......\BachelorDataStructure> mkdir build
......\BachelorDataStructure> cd build
......\BachelorDataStructure\build> cmake ..
......\BachelorDataStructure\build> make
```
这样会在Output里生成exe，修改CMakeList.txt可以修改exe生成的位置。

如果要使用vs code编译，需要配置tasks.json：

```json
 "args":[
    "-fdiagnostics-color=always",
    "-g",
    "${file}",
    "-I","${fileDirname}\\Source",
    "-o",
    "${fileDirname}\\Output\\${fileBasenameNoExtension}.exe"
    ],
```

## 二.目录介绍

    1.Data Structure中，是各种数据结构的结构定义和其基本操作。Test中是对基本操作的测试。

    2.Experiment中，是我的老师布置的实验所需的代码。在实验2之后，没有布置实验3却就布置了实验4.

    3.Practice中，是我的编程练习代码。

    4.Document中，是对相关代码的介绍、测试用的输入和正确的输出。
