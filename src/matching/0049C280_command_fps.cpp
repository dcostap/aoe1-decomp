// 0049C280 TRIBE_Screen_Game::command_fps
// first pass: direct panel virtual call surface and binary-proven screen offsets.

#if !defined(SCR_GAME_TU_CONTEXT)
class RGE_Base_Game {
public:
    char gap_00[0x8E8];
    int do_show_timings;
};
extern RGE_Base_Game* rge_base_game;
extern int show_timing_max;

class TPanel {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void set_active(int active);
};

class TRIBE_Screen_Game {
public:
    char gap_00[0x4C0];
    TPanel* inven_panel;
    char gap_4C4[0x588 - 0x4C4];
    TPanel* fps_panel;

    void command_fps();
};
#endif

void TRIBE_Screen_Game::command_fps() {
    RGE_Base_Game* game = rge_base_game;
    if (game->do_show_timings != 0) {
        if (show_timing_max == 0) {
            show_timing_max = 1;
            return;
        }
        game->do_show_timings = 0;
        this->fps_panel->set_active(0);
        this->inven_panel->set_active(1);
    } else {
        show_timing_max = 0;
        game->do_show_timings = 1;
        this->fps_panel->set_active(1);
        this->inven_panel->set_active(0);
    }
}
