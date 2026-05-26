// TRIBE_Screen_Game::command_score
// VA: 0049C650
// scr_game.cpp
// Attempts: built natural typed surface: world +0x5B4 show_score byte, eight score_panel pointers at +0x58C, text_line_panel +0x50C, main_view +0x4B8, virtual slots +0x14/+0x18/+0x20.
// Good prologue/loop through reset_score_display matches. Stuck after show_score test: VC5 tail-merges the two set_rect/redraw arms into one common tail with a conditional 0xB8-vs-4 push (144B), while original keeps two fully duplicated call+redraw+epilogue arms (189B).
// Tried explicit if/else returns, switch, two independent ifs, branch-local locals, duplicate helper class/cast, volatile show_score read, and /Ob0,/O1,/Od,/Og- probes. No exact source basin found; no accepted_drift proposed because branch layout/call duplication differs broadly.

struct ScoreButton {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void set_visible(int v); // +0x14
};

struct TextLinePanel {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void set_rect(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m); // +0x18
};

struct TextLinePanel2 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void set_rect(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l, int m); // +0x18
};

struct MainView {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void redraw(int v); // +0x20
};

struct WorldLike {
    char gap_00[0x11C];
    unsigned char show_score;
};

class TRIBE_Screen_Game {
public:
    char gap_00[0x4B8];
    MainView* main_view;          // +0x4B8
    char gap_4BC[0x50];
    TextLinePanel* text_line_panel; // +0x50C
    char gap_510[0x7C];
    ScoreButton* score_panel[8];  // +0x58C
    char gap_5AC[0x08];
    WorldLike* world;             // +0x5B4

    void reset_score_display();
    void command_score(int a1);
};

void TRIBE_Screen_Game::command_score(int a1)
{
    int count = 8;
    ScoreButton** p = this->score_panel;

    this->world->show_score = (unsigned char)a1;
    do {
        ScoreButton* b = *p;
        if (b != 0) {
            b->set_visible(a1);
        }
        ++p;
        --count;
    } while (count != 0);

    if (a1 != 0) {
        this->reset_score_display();
    }

    if (*(volatile unsigned char*)&this->world->show_score != 0) {
        TextLinePanel* line1 = this->text_line_panel;
        line1->set_rect(8, 4, 0, 0xB8, 4, 0, 0, 0x22, 0x22, 0, 0, 0, 0);
        MainView* view1 = this->main_view;
        view1->redraw(1);
        return;
    } else {
        TextLinePanel* line2 = this->text_line_panel;
        line2->set_rect(8, 4, 0, 4, 4, 0, 0, 0x22, 0x22, 0, 0, 0, 0);
        MainView* view2 = this->main_view;
        view2->redraw(1);
        return;
    }
}
