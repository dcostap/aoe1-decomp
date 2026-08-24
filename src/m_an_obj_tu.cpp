// Authentic PDB-ordered owner wrapper for m_an_obj.cpp.
//
// Module: C:\\msdev\\work\\age1_x1\\m_an_obj.cpp
// The owner order follows the line bands in build/tu_plans/m_an_obj_cpp.
// The vector deleting destructor at 0044FA20 is compiler generated and is
// listed in the proposal, not included as a source owner.
//
// Constructors and both factories have original EH frames.  The candidate
// response uses the existing /GX constructor flags.  The remaining owners
// have the ordinary /O2 /Oy context in their isolated sources.
//
// Categories: matching owners are 0044F9C0, 0044FA40, 0044FAB0, 0044FB30,
// 0044FB60, 0044FBA0, 0044FC00, 0044FD40, 0044FD60, and 0044FDF0.
// Scratch owners are 0044FBF0 and 0044FCD0.  Accepted-drift owners are
// 0044FD90 and 0044FDC0.  The 0044FA20 vector deleting destructor is compiler
// generated.  These categories remain unchanged by grouped validation.
//
// The context uses reviewed m_s_obj declarations for the inherited class.
// A shared-header risk is limited to this wrapper and its included owners:
// changing that reviewed base surface can alter all 14 emitted owners.  Do not
// add a dummy owner, inline assembly, fake volatility, or metric-only aliases.

#define RGE_MAN_OBJ_SHARED_CONTEXT 1
#include "../include/m_an_obj_context.h"

#include "matching/0044F9C0_RGE_Master_Animated_Object.cpp"
#include "matching/0044FA40_RGE_Master_Animated_Object.cpp"
#include "matching/0044FAB0_RGE_Master_Animated_Object.cpp"
#include "matching/0044FB30_setup.cpp"
#include "matching/0044FB60_setup.cpp"
#include "matching/0044FBA0_setup.cpp"
#include "matching/0044FBF0_RGE_Master_Animated_Object.cpp"
#include "matching/0044FC00_make_new_obj.cpp"
#include "matching/0044FCD0_make_new_master.cpp"
#include "matching/0044FD40_copy_obj.cpp"
#include "matching/0044FD60_modify.cpp"
#include "matching/0044FD90_modify_delta.cpp"
#include "matching/0044FDC0_modify_percent.cpp"
#include "matching/0044FDF0_save.cpp"

#undef RGE_MAN_OBJ_SHARED_CONTEXT
