#ifndef ACOMPONENT_H
#define ACOMPONENT_H


class AComponent
{
public:
    const char *name() const;
    void setName(const char *newName);
    virtual ~AComponent();


protected:
    AComponent();

private:
    const char* m_name;
};


#endif // ACOMPONENT_H
