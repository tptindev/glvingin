#ifndef IEVENTLISTENER_H
#define IEVENTLISTENER_H

class IEventListener
{
public:
    virtual ~IEventListener() = default;
    virtual void OnMouseStateChanged(const int &x,const int &y, int type, int button, int state, int clicks) = 0;
};

#endif // IEVENTLISTENER_H
