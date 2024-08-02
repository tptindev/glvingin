#include "GLWindowWrapper.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
GLWindowWrapper::GLWindowWrapper()
{

}

bool GLWindowWrapper::CreateWindow(int width, int height, const char *title)
{
    return false;
}

void GLWindowWrapper::DestroyWindow()
{

}

GLFWwindow *GLWindowWrapper::window() const
{
    return m_window;
}
