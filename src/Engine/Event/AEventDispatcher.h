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
    void Dispatch();

protected:
    std::vector<IEventListener*> m_listener;
};

#endif // AEVENTDISPATCHER_H
