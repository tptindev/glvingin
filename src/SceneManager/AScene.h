#ifndef ASCENE_H
#define ASCENE_H

#include <GLFW/glfw3.h>

class AScene
{
public:
    AScene(int width, int height, const char* title);
    virtual ~AScene();
    int id() const;
    const char *name() const;
    float opacity() const;
    void setOpacity(float newOpacity);
    bool visible() const;
    void setVisible(bool newVisible);
    bool enable() const;
    void setEnable(bool newEnable);

    virtual void EventHandle();
    virtual void Update();
    virtual void Render();

    int width() const;
    void setWidth(int newWidth);

    int height() const;
    void setHeight(int newHeight);

private:
    int m_id;
    const char* m_name;
    int m_width{300};
    int m_height{300};
    float m_opacity{1.0f};
    bool m_visible{true};
    bool m_enable{true};

    GLFWwindow* m_window;
};

#endif // ASCENE_H
