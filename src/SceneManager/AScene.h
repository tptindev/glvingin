#ifndef ASCENE_H
#define ASCENE_H


class AScene
{
public:
    AScene();
    virtual ~AScene();
    int id() const;
    const char *name() const;

    virtual void EventHandle();
    virtual void Update();
    virtual void Render();

private:
    int m_id;
    const char* m_name;

};

#endif // ASCENE_H
