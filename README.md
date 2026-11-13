# qt-workspace

用于存放 Qt 项目和小实验的工作区。当前包含一个可运行的 Qt 6 Widgets 示例程序 `hello`：主窗口里有标签、可累计点击次数的按钮，以及带「关于」「退出」的菜单和状态栏。

## 目录结构

```
qt-workspace/
├── CMakeLists.txt          # 顶层工程：查找 Qt 6、注册子目录
├── README.md
├── .gitignore
└── apps/
    └── hello/              # 示例窗口程序
        ├── CMakeLists.txt
        ├── main.cpp
        ├── mainwindow.h
        └── mainwindow.cpp
```

后续新应用建议同样放在 `apps/<应用名>/` 下。

## 环境要求

- **Qt 6.5+**（至少需要 `Qt6::Widgets` 组件）
- **CMake 3.16+**
- 兼容的 C++ 编译器（Linux：g++ / clang++；Windows：MSVC 或 MinGW；macOS：Apple Clang / Xcode 命令行工具）

## 构建

在项目根目录执行。若 CMake 找不到 Qt，把 `-DCMAKE_PREFIX_PATH` 换成本机 Qt 的安装前缀（即包含 `lib/cmake/Qt6` 的那一层目录）。

### Linux

```bash
# 示例前缀，请按本机安装路径修改，例如：
#   /usr
#   /usr/lib/x86_64-linux-gnu/cmake 的上两级通常是 /usr
#   ~/Qt/6.8.0/gcc_64
cmake -B build -DCMAKE_PREFIX_PATH=/usr
cmake --build build
./build/apps/hello/hello
```

### Windows

在「x64 Native Tools Command Prompt for VS」或已配置好编译器的终端中：

```bat
REM 将前缀换成本机 Qt 路径，例如 C:\Qt\6.8.0\msvc2022_64
cmake -B build -DCMAKE_PREFIX_PATH=C:\Qt\6.8.0\msvc2022_64
cmake --build build --config Release
build\apps\hello\Release\hello.exe
```

### macOS

```bash
# 将前缀换成本机 Qt 路径，例如 ~/Qt/6.8.0/macos
cmake -B build -DCMAKE_PREFIX_PATH=$HOME/Qt/6.8.0/macos
cmake --build build
open ./build/apps/hello/hello.app
```

也可以直接运行包内可执行文件：

```bash
./build/apps/hello/hello.app/Contents/MacOS/hello
```

## 如何新增应用

1. 在 `apps/` 下新建目录，例如 `apps/myapp/`。
2. 放入源码（至少要有 `main.cpp`；窗口类可参照 `apps/hello`）。
3. 在该目录编写 `CMakeLists.txt`，用 `qt_add_executable` 声明目标并链接 `Qt6::Widgets`：

   ```cmake
   qt_add_executable(myapp
       main.cpp
       mainwindow.h
       mainwindow.cpp
   )

   target_link_libraries(myapp PRIVATE Qt6::Widgets)

   set_target_properties(myapp PROPERTIES
       WIN32_EXECUTABLE ON
       MACOSX_BUNDLE ON
   )
   ```

4. 在顶层 `CMakeLists.txt` 中追加一行：

   ```cmake
   add_subdirectory(apps/myapp)
   ```

5. 重新配置并编译：

   ```bash
   cmake -B build -DCMAKE_PREFIX_PATH=<你的 Qt 前缀>
   cmake --build build
   ```

如果新应用还需要其他 Qt 模块（例如 `Network`、`Svg`），在顶层 `find_package(Qt6 ...)` 里补上对应组件，并在该应用的 `target_link_libraries` 中链接 `Qt6::<模块>`。
