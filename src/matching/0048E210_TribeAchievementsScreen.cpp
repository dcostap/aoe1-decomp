// VA: 0048E210 TribeAchievementsScreen::~TribeAchievementsScreen (493 B)
// PDB source: scr_ach.cpp (lines 360-435)
//
// Attempt log:
// - Replaced the unrelated offset/free shim with the packet-grounded destructor
//   surface: destroy YesNoDialog, delete the decal, delete the named panels,
//   then clean title/statistics arrays before the TScreenPanel base destructor.

class TPanel {
public:
    char pad_04[0xF0];
    virtual ~TPanel();
    void delete_panel(TPanel** panel);
};

class TEasy_Panel : public TPanel {
public:
    char pad_F4[0x384];
    virtual ~TEasy_Panel();
};

class TScreenPanel : public TEasy_Panel {
public:
    virtual ~TScreenPanel();
};

class TTextPanel : public TPanel {
public:
    virtual ~TTextPanel();
};

class TButtonPanel : public TPanel {
public:
    virtual ~TButtonPanel();
};

class TScrollBarPanel : public TPanel {
public:
    virtual ~TScrollBarPanel();
};

class Time_Line_Panel : public TPanel {
public:
    virtual ~Time_Line_Panel();
};

class TShape {
public:
    ~TShape();
};

class TPanelSystem {
public:
    int destroyPanel(char* name);
};

extern TPanelSystem panel_system;

class TribeAchievementsScreen : public TScreenPanel {
public:
    int end_game_flag;                    // +0x478
    int current_mode;                     // +0x47C
    int size;                             // +0x480
    TTextPanel* title;                    // +0x484
    TTextPanel* summary_text;             // +0x488
    TTextPanel* instruction;              // +0x48C
    TTextPanel* win_loss_text;            // +0x490
    TTextPanel* time;                     // +0x494
    TTextPanel* title_bar[7];             // +0x498
    TTextPanel* achievement_choice[5];    // +0x4B4
    TTextPanel* statistics[8][7];         // +0x4C8
    TTextPanel* player_names[8];          // +0x5A8
    TScrollBarPanel* summary_text_bar;    // +0x5C8
    TScrollBarPanel* instruction_bar;     // +0x5CC
    TScrollBarPanel* win_loss_text_bar;   // +0x5D0
    TButtonPanel* okButton;               // +0x5D4
    TButtonPanel* backButton;             // +0x5D8
    TButtonPanel* backButton2;            // +0x5DC
    TButtonPanel* timelineButton;         // +0x5E0
    TButtonPanel* aftermathButton;        // +0x5E4
    TButtonPanel* restartButton;          // +0x5E8
    TButtonPanel* close_button;            // +0x5EC
    TShape* win_decal;                    // +0x5F0
    Time_Line_Panel* time_line;            // +0x5F4

    virtual ~TribeAchievementsScreen();
};

TribeAchievementsScreen::~TribeAchievementsScreen()
{
    panel_system.destroyPanel("YesNoDialog");

    if (this->win_decal != 0) {
        delete this->win_decal;
    }

    if (this->title != 0) {
        delete this->title;
    }
    if (this->summary_text != 0) {
        delete this->summary_text;
    }
    if (this->time != 0) {
        delete this->time;
    }
    if (this->win_loss_text != 0) {
        delete this->win_loss_text;
    }
    if (this->instruction != 0) {
        delete this->instruction;
    }
    if (this->restartButton != 0) {
        delete this->restartButton;
    }
    if (this->okButton != 0) {
        delete this->okButton;
    }
    if (this->backButton != 0) {
        delete this->backButton;
    }
    if (this->backButton2 != 0) {
        delete this->backButton2;
    }
    if (this->aftermathButton != 0) {
        delete this->aftermathButton;
    }
    if (this->timelineButton != 0) {
        delete this->timelineButton;
    }
    if (this->time_line != 0) {
        delete this->time_line;
    }
    if (this->win_loss_text_bar != 0) {
        delete this->win_loss_text_bar;
    }
    if (this->summary_text_bar != 0) {
        delete this->summary_text_bar;
    }
    if (this->instruction_bar != 0) {
        delete this->instruction_bar;
    }

    this->delete_panel((TPanel**)&this->close_button);

    TTextPanel** title_bar = this->title_bar;
    int title_count = 7;
    do {
        if (*title_bar != 0) {
            delete *title_bar;
        }
        title_bar++;
        title_count--;
    } while (title_count != 0);

    TTextPanel** choices = this->achievement_choice;
    int choice_count = 5;
    do {
        if (*choices != 0) {
            delete *choices;
        }
        choices++;
        choice_count--;
    } while (choice_count != 0);

    TTextPanel** statistics = this->statistics[0];
    TTextPanel** player_names = this->player_names;
    int player_count = 8;
    do {
        if (*player_names != 0) {
            delete *player_names;
        }
        int statistic_count = 7;
        do {
            if (*statistics != 0) {
                delete *statistics;
            }
            statistics++;
            statistic_count--;
        } while (statistic_count != 0);
        player_names++;
        player_count--;
    } while (player_count != 0);
}
