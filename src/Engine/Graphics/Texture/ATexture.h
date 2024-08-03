#ifndef ATEXTURE_H
#define ATEXTURE_H

class ATexture
{
public:
    ~ATexture() = default;
    
    virtual bool Create(const char* path) = 0;
    virtual void Destroy() = 0;

    float angle() const;
    void setAngle(float newAngle);

    bool flip() const;
    void setFlip(bool newFlip);

private:
    float m_angle;
    bool m_flip;
};

#endif // ATEXTURE_H
