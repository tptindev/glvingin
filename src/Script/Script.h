#ifndef SCRIPT_H
#define SCRIPT_H

class Script
{
public:
    Script(const Script &) = delete;
    Script(Script &&) = delete;
    Script &operator=(const Script &) = delete;
    Script &operator=(Script &&) = delete;
    static Script *Instance();
    static void ResetInstance();
    ~Script();
    void Initialize();
private:
    static Script* s_instance;
    Script();
};

#endif // SCRIPT_H
