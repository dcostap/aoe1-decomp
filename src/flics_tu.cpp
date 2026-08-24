// Authentic owner wrapper for C:\\msdev\\work\\age1_x1\\flics.cpp.
//
// Translation-unit context gate evidence:
//   PDB module: flics.cpp, source path C:\\msdev\\work\\age1_x1\\flics.cpp.
//   PDB owner order and source bands:
//     00449B30 RGE_Flic_Player::RGE_Flic_Player 21-50
//     00449BE0 RGE_Flic_Player::RGE_Flic_Player 54-70
//     00449C40 RGE_Flic_Player::~RGE_Flic_Player 74-77
//     00449C50 RGE_Flic_Player::palette 81-171
//     00449DF0 RGE_Flic_Player::resolution 175-180
//     00449E00 RGE_Flic_Player::time_delay 184-186
//     00449E10 RGE_Flic_Player::frames 190-192
//     00449E20 RGE_Flic_Player::start 196-212
//     00449E80 RGE_Flic_Player::reset 216-218
//     00449E90 RGE_Flic_Player::draw 222-345
//     0044A090 RGE_Flic_Player::literal 349-361
//     0044A100 RGE_Flic_Player::delta_flc 365-441
//     0044A2A0 RGE_Flic_Player::delta_fli 445-488
//     0044A390 RGE_Flic_Player::black 492-500
//     0044A3E0 RGE_Flic_Player::byte_run 504-541
//
// The owner sequence follows PDB source-line order.  The same class surface,
// FLIC record layouts, TDrawArea layout, CRT declarations, and private helper
// ownership are shared by every included owner.  0044A05D is a reviewed
// padding-only boundary, not a compiler-facing function owner.
//
// This wrapper is for authentic TU compilation and proposal validation only.
// Exact tuning stops after the first grouped compile.

#define FLICS_SHARED_CONTEXT 1
#include "../include/flics_context.h"

#include "matching/00449B30_RGE_Flic_Player.cpp"
#include "matching/00449BE0_RGE_Flic_Player.cpp"
#include "matching/00449C40_RGE_Flic_Player.cpp"
#include "scratch/00449C50_palette.cpp"
#include "matching/00449DF0_resolution.cpp"
#include "matching/00449E00_time_delay.cpp"
#include "matching/00449E10_frames.cpp"
#include "matching/00449E20_start.cpp"
#include "matching/00449E80_reset.cpp"
#include "matching/00449E90_draw.cpp"
#include "matching/0044A090_literal.cpp"
#include "scratch/0044A100_delta_flc.cpp"
#include "matching/0044A2A0_delta_fli.cpp"
#include "matching/0044A390_black.cpp"
#include "matching/0044A3E0_byte_run.cpp"

#undef FLICS_SHARED_CONTEXT
