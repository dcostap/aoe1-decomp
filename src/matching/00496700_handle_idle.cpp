// VA: 00496700 TRIBE_Screen_Game::handle_idle (scr_game.cpp)
//
// Baseline reconstruction: the executable shows the original idle tracing,
// input-enable guard, mode-gated animation/terrain work, and a final base
// panel idle call.  The local base/layout stubs retain the proven field at
// TRIBE_Screen_Game+0x4B8 and the RGE_Base_Game fields at +0x1B0/+0x1D8.
//
// Attempt log:
// - baseline: natural same-TU source shape with named panel/game ownership;
//   standalone compile/check is an exact 246-byte MATCH.
// - TU context gate: proved PDB module is scr_game.cpp, with source lines
//   1527-1579.  The owner is TRIBE_Screen_Game.  Address anchors are the
//   color_log calls at 0049670A, 00496727, 00496740, and 004967E9, the
//   currentPanel/get_focus pair at 00496768/00496777, and the TPanel base
//   idle call at 004967DC.  The wrapper address order is proved by the
//   neighboring 00496550, 00496800, and later scr_game.cpp owners.
// - grouped candidate check: the authentic scr_game_tu.cpp build differs by
//   one byte, while the owner symbol, size, calls, relocations, and boundary
//   remain correct.  The shared context is the unresolved blocker.
// - exact reduction: initializing result at declaration and scoping result
//   at the final call both emit identical bytes, so neither is required.
//   Reordering equivalent mode tests changes two bytes and loses exactness.
//   The clean function-wide declaration and original mode order are restored.

#if !defined(SCR_GAME_TU_CONTEXT)
extern "C" void __cdecl color_log(unsigned char a, unsigned char b,
                                   unsigned char c);

class TPanel {
public:
    virtual ~TPanel();

    int get_focus();
    long handle_idle();
};

class TScreenPanel : public TPanel {
public:
    char gap_04[0x474];
};

class TPanelSystem {
public:
    char gap_00[0x0C];

    TPanel* currentPanel();
};

extern TPanelSystem panel_system;

class RGE_Base_Game {
public:
    char gap_00[0x1B0];
    int prog_mode;
    char gap_1B4[0x24];
    int input_enabled;

    void enable_input();
};

extern RGE_Base_Game* rge_base_game;

class TRIBE_Screen_Game : public TScreenPanel {
public:
    char gap_478[0x40];
    TPanel* main_view;

    void handle_anim_pal();
    void handle_terrain_sound();
    void handle_mouse_pointing_at();
    long handle_idle();
};
#endif

long TRIBE_Screen_Game::handle_idle() {
    long result;

    color_log(0x5F, 0x5F, 5);

    if (rge_base_game->input_enabled == 0) {
        color_log(0x5F, 0x4C, 5);
        rge_base_game->enable_input();
    }

    color_log(0x5F, 0x16, 5);
    int mode = rge_base_game->prog_mode;

    if (mode == 4 || mode == 6 || mode == 5) {
        if (panel_system.currentPanel() == this &&
            this->main_view->get_focus() != 0) {
            color_log(0x5F, 0x45, 5);
            this->handle_anim_pal();
        }
    }

    if (mode == 4 || mode == 6) {
        color_log(0x5F, 0x32, 5);
        this->handle_terrain_sound();
        color_log(0x5F, 0xBA, 5);
        this->handle_mouse_pointing_at();
    }

    color_log(0x5F, 0x24, 5);
    result = TPanel::handle_idle();
    color_log(0x5F, 0x5F, 5);
    return result;
}
