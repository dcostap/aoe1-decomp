// Authentic scr_cj.cpp source-order prefix through TribeJoinScreen::action.
//
// PDB source order and lines:
//   TribeJoinScreen::TribeJoinScreen       62-126
//   TribeJoinScreen::~TribeJoinScreen      131-146
//   TribeJoinScreen::handle_idle            152-181
//   TribeJoinScreen::handle_user_command    187-230
//   TribeJoinScreen::fillList               235-283
//   TribeJoinScreen::action                 289-368
//
// 00491C42 is a padding-only fragment inside the handle_user_command range.
// It has no compiler-facing owner and is not included.
// Flags: config/flags/00491E20_action.rsp (/nologo /c /O2 /Oy /GX).
// /GX is supported by the original EH registration. /G5, /G6, /Zi, and /Zd
// were tested and did not change the handler or FS/ESI unwind frontier.
#include "matching/00491650_TribeJoinScreen.cpp"
#include "matching/00491990_TribeJoinScreen.cpp"
#include "matching/00491A80_handle_idle.cpp"
#include "matching/00491B20_handle_user_command.cpp"
#include "matching/00491C70_fillList.cpp"
#include "scratch/00491E20_action.cpp"
