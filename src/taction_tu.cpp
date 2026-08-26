// Authentic TACTION.cpp recovery wrapper.
//
// PDB source module: C:\\msdev\\work\\age1_x1\\TACTION.cpp
// PDB source order:
//   004D38E0 TRIBE_Action::TRIBE_Action (23-26)
//   004D3980 TRIBE_Action::TRIBE_Action (31-34)
//   004D39E0 TRIBE_Action::setup (38-40)
//   004D3A00 TRIBE_Action::setup (44-46)
//   004D3A10 TRIBE_Action::create_action_list (50-52)
//
// 004D3950 and the 004D3970 destructor body are compiler-generated from the
// virtual RGE_Action base.  They are not source owners in this module packet.
// The module context uses the binary-proven RGE_Action and RGE_Action_List
// layouts, virtual slots, constructor overloads, and member ownership.
//
// Forbidden patterns rejected:
// - no inline assembly, naked functions, or manual vtable writes;
// - no synthetic dummy function or wrapper used to create a match;
// - no fake volatility, register steering, or replacement ABI declarations;
// - no padding-only source owner for a behavioral function.

#include "../include/taction_context.h"

#include "matching/004D38E0_TRIBE_Action.cpp"
#include "matching/004D3980_TRIBE_Action.cpp"
#include "matching/004D39E0_setup.cpp"
#include "matching/004D3A00_setup.cpp"
#include "matching/004D3A10_create_action_list.cpp"
