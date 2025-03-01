#include <glew.h>
#include <glfw3.h>
#include <iostream>

void error_callback(int error, const char* description) {
    std::cerr << "Error: " << description << std::endl;
}

void drawSquare(float x, float y, float size) {
    glBegin(GL_TRIANGLE_STRIP);

    glColor3f(1.0f, 0.0f, 1.0f); // Розовый цвет
    glVertex2f(x, y);
    glVertex2f(x + size, y);
    glVertex2f(x, y + size);
    glVertex2f(x + size, y + size);

    glEnd();
}

int main() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    glfwSetErrorCallback(error_callback);

    GLFWwindow* window = glfwCreateWindow(640, 480, "Pink Square", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        return -1;
    }

    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        drawSquare(-0.25f, -0.25f, 0.5f); // Квадрат по центру

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
