#include "Window.hpp"

int main()
{
    constexpr int window_width{640};
    constexpr int window_height{640};
    mbe::Window window{window_width, window_height, "Mandlebrot Explorer."};

    while (window.isOpen())
    {
        // ok
        window.sync();
    }
}