#ifndef ALAYER_H
#define ALAYER_H

class IRenderer;
class ALayer
{
public:
    virtual ~ALayer() = default;
    virtual void Initialize() = 0;
    virtual void Update(float deltaTime) = 0;
    virtual void Render(IRenderer* renderer) = 0;
    virtual void Cleanup() = 0;

    int id() const;
    void setId(int newId);

private:
    int m_id{0};
};

#endif // ALAYER_H
