// Authentic scr_cj.cpp source order.
//
// PDB source order and lines:
//   TribeJoinScreen::TribeJoinScreen       62-126
//   TribeJoinScreen::~TribeJoinScreen      131-146
//   TribeJoinScreen::handle_idle            152-181
//   TribeJoinScreen::handle_user_command    187-230
//   TribeJoinScreen::fillList               235-283
//   TribeJoinScreen::action                 289-368
//   TribeMPCreateDialog::TribeMPCreateDialog 375-412
//   TribeMPCreateDialog::~TribeMPCreateDialog 418-424
//   TribeMPCreateDialog::action              430-513
//
// 00491C42 is a padding-only fragment inside the handle_user_command range.
// It has no compiler-facing owner and is not included.
// The nearby deleting destructors are compiler-generated. The scalar
// destructor at 00491970 and vector destructor at 00492310 are checked as
// generated entries, not included as compiler-facing source owners.
// Flags: config/flags/00491E20_action.rsp (/nologo /c /O2 /Oy /GX).
// /GX is supported by the original EH registration. /G5, /G6, /Zi, and /Zd
// were tested and did not change the handler or FS/ESI unwind frontier.
#define SCR_CJ_GROUPED_TU 1
#include "../include/scr_cj_context.h"
#include "matching/00491650_TribeJoinScreen.cpp"
#include "matching/00491990_TribeJoinScreen.cpp"
#include "matching/00491A80_handle_idle.cpp"
#include "matching/00491B20_handle_user_command.cpp"
#include "matching/00491C70_fillList.cpp"
#include "scratch/00491E20_action.cpp"
#include "accepted_drift/004920C0_TribeMPCreateDialog.cpp"
#include "matching/00492330_TribeMPCreateDialog.cpp"
#include "scratch/004923C0_action.cpp"
#undef SCR_CJ_GROUPED_TU
