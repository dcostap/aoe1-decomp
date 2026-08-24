// Authentic PDB-ordered wrapper for C:\\msdev\\work\\age1_x1\\tcommand.cpp.
//
// The PDB owner order runs from 00509720 through 0050B3E0. The reviewed
// tcommand context can compile the nine later command packet owners below.
// Earlier owners still carry incompatible standalone class surfaces. They stay
// blocked instead of using aliases, namespaces, dummy bodies, or manual
// vtables.
//
// The compiler-generated vector deleting destructor at 00509740 has no source
// include. Accepted-drift and scratch owners remain observations in the
// proposal. This wrapper does not reopen or promote them.

#include "../include/tcommand_context.h"

// PDB order: lines 1396-1716.
#include "matching/0050AF30_command_quick_build.cpp"
#include "matching/0050AF80_command_shared_los.cpp"
#include "matching/0050AFD0_command_cancel_build.cpp"
#include "matching/0050B020_command_attack_ground.cpp"
#include "matching/0050B0D0_command_cheat.cpp"
#include "accepted_drift/0050B130_command_give_attribute.cpp"
#include "matching/0050B190_command_trade_attribute.cpp"
#include "matching/0050B230_command_trade_attribute.cpp"
#include "matching/0050B290_command_repair.cpp"
