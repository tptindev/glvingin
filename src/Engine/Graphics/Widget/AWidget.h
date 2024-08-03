#ifndef AWIDGET_H
#define AWIDGET_H

class AWidget
{
public:
    virtual ~AWidget() = default;

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

    virtual void Initialize() = 0;
    virtual void HandleEvent() = 0;
    virtual void Render() = 0;
private:
    int m_x{0};
    int m_y{0};
    int m_width{0};
    int m_height{0};
    bool m_enable{true};
    bool m_visible{true};
};

#endif // AWIDGET_H
