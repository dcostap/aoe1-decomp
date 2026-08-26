#include "../../include/scr_cj_context.h"

// attempt 1: natural fillList shape; matched field offsets but used direct nonvirtual label calls and named sprintf temps
// attempt 2: model panel vtable slot e4 manually, real-size TCommunications_Sessions new, and inline sprintf argument calls to avoid EBX/EBP liveness

/* Historical ABI scaffold retained outside the compiler-facing source.
#if 0
#include <stdio.h>
class TPanel {
public:
    char pad[0xF4];

    void set_curr_child(TPanel* child);
    virtual void vf00();
    virtual void vf01();
    virtual void vf02();
    virtual void vf03();
    virtual void vf04();
    virtual void vf05();
    virtual void vf06();
    virtual void vf07();
    virtual void vf08();
    virtual void vf09();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void set_string_id(long id);
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
    char data[0x457B0];
    TCommunications_Sessions(TCommunications_Handler* handler);
    void Refresh();
    long GetSessionCount();
    long GetSessionMaxPlayers(long index);
    long GetSessionCurrentPlayers(long index);
    char* GetSessionName(long index);
};

extern TCommunications_Sessions* Sess;

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
#endif
*/

void TribeJoinScreen::fillList() {
    char szTemp[126];

    rge_base_game->disable_input();
    this->listFilled = 0;
    this->game_count = 0;
    this->list->set_string(0x25A9);
    rge_base_game->draw_window();

    if (this->startedSession == 0) {
        Sess = new TCommunications_Sessions(comm);
        if (Sess == 0) {
            this->list->set_string(0x25AB);
            return;
        }
        this->startedSession = 1;
    } else {
        Sess->Refresh();
    }

    this->game_count = Sess->GetSessionCount();

    if (this->game_count > 0) {
        this->list->empty_list();
        int i = 0;
        if (i < this->game_count) {
            do {
                sprintf(szTemp, "%s ( %.1d / %.1d )",
                    Sess->GetSessionName(i),
                    Sess->GetSessionCurrentPlayers(i),
                    Sess->GetSessionMaxPlayers(i));
                this->list->append_line(szTemp, 0);
                i++;
            } while (i < this->game_count);
        }
        this->set_curr_child(this->list);
    } else {
        this->list->set_string(0x25AB);
    }

    this->listFilled = 1;
}
