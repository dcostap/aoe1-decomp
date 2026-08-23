// Authentic victory.cpp context prefix in PDB source-line and address order.
//
// The PDB assigns 00531750 through 00531F30 to victory.cpp lines 28-395.
// These canonical owners share include/victory_context.h and retain their
// individual source bodies.  00531F90 remains outside this prefix because its
// current source has a different switch-call context.
//
// Later repaired probes 00533180 and 00533240 also use this header, but the
// owners between 00531F90 and 00533180 remain outside the prefix.  Do not skip
// those PDB owners or append the later probes to this wrapper.
//
// 00531F71 is a reviewed padding-only fragment and is not an owner.
// Generated, asm, and parent-fragment entries are not included.
//
// This is a safe expanded context-prefix proposal.  Do not map later
// victory.cpp owners to this wrapper until their declarations use this context.

#include "../include/victory_context.h"

#include "scratch/00531750_RGE_Victory_Conditions.cpp"
#include "matching/00531AF0_RGE_Victory_Conditions.cpp"
#include "matching/00531B20_RGE_Victory_Conditions.cpp"
#include "scratch/00531B70_save.cpp"
#include "accepted_drift/00531DB0_check_for_victory.cpp"
#include "matching/00531E90_update.cpp"
#include "matching/00531EF0_update_for_object.cpp"
#include "matching/00531F30_handle_point_condition.cpp"
