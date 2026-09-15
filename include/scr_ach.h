#ifndef AOE1_SCR_ACH_H
#define AOE1_SCR_ACH_H

#include "Pnl_scr.h"
#include "tpnl_tml.h"

class TShape;
class TTextPanel;
class TButtonPanel;
class TScrollBarPanel;

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

    TribeAchievementsScreen(char* titleText, int end_flag);
    virtual ~TribeAchievementsScreen();

protected:
    void set_mode(long new_mode);

public:
    virtual long action(TPanel* fromPanel, long actionIn, unsigned long a1, unsigned long a2);
    virtual long handle_mouse_down(unsigned char mouse_button_in, long x, long y, int ctrl_key, int shift_key);
    virtual void draw();
    virtual long handle_idle();
    virtual long wnd_proc(void* hwnd, unsigned int msg, unsigned int wParam, long lParam);
};

typedef char tribe_achievements_screen_size_check[
    (sizeof(TribeAchievementsScreen) == 0x5F8) ? 1 : -1];

#endif
