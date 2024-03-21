#include <glad/glad.h>
#include <vector>

#include "Screen.hpp"
#include "constants.hpp"
#include "Window.hpp"

mbe::Screen::Screen()
{
    std::vector<GLfloat> vertices{
        -1.0f, +1.0f, // top left
        +1.0f, +1.0f, // top right
        +1.0f, -1.0f, // bottom right
        -1.0f, -1.0f, // bottom left
    };

    std::vector<GLuint> indices{
        0, 1, 3, // top-left right triangular
        3, 1, 2, // bottom-right right triangular
    };

    glGenVertexArrays(1, &mVAO);
    glGenBuffers(1, &mVBO);
    glGenBuffers(1, &mEBO);

    glBindVertexArray(mVAO);
    glBindBuffer(GL_ARRAY_BUFFER, mVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * vertices.size(), &vertices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mEBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * indices.size(), &indices[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), ((void *)(0)));

    glBindVertexArray(0);
}

void mbe::Screen::render()
{
    mShader.use();

    mShader.set("uTranslate", mTranslate[0], mTranslate[1]);
    mShader.set("uZoom", mZoom);

    mShader.set("uScreenRes", mbe::constants::windowWidth, mbe::constants::windowHeight);
    glBindVertexArray(mVAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
}


float lerp(float x0, float x1, float t)
{
    return x0 + (x1 - x0) * t;
}

// Just for debugging
// TODO : remove this
#include <iostream>

void mbe::Screen::handleInputs(Window &window)
{

    const float translateFac{mZoom * 0.1f};
    const float lerpFactor{0.01};
    const float zoomFactor{0.2f};

    // TODO : remove these
    system("cls"); 
    std::cout << "mZoom        : " << mZoom << '\n';
    std::cout << "Translate    : " << mTranslate[0] << "," << mTranslate[1] << '\n';

    if (window.isKeyPressed(GLFW_KEY_Z))
    {
        mZoom = lerp(mZoom, mZoom * zoomFactor, lerpFactor);
    }
    if (window.isKeyPressed(GLFW_KEY_X))
    {
        mZoom = lerp(mZoom, mZoom / zoomFactor, lerpFactor);
    }

    if (window.isKeyPressed(GLFW_KEY_LEFT))
    {
        mTranslate[0] += translateFac;
    }
    if (window.isKeyPressed(GLFW_KEY_RIGHT))
    {
        mTranslate[0] -= translateFac;
    }

    if (window.isKeyPressed(GLFW_KEY_UP))
    {
        mTranslate[1] -= translateFac;
    }
    if (window.isKeyPressed(GLFW_KEY_DOWN))
    {
        mTranslate[1] += translateFac;
    }

    if (window.isKeyPressed(GLFW_KEY_R))
    {
        mZoom = 1.0f;
        mTranslate[0] = 0.0f;
        mTranslate[1] = 0.0f;
    }
}