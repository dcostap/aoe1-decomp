#pragma once
#include "../common.h"

class TribeAchievementsScreen : public TScreenPanel {
public:
    int end_game_flag;                       // 0x478
    int current_mode;                        // 0x47C
    int size;                                // 0x480
    TTextPanel* title;                       // 0x484
    TTextPanel* summary_text;                // 0x488
    TTextPanel* instruction;                 // 0x48C
    TTextPanel* win_loss_text;               // 0x490
    TTextPanel* time;                        // 0x494
    TTextPanel* title_bar[7];                // 0x498
    TTextPanel* achievement_choice[5];       // 0x4B4
    TTextPanel** statistics[8];              // 0x4C8
    TTextPanel* player_names[8];             // 0x5A8
    TScrollBarPanel* summary_text_bar;       // 0x5C8
    TScrollBarPanel* instruction_bar;        // 0x5CC
    TScrollBarPanel* win_loss_text_bar;      // 0x5D0
    TButtonPanel* okButton;                  // 0x5D4
    TButtonPanel* backButton;                // 0x5D8
    TButtonPanel* backButton2;               // 0x5DC
    TButtonPanel* timelineButton;            // 0x5E0
    TButtonPanel* aftermathButton;           // 0x5E4
    TButtonPanel* restartButton;             // 0x5E8
    TButtonPanel* close_button;              // 0x5EC
    TShape* win_decal;                       // 0x5F0
    Time_Line_Panel* time_line;              // 0x5F4

    TribeAchievementsScreen(char* param_1, int param_2);
    virtual ~TribeAchievementsScreen();
    virtual void set_mode(long param_1);
    virtual void draw();
    virtual long handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5);
    virtual long action(TPanel* param_1, long param_2, ulong param_3, ulong param_4);
    virtual long handle_idle();
    virtual long wnd_proc(void* param_1, uint param_2, uint param_3, long param_4);
};

static_assert(sizeof(TribeAchievementsScreen) == 0x5F8, "TribeAchievementsScreen Size Mismatch");
static_assert(offsetof(TribeAchievementsScreen, time_line) == 0x5F4, "TribeAchievementsScreen Offset Mismatch");

