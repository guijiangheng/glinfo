#include <glinfo/glinfo.h>
#include <GLFW/glfw3.h>
#include <cstdio>

namespace glinfo {
    std::string getGlInfo() {
        if (!glfwInit())
            return "Error: glfw Init failed!";

        glfwDefaultWindowHints();
        glfwWindowHint(GLFW_VISIBLE, false);

        auto window = glfwCreateWindow(640, 480, "glinfo", NULL, NULL);
        if (!window) {
            glfwTerminate();
            return "Error: glfw create window failed!";
        }

        glfwHideWindow(window);
        glfwMakeContextCurrent(window);

        char glInfo[256];
        std::sprintf(
            glInfo,
            "OpenGL Version: %s\nOpenGL Vendor: %s\nOpenGL Renderer: %s\n",
            glGetString(GL_VERSION),
            glGetString(GL_VENDOR),
            glGetString(GL_RENDERER));

        glfwDestroyWindow(window);
        glfwTerminate();

        return glInfo;
    }

    std::string displayWindow() {
        if (!glfwInit())
            return "Error: glfw Init failed!";

        glfwDefaultWindowHints();

        auto window = glfwCreateWindow(640, 480, "glinfo", NULL, NULL);
        if (!window) {
            glfwTerminate();
            return "Error: glfw create window failed!";
        }

        glfwMakeContextCurrent(window);
        glClearColor(1.0, 0.0, 0.0, 1.0);

        while (!glfwWindowShouldClose(window)) {
            glClear(GL_COLOR_BUFFER_BIT);
            glfwSwapBuffers(window);
            glfwPollEvents();
        }

        glfwDestroyWindow(window);
        glfwTerminate();

        return "";
    }
}