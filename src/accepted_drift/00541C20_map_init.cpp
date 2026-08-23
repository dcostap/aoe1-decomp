// VA: 00541C20 RGE_Game_World::map_init
// PDB: World.cpp lines 831-833 (97 bytes, 30 asm lines)
// FLAGS: /GX required for original SEH frame — use config/flags/00541C20_map_init.rsp
// No inline asm/hacks.
// === ACCEPTED_DRIFT ===
// Same behavior-neutral VC5 no-op phi-merge artifact as accepted World/tworld init helpers:
// first 76 bytes exact, then dead `test eax,eax; jne +0` shifts final epilogue into padding.
// Full canonical World.cpp context emits the same reviewed drift bytes.

#include "../../include/world_scenario_context.h"

void RGE_Game_World::map_init(int param_1, TSound_Driver* param_2) {
    RGE_Map* new_map = new RGE_Map(param_1, this->sounds, 1);
    if (new_map == 0) {
        new_map = 0;
    }
    this->map = new_map;
}
