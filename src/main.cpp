#include <Engine3D.h>
#include <Engine2D.h>
#include "Script/Script.h"
int main(void)
{
    if (Engine2D::Instance()->Initialize("ViNgin[%s]"))
    {
        Script::Instance()->Initialize();
        Engine2D::Instance()->Loop();
        Engine2D::Instance()->Quit();
        Engine2D::ResetInstance();
    }
    else
    {
        return -1;
    }
    return 0;
}

