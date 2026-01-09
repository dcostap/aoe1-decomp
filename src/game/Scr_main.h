#pragma once
#include "common.h"

class TRIBE_Screen_Main_Error : public TScreenPanel {
public:
    TTextPanel* message;                     // 0x478
    TButtonPanel* cancel_button;             // 0x47C
    TButtonPanel* close_button;              // 0x480

    virtual long handle_idle();                             // vt0[19]+0x4C=0x49F340
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4); // vt0[45]+0xB4=0x49F2F0
    TRIBE_Screen_Main_Error();
    ~TRIBE_Screen_Main_Error();
    void set_text(char* param_1);
    void set_text(long param_1);
};

static_assert(sizeof(TRIBE_Screen_Main_Error) == 0x484, "TRIBE_Screen_Main_Error Size Mismatch");

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

    virtual long handle_idle();                             // vt0[19]+0x4C=0x49ECD0
    virtual long key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5); // vt0[43]+0xAC=0x49ED00
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4); // vt0[45]+0xB4=0x49EE00
    TRIBE_Screen_Main_Menu();
    ~TRIBE_Screen_Main_Menu();
};

static_assert(sizeof(TRIBE_Screen_Main_Menu) == 0x4B0, "TRIBE_Screen_Main_Menu Size Mismatch");

