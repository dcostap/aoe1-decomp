// 0049BCA0 TRIBE_Screen_Game::command_ai_info
// PDB: scr_game.cpp:4857-4873, 126 bytes
// FLAGS: default
//
// Fixed: each rge_base_game->field store must be in its own block-scoped
// local to force VC5 to reload the global pointer 3 times using `a1`
// (mov eax,[addr32], 5 bytes). Without block-scoped locals, VC5 reuses a
// register for the last store, using `8b 0d` (mov ecx,[addr32], 6 bytes)
// which changes function size and breaks the match.

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
    {
        RGE_Base_Game* g = rge_base_game;
        g->do_show_timings = 0;
    }
    {
        RGE_Base_Game* g = rge_base_game;
        g->do_show_comm = 0;
    }
    {
        RGE_Base_Game* g = rge_base_game;
        g->do_show_ai = 1;
    }
}
