#include "Renderer3D.h"
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GLWindowWrapper.h>
Renderer3D *Renderer3D::s_instance = nullptr;
Renderer3D::Renderer3D()
{
    std::cout << __FUNCTION__ << std::endl;
}

Renderer3D *Renderer3D::Instance()
{
    if (Renderer3D::s_instance == nullptr)
    {
        Renderer3D::s_instance = new Renderer3D();
    }
    return Renderer3D::s_instance;
}

void Renderer3D::ResetInstance()
{
    if (Renderer3D::s_instance != nullptr)
    {
        delete Renderer3D::s_instance;
        Renderer3D::s_instance = nullptr;
    }
    return;
}

Renderer3D::~Renderer3D()
{
    std::cout << __FUNCTION__ << std::endl;
}

bool Renderer3D::Initialize(IWindowWrapper* window)
{
    this->m_winWrapper = static_cast<GLWindowWrapper*>(window);
    return (window != nullptr);
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
    /* Swap front and back buffers */
    glfwSwapBuffers(this->m_winWrapper->window());
}

void Renderer3D::Destroy()
{

}
