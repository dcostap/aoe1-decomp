// Authentic owner wrapper for the PDB source module tm_b_obj.cpp.
//
// Owner includes follow the PDB line bands 30 through 266.  The scalar
// deleting destructor at 0050E0A0 is compiler generated and is listed in the
// candidate proposal, not as a source owner.  Scratch owners remain included
// so this file represents the complete reachable module source.
//
// Constructors and factories use the module's observed /GX context.  The
// candidate uses /nologo /c /O2 /Oy /GX.

#define TM_B_OBJ_SHARED_CONTEXT 1
#include "../include/tm_b_obj_context.h"

#include "matching/0050E040_TRIBE_Master_Building_Object.cpp"
#include "matching/0050E0C0_TRIBE_Master_Building_Object.cpp"
#include "matching/0050E130_TRIBE_Master_Building_Object.cpp"
#include "matching/0050E1B0_setup.cpp"
#include "matching/0050E250_setup.cpp"
#include "matching/0050E360_setup.cpp"
#include "matching/0050E430_TRIBE_Master_Building_Object.cpp"
#include "matching/0050E440_copy_obj.cpp"
#include "matching/0050E4D0_modify.cpp"
#include "matching/0050E500_modify_delta.cpp"
#include "matching/0050E530_modify_percent.cpp"
#include "matching/0050E550_save.cpp"
#include "matching/0050E630_make_new_obj.cpp"
#include "matching/0050E6B0_make_new_obj.cpp"
#include "matching/0050E730_make_new_master.cpp"
#include "scratch/0050E7A0_draw.cpp"
#include "matching/0050E950_alignment.cpp"

#undef TM_B_OBJ_SHARED_CONTEXT
