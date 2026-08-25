// VA: 0052E790 TRIBE_World::save (145 B)
// PDB source: tworld.cpp

#ifndef TWORLD_PHASE2_CONTEXT
#include "../../include/tworld_prefix_context.h"
#endif

void TRIBE_World::save(int fd)
{
    RGE_Game_World::save(fd);
    rge_write(fd, &victory_type, 4);
    rge_write(fd, &artifact_count, 4);
    rge_write(fd, &ruin_count, 4);
    rge_write(fd, &countdown_victory, 1);
    rge_write(fd, &countdown_clock, 4);
    rge_write(fd, &score_displayed, 1);
    rge_write(fd, &controllingComputerPlayer, 1);
}
