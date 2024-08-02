#ifndef ARENDERER_H
#define ARENDERER_H


class ARenderer
{
public:
    ~ARenderer() = default;
    virtual void Initialize() = 0;
    virtual void SetDrawColor() = 0;
    virtual void Clear() = 0;
    virtual void Present() = 0;
};

#endif // ARENDERER_H
