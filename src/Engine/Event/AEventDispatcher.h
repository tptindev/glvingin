#ifndef AEVENTDISPATCHER_H
#define AEVENTDISPATCHER_H

#include <vector>

class IEventListener;
class AEventDispatcher
{
public:
    virtual ~AEventDispatcher() = default;
    virtual void Listen() = 0;
    void AddListener(IEventListener* listener);
    void RemoveListener(IEventListener* listener);
    void DispatchMouseEvent(const int &x,const int &y, int type, int button, int state, int clicks);
    void DispatchKeyEvent(int key, int scancode, int action);


protected:
    std::vector<IEventListener*> m_listener;
};

#endif // AEVENTDISPATCHER_H
