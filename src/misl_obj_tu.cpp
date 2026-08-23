// Canonical misl_obj.cpp owner sequence through make_object_collision_list.
// cvdump module 147 records these PDB owners in this exact order:
// A740, A800, A870, A8A0, A900, A910, A940, A950, A9E0, AA70, and AB20.
// The padding-only block stays outside this wrapper.
// A7D0 and A7F0 are compiler-generated destructor COMDATs without PDB owners.
// The class destructor emits them. They have no separate source include.
// The shared surface keeps one compiler-facing missile-object declaration.
// This wrapper is intentionally not added to translation_units.json.

#define RGE_MISL_OBJ_SHARED_CONTEXT 1
#include "../include/misl_obj_context.h"

#include "matching/0045A740_RGE_Missile_Object.cpp"
#include "matching/0045A800_RGE_Missile_Object.cpp"
#include "matching/0045A870_setup.cpp"
#include "matching/0045A8A0_setup.cpp"
#include "matching/0045A900_rehook.cpp"
#include "matching/0045A910_save.cpp"
#include "matching/0045A940_update.cpp"
#include "matching/0045A950_init_missile.cpp"
#include "matching/0045A9E0_init_missile.cpp"
#include "matching/0045AA70_missile_move.cpp"
#include "scratch/0045AB20_make_object_collision_list.cpp"

#undef RGE_MISL_OBJ_SHARED_CONTEXT
