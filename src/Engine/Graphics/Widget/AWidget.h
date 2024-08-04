#ifndef AWIDGET_H
#define AWIDGET_H

class AWidget
{
public:
    virtual ~AWidget() = default;

    virtual void Initialize() = 0;
    virtual void Completed() = 0;
    virtual void HandleEvent() = 0;
    virtual void Render() = 0;

    int x() const;
    void setX(int newX);
    int y() const;
    void setY(int newY);
    int width() const;
    void setWidth(int newWidth);
    int height() const;
    void setHeight(int newHeight);
    bool enable() const;
    void setEnable(bool newEnable);
    bool visible() const;
    void setVisible(bool newVisible);

    bool clip() const;
    void setClip(bool newClip);

private:
    int m_x{0};
    int m_y{0};
    int m_width{0};
    int m_height{0};
    bool m_enable{true};
    bool m_visible{true};
    bool m_clip{false};
};

#endif // AWIDGET_H
