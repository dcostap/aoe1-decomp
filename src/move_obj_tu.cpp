// Authentic move_obj.cpp owner wrapper.
// PDB order follows the reviewed owners from 0045C450 through 00460F40.
// PDB lines are move_obj.cpp:96-3183.
//
// PREFIX CHECKPOINT: this wrapper compiles with the 0045C450 /GX flag set.
// The candidate-TU checker proves exact grouped output for 0045C450,
// 0045C5C0, 0045C970, and 0045CAA0. It also proves the generated deleting
// destructor at 0045C5A0. All later owners are included in PDB order so the
// module has one authentic compiling source wrapper. Their observed status is
// recorded in the candidate proposal until each owner reaches exact output.
// The canonical moving-object surface is declared once in move_obj_context.h.
// The four grouped exact owners are registered in translation_units.json.

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

// PDB-ordered owners.
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
#include "accepted_drift/0045D150_angle_to_object.cpp"
#include "matching/0045D1F0_turn_towards.cpp"
#include "matching/0045D360_set_angle.cpp"
#include "scratch/0045D3D0_teleport.cpp"
#include "matching/0045D5C0_set_velocity.cpp"
#include "matching/0045D5F0_new_angle.cpp"
#include "matching/0045D610_getPath.cpp"
#include "matching/0045D620_facetToNextWaypoint.cpp"
#include "matching/0045D650_setGoal.cpp"
#include "matching/0045D680_setActionRange.cpp"
#include "matching/0045D690_setTargetID.cpp"
#include "matching/0045D6A0_setTargetRadius.cpp"
#include "matching/0045D6C0_findPath.cpp"
#include "scratch/0045DB90_doMove.cpp"
#include "scratch/0045E970_doTrivialMove.cpp"
#include "matching/0045F7F0_passableTile.cpp"
#include "matching/0045F820_canPath.cpp"
#include "matching/0045F9D0_canPath.cpp"
#include "matching/0045FBC0_canBidirectionPath.cpp"
#include "matching/0045FED0_canPathWithObstructions.cpp"
#include "matching/004600F0_canPathWithAdditionalPassability.cpp"
#include "matching/00460210_findFirstTerrainAlongExceptionPath.cpp"
#include "matching/004603B0_canLinePath.cpp"
#include "matching/00460570_canLinePath.cpp"
#include "matching/00460710_firstTileAlongLine.cpp"
#include "matching/004608D0_maximumSpeed.cpp"
#include "matching/00460900_waitingToMove.cpp"
#include "matching/00460930_setWaitingToMove.cpp"
#include "accepted_drift/00460940_userDefinedWaypoint.cpp"
#include "matching/00460970_addUserDefinedWaypoint.cpp"
#include "matching/00460B20_removeAllUserDefinedWaypoints.cpp"
#include "matching/00460B70_removeUserDefinedWaypoint.cpp"
#include "matching/00460BF0_setFinalUserDefinedWaypoint.cpp"
#include "matching/00460C00_findAvoidancePath.cpp"
#include "matching/00460D30_setInitialPoints.cpp"
#include "matching/00460D60_copy_obj.cpp"
#include "matching/00460DB0_boundAngle.cpp"
#include "matching/00460EB0_rotate.cpp"
#include "accepted_drift/00460F40_get_waypoint_checksum.cpp"

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
