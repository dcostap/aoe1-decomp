// VA: 0052E750 TRIBE_World::init(char*, TSound_Driver*, TCommunications_Handler*)
// BINARY NOTE: the direct call target is RGE_Game_World::init with the same
// three-argument surface.  The prior placeholder target_method changed only
// relocation identity.  The canonical base declaration now reports MATCH.

#ifndef TWORLD_PHASE2_CONTEXT
#include "../../include/tworld_prefix_context.h"
#endif

uchar TRIBE_World::init(char* file, TSound_Driver* sound,
                        TCommunications_Handler* communications)
{
    return RGE_Game_World::init(file, sound, communications);
}
