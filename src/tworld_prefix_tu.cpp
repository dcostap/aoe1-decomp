// tworld.cpp PDB/address-order exact prefix reconstruction.
//
// This wrapper owns the largest contiguous all-exact normal block after
// 0052DF60. It starts at 0052E6B0 and ends at 0052E830. The generated
// destructor at 0052E020 remains owned by 0052E040 and is not duplicated here.
// The padding fragments at 005310DE and 005316BD are not wrapper owners.
//
// Each included file is the sole compiler-facing owner of its VA. The wrapper
// supplies only the reviewed PDB order and shared canonical declarations.
// It remains an audit TU until its source-module mapping is reviewed.

#include "matching/0052E6B0_world_init.cpp"
#include "matching/0052E750_init.cpp"
#include "matching/0052E770_base_save.cpp"
#include "matching/0052E790_save.cpp"
#include "matching/0052E830_load_player.cpp"
