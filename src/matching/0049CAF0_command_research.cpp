// VA: 0049CAF0 command_research (160B)
// scr_game.cpp
// Retry 2026-05-19: replace placeholder with natural member-call surface.

struct RGE_Base_Game;
struct TRIBE_Player;
struct TMessagePanel;

extern RGE_Base_Game* rge_base_game;

struct RGE_Base_Game {
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void language(int id, int a, int attr, char* buf, int size);
    int get_paused();
    TRIBE_Player* get_player(int id);
    TRIBE_Player* get_player(int id, short* attr);
};

struct TRIBE_Player {
    unsigned char check_tech_cost();
    unsigned char command_building_make_tech();
};

struct TMessagePanel {
    void show_message(int a, char* msg, int code, int z1, int z2, int z3, int z4);
};

class TRIBE_Screen_Game {
public:
    char gap_000[0x544];
    TMessagePanel* message_panel;
    void command_research(int player_id);
};

void TRIBE_Screen_Game::command_research(int player_id) {
    register TRIBE_Screen_Game* self = this;
    short attr;
    char msg[512];

    if (rge_base_game->get_paused() == 0) {
        TRIBE_Player* player = rge_base_game->get_player(player_id, &attr);
        if (player->check_tech_cost()) {
            rge_base_game->get_player(player_id)->command_building_make_tech();
            return;
        }
        rge_base_game->language(0x67, 1, (int)attr, msg, 0x200);
        self->message_panel->show_message(1, msg, 0x56, 0, 0, 0, 0);
    }
}
