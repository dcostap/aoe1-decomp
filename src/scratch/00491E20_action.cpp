// attempt 1: TribeJoinScreen::action - large branch-heavy function, likely won't match on first try
// This has 15+ branches, operator_new calls, sprintf, and converging control flow
// Leaving in scratch as a reference; skipping for now due to complexity

#include <stdio.h>

struct tagRECT;

class TPanel {
public:
    void* vftable;
    char pad[0xF0];

    virtual ~TPanel();
    long action(TPanel* src, long cmd, unsigned long p3, unsigned long p4);
    void set_curr_child(TPanel* child);
    void set_tab_order(TPanel** list, long count);
    int get_string(long id, char* buf, long size);
    void vfunc_b4(TPanel* target, long p2, long p3, long p4);
};

class TTextPanel : public TPanel {
public:
    int currentLineNumber();
    char* currentLine();
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
    void disable_input();
    void enable_input();
    void draw_window();
    void close();
};

extern RGE_Base_Game* rge_base_game;

class TCommunications_Handler {
public:
    long JoinMultiplayerGame(void* guid);
    void UnlinkToLevel(int param);
};

extern TCommunications_Handler* comm;

class TCommunications_Sessions {
public:
    void* GetSessionGUID(long index);
};

extern TCommunications_Sessions* Sess;

class TPanelSystem {
public:
    int setCurrentPanel(char* name, long param);
    int destroyPanel(char* name);
};

extern TPanelSystem panel_system;

unsigned long debug_timeGetTime(const char* file, int line);
void* operator_new(unsigned int size);
void TribeMPStartupScreen_ctor(void* ptr);
void TribeMPCreateDialog_ctor(void* ptr, TPanel* parent);
void TribeJoinScreen_fillList(void* self);

class TribeJoinScreen : public TScreenPanel {
public:
    int startedSession;
    int listFilled;
    TPanel* title;
    TPanel* listTitle;
    TTextPanel* list;
    TPanel* scrollbar;
    TPanel* joinButton;
    TPanel* createButton;
    TPanel* cancelButton;
    TPanel* refreshButton;
    TPanel* close_button;
    int game_count;
    int waitingToStart;
    unsigned long joinTime;

    long action(TPanel* src, long cmd, unsigned long p3, unsigned long p4);
    void fillList();
};

long TribeJoinScreen::action(TPanel* src, long cmd, unsigned long p3, unsigned long p4) {
    if (src == 0) {
        return TEasy_Panel::action(src, cmd, p3, p4);
    }
    if (src == this->list) {
        if (cmd == 3 && this->game_count > 0) {
            this->vfunc_b4(this->joinButton, 1, 0, 0);
            return 1;
        }
    } else if (src == this->joinButton) {
        if (cmd == 1) {
            if (this->game_count < 1) {
                TEasy_Panel::popupOKDialog(0x25A4, 0, 0x1C2, 100);
                return 1;
            }
            int line = this->list->currentLineNumber();
            void* guid = Sess->GetSessionGUID(line);
            int result = comm->JoinMultiplayerGame(guid);
            if (result == 0) {
                char temp[256];
                char string[256];
                this->get_string(0x25A3, temp + 4, 0x100);
                char* lineStr = this->list->currentLine();
                sprintf(string + 4, temp + 4, lineStr);
                TEasy_Panel::popupOKDialog(string + 4, 0, 0x1C2, 100);
                return 1;
            }
            int line = this->list->currentLineNumber();
            void* guid = Sess->GetSessionGUID(line);
            int result = comm->JoinMultiplayerGame(guid);
            if (result == 0) {
                char temp[256];
                char string[256];
                this->get_string(0x25A3, temp + 4, 0x100);
                char* lineStr = this->list->currentLine();
                sprintf(string + 4, temp + 4, lineStr);
                TEasy_Panel::popupOKDialog(string + 4, 0, 0x1C2, 100);
                return 1;
            }
            rge_base_game->disable_input();
            this->waitingToStart = 1;
            this->joinTime = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\scr_cj.cpp", 0x140);
            return 1;
        }
    } else if (src == this->cancelButton) {
        if (cmd == 1) {
            rge_base_game->disable_input();
            comm->UnlinkToLevel(2);
            void* p = operator_new(0x6A0);
            if (p != 0) {
                TribeMPStartupScreen_ctor(p);
            }
            panel_system.setCurrentPanel("MP Startup Screen", 0);
            panel_system.destroyPanel("Join Screen");
            return 1;
        }
    } else if (src == this->createButton && cmd == 1) {
        void* p = operator_new(0x4A4);
        if (p != 0) {
            TribeMPCreateDialog_ctor(p, this);
            return 1;
        }
    } else if (src == this->refreshButton) {
        if (cmd == 1) {
            this->fillList();
            return 1;
        }
    } else {
        if (src != this->close_button || cmd != 1) {
            return TEasy_Panel::action(src, cmd, p3, p4);
        }
        rge_base_game->close();
        return 1;
    }
    return 1;
}
