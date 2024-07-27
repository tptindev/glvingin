#ifndef ACOMPONENT_H
#define ACOMPONENT_H


class AComponent
{
public:
    const char *name() const;
    virtual ~AComponent();


protected:
    void setName(const char *newName);
    AComponent();

private:
    const char* m_name;
};


#endif // ACOMPONENT_H
