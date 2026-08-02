// TRIBE_Screen_Game::command_score
// VA: 0049C650
// scr_game.cpp
// Attempt log:
// - Canonical fields are world +0x5B4 score_displayed, score_panel[8] +0x58C,
//   text_line_panel +0x50C, and main_view +0x4B8.  The natural counted panel
//   loop and reset_score_display call match through 0049C68E in the best basin.
// - Hoisting one TMessagePanel* line before the score_displayed branch moved
//   the first mismatch from offset 0 to +0x44 and improved positional diff
//   113 -> 100; this is retained as the best source reconstruction.
// - Restoring the period type surfaces (TPanel/TMessagePanel, TRIBE_World,
//   TRIBE_Main_View, TScreenPanel) and naming the +0x18 call set_positioning
//   produced the same best code, but supports the canonical ownership.
// - Direct branch-local panel access, explicit else/fallthrough/two-if/goto
//   forms, defaulted trailing set_positioning arguments, alternate virtual
//   surfaces, and a narrow volatile main_view probe did not improve the best.
// - A focused branch/local variant lab found no 189-byte/6-call candidate:
//   VC5 emits one 142-byte common set_positioning/redraw tail in every basin.
// - Paused unresolved: original retains two duplicated virtual call arms
//   (+0x18 and +0x20), while VC5 tail-merges them; no accepted_drift proposed
//   because the remaining call-count/CFG drift is broad.

class TPanel {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void set_visible(int v); // +0x14
    virtual void set_positioning(int mode, int x, int y, int w, int h,
                                 int a, int b, int c, int d,
                                 TPanel* p1 = 0, TPanel* p2 = 0,
                                 TPanel* p3 = 0, TPanel* p4 = 0); // +0x18
    virtual void v7();
    virtual void set_redraw(int v); // +0x20
};

class TMessagePanel : public TPanel {
};

class RGE_Main_View {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void set_redraw(int v); // +0x20
};

class TRIBE_Main_View : public RGE_Main_View {
};

class RGE_Game_World {
public:
    virtual void v0();
    char gap_04[0x100];
};

class TRIBE_World : public RGE_Game_World {
public:
    char gap_104[0x18];
    unsigned char show_score;
};

class TScreenPanel {
public:
    virtual void v0();
    char gap_04[0x474];
};

class TRIBE_Screen_Game : public TScreenPanel {
public:
    char gap_478[0x40];
    TRIBE_Main_View* main_view;          // +0x4B8
    char gap_4BC[0x50];
    TMessagePanel* text_line_panel; // +0x50C
    char gap_510[0x7C];
    TMessagePanel* score_panel[8];  // +0x58C
    char gap_5AC[0x08];
    TRIBE_World* world;             // +0x5B4

    void reset_score_display();
    void command_score(int a1);
};

void TRIBE_Screen_Game::command_score(int a1)
{
    int count = 8;
    TMessagePanel** p = this->score_panel;

    this->world->show_score = (unsigned char)a1;
    do {
        TMessagePanel* b = *p;
        if (b != 0) {
            b->set_visible(a1);
        }
        ++p;
        --count;
    } while (count != 0);

    if (a1 != 0) {
        this->reset_score_display();
    }

    TMessagePanel* line = this->text_line_panel;
    if (this->world->show_score != 0) {
        line->set_positioning(8, 4, 0, 0xB8, 4, 0, 0, 0x22, 0x22);
        this->main_view->set_redraw(1);
        return;
    }
    line->set_positioning(8, 4, 0, 4, 4, 0, 0, 0x22, 0x22);
    this->main_view->set_redraw(1);
    return;
}
