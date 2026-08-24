// Authentic Dlg_msg.cpp translation-unit wrapper.
//
// PDB module: C:\\msdev\\work\\age1_x1\\Dlg_msg.cpp.
// Owner order follows the source line bands and shipped address sequence:
//   0043FC70 TMessageDialog::TMessageDialog  lines 43-48  accepted_drift
//   0043FCB0 scalar deleting destructor      compiler_generated
//   0043FCD0 TMessageDialog::~TMessageDialog lines 54-64  matching
//   0043FD50 TMessageDialog::setup          lines 71-165 accepted_drift
//   0043FFF0 TMessageDialog::setup          lines 172-176 matching
//   00440070 TMessageDialog::action         lines 182-203 matching
//   00440100 TMessageDialog::key_down_action lines 209-215 matching
//   00440110 TMessageDialog::handle_idle    lines 222-226 matching
//
// 0043FCB0 is compiler-generated. It has no standalone source owner and is
// emitted from the virtual destructor declaration. The two accepted-drift
// owners remain accepted drift. The five matching owners remain matching;
// this wrapper does not promote them or retune their function bodies.
//
// The destructor's original EH frame requires the reviewed /GX response file:
// config/flags/0043FCD0_TMessageDialog.rsp (/nologo /c /O2 /Oy /GX).

#define DLG_MSG_CANONICAL_TU 1
#include "../include/dlg_msg_context.h"

#include "accepted_drift/0043FC70_TMessageDialog.cpp"
// 0043FCB0 is the compiler-generated scalar deleting destructor.
#include "matching/0043FCD0_TMessageDialog.cpp"
#include "accepted_drift/0043FD50_setup.cpp"
#include "matching/0043FFF0_setup.cpp"
#include "matching/00440070_action.cpp"
#include "matching/00440100_key_down_action.cpp"
#include "matching/00440110_handle_idle.cpp"

#undef DLG_MSG_CANONICAL_TU
