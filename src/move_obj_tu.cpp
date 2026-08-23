// Authentic move_obj.cpp owner wrapper.
// PDB order follows the reviewed anchors and priority owners from 0045C450
// through 0045E970. Other module owners remain standalone until review.
// The canonical moving-object surface is declared once in move_obj_context.h.
// This wrapper is intentionally not added to translation_units.json.

#define MOVE_OBJ_CANONICAL_TU 1
#include "../include/move_obj_context.h"

#define DAT_00570b40 DAT_00570B40
#define DAT_00570b48 DAT_00570B48
#define DAT_00570b4c DAT_00570B4C
#define DAT_00570b50 DAT_00570B50
#define DAT_00570b60 DAT_00570B60
#define DAT_00570b64 DAT_00570B64
#define DAT_00570b68 DAT_00570B68
#define DAT_00570b70 DAT_00570B70
#define DAT_00570b78 DAT_00570B78
#define DAT_00570b80 DAT_00570B80
#define DAT_00570b90 DAT_00570B90
#define DAT_00570b98 DAT_00570B98
#define DAT_00570ba0 DAT_00570BA0
#define DAT_00570ba8 DAT_00570BA8
#define DAT_00570bb0 DAT_00570BB0
#define DAT_00570bb8 DAT_00570BB8
#define DAT_00570bc0 DAT_00570BC0
#define DAT_00570bc8 DAT_00570BC8
#define DAT_00570bd0 DAT_00570BD0
#define DAT_00570be0 DAT_00570BE0
#define DAT_00570bf0 DAT_00570BF0

// Exact anchors.
#include "matching/0045C450_RGE_Moving_Object.cpp"
#include "matching/0045C5C0_RGE_Moving_Object.cpp"
#include "matching/0045C700_RGE_Moving_Object.cpp"
#include "matching/0045C790_recycle_in_to_game.cpp"
#include "matching/0045C970_setup.cpp"
#include "matching/0045CAA0_setup.cpp"
#include "matching/0045CE00_save.cpp"
#include "matching/0045D080_new_sprite.cpp"
#include "matching/0045D0B0_spawn_death_obj.cpp"
#include "matching/0045D0E0_transform.cpp"
#include "matching/0045D120_is_moving.cpp"
#include "matching/0045D140_stop_moving.cpp"
#include "matching/0045D1F0_turn_towards.cpp"
#include "matching/0045D360_set_angle.cpp"
#include "matching/0045D5C0_set_velocity.cpp"
#include "matching/0045D5F0_new_angle.cpp"
#include "matching/0045D610_getPath.cpp"
#include "matching/0045D620_facetToNextWaypoint.cpp"
#include "matching/0045D650_setGoal.cpp"
#include "matching/0045D680_setActionRange.cpp"
#include "matching/0045D690_setTargetID.cpp"
#include "matching/0045D6A0_setTargetRadius.cpp"

// Priority behavior owners.
#include "scratch/0045D3D0_teleport.cpp"
#include "matching/0045D6C0_findPath.cpp"
#include "scratch/0045DB90_doMove.cpp"
#include "scratch/0045E970_doTrivialMove.cpp"

#undef DAT_00570b40
#undef DAT_00570b48
#undef DAT_00570b4c
#undef DAT_00570b50
#undef DAT_00570b60
#undef DAT_00570b64
#undef DAT_00570b68
#undef DAT_00570b70
#undef DAT_00570b78
#undef DAT_00570b80
#undef DAT_00570b90
#undef DAT_00570b98
#undef DAT_00570ba0
#undef DAT_00570ba8
#undef DAT_00570bb0
#undef DAT_00570bb8
#undef DAT_00570bc0
#undef DAT_00570bc8
#undef DAT_00570bd0
#undef DAT_00570be0
#undef DAT_00570bf0
#undef MOVE_OBJ_CANONICAL_TU
