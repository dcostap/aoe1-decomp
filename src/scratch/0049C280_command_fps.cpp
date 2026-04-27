// 0049C280 command_fps
// 126 bytes, __thiscall, TRIBE_Screen_Game method
// probe 1: toggle do_show_timings, call fps/inven panel vfuncs

class RGE_Base_Game {
public:
    char gap_00[0x8E8];
    unsigned int do_show_timings;
};

extern RGE_Base_Game* rge_base_game;
extern int show_timing_max;

class TPanel {
public:
    char gap_00[0x14];
    void (*vf_14)(int);
};

class TRIBE_Screen_Game {
public:
    TPanel* fps_panel;
    TPanel* inven_panel;

    void command_fps();
};

void TRIBE_Screen_Game::command_fps() {
    if (rge_base_game->do_show_timings == 0) {
        show_timing_max = 0;
        rge_base_game->do_show_timings = 1;
        fps_panel->vf_14(1);
        inven_panel->vf_14(0);
        return;
    }
    if (show_timing_max == 0) {
        show_timing_max = 1;
        return;
    }
    rge_base_game->do_show_timings = 0;
    fps_panel->vf_14(0);
    inven_panel->vf_14(1);
}
