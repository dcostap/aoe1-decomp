// tworld.cpp PDB/address-order exact prefix reconstruction.
//
// This wrapper owns the reviewed normal-owner prefix after 0052DF60. It starts
// at 0052E6B0 and reaches 0052E990. The generated
// destructor at 0052E020 remains owned by 0052E040 and is not duplicated here.
// The padding fragments at 005310DE and 005316BD are not wrapper owners.
// 0052E920 is the reviewed accepted-drift owner between the exact anchors.
// 0052EAC0 is the canonicalized scratch owner.
// 0052ECF0 and 0052EDF0 remain exact. 0052EF30 is behavior-valid scratch
// work with known structural drift and is the current prefix endpoint.
//
// Each included file is the sole compiler-facing owner of its VA. The wrapper
// supplies only the reviewed PDB order and shared canonical declarations.
// It remains an audit TU until its source-module mapping is reviewed.

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
