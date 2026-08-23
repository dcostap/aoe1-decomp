// VA: 0048F280 TribeAchievementsScreen::action (638 B)
// PDB source: scr_ach.cpp (lines 808-905)
//
// Exact source notes:
// - The natural button action tree preserves the timeline and aftermath paths,
//   typed panel-name test, and base action fallback.
// - A branch-local return in the dialog path made VC5 merge both close calls.
//   That form emitted 24 calls and removed the close-button call site.
// - PDB lines 897-901 show one dialog condition, two arms, and one shared
//   return. Expressing that source shape restores both direct close calls.
// - The complete PDB-order scr_ach translation unit emits all 638 bytes exactly.

#include <string.h>
#include "../../include/scr_ach_context.h"

#if 0

class TDrawArea;

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea* area, TPanel* parent, long x,
                       long y, long width, long height, unsigned char mode);
    virtual void set_rect(tagRECT rect);
    virtual void set_rect(long x, long y, long width, long height);
    virtual void set_color(unsigned char color);
    virtual void set_active(int active);
    virtual void set_positioning(int mode, long x, long y, long width,
                                 long height, long x2, long y2, TPanel* p1,
                                 TPanel* p2, TPanel* p3, TPanel* p4);
    virtual void set_fixed_position(long x, long y, long width, long height);
    virtual void set_redraw(int mode);

    char pad_04[0xF0];

    char* panelName();
};

class TEasy_Panel : public TPanel {
public:
    char pad_F4_easy[0x384];
    virtual ~TEasy_Panel();
    long action(TPanel* panel, long id, unsigned long param3,
                unsigned long param4);
};

class TScreenPanel : public TEasy_Panel {
public:
    virtual ~TScreenPanel();
};

class TButtonPanel : public TPanel {
public:
    virtual ~TButtonPanel();
};

class TPanelSystem {
public:
    int setCurrentPanel(char* name, int param);
    int destroyPanel(char* name);
};

class RGE_Base_Game {
public:
    char pad_000[0xA00];
    int save_paused;

    int singlePlayerGame();
    void set_paused(int paused, int non_user_pause);
    void close();
};

class TRIBE_Game : public RGE_Base_Game {
public:
    void quit_game();
    void restart_game();
};

extern TPanelSystem panel_system;
extern TRIBE_Game* rge_base_game;
extern int confirmed_close;

class TribeAchievementsScreen : public TScreenPanel {
public:
    int end_game_flag;                    // +0x478
    int current_mode;                     // +0x47C
    int size;                             // +0x480
    TPanel* title;                        // +0x484
    TPanel* summary_text;                 // +0x488
    TPanel* instruction;                  // +0x48C
    TPanel* win_loss_text;                // +0x490
    TPanel* time;                         // +0x494
    TPanel* title_bar[7];                 // +0x498
    TPanel* achievement_choice[5];        // +0x4B4
    TPanel* statistics[8][7];             // +0x4C8
    TPanel* player_names[8];              // +0x5A8
    TPanel* summary_text_bar;             // +0x5C8
    TPanel* instruction_bar;              // +0x5CC
    TPanel* win_loss_text_bar;            // +0x5D0
    TButtonPanel* okButton;               // +0x5D4
    TButtonPanel* backButton;             // +0x5D8
    TButtonPanel* backButton2;            // +0x5DC
    TButtonPanel* timelineButton;         // +0x5E0
    TButtonPanel* aftermathButton;        // +0x5E4
    TButtonPanel* restartButton;          // +0x5E8
    TButtonPanel* close_button;           // +0x5EC
    void* win_decal;                      // +0x5F0
    void* time_line;                      // +0x5F4

    virtual long action(TPanel* panel, long id, unsigned long param3,
                        unsigned long param4);
    void set_mode(long mode);
};

#endif

long TribeAchievementsScreen::action(TPanel* panel, long id,
                                     unsigned long param3,
                                     unsigned long param4)
{
    if (panel == this->okButton && id == 1) {
        if (this->end_game_flag != 0) {
            rge_base_game->quit_game();
        } else {
            if (rge_base_game->singlePlayerGame() == 1 &&
                rge_base_game->save_paused == 0) {
                rge_base_game->set_paused(0, 0);
            }
            panel_system.setCurrentPanel("Game Screen", 0);
        }
        panel_system.destroyPanel("Achievements Screen");
        return 1;
    }

    if (panel == this->restartButton && id == 1) {
        rge_base_game->restart_game();
        return id;
    }

    if (panel == this->timelineButton && id == 1) {
        this->set_mode(6);
        if (this->restartButton != 0) {
            this->restartButton->set_active(0);
        }
        if (this->okButton != 0) {
            this->okButton->set_active(0);
        }
        if (this->aftermathButton != 0) {
            this->aftermathButton->set_active(0);
        }
        if (this->timelineButton != 0) {
            this->timelineButton->set_active(0);
        }
        if (this->backButton != 0) {
            this->backButton->set_active(1);
            return id;
        }
    } else {
        if (panel != this->aftermathButton || id != 1) {
            if ((panel == this->backButton || panel == this->backButton2) &&
                id == 1) {
                this->set_mode(0);
                return id;
            } else if (panel == this->close_button && id == 1) {
                rge_base_game->close();
                return id;
            } else {
                char* panel_name = panel->panelName();
                if (panel_name != 0 &&
                    strcmp(panel->panelName(), "YesNoDialog") == 0) {
                    panel_system.destroyPanel("YesNoDialog");
                    if (id == 0) {
                        rge_base_game->close();
                    } else {
                        confirmed_close = 0;
                    }
                    return 1;
                }

                return TEasy_Panel::action(panel, id, param3, param4);
            }
        }

        this->set_mode(5);
        if (this->restartButton != 0) {
            this->restartButton->set_active(0);
        }
        if (this->okButton != 0) {
            this->okButton->set_active(0);
        }
        if (this->aftermathButton != 0) {
            this->aftermathButton->set_active(0);
        }
        if (this->timelineButton != 0) {
            this->timelineButton->set_active(0);
        }
        if (this->backButton != 0) {
            this->backButton->set_active(1);
            return id;
        }
    }

    return 1;
}
