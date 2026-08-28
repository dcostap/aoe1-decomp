#ifndef AOE1_PNL_SCR_H
#define AOE1_PNL_SCR_H

// PDB source: C:\\msdev\\work\\age1_x1\\Pnl_scr.cpp.
// This header owns TScreenPanel. Shared types come from their owners.
#include "panel_ez.h"
#include "drawarea.h"
#include "color.h"

class TScreenPanel : public TEasy_Panel {
public:
    TScreenPanel();
    TScreenPanel(char*);
    virtual ~TScreenPanel();

    long setup(TDrawArea*, char*, long, int);
    long setup(TDrawArea*, char*, long, unsigned char, int);
    virtual void draw();
    virtual long handle_paint();
    virtual void set_focus(int);
};

typedef char pnl_scr_tscreen_size_check[
    (sizeof(TScreenPanel) == 0x478) ? 1 : -1];

#endif
