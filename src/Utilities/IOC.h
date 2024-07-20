/**
 *  Inter-Object Communication
 *  Signal & Slot mechanism
 */
#ifndef IOC_H
#define IOC_H

#include <unordered_map>
#include <functional>

template<typename Return, typename ...Args>
class Signal
{
    typedef std::function<Return(Args...)> SLOT;
public:
    Signal()
    {
    }

    ~Signal()
    {

    }

    bool Connect(int id, const SLOT& slot)
    {
        if (this->m_slots[id] != nullptr) return false;
        else
        {
            this->m_slots[id] = slot;
        }
        return true;
    }
    bool Disconnect(int id)
    {
        if (this->m_slots[id] == nullptr)
        {
            return false;
        }
        this->m_slots.erase(this->m_slots.find(id), this->m_slots.end());
        return true;
    }
    void Emit(int id, Args&&... args) const
    {
        typename std::unordered_map<int, SLOT>::const_iterator it = this->m_slots.find(id);
        if (it != this->m_slots.end())
        {
            it->second(std::forward<Args>(args)...);
        }
    }
    void EmitAll(Args&&... args) const
    {
        typename std::unordered_map<int, SLOT>::const_iterator it = this->m_slots.begin();
        while (it != this->m_slots.end())
        {
            if (it->second != nullptr)
            {
                it->second(std::forward<Args>(args)...);
            }
            ++it;
        }
    }

private:
    std::unordered_map<int, SLOT> m_slots;
};

#endif // IOC_H
