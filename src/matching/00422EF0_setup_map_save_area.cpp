// VA: 00422EF0 RGE_Base_Game::setup_map_save_area (214 B)
// PDB source: basegame.cpp, lines 6128-6139
// Attempt log:
// - Replaced the prior free-function/shim lift with the natural TDrawArea
//   new-expression, member calls, and ordinary typed delete cleanup. The
//   binary-proven 0x100 size includes TDrawArea's vptr. Exact match.

#include <new.h>

class TDrawSystem;



int RGE_Base_Game::setup_map_save_area()
{
    TDrawArea* area = new TDrawArea("Diamond Map Save Area", 0);
    this->map_save_area = area;

    if (area == 0) {
        return 0;
    }

    if (area->Init(this->draw_system, 0x118, 0x8C, 0, 0) == 0) {
        TDrawArea* to_delete = this->map_save_area;
        if (to_delete != 0) {
            delete to_delete;
        }
        this->map_save_area = 0;
        return 0;
    }

    return 1;
}
