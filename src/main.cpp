#include "Engine/Engine.h"

int main(void)
{
    if (Engine::instance()->Initialize())
    {
        Engine::instance()->Loop();
        Engine::instance()->Quit();
    }
    else
    {
        return -1;
    }
    return 0;
}

