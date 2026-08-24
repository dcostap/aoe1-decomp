// Authentic mst_play.cpp owner wrapper in PDB source order.
//
// The module has one RGE_Master_Player declaration surface. The wrapper also
// carries both constructor families used by the master-object classes. The
// /GX flag is required by the two exception-registration owner bodies.
#define MST_PLAY_SHARED_CONTEXT 1
#include "../include/mst_play_context.h"

#include "matching/00460FD0_RGE_Master_Player.cpp"
#include "matching/004610C0_RGE_Master_Player.cpp"
#include "matching/00461150_RGE_Master_Player.cpp"
#include "matching/004611D0_finish_init.cpp"
#include "matching/00461270_load_master_object.cpp"
#include "matching/00461530_create_master_object_space.cpp"
#include "matching/00461560_load_object.cpp"
#include "scratch/00461840_save.cpp"

#undef MST_PLAY_SHARED_CONTEXT
