#ifndef COMPONENT_H
#define COMPONENT_H


class Component
{
public:
    const char *name() const;
    void setName(const char *newName);
    virtual ~Component();


protected:
    Component();

private:
    const char* m_name;
};


#endif // COMPONENT_H
