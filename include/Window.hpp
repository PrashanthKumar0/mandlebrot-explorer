#ifndef _WINDOW_HPP_
#define _WINDOW_HPP_

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
        
    };
}
#endif // _WINDOW_HPP_