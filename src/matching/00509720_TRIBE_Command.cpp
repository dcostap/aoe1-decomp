// VA: 00509720 TRIBE_Command::TRIBE_Command
// PDB: tcommand.cpp lines 56-57.
// The constructor uses the reviewed RGE_Command base and the natural derived
// vptr initialization. It does not write a vtable pointer by hand.

#include "../tcommand_context.h"

TRIBE_Command::TRIBE_Command(
    TRIBE_World* world,
    TCommunications_Handler* com_hand)
    : RGE_Command(world, com_hand)
{
}
