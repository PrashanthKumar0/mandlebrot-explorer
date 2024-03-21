#include "Window.hpp"
#include "Screen.hpp"
#include "constants.hpp"

int main()
{

    mbe::Window window{mbe::constants::windowWidth, mbe::constants::windowHeight, "Mandlebrot Explorer."};
    mbe::Screen screen{};
    
    double then = window.time();

    while (window.isOpen())
    {
        double now = window.time();
        double dt = now - then;
        then = now;
        
        screen.handleInputs(window,dt);

        screen.render();
        
        window.sync();
    }
}