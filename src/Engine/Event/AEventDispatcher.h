#ifndef AEVENTDISPATCHER_H
#define AEVENTDISPATCHER_H

#include <vector>

class AEventListener;
class AEventDispatcher
{
public:
    virtual ~AEventDispatcher() = default;
    virtual void Listen() = 0;
    void AddListener(AEventListener* listener);
    void RemoveListener(AEventListener* listener);
    void Dispatch();

protected:
    std::vector<AEventListener*> m_listener;
};

#endif // AEVENTDISPATCHER_H
