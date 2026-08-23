#include "../../include/tscenaro_context.h"

extern void rge_read_uncompressed(int, void*, int);

TRIBE_Scenario_Header::TRIBE_Scenario_Header(int param_1)
    : RGE_Scenario_Header((RGE_Scenario*)param_1) {
    any_sp_victory = 0;
    active_player_count = 0;
    if (error_code == 0) {
        rge_read_uncompressed(param_1, &any_sp_victory, 4);
        rge_read_uncompressed(param_1, &active_player_count, 4);
    }
}
