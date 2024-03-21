#ifndef _WINDOW_HPP_
#define _WINDOW_HPP_

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>

namespace mbe
{
    class Window
    {
    public:
        Window(int width, int height, const std::string &title);
        auto isOpen() -> bool;
        auto sync() -> void;
        auto isKeyPressed(int GLFW_KEY_NAME) -> bool;
        auto time() -> double;
    private:
        GLFWwindow *mGLFWwindow{nullptr};
    };
}
#endif // _WINDOW_HPP_