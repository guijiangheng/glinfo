# glinfo 

glinfo是gflw的c++ nodejs addon。

# build

项目依赖glfw，首先需要编译glfw。编译的话需要安装编译工具:

> Windows下面需要安装CMake，Visual Studio\
> Mac下需要安装CMake，XCode\
> Linux下面需要安装gcc，CMake

把编译得到的glfw静态库根据系统和架构放到libs对应的目录下。

编译完glfw后，输入以下命令编译glinfo.node扩展：
```bash
# 或者node-gyp rebuild
node-gyp configure
node-gyp build
```
同样的，不同的操作系统需要安装相应的编译工具。

# example

进入example目录，输入以下命令：
```bash
npm ci
node ./info.js
```
因为依赖的包模块目录下有binding.gyp文件，npm install的时候会自动触发编译。

## 参考链接

1. [https://medium.com/jspoint/a-simple-guide-to-load-c-c-code-into-node-js-javascript-applications-3fcccf54fd32](https://medium.com/jspoint/a-simple-guide-to-load-c-c-code-into-node-js-javascript-applications-3fcccf54fd32)
2. [https://nodeaddons.com/cross-platform-addons-with-node-pre-gyp/](https://nodeaddons.com/cross-platform-addons-with-node-pre-gyp/)