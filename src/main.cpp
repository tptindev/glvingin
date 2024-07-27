#include <Engine.h>
#include "Script/Script.h"
int main(void)
{
    if (Engine::Instance()->Initialize("ViNgin[%s]", EngineEnums::MODE_2D))
    {
        Script::Instance()->Initialize();
        Engine::Instance()->Loop();
        Engine::Instance()->Quit();
        Engine::ResetInstance();
    }
    else
    {
        return -1;
    }
    return 0;
}

