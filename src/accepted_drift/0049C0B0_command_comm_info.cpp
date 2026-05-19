// VA: 0049C0B0 command_comm_info (165B)
// scr_game.cpp
// Fresh 2026-05-19: implement real command_comm_info panel toggle logic.
// try 1: natural panel/global logic: exact size, only broad diffs from set_visible vslot at +0x10 and final global reload register choices.
// try 2: add missing vf10 so set_visible is +0x14: reduced to 30/165 positional.
// try 3: force final else-branch global reloads through a local `game`: reduced to 4/165 positional.
// try 4: first-call temp local; no change.
// try 5: second-call temp local; no change.
// try 6: int-return virtual surface; no change, rolled back.
// Remaining drift is only vtable scratch register selection for two adjacent calls: rebuilt uses EDX then EAX;
// original uses EAX then EDX. Same ECX this pointers, pushed args (0/1), vslot +0x14, calls, and all later bytes exact.

class TPanel {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void set_visible(int visible); // +0x14
};

class TMessagePanel {
public:
    void remove_message();
};

class RGE_Base_Game {
public:
    char gap_000[0x8e8];
    int do_show_timings;
    int do_show_comm;
    int do_show_ai;
};

class TRIBE_Screen_Game {
public:
    char gap_000[0x4c0];
    TPanel* inven_panel;     // +0x4c0
    char gap_4c4[0x80];
    TMessagePanel* message_panel1; // +0x544
    TMessagePanel* message_panel2; // +0x548
    TMessagePanel* message_panel3; // +0x54c
    TMessagePanel* message_panel4; // +0x550
    TMessagePanel* message_panel5; // +0x554
    TMessagePanel* message_panel6; // +0x558
    char gap_55c[0x2c];
    TPanel* fps_panel;       // +0x588
    void command_comm_info();
};

#define rge_base_game (*(RGE_Base_Game**)0x62C574)

void TRIBE_Screen_Game::command_comm_info() {
    rge_base_game->do_show_timings = 0;
    this->fps_panel->set_visible(0);
    this->inven_panel->set_visible(1);
    this->message_panel1->remove_message();
    this->message_panel2->remove_message();
    this->message_panel3->remove_message();
    this->message_panel4->remove_message();
    this->message_panel5->remove_message();
    this->message_panel6->remove_message();
    if (rge_base_game->do_show_comm != 0) {
        rge_base_game->do_show_comm = 0;
    }
    else {
        RGE_Base_Game* game;
        rge_base_game->do_show_timings = 0;
        game = rge_base_game;
        game->do_show_ai = 0;
        game = rge_base_game;
        game->do_show_comm = 1;
    }
}
