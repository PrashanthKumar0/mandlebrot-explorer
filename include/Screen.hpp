#ifndef _SCREEN_HPP_
#define _SCREEN_HPP_

#include <glad/glad.h>
#include "Shader.hpp"

namespace mbe
{
    class Screen
    {
    public:
        Screen();
        auto render() -> void;

    private:
    private:
        GLuint mVAO{};
        GLuint mVBO{};
        GLuint mEBO{};
        
        Shader mShader{"Mandlebrot"};
    };
}

#endif // _SCREEN_HPP_