// Authentic PDB-ordered owner wrapper for C:\\msdev\\work\\age1_x1\\tworld.cpp.
//
// The module contains 30 normal owners. This wrapper keeps the policy-safe
// shared-context segment in PDB order. Standalone private declaration surfaces
// remain blocked and are listed in the candidate proposal.
// Accepted-drift and scratch owners remain observed. No exact source is tuned
// by this wrapper.
//
// The nearby scalar deleting destructor depends on the blocked destructor owner
// and is recorded as blocked in the proposal.

#include "../include/tworld_prefix_context.h"

#include "matching/0052E6B0_world_init.cpp"
#include "matching/0052E750_init.cpp"
#include "matching/0052E770_base_save.cpp"
#include "matching/0052E790_save.cpp"
#include "matching/0052E830_load_player.cpp"
#include "accepted_drift/0052E920_setup_gaia.cpp"
#include "matching/0052E990_setup_players.cpp"
#include "scratch/0052EAC0_check_destructables.cpp"
#include "matching/0052ECF0_scenario_make_player.cpp"
#include "matching/0052EDF0_load_world.cpp"
#include "scratch/0052EF30_new_game.cpp"
