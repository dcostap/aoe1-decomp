// 005419E0 init_sounds (159 bytes) — MATCHED
// PDB: World.cpp (RGE_Game_World::init_sounds)
// protected virtual, __thiscall
// FLAGS: /GX (EH frame for new expression)

#include "../../include/world_scenario_context.h"

void RGE_Game_World::init_sounds(int param_1, TSound_Driver* param_2)
{
    rge_read(param_1, &this->sound_num, 2);
    this->sounds = (RGE_Sound**)calloc(this->sound_num, 4);
    for (int i = 0; i < this->sound_num; i++) {
        this->sounds[i] = new RGE_Sound(param_1, this->sound_driver);
    }
}
