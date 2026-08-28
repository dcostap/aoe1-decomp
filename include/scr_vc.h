#ifndef AOE1_SCR_VC_H
#define AOE1_SCR_VC_H

// PDB source module: C:\\msdev\\work\\age1_x1\\scr_vc.cpp.
// This module owns TRIBE_Mission_Screen. Shared panel and screen types keep
// their declarations in their canonical owner headers.
#include "Pnl_scr.h"

class TTextPanel;
class TButtonPanel;
class TScrollBarPanel;
class TPicture;

class TRIBE_Mission_Screen : public TScreenPanel {
public:
    TTextPanel* title;
    TTextPanel* list;
    TScrollBarPanel* scroll_bar;
    TButtonPanel* ok_button;
    TButtonPanel* text_buttons[3];
    unsigned char game_flag;
    TPicture* vc_back_bmp;

    TRIBE_Mission_Screen(char* info_file, unsigned char game_flag,
                         TPicture* vc_back_bmp);
    virtual ~TRIBE_Mission_Screen();
    virtual long handle_idle();
    virtual void draw();
    virtual long action(TPanel* sender, long actionType,
                        unsigned long param3, unsigned long param4);
    virtual long key_down_action(long param_1, short param_2, int param_3,
                                 int param_4, int param_5);
};

typedef char scr_vc_screen_size_check[
    (sizeof(TRIBE_Mission_Screen) == 0x49C) ? 1 : -1];

#endif
