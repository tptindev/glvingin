#ifndef AENTITY_H
#define AENTITY_H

#include <functional>

class AEntity
{
public:
    AEntity();

    template<typename T, typename ...Args>
    void AddComponent(Args&& ...args)
    {
        T* comp = new T(std::forward<Args>(args)...);

    }
};

#endif // AENTITY_H
