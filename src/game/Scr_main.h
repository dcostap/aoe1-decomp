#pragma once
#include "../common.h"

class TRIBE_Screen_Main_Menu : public TScreenPanel {
public:
    TTextPanel* title1;                      // 0x478
    TTextPanel* title2;                      // 0x47C
    TButtonPanel* button[7];                 // 0x480
    TTextPanel* ms_title_text;               // 0x49C
    TTextPanel* ms_copy_text1;               // 0x4A0
    TTextPanel* ms_copy_text2;               // 0x4A4
    TTextPanel* warning_text;                // 0x4A8
    TPicturePanel* circle_p_pic;             // 0x4AC

    TRIBE_Screen_Main_Menu();
    virtual ~TRIBE_Screen_Main_Menu();
    virtual long handle_idle();
    virtual long key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5);
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4);
};

static_assert(sizeof(TRIBE_Screen_Main_Menu) == 0x4B0, "TRIBE_Screen_Main_Menu Size Mismatch");
static_assert(offsetof(TRIBE_Screen_Main_Menu, circle_p_pic) == 0x4AC, "TRIBE_Screen_Main_Menu Offset Mismatch");

class TRIBE_Screen_Main_Error : public TScreenPanel {
public:
    TTextPanel* message;                     // 0x478
    TButtonPanel* cancel_button;             // 0x47C
    TButtonPanel* close_button;              // 0x480

    TRIBE_Screen_Main_Error();
    virtual ~TRIBE_Screen_Main_Error();
    virtual void set_text(char* param_1);
    virtual void set_text(long param_1);
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4);
    virtual long handle_idle();
};

static_assert(sizeof(TRIBE_Screen_Main_Error) == 0x484, "TRIBE_Screen_Main_Error Size Mismatch");
static_assert(offsetof(TRIBE_Screen_Main_Error, close_button) == 0x480, "TRIBE_Screen_Main_Error Offset Mismatch");

