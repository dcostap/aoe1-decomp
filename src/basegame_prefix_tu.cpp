// Canonical basegame.cpp prefix in PDB source and address order.
// Compile this translation unit with /O2 /Oy /GX.
#include <windows.h>
#include <stdio.h>
#include <io.h>
#include <new.h>
#include <string.h>

#define BASEGAME_GROUPED_TU
extern FILE* draw_log;
extern char draw_log_name[260];

#include "matching/0041B620_write_draw_log.cpp"
#include "matching/0041B650_write_draw_log2.cpp"
#include "matching/0041B6A0_RGE_Base_Game.cpp"
#include "accepted_drift/0041BAA0_setup.cpp"
#include "scratch/0041C270_RGE_Base_Game.cpp"
