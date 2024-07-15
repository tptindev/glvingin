#ifndef ASCENE_H
#define ASCENE_H


class AScene
{
public:
    AScene();
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

private:
    int m_id;
    const char* m_name;
    float m_opacity{1.0f};
    bool m_visible{true};
    bool m_enable{true};

};

#endif // ASCENE_H
