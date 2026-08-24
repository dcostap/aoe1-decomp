// Authentic move_obj.cpp owner wrapper.
// PDB order follows the reviewed owners from 0045C450 through 0045CAA0.
// PDB lines are move_obj.cpp:96-305. The next owner is save at 0045CE00.
//
// PREFIX CHECKPOINT: this wrapper compiles with the 0045C450 /GX flag set.
// The candidate-TU checker proves exact grouped output for 0045C450,
// 0045C5C0, 0045C970, and 0045CAA0. It also proves the generated deleting
// destructor at 0045C5A0. The destructor at 0045C700 and recycle owner at
// 0045C790 retain one wrong direct relocation each. Keep this boundary until
// those declarations are recovered. Later owners remain standalone.
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

// PDB-ordered prefix owners.
#include "matching/0045C450_RGE_Moving_Object.cpp"
#include "matching/0045C5C0_RGE_Moving_Object.cpp"
#include "matching/0045C700_RGE_Moving_Object.cpp"
#include "matching/0045C790_recycle_in_to_game.cpp"
#include "matching/0045C970_setup.cpp"
#include "matching/0045CAA0_setup.cpp"

// Proven PDB-ordered prefix ends at 0045CAA0. Later owners need canonical
// declaration recovery before they can enter this authentic wrapper.

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
