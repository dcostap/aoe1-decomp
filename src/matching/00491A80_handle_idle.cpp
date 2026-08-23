#include "../../include/scr_cj_context.h"

#if 0
struct tagRECT;

class TPanel {
public:
    void* vftable;
    char pad[0xF0];

    virtual ~TPanel();
    long handle_idle();
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

unsigned long debug_timeGetTime(const char* file, int line);

class TribeJoinScreen : public TScreenPanel {
public:
    int startedSession;
    int listFilled;
    void* title;
    void* listTitle;
    void* list;
    void* scrollbar;
    void* joinButton;
    void* createButton;
    void* cancelButton;
    void* refreshButton;
    void* close_button;
    int game_count;
    int waitingToStart;
    unsigned long joinTime;

    long handle_idle();
};
#endif

long TribeJoinScreen::handle_idle() {
    if (this->waitingToStart == 0) {
        if ((this->listFilled != 0) && (rge_base_game->input_enabled == 0)) {
            rge_base_game->enable_input();
        }
        if (this->waitingToStart == 0) {
            return TPanel::handle_idle();
        }
    }
    unsigned long now = debug_timeGetTime("scr_cj.cpp", 0xAA);
    if (10000 < now - this->joinTime) {
        comm->UnlinkToLevel(5);
        this->waitingToStart = 0;
        rge_base_game->enable_input();
        TEasy_Panel::popupOKDialog(0x25A3, 0, 0x1C2, 100);
        return 1;
    }
    return TPanel::handle_idle();
}
