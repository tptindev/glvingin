#ifndef ASCENE_H
#define ASCENE_H

#include "../Utilities/IOC.h"

struct GLFWwindow;
class SceneManager;
class AScene
{
public:
    AScene(GLFWwindow* surface, SceneManager* manager);
    virtual ~AScene();
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
    virtual void EventHandle() = 0;
    virtual void Update() = 0;
    virtual void Render() = 0;

    GLFWwindow *surface() const;

    Signal<void, const char *> &SignalNotifyTitleChanged();

protected:
    static SceneManager* manager();

private:
    int m_id{-1};
    const char* m_title{"Unknow"};
    int m_width{300};
    int m_height{300};
    float m_opacity{1.0f};
    bool m_visible{true};
    bool m_enable{true};
    GLFWwindow* m_surface;
    static SceneManager* s_manager;
    Signal<void, const char*> m_SignalNotifyTitleChanged;
};

#endif // ASCENE_H
