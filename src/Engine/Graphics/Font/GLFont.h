#ifndef GLFONT_H
#define GLFONT_H

#include "AFont.h"

class GLFont : public AFont
{
public:
    GLFont();

    // AFont interface
public:
    bool OpenFont() override;
    void *Data() override;
    void CloseFont() override;
};

#endif // GLFONT_H
