#include <iostream>
#include <string>
#include <GLFW/glfw3.h>

class HelloTriangle {
public:
    int width;
    int height;
    GLFWwindow* window;

    HelloTriangle(GLFWwindow* window, int width, int height) {
        this->window = window;
    }

    void run() {
        mainLoop();
    }

    void init() {

    }

    void mainLoop() {
        while (!glfwWindowShouldClose(window)) {
            glfwPollEvents();
        }
    }
};

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    GLFWwindow* window = glfwCreateWindow(800, 600, "Hello Triangle", nullptr, nullptr);

    HelloTriangle app(window, 800, 600);
    app.run();

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}