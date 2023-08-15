#include <GLFW/glfw3.h>
#include "Window.h"

using namespace window;

int main(void)
{
    Window window;

    int width = 640;
    int height = 480;

    const char* windowName = "Pinguano-Engine";

    GLFWmonitor* monitor = NULL;
    GLFWwindow* share = NULL;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window.initWindow(width, height, windowName, monitor, share);

    /* Loop until the user closes the window */
    while (!window.windowShouldClose(window.getWindow()))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window.getWindow());

        /* Poll for and process events */
        glfwPollEvents();
    }

    window.closeWindow();

    return 0;
}