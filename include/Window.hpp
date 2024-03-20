#ifndef _WINDOW_HPP_
#define _WINDOW_HPP_

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

    private:
        GLFWwindow *mGLFWwindow{nullptr};
    };
}
#endif // _WINDOW_HPP_