#ifndef AOE1_SCR_SING_H
#define AOE1_SCR_SING_H

// PDB source module: C:\msdev\work\age1_x1\Scr_sing.cpp.
#include "Pnl_scr.h"

class TTextPanel;
class TButtonPanel;

class TribeSPMenuScreen : public TScreenPanel {
public:
    TTextPanel* title;
    TButtonPanel* button[7];
    TButtonPanel* close_button;

    TribeSPMenuScreen();
    virtual ~TribeSPMenuScreen();
    virtual long handle_idle();
    virtual long action(TPanel*, long, unsigned long, unsigned long);
};

typedef char scr_sing_screen_size_check[
    (sizeof(TribeSPMenuScreen) == 0x49C) ? 1 : -1];

#endif
