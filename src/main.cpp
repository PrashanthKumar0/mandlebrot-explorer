#include "Window.hpp"
#include "Screen.hpp"

int main()
{
    constexpr int window_width{640};
    constexpr int window_height{640};
    mbe::Window window{window_width, window_height, "Mandlebrot Explorer."};
    mbe::Screen screen{};
    
    while (window.isOpen())
    {
        screen.render();
        window.sync();
    }
}