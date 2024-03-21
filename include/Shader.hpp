#ifndef _SHADER_HPP_
#define _SHADER_HPP_

#include <glad/glad.h>
#include <string>

namespace mbe
{
    class Shader
    {
    public:
        Shader(const std::string &shaderName);
        auto use() -> void;
        auto set(const std::string &pName, double x, double y) -> void;
        auto set(const std::string &pName, double val) -> void;

    private:
        GLuint mProgramID{};
        GLuint mVSID{};
        GLuint mFSID{};

        // TODO : make this static and make a setter for it
        std::string mBaseDir{"res/shaders/"};
    };
}

#endif // _SHADER_HPP_