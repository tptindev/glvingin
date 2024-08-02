#include "GLWindowWrapper.h"
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
GLWindowWrapper::GLWindowWrapper()
{
    std::cout << __FUNCTION__ << std::endl;
}

GLWindowWrapper::~GLWindowWrapper()
{
    std::cout << __FUNCTION__ << std::endl;
}

bool GLWindowWrapper::CreateWindow(int width, int height, const char *title)
{
    this->m_window = glfwCreateWindow(640, 480, title, NULL, NULL);
    if (this->m_window == nullptr)
    {
        glfwTerminate();
        return false;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(this->m_window);
    return true;
}

void GLWindowWrapper::DestroyWindow()
{
    glfwDestroyWindow(this->m_window);
    glfwTerminate();
}

GLFWwindow *GLWindowWrapper::window() const
{
    return m_window;
}
