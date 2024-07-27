#include "Engine/Engine.h"

int main(void)
{
    if (Engine::Instance()->Initialize("ViNgin[%s]", EngineEnums::MODE_2D))
    {
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

