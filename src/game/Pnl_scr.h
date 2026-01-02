#pragma once
#include "../common.h"

class TScreenPanel : public TEasy_Panel {
public:

    TScreenPanel();
    TScreenPanel(char* param_1);
    virtual ~TScreenPanel();
    virtual long setup(TDrawArea* param_1, char* param_2, long param_3, int param_4);
    virtual long setup(TDrawArea* param_1, char* param_2, long param_3, uchar param_4, int param_5);
    virtual void draw();
    virtual long handle_paint();
    virtual void set_focus(int param_1);
};

static_assert(sizeof(TScreenPanel) == 0x478, "TScreenPanel Size Mismatch");

