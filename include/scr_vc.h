#ifndef AOE1_SCR_VC_H
#define AOE1_SCR_VC_H

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

    TRIBE_Mission_Screen(char* text_in, unsigned char from_game, TPicture* background_bmp);
    virtual ~TRIBE_Mission_Screen();
    virtual long handle_idle();
    virtual void draw();
    virtual long action(TPanel* fromPanel, long actionIn, unsigned long a1, unsigned long a2);
    virtual long key_down_action(long key, short count, int alt_key, int ctrl_key, int shift_key);
};

typedef char scr_vc_screen_size_check[(sizeof(TRIBE_Mission_Screen) == 0x49C) ? 1 : -1];

#endif
