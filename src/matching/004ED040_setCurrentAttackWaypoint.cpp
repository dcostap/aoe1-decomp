// BINARY NOTE: PDB ownership is TacticalAIGroup; the fields are at +0x1D4 and +0x1D5.
#ifndef TAITACMD_SHARED_CONTEXT
#include "../../include/taitacmd_context.h"
#endif

void TacticalAIGroup::setCurrentAttackWaypoint(unsigned char wp)
{
    if (wp < this->numberAttackWaypointsValue)
        this->currentAttackWaypointValue = wp;
}
