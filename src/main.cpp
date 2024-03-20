#include "Window.hpp"

int main()
{
    constexpr int window_width{640};
    constexpr int window_height{640};
    mbe::Window window{window_width, window_height, "Mandlebrot Explorer."};

    glClearColor(0.1f, 0.2f, 0.2f, 1.0f);
    while (window.isOpen())
    {
        glClear(GL_COLOR_BUFFER_BIT);
        window.sync();
    }
}