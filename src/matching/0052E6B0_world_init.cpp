// VA: 0052E6B0 TRIBE_World::world_init
// PDB source: tworld.cpp
// Attempt log:
// try 1: natural member implementation with base world_init and TRIBE_Tech allocation.

#ifndef TWORLD_PHASE2_CONTEXT
#include "../../include/tworld_prefix_context.h"
#endif

void TRIBE_World::world_init(int param_1, TSound_Driver* sound, TCommunications_Handler* comm)
{
    RGE_Game_World::world_init(param_1, sound, comm);

    TRIBE_Tech* new_tech = new TRIBE_Tech(param_1, this);
    this->tech = new_tech;
    this->victory_type = 0;
    this->artifact_count = 0;
    this->ruin_count = 0;
    this->countdown_victory = 0;
    this->countdown_clock = 0;
    this->score_displayed = 0;
}
