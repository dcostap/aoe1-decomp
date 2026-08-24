// Canonical ACT_make.cpp reconstruction wrapper.
//
// Source module: C:\\msdev\\work\\age1_x1\\ACT_make.cpp.
// The PDB owner order is constructor, generated vector-deleting destructor,
// constructor, first_in_stack, set_state, and update.  The compiler-generated
// destructor is emitted from RGE_Action_Make's virtual destructor declaration;
// it has no source owner here.
//
// The four matching owners stay in their PDB positions.  update is the
// accepted-drift owner.  It has the correct frame, CFG, six ordered calls,
// virtual targets, x87 operations, and object effects.  Its remaining mismatch
// is the original split callee-save schedule, which VC5 does not reproduce
// with this authentic module context.  No source-level register steering or
// raw vtable writes are used in the canonical path.
//
// Compile with config/flags/default.rsp (/nologo /c /O2 /Oy).

#include "../include/act_make_context.h"

#include "matching/004049B0_RGE_Action_Make.cpp"
// 004049E0 is the compiler-generated vector-deleting destructor.
#include "matching/00404A10_RGE_Action_Make.cpp"
#include "matching/00404A40_first_in_stack.cpp"
#include "matching/00404A70_set_state.cpp"
#include "accepted_drift/00404A90_update.cpp"
