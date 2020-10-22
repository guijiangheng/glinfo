# glinfo 

glinfo是gflw的c++ nodejs addon。

# build

项目依赖glfw，首先需要编译glfw。编译的话需要安装编译工具，Windows下面需要安装CMake，Visual Studio，Mac下需要安装CMake，XCode，Linux下面需要安装gcc，CMake。把编译得到的glfw静态库放到对应的目录下。

编译完glfw后需，输入命令
```bash
node-gyp configure
node-gyp build
# 或者node-gyp rebuild
```
进行编译。同样的，不同的操作系统需要安装编译工具。

# example

进入example目录，输入
```bash
npm ci
node ./info.js
```
即可。因为依赖包含了binding.gyp，node会自动触发编译，如果之前没有编译过，需要安装编译工具进行编译。

# 参考链接
