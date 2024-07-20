#ifndef ENGINEENUMS_H
#define ENGINEENUMS_H

class EngineEnums
{
public:
    enum EngineMode
    {
        MODE_2D,
        MODE_3D
    };

    enum EngineState
    {
        ENGINE_READY,
        ENGINE_RUNNING,
        ENGINE_PAUSED,
        ENGINE_STOPED
    };

    enum EngineSlot
    {
        ENGINE_WIN_TITLE_CHANGED
    };
};

#endif // ENGINEENUMS_H
