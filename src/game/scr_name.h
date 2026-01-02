#pragma once
#include "../common.h"

class TRIBE_Screen_Name : public TScreenPanel {
public:
    TTextPanel* title;                       // 0x478
    TTextPanel* name_text;                   // 0x47C
    TListPanel* name_list;                   // 0x480
    TScrollBarPanel* name_scrollbar;         // 0x484
    TButtonPanel* new_button;                // 0x488
    TButtonPanel* remove_button;             // 0x48C
    TButtonPanel* ok_button;                 // 0x490
    TButtonPanel* cancel_button;             // 0x494
    TButtonPanel* close_button;              // 0x498
    int started_input;                       // 0x49C

    TRIBE_Screen_Name();
    virtual ~TRIBE_Screen_Name();
    virtual void init_vars();
    virtual void get_player_names();
    virtual void setup_tab_order();
    virtual long handle_idle();
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4);
};

static_assert(sizeof(TRIBE_Screen_Name) == 0x4A0, "TRIBE_Screen_Name Size Mismatch");
static_assert(offsetof(TRIBE_Screen_Name, started_input) == 0x49C, "TRIBE_Screen_Name Offset Mismatch");

class TRIBE_Dialog_Name : public TDialogPanel {
public:
    TTextPanel* title;                       // 0x490
    TTextPanel* name_text;                   // 0x494
    TEditPanel* name_input;                  // 0x498
    TButtonPanel* ok_button;                 // 0x49C
    TButtonPanel* cancel_button;             // 0x4A0

    TRIBE_Dialog_Name(TScreenPanel* param_1);
    virtual ~TRIBE_Dialog_Name();
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4);
    virtual long wnd_proc(void* param_1, uint param_2, uint param_3, long param_4);
};

static_assert(sizeof(TRIBE_Dialog_Name) == 0x4A4, "TRIBE_Dialog_Name Size Mismatch");
static_assert(offsetof(TRIBE_Dialog_Name, cancel_button) == 0x4A0, "TRIBE_Dialog_Name Offset Mismatch");

