#include "../../include/tscenaro_context.h"

void rge_write_uncompressed(int file, void* data, int size);

void TRIBE_Scenario_Header::save(int file) {
    RGE_Scenario_Header::save(file);
    rge_write_uncompressed(file, &this->any_sp_victory, 4);
    rge_write_uncompressed(file, &this->active_player_count, 4);
}
