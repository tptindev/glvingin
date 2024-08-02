#ifndef ASCENE_H
#define ASCENE_H

struct GLFWwindow;
class SceneManager;
class EntityManager;
class LayerManager;
class AScene
{
public:
    virtual ~AScene() = default;
    int id() const;
    void setId(int newId);
    const char *title() const;
    void setTitle(const char *newName);
    float opacity() const;
    void setOpacity(float newOpacity);
    bool visible() const;
    void setVisible(bool newVisible);
    bool enable() const;
    void setEnable(bool newEnable);
    int width() const;
    void setWidth(int newWidth);
    int height() const;
    void setHeight(int newHeight);
    virtual void Initialize() = 0;
    virtual void HandleEvents() = 0;
    virtual void Update(float deltaTime) = 0;
    virtual void Render() = 0;
    virtual void Cleanup() = 0;

private:
    int m_id{-1};
    const char* m_title{"Unknow"};
    int m_width{300};
    int m_height{300};
    float m_opacity{1.0f};
    bool m_visible{true};
    bool m_enable{true};
};

#endif // ASCENE_H
