#include <GLFW/glfw3.h>
#include <string>
#include <stdexcept>

#include "Window.hpp"

mbe::Window::Window(int width, int height, const std::string &title)
{
    if (!glfwInit())
    {
        throw std::runtime_error("Failed Initializing glfw");
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    mGLFWwindow = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

    if (!mGLFWwindow)
    {
        throw std::runtime_error("Failed Creating glfw window");
    }

    glfwMakeContextCurrent(mGLFWwindow);
}

bool mbe::Window::isOpen()
{
    return !glfwWindowShouldClose(mGLFWwindow);
}

void mbe::Window::sync()
{
    glfwSwapBuffers(mGLFWwindow);
    glfwPollEvents();
}
