#ifndef AEVENTLISTENER_H
#define AEVENTLISTENER_H

class AEventListener
{
public:
    virtual ~AEventListener() = default;
    virtual void OnTouched();
    virtual void OnClicked();
    virtual void OnPressed();
    virtual void OnLongPressed();
    virtual void OnReleased();
};

#endif // AEVENTLISTENER_H
