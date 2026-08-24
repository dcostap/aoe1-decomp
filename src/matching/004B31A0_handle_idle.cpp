// Attempt log:
// - The standalone owner already matched with input_enabled at +0x1D8.
// - The authentic TU context also exposes draw_area, so its provisional
//   +0x50 member placed this access in the wrong field. A narrow local view
//   for the proven +0x1D8 access restores the complete TU match.

#ifndef SCR_SEDM_TU
class RGE_Base_Game {
public:
    char gap_0[0x1D8];
    int input_enabled;
    void enable_input();
};

extern RGE_Base_Game* rge_base_game;

class TPanel {
public:
    virtual long handle_idle();
};

class TRIBE_Screen_Sed_Menu : public TPanel {
public:
    long handle_idle();
};
#else
// BINARY NOTE: this module's shared game declaration exposes draw_area, but
// the shipped input_enabled field is at +0x1D8. Keep this one proven access
// local instead of changing the shared TU context header.
class RGE_Base_Game_Input_View {
public:
    char gap_0[0x1D8];
    int input_enabled;
};
#endif

long TRIBE_Screen_Sed_Menu::handle_idle() {
#ifdef SCR_SEDM_TU
    RGE_Base_Game_Input_View* game = (RGE_Base_Game_Input_View*)rge_base_game;
    if (!game->input_enabled)
#else
    if (!rge_base_game->input_enabled)
#endif
        rge_base_game->enable_input();
    return TPanel::handle_idle();
}
