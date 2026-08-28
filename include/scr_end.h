#ifndef AOE1_SCR_END_H
#define AOE1_SCR_END_H

// PDB source module: C:\msdev\work\age1_x1\scr_end.cpp.
#include "Pnl_scr.h"

class TPicturePanel;
class TTextPanel;
class TButtonPanel;
class TScrollBarPanel;
class TShape;
class Time_Line_Panel;

class TribeEndScreen : public TScreenPanel {
public:
    TPicturePanel* background;
    TTextPanel* title;
    TTextPanel* text;
    TButtonPanel* okButton;

    TribeEndScreen(char* title_text, char** text_list, int text_count);
    virtual ~TribeEndScreen();

protected:
    virtual long action(TPanel*, long, unsigned long, unsigned long);
};

typedef char tribe_end_screen_size_check[
    (sizeof(TribeEndScreen) == 0x488) ? 1 : -1];

// PDB type record: TribeAchievementsScreen is 0x5F8 bytes.  scr_ach.h has
// an incompatible older panel surface, so this module uses this narrow caller
// declaration until its owner header is reunified.
class TribeAchievementsScreen : public TScreenPanel {
public:
    int end_game_flag;
    int current_mode;
    int size;
    TTextPanel* title;
    TTextPanel* summary_text;
    TTextPanel* instruction;
    TTextPanel* win_loss_text;
    TTextPanel* time;
    TTextPanel* title_bar[7];
    TTextPanel* achievement_choice[5];
    TTextPanel* statistics[8][7];
    TTextPanel* player_names[8];
    TScrollBarPanel* summary_text_bar;
    TScrollBarPanel* instruction_bar;
    TScrollBarPanel* win_loss_text_bar;
    TButtonPanel* okButton;
    TButtonPanel* backButton;
    TButtonPanel* backButton2;
    TButtonPanel* timelineButton;
    TButtonPanel* aftermathButton;
    TButtonPanel* restartButton;
    TButtonPanel* close_button;
    TShape* win_decal;
    Time_Line_Panel* time_line;

    virtual ~TribeAchievementsScreen();
    TribeAchievementsScreen(char*, int);
    void set_mode(long);
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual long handle_mouse_down(unsigned char, long, long, int, int);
    virtual void draw();
    virtual long handle_idle();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
};

typedef char tribe_achievements_screen_size_check[
    (sizeof(TribeAchievementsScreen) == 0x5F8) ? 1 : -1];

#endif
