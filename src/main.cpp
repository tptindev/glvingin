#include <Engine3D.h>
#include <Engine2D.h>
#include "Script/Script.h"
#define MODE2D 1
int main(void)
{
#if MODE2D
    if (Engine2D::Instance()->Initialize("ViNgin[2D][%s]"))
    {
        Script::Instance()->Initialize();
        Engine2D::Instance()->Loop();
        Engine2D::Instance()->Quit();
        Engine2D::ResetInstance();
    }
#else
    if (Engine3D::Instance()->Initialize("ViNgin[3D][%s]"))
    {
        Script::Instance()->Initialize();
        Engine3D::Instance()->Loop();
        Engine3D::Instance()->Quit();
        Engine3D::ResetInstance();
    }
#endif
    else
    {
        return -1;
    }
    return 0;
}

