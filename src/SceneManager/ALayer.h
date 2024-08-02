#ifndef ALAYER_H
#define ALAYER_H

class IRenderer;
class ALayer
{
public:
    virtual ~ALayer() = default;
    virtual void init() = 0;
    virtual void update(float deltaTime) = 0;
    virtual void render(IRenderer* renderer) = 0;
    virtual void cleanup() = 0;

    int id() const;
    void setId(int newId);

private:
    int m_id{0};
};

#endif // ALAYER_H
