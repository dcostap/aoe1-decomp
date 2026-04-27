// attempt 1: fillList with do-while loop

#include <stdio.h>

struct tagRECT;

class TPanel {
public:
    void* vftable;
    char pad[0xF0];

    virtual ~TPanel();
    void set_curr_child(TPanel* child);
    void vfunc_e4(long id);
};

class TTextPanel : public TPanel {
public:
    void empty_list();
    int append_line(char* line, long param);
};

class TEasy_Panel : public TPanel {
public:
    char pad_easy[0x380];
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
};

extern RGE_Base_Game* rge_base_game;

class TCommunications_Handler {
};

extern TCommunications_Handler* comm;

class TCommunications_Sessions {
public:
    TCommunications_Sessions(TCommunications_Handler* handler);
    void Refresh();
    long GetSessionCount();
    long GetSessionMaxPlayers(long index);
    long GetSessionCurrentPlayers(long index);
    char* GetSessionName(long index);
};

extern TCommunications_Sessions* Sess;

void TCommunications_Sessions_ctor(TCommunications_Sessions* this_, TCommunications_Handler* handler);

void* operator_new(unsigned int size);

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

    void fillList();
};

void TribeJoinScreen::fillList() {
    rge_base_game->disable_input();
    this->listFilled = 0;
    this->game_count = 0;
    this->list->vfunc_e4(0x25A9);
    rge_base_game->draw_window();

    if (this->startedSession == 0) {
        TCommunications_Sessions* p = (TCommunications_Sessions*)operator_new(0x457B0);
        if (p != 0) {
            TCommunications_Sessions_ctor(p, comm);
        }
        Sess = p;
        if (Sess == 0) {
            this->list->vfunc_e4(0x25AB);
            return;
        }
        this->startedSession = 1;
    } else {
        Sess->Refresh();
    }

    this->game_count = Sess->GetSessionCount();

    if (this->game_count < 1) {
        this->list->vfunc_e4(0x25AB);
    } else {
        this->list->empty_list();
        int i = 0;
        do {
            long maxPlayers = Sess->GetSessionMaxPlayers(i);
            long curPlayers = Sess->GetSessionCurrentPlayers(i);
            char* name = Sess->GetSessionName(i);
            char szTemp[126];
            sprintf(szTemp, "%s ( %.1d / %.1d )", name, curPlayers, maxPlayers);
            this->list->append_line(szTemp, 0);
            i++;
        } while (i < this->game_count);
        this->set_curr_child(this->list);
    }

    this->listFilled = 1;
}
