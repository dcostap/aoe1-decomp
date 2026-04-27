// 0049BCA0 command_ai_info
// 126 bytes, __thiscall, TRIBE_Screen_Game method
// probe 4: best at 126/126, 7.1% diff
// remaining diff: VC5 reuses rge_base_game pointer across 3 stores, original reloads between each pair
// also: VC5 pop esi placement differs, original reloads into ecx for final store
// tried: direct extern globals (112 bytes, smaller), struct access (126/126, 7.1%)
// left in scratch: deep VC5 register allocation/reload basin, core logic exact

class TMessagePanel {
public:
    void remove_message();
};

class RGE_Base_Game {
public:
    char gap_00[0x8E8];
    unsigned int do_show_timings;
    unsigned int do_show_comm;
    unsigned int do_show_ai;
};

extern RGE_Base_Game* rge_base_game;

class TRIBE_Screen_Game {
public:
    char gap_00[0x544];
    TMessagePanel* message_panel;
    TMessagePanel* message_panel2;
    TMessagePanel* message_panel3;
    TMessagePanel* message_panel4;
    TMessagePanel* message_panel5;
    TMessagePanel* message_panel6;

    void command_ai_info();
};

void TRIBE_Screen_Game::command_ai_info() {
    message_panel->remove_message();
    message_panel2->remove_message();
    message_panel3->remove_message();
    message_panel4->remove_message();
    message_panel5->remove_message();
    message_panel6->remove_message();

    if (rge_base_game->do_show_ai != 0) {
        rge_base_game->do_show_ai = 0;
        return;
    }
    rge_base_game->do_show_timings = 0;
    rge_base_game->do_show_comm = 0;
    rge_base_game->do_show_ai = 1;
}
