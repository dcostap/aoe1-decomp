#ifndef AOE1_SCR_MAIN_H
#define AOE1_SCR_MAIN_H

// This header owns only the two screen classes from this module.
#include "Pnl_scr.h"

class TTextPanel;
class TButtonPanel;
class TPicturePanel;

class TRIBE_Screen_Main_Menu : public TScreenPanel {
  public:
    TTextPanel* title1;
    TTextPanel* title2;
    TButtonPanel* button[7];
    TTextPanel* ms_title_text;
    TTextPanel* ms_copy_text1;
    TTextPanel* ms_copy_text2;
    TTextPanel* warning_text;
    TPicturePanel* circle_p_pic;

    TRIBE_Screen_Main_Menu();
    virtual ~TRIBE_Screen_Main_Menu();
    virtual long handle_idle();
    virtual long key_down_action(long key, short count, int alt_key, int ctrl_key, int shift_key);
    virtual long action(TPanel* fromPanel, long actionIn, unsigned long a1, unsigned long a2);
};

typedef char scr_main_menu_size_check[(sizeof(TRIBE_Screen_Main_Menu) == 0x4B0) ? 1 : -1];

class TRIBE_Screen_Main_Error : public TScreenPanel {
  public:
    TTextPanel* message;
    TButtonPanel* cancel_button;
    TButtonPanel* close_button;

    TRIBE_Screen_Main_Error();
    virtual ~TRIBE_Screen_Main_Error();
    void set_text(char* message_in);
    void set_text(long message_in);
    virtual long action(TPanel* from_panel, long action_in, unsigned long val1, unsigned long val2);
    virtual long handle_idle();
};

typedef char scr_main_error_size_check[(sizeof(TRIBE_Screen_Main_Error) == 0x484) ? 1 : -1];

#endif
