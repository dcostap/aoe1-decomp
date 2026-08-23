// BINARY NOTE: this PDB owner is TRIBE_Screen_Info.  It calls the same-class
// close_screen method and does not belong to Pnl_ScenarioObjectives.
#include "../../include/scr_info_context.h"

long TRIBE_Screen_Info::mouse_left_down_action(long x, long y, int flags,
                                               int extra)
{
    close_screen();
    return 0;
}
