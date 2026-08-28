#ifndef AOE1_SCR_MAIN_H
#define AOE1_SCR_MAIN_H

// PDB source module: C:\msdev\work\age1_x1\Scr_main.cpp.
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
    virtual long key_down_action(long, short, int, int, int);
    virtual long action(TPanel*, long, unsigned long, unsigned long);
};

typedef char scr_main_menu_size_check[
    (sizeof(TRIBE_Screen_Main_Menu) == 0x4B0) ? 1 : -1];

class TRIBE_Screen_Main_Error : public TScreenPanel {
public:
    TTextPanel* message;
    TButtonPanel* cancel_button;
    TButtonPanel* close_button;

    TRIBE_Screen_Main_Error();
    virtual ~TRIBE_Screen_Main_Error();
    void set_text(char*);
    void set_text(long);
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual long handle_idle();
};

typedef char scr_main_error_size_check[
    (sizeof(TRIBE_Screen_Main_Error) == 0x484) ? 1 : -1];

#endif
