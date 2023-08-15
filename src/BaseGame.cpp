#include "BaseGame.h"

namespace baseEngine
{
    int BaseGame::initEngine()
    {
        int width = 640;
        int height = 480;

        const char* windowName = "Pinguano-Engine";

        GLFWmonitor* monitor = NULL;
        GLFWwindow* share = NULL;

        if (!glfwInit())
        {
            return -1;
        }

        window.initWindow(width, height, windowName, monitor, share);
    }

    void BaseGame::updateEngine()
    {
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
    }

    void BaseGame::closeEngine()
    {
        window.closeWindow();
    }
}