// attempt 1: switch-based handle_user_command with EH frame

struct tagRECT;

class TPanel {
public:
    void* vftable;
    char pad[0xF0];

    virtual ~TPanel();
    long handle_user_command(unsigned int cmd, long param);
};

class TEasy_Panel : public TPanel {
public:
    char pad_easy[0x380];
    void popupOKDialog(long title_id, char* msg, long body_id, long button_count);
};

class TScreenPanel : public TEasy_Panel {
};

class RGE_Base_Game {
public:
    char gap_0[0x1D8];
    int input_enabled;
    void enable_input();
};

extern RGE_Base_Game* rge_base_game;

class TCommunications_Handler {
public:
    void UnlinkToLevel(int param);
};

extern TCommunications_Handler* comm;

class TPanelSystem {
public:
    int setCurrentPanel(char* name, long param);
    int destroyPanel(char* name);
};

extern TPanelSystem panel_system;

void* operator_new(unsigned int size);

class TribeMPSetupScreen {
public:
    void init();
};

void TribeMPSetupScreen_ctor(TribeMPSetupScreen* this_);

class TribeJoinScreen : public TScreenPanel {
public:
    int startedSession;
    int listFilled;
    TPanel* title;
    TPanel* listTitle;
    TPanel* list;
    TPanel* scrollbar;
    TPanel* joinButton;
    TPanel* createButton;
    TPanel* cancelButton;
    TPanel* refreshButton;
    TPanel* close_button;
    int game_count;
    int waitingToStart;
    unsigned long joinTime;

    long handle_user_command(unsigned int cmd, long param);
};

long TribeJoinScreen::handle_user_command(unsigned int cmd, long param) {
    switch (cmd) {
        case 0x17B8:
            if (this->waitingToStart != 0) {
                TribeMPSetupScreen* p = (TribeMPSetupScreen*)operator_new(0x890);
                if (p != 0) {
                    TribeMPSetupScreen_ctor(p);
                }
                panel_system.setCurrentPanel("MP Setup Screen", 0);
                panel_system.destroyPanel("Join Screen");
                return 1;
            }
            break;
        case 0x17A8:
        case 0x17A9:
        case 0x17AA:
        case 0x17B2:
            if (this->waitingToStart != 0) {
                comm->UnlinkToLevel(5);
                this->waitingToStart = 0;
                rge_base_game->enable_input();
                TEasy_Panel::popupOKDialog(0x25A3, 0, 0x1C2, 100);
                return 1;
            }
            break;
    }
    return TPanel::handle_user_command(cmd, param);
}
