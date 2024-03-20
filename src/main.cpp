#include "Window.hpp"

int main()
{
    constexpr int window_width{};
    constexpr int window_height{};
    mbe::Window window{window_width, window_height, "Mandlebrot Explorer."};

    while (window.isOpen())
    {
        // ok
        window.sync();
    }
}