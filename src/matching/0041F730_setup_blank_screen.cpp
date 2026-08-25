// VA: 0041F730 RGE_Base_Game::setup_blank_screen (196 B)
// PDB source: basegame.cpp, lines 2737-2749
// Attempt log:
// - Baseline: free-function shims compiled with the right call count but lost
//   member-call conventions, the IAT call, and the /GX new-expression frame.
// - Reconstructed the natural new TScreenPanel/member-call source with the
//   panel-system object, set_render_all member, and SendMessageA IAT surface;
//   exact match.
// - Restored the proven TPanel -> TEasy_Panel -> TScreenPanel inheritance and
//   0xF4/0x478 sizes; unchanged exact match.
// - Removed unnecessary char* casts from the old-style string arguments;
//   unchanged exact match.

#include <new.h>

class TDrawArea;
class TPanel;






extern TPanelSystem panel_system;

int RGE_Base_Game::setup_blank_screen()
{
    TScreenPanel* panel;

    panel = new TScreenPanel("Blank Screen");
    if (panel == 0)
        return 0;

    if (panel->setup(this->draw_area, 0, -1, 0) == 0)
        return 0;

    panel_system.setCurrentPanel("Blank Screen", 0);
    this->set_render_all();
    SendMessageA(this->prog_window, 0x0F, 0, 0);
    return 1;
}
