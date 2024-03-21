#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <stdexcept>

#include "Window.hpp"

mbe::Window::Window(int width, int height, const std::string &title)
{
    if (glfwInit() != GLFW_TRUE)
    {
        throw std::runtime_error("Failed Initializing glfw");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    mGLFWwindow = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

    if (!mGLFWwindow)
    {
        throw std::runtime_error("Failed Creating glfw window");
    }

    glfwMakeContextCurrent(mGLFWwindow);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        throw std::runtime_error("Glad failed finding opengl instance (opengl32.dll)");
    }

    glViewport(0, 0, width, height);
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

bool mbe::Window::isKeyPressed(int GLFW_KEY_NAME)
{
    return glfwGetKey(mGLFWwindow, GLFW_KEY_NAME) == GLFW_PRESS;
}