#ifndef AOE1_SCR_ACH_H
#define AOE1_SCR_ACH_H

// PDB source module: C:\msdev\work\age1_x1\scr_ach.cpp.
#include "Pnl_scr.h"

class TShape;
class TTextPanel;
class TButtonPanel;
class TScrollBarPanel;

// tpnl_tml.h has not yet adopted the canonical panel surface. This caller
// needs only the PDB-proved methods below. It does not construct this type.
class Time_Line_Panel : public TEasy_Panel {
public:
    virtual ~Time_Line_Panel();
    long create_timeline(TPanel*, Time_Line_Panel**, long, long, long, long,
                         long, long, long, long);
    void set_bevel_info(int, int, int, int, int, int, int);
    int set_special_events(char*);
};

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

    TribeAchievementsScreen(char*, int);
    virtual ~TribeAchievementsScreen();

protected:
    void set_mode(long);

public:
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual long handle_mouse_down(unsigned char, long, long, int, int);
    virtual void draw();
    virtual long handle_idle();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
};

typedef char tribe_achievements_screen_size_check[
    (sizeof(TribeAchievementsScreen) == 0x5F8) ? 1 : -1];

#endif
