#include "Window.hpp"
#include "Screen.hpp"
#include "constants.hpp"

int main()
{

    mbe::Window window{mbe::constants::windowWidth, mbe::constants::windowHeight, "Mandlebrot Explorer."};
    mbe::Screen screen{};
    
    while (window.isOpen())
    {
        screen.render();
        
        screen.handleInputs(window);
        window.sync();
    }
}