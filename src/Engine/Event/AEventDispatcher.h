#ifndef AEVENTDISPATCHER_H
#define AEVENTDISPATCHER_H

#include <vector>

class AEventListener;
class AEventDispatcher
{
public:
    virtual void AddListener(AEventListener* listener) = 0;
    virtual void RemoveListener(AEventListener* listener) = 0;
    virtual void Dispatch() = 0;

protected:
    std::vector<AEventListener*> m_listener;
};

#endif // AEVENTDISPATCHER_H
