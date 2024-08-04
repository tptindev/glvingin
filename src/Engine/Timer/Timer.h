#ifndef TIMER_H
#define TIMER_H


class Timer
{
public:
    Timer();
    ~Timer();

    void SetInterval(int milliseconds = 0);
    void SetSingleShot(bool singleShot);
    void Start(int milliseconds = 0);
    void Stop();
    int RemainingTime() const;

    int interval() const;

    bool singleShot() const;

private:
    bool m_timeout{false};
    bool m_singleShot{false};
    int m_interval{0};
};

#endif // TIMER_H
