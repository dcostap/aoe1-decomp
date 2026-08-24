// BINARY NOTE: The body calls TribeTacticalAIModule::numberUnitsInGroups(0x66).
#ifndef TAITACMD_SHARED_CONTEXT
#include "../../include/taitacmd_context.h"
#endif

int TribeTacticalAIModule::numberSoldierExplorers()
{
    return this->numberUnitsInGroups(0x66);
}
