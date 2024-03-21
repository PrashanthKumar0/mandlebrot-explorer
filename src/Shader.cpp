#include <glad/glad.h>
#include <string>
#include <fstream>
#include <stdexcept>

#include "Shader.hpp"

//--[ Some private helper functions ]----------------------------
GLuint compileShader(const std::string &code, GLenum shaderType);
GLuint linkShaders(GLuint shader1, GLuint shader2);
// ---------------------------------------------------------------

mbe::Shader::Shader(const std::string &shaderName)
{
    const std::string vsFileName{mBaseDir + shaderName + ".vs"};
    const std::string fsFileName{mBaseDir + shaderName + ".fs"};

    std::fstream vsFile{vsFileName};
    if (!vsFile.is_open())
    {
        throw std::runtime_error("vertex shader file (" + vsFileName + ") not found");
    }

    std::fstream fsFile{fsFileName};
    if (!fsFile.is_open())
    {
        throw std::runtime_error("fragment shader file (" + fsFileName + ") not found");
    }

    std::string vsCode{};
    std::string fsCode{};
    std::string line{};

    while (std::getline(vsFile, line))
        vsCode += line + "\n";

    while (std::getline(fsFile, line))
        fsCode += line + "\n";

    mVSID = compileShader(vsCode, GL_VERTEX_SHADER);
    mVSID = compileShader(fsCode, GL_FRAGMENT_SHADER);
    mProgramID = linkShaders(mVSID, mFSID);
}

void mbe::Shader::use()
{
    glUseProgram(mProgramID);
}

void mbe::Shader::set(const std::string &pName, double x, double y)
{
    GLint location{glGetUniformLocation(mProgramID, pName.c_str())};
    glUniform2f(location, x, y);
}
void mbe::Shader::set(const std::string &pName, double val)
{
    GLint location{glGetUniformLocation(mProgramID, pName.c_str())};
    glUniform1f(location, val);
}

// private helper methods

GLuint compileShader(const std::string &code, GLenum shaderType)
{
    const GLchar *code_cstr{code.c_str()};
    GLuint shaderID{glCreateShader(shaderType)};
    glShaderSource(shaderID, 1, &code_cstr, nullptr);
    glCompileShader(shaderID);

    GLint success{};
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        char infoLog[512]{};
        glGetShaderInfoLog(shaderID, 512, nullptr, infoLog);
        switch (shaderType)
        {
        case GL_VERTEX_SHADER:
            throw std::runtime_error(std::string("Failed compiling vertex shader \n" + std::string(infoLog)));

        case GL_FRAGMENT_SHADER:
            throw std::runtime_error(std::string("Failed compiling fragment shader \n" + std::string(infoLog)));

        default:
            throw std::runtime_error(std::string("Failed compiling shader \n" + std::string(infoLog)));
        }
    }

    return shaderID;
}

GLuint linkShaders(GLuint shader1, GLuint shader2)
{
    GLuint programID{glCreateProgram()};

    glAttachShader(programID, shader1);
    glAttachShader(programID, shader2);
    glLinkProgram(programID);

    GLint success{};
    glGetProgramiv(programID, GL_LINK_STATUS, &success);

    if (!success)
    {
        char infoLog[512];
        glGetProgramInfoLog(programID, 512, nullptr, infoLog);

        throw std::runtime_error(std::string("Failed Linking Shaders \n") + std::string(infoLog));
    }

    return programID;
}