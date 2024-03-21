#ifndef _SCREEN_HPP_
#define _SCREEN_HPP_

#include <glad/glad.h>
#include <array>

#include "Shader.hpp"
#include "Window.hpp"

namespace mbe
{
    class Screen
    {
    public:
        Screen();
        auto render() -> void;
        auto handleInputs(Window& window) -> void;

    private:
    private:
        GLuint mVAO{};
        GLuint mVBO{};
        GLuint mEBO{};

        float mZoom{1.0f};
        std::array<float, 2> mTranslate{0.0f, 0.0f};

        Shader mShader{"Mandlebrot"};
    };
}

#endif // _SCREEN_HPP_