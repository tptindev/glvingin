#include "Timer.h"
#include <chrono>

Timer::Timer()
{

}

Timer::~Timer()
{

}

void Timer::SetInterval(int milliseconds)
{
    this->m_interval = milliseconds;
}

void Timer::SetSingleShot(bool singleShot)
{
    this->m_singleShot = singleShot;
}

void Timer::Start(int milliseconds)
{
    this->SetInterval(milliseconds);
}

void Timer::Stop()
{

}

int Timer::RemainingTime() const
{
    return 0;
}

int Timer::interval() const
{
    return m_interval;
}

bool Timer::singleShot() const
{
    return m_singleShot;
}
