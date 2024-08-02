#ifndef ALAYER_H
#define ALAYER_H

struct SDL_Renderer;
class ALayer
{
public:
    virtual ~ALayer() = default;
    virtual void init() = 0;
    virtual void update(float deltaTime) = 0;
    virtual void render(SDL_Renderer* renderer) = 0;
    virtual void cleanup() = 0;

    int id() const;
    void setId(int newId);

    const char *name() const;
    void setName(const char *newName);

private:
    int m_id{-1};
    const char* m_name;
};

#endif // ALAYER_H
