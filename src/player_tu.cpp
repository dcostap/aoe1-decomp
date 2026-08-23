// Authentic player.cpp owner span.
//
// The include order follows the PDB source order, not only numeric address
// order.  The audited constructors remain first.  The destructor, scenario
// serialization, and load owners then provide isolated exact anchors for the
// shared player surface.  The wrapper is intentionally not registered in
// config/translation_units.json yet.
//
// The constructor and load bodies remain the reviewed owners.  Do not move a
// read, allocation, store, publication, or cleanup across a call.  The
// accepted-drift constructor keeps its documented 18-byte scheduling hunk;
// its calls, state publication, exception coverage, and fault order remain
// unchanged.
//
// PDB source order and retained evidence:
//   0046E4B0  player.cpp:91-167   isolated exact load-constructor anchor
//   0046E770  player.cpp:177-274  reviewed constructor drift
//   0046EB00  player.cpp:279-325  isolated exact destructor anchor
//   0046F3A0  player.cpp:734-749  isolated exact scenario-object anchor
//   0046F6B0  player.cpp:855-874  isolated exact scenario-save anchor
//   0046FA60  player.cpp:1020-1072 isolated exact load anchor
//   0046FC40  player.cpp:1077-1106 isolated exact master-object load anchor
//
// The unreviewed scenario_load/scenario_postload owners remain outside this
// span.  Their source files retain sole ownership of their VAs and are not
// replaced by synthetic declarations.

#define PLAYER_GROUPED_TU
#include "../include/player_context.h"

#include "matching/0046E4B0_RGE_Player.cpp"
#include "accepted_drift/0046E770_RGE_Player.cpp"
#include "matching/0046EB00_RGE_Player.cpp"
#include "matching/0046F3A0_make_scenario_obj.cpp"
#include "matching/0046F6B0_scenario_postsave.cpp"
#include "matching/0046FA60_load.cpp"
#include "matching/0046FC40_load_master_object.cpp"

#undef PLAYER_GROUPED_TU
