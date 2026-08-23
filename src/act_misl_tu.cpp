// Authentic owner wrapper for C:\\msdev\\work\\age1_x1\\ACT_misl.cpp.
//
// PDB owner order and line bands:
//   00404BB0 RGE_Action_Missile(int, object)       lines 30-38
//   00404C90 RGE_Action_Missile(object, targets)   lines 44-53
//   00404D10 first_in_stack                       lines 58-68
//   00404D50 intercept                            lines 73-86
//   00404DB0 set_state                            lines 91-200
//   004050F0 update                               lines 205-356
//   004054B0 save                                 lines 361-369
//
// 004050D5 is a three-byte padding/data-dispatch neighborhood inside the
// set_state span.  It is not an ordinary source owner and is not included.
// 00404C60/00404C80 are compiler-owned destructor COMDATs without module-local
// source bands.  They are not represented as duplicate body sources here.
//
// Exact sibling anchors are 00404BB0, 00404C90, 00404D10, 00404D50, and
// 004054B0. Fresh wrapper extraction confirms all five anchors. 00404DB0
// remains an unresolved review candidate in its PDB position. 004050F0 is a
// reviewed-drift candidate with preserved behavior and remains in its PDB
// position for the complete declaration and compiler context.
// Registration note: the 00404C90 constructor symbol is
// ??0RGE_Action_Missile@@QAE@PAVRGE_Action_Object@@PAVRGE_Static_Object@@1MMM@Z.
//
// The shared header preserves the canonical RGE_Action_Missile, RGE_Action,
// object, and master-object ownership chain.  It also preserves the proven
// +0x40 missile fields, +0x148/+0x149/+0x150 master fields, and virtual slots
// used by this module.  Keep calls, state publication, size, CFG, and fault
// order in the owner sources.
//
// Evidence-backed module flags: /nologo /c /O2 /Oy /GX.  The two constructors
// at 00404BB0 and 00404C90 carry the original C++ EH setup; /GX is therefore a
// module property, not a target-local code-shape device. The safe registration
// scope is the five exact anchors above, plus 004050F0 only after its reviewed
// drift status is accepted. The integration agent owns manifest changes.

#define ACT_MISL_SHARED_CONTEXT 1
#include "../include/act_misl_context.h"

#include "matching/00404BB0_RGE_Action_Missile.cpp"
#include "matching/00404C90_RGE_Action_Missile.cpp"
#include "matching/00404D10_first_in_stack.cpp"
#include "matching/00404D50_intercept.cpp"
#include "scratch/00404DB0_set_state.cpp"
#include "accepted_drift/004050F0_update.cpp"
#include "matching/004054B0_save.cpp"

#undef ACT_MISL_SHARED_CONTEXT
