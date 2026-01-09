#pragma once
#include "common.h"

class TScreenPanel : public TEasy_Panel {
public:

    virtual void draw();                                    // vt0[12]+0x30=0x47BB40
    virtual long handle_paint();                            // vt0[21]+0x54=0x47BB50
    virtual void set_focus(int param_1);                    // vt0[48]+0xC0=0x47BB60
    TScreenPanel();
    TScreenPanel(char* param_1);
    ~TScreenPanel();
    long setup(TDrawArea* param_1, char* param_2, long param_3, int param_4);
    long setup(TDrawArea* param_1, char* param_2, long param_3, uchar param_4, int param_5);
};

static_assert(sizeof(TScreenPanel) == 0x478, "TScreenPanel Size Mismatch");

