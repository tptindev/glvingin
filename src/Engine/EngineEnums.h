#ifndef ENGINEENUMS_H
#define ENGINEENUMS_H

class EngineEnums
{
public:
    enum EngineMode
    {
        EngineMode_Min,
        MODE_2D,
        MODE_3D,
        EngineMode_Max
    };

    enum EngineState
    {
        EngineState_Min = EngineMode_Max,
        ENGINE_READY,
        ENGINE_RUNNING,
        ENGINE_PAUSED,
        ENGINE_STOPED,
        EngineState_max
    };

    enum EngineNotify
    {
        EngineNotify_Min = EngineState_max,
        ENGINE_WIN_TITLE_CHANGED,
        EngineNotify_Max
    };
};

#endif // ENGINEENUMS_H
