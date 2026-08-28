#ifndef AOE1_SCR_SING_H
#define AOE1_SCR_SING_H

// PDB source module: C:\\msdev\\work\\age1_x1\\Scr_sing.cpp.
// TribeSPMenuScreen is the only class owned by this header. Shared panel,
// screen, game, list, button, and settings surfaces come from their owners.

#include "Pnl_scr.h"
#include "panel.h"
#include "panel_ez.h"
#include "basegame.h"
#include "tribegam.h"
#include "gameinfo.h"
#include "pnl_lst.h"
#include "pnl_btn.h"
#include "scr_set_screen.h"
#include "rge_base_game_global.h"

class TribeSPMenuScreen : public TScreenPanel {
public:
    TTextPanel* title;
    TButtonPanel* button[7];
    TButtonPanel* close_button;

    TribeSPMenuScreen();
    virtual ~TribeSPMenuScreen();
    virtual long handle_idle();
    virtual long action(TPanel* panel, long code, unsigned long p3,
                        unsigned long p4);
};

typedef char scr_sing_screen_size_check[
    (sizeof(TribeSPMenuScreen) == 0x49C) ? 1 : -1];

#endif
