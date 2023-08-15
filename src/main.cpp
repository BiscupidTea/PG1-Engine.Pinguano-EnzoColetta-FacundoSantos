#include <GLFW/glfw3.h>
#include "Window.h"
#include "Renderer.h"

using namespace window;
using namespace renderer;

int initLibrary();
bool isLibraryInit();

int main(void)
{
    Window window;
    Renderer renderer;

    int width = 640;
    int height = 480;

    const char* windowName = "Pinguano-Engine";

    GLFWmonitor* monitor = NULL;
    GLFWwindow* share = NULL;

    /* Initialize the library*/
    initLibrary();

    /* Create a windowed mode window and its OpenGL context */
    window.initWindow(width, height, windowName, monitor, share);

    /* Loop until the user closes the window */
    while (!window.windowShouldClose(window.getWindow()))
    {
        /* Render here */
        renderer.clear();

        /* Swap front and back buffers */
        renderer.swapBuffers(window.getWindow());

        /* Poll for and process events */
        renderer.pollEvents();
    }

    window.closeWindow();

    return 0;
}

int initLibrary()
{
    if (!isLibraryInit())
    {
        return -1;
    }
}

bool isLibraryInit()
{
    return glfwInit();
}