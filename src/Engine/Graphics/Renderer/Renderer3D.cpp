#include "Renderer3D.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GLWindowWrapper.h>
Renderer3D::Renderer3D()
{

}

bool Renderer3D::Initialize(IWindowWrapper* window)
{
    return false;
}

void Renderer3D::SetDrawColor()
{
    glClearColor(1,1,1,1);
}

void Renderer3D::Clear()
{
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer3D::Present()
{
    glfwSwapBuffers(this->m_winWrapper->window());
}

void Renderer3D::Destroy()
{

}
