#ifndef ASCENE_H
#define ASCENE_H

#include <GLFW/glfw3.h>

class AScene
{
public:
    AScene();
    virtual ~AScene();
    int id() const;
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

    void Setup();
    virtual void EventHandle() = 0;
    virtual void Update() = 0;
    virtual void Render() = 0;



    void setId(int newId);

private:
    int m_id{-1};
    const char* m_title{"Unknow"};
    int m_width{300};
    int m_height{300};
    float m_opacity{1.0f};
    bool m_visible{true};
    bool m_enable{true};

    GLFWwindow* m_buffer;
};

#endif // ASCENE_H
