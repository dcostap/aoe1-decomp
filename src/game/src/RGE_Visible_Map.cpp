#include "../include/RGE_Visible_Map.h"

#include "../include/LOSTBL.h"
#include "../include/RGE_Map.h"
#include "../include/RGE_Player.h"
#include "../include/RGE_Game_World.h"
#include "../include/globals.h"

#include <stdlib.h>
#include <string.h>
#include <cstdint>

// LOS edge tables (NormalLOS / SquareLOS) extracted from:
//   dist\_original_empiresx_from_beta_that_was_decompiled.exe
// using the addresses referenced by visible.cpp.asm (e.g. 0x0058EA10 / 0x0058EA58).
// Each table is a list of {y_delta, x_left, x_right} entries terminated by y_delta==999.
static LOSTBL Edge_Offsets_N0[] = {
    {0, 0, 0},
    {999, 0, 0},
};

static LOSTBL Edge_Offsets_N1[] = {
    {-1, -1, 1},
    {0, -1, 1},
    {1, -1, 1},
    {999, 0, 0},
};

static LOSTBL Edge_Offsets_N2[] = {
    {-2, -1, 1},
    {-1, -2, 2},
    {0, -2, 2},
    {1, -2, 2},
    {2, -1, 1},
    {999, 0, 0},
};

static LOSTBL Edge_Offsets_N3[] = {
    {-3, -1, 1},
    {-2, -2, 2},
    {-1, -3, 3},
    {0, -3, 3},
    {1, -3, 3},
    {2, -2, 2},
    {3, -1, 1},
    {999, 0, 0},
};

static LOSTBL Edge_Offsets_N4[] = {
    {-4, -1, 1},
    {-3, -3, 3},
    {-2, -3, 3},
    {-1, -4, 4},
    {0, -4, 4},
    {1, -4, 4},
    {2, -3, 3},
    {3, -3, 3},
    {4, -1, 1},
    {999, 0, 0},
};

static LOSTBL Edge_Offsets_N5[] = {
    {-5, -2, 2},
    {-4, -3, 3},
    {-3, -4, 4},
    {-2, -5, 5},
    {-1, -5, 5},
    {0, -5, 5},
    {1, -5, 5},
    {2, -5, 5},
    {3, -4, 4},
    {4, -3, 3},
    {5, -2, 2},
    {999, 0, 0},
};

static LOSTBL Edge_Offsets_N6[] = {
    {-6, -2, 2},
    {-5, -4, 4},
    {-4, -5, 5},
    {-3, -5, 5},
    {-2, -6, 6},
    {-1, -6, 6},
    {0, -6, 6},
    {1, -6, 6},
    {2, -6, 6},
    {3, -5, 5},
    {4, -5, 5},
    {5, -4, 4},
    {6, -2, 2},
    {999, 0, 0},
};

static LOSTBL Edge_Offsets_N7[] = {
    {-7, -2, 2},
    {-6, -4, 4},
    {-5, -5, 5},
    {-4, -6, 6},
    {-3, -7, 7},
    {-2, -7, 7},
    {-1, -7, 7},
    {0, -7, 7},
    {1, -7, 7},
    {2, -7, 7},
    {3, -7, 7},
    {4, -6, 6},
    {5, -5, 5},
    {6, -4, 4},
    {7, -2, 2},
    {999, 0, 0},
};

static LOSTBL Edge_Offsets_N8[] = {
    {-8, -2, 2},
    {-7, -4, 4},
    {-6, -6, 6},
    {-5, -7, 7},
    {-4, -7, 7},
    {-3, -8, 8},
    {-2, -8, 8},
    {-1, -8, 8},
    {0, -8, 8},
    {1, -8, 8},
    {2, -8, 8},
    {3, -8, 8},
    {4, -7, 7},
    {5, -7, 7},
    {6, -6, 6},
    {7, -4, 4},
    {8, -2, 2},
    {999, 0, 0},
};

static LOSTBL Edge_Offsets_N9[] = {
    {-9, -3, 3},
    {-8, -5, 5},
    {-7, -6, 6},
    {-6, -7, 7},
    {-5, -8, 8},
    {-4, -9, 9},
    {-3, -9, 9},
    {-2, -9, 9},
    {-1, -9, 9},
    {0, -9, 9},
    {1, -9, 9},
    {2, -9, 9},
    {3, -9, 9},
    {4, -9, 9},
    {5, -8, 8},
    {6, -7, 7},
    {7, -6, 6},
    {8, -5, 5},
    {9, -3, 3},
    {999, 0, 0},
};

static LOSTBL Edge_Offsets_N10[] = {
    {-10, -3, 3},
    {-9, -5, 5},
    {-8, -7, 7},
    {-7, -8, 8},
    {-6, -9, 9},
    {-5, -9, 9},
    {-4, -10, 10},
    {-3, -10, 10},
    {-2, -10, 10},
    {-1, -10, 10},
    {0, -10, 10},
    {1, -10, 10},
    {2, -10, 10},
    {3, -10, 10},
    {4, -10, 10},
    {5, -9, 9},
    {6, -9, 9},
    {7, -8, 8},
    {8, -7, 7},
    {9, -5, 5},
    {10, -3, 3},
    {999, 0, 0},
};

static LOSTBL Edge_Offsets_N11[] = {
    {-11, -3, 3},
    {-10, -6, 6},
    {-9, -7, 7},
    {-8, -8, 8},
    {-7, -9, 9},
    {-6, -10, 10},
    {-5, -11, 11},
    {-4, -11, 11},
    {-3, -11, 11},
    {-2, -11, 11},
    {-1, -11, 11},
    {0, -11, 11},
    {1, -11, 11},
    {2, -11, 11},
    {3, -11, 11},
    {4, -11, 11},
    {5, -11, 11},
    {6, -10, 10},
    {7, -9, 9},
    {8, -8, 8},
    {9, -7, 7},
    {10, -6, 6},
    {11, -3, 3},
    {999, 0, 0},
};

static LOSTBL Edge_Offsets_N12[] = {
    {-12, -3, 3},
    {-11, -6, 6},
    {-10, -8, 8},
    {-9, -9, 9},
    {-8, -10, 10},
    {-7, -11, 11},
    {-6, -11, 11},
    {-5, -12, 12},
    {-4, -12, 12},
    {-3, -12, 12},
    {-2, -12, 12},
    {-1, -12, 12},
    {0, -12, 12},
    {1, -12, 12},
    {2, -12, 12},
    {3, -12, 12},
    {4, -12, 12},
    {5, -12, 12},
    {6, -11, 11},
    {7, -11, 11},
    {8, -10, 10},
    {9, -9, 9},
    {10, -8, 8},
    {11, -6, 6},
    {12, -3, 3},
    {999, 0, 0},
};

static LOSTBL Edge_Offsets_N13[] = {
    {-13, -4, 4},
    {-12, -7, 7},
    {-11, -8, 8},
    {-10, -9, 9},
    {-9, -10, 10},
    {-8, -11, 11},
    {-7, -12, 12},
    {-6, -13, 13},
    {-5, -13, 13},
    {-4, -13, 13},
    {-3, -13, 13},
    {-2, -13, 13},
    {-1, -13, 13},
    {0, -13, 13},
    {1, -13, 13},
    {2, -13, 13},
    {3, -13, 13},
    {4, -13, 13},
    {5, -13, 13},
    {6, -13, 13},
    {7, -12, 12},
    {8, -11, 11},
    {9, -10, 10},
    {10, -9, 9},
    {11, -8, 8},
    {12, -7, 7},
    {13, -4, 4},
    {999, 0, 0},
};

static LOSTBL Edge_Offsets_N14[] = {
    {-14, -4, 4},
    {-13, -7, 7},
    {-12, -9, 9},
    {-11, -10, 10},
    {-10, -11, 11},
    {-9, -12, 12},
    {-8, -13, 13},
    {-7, -13, 13},
    {-6, -14, 14},
    {-5, -14, 14},
    {-4, -14, 14},
    {-3, -14, 14},
    {-2, -14, 14},
    {-1, -14, 14},
    {0, -14, 14},
    {1, -14, 14},
    {2, -14, 14},
    {3, -14, 14},
    {4, -14, 14},
    {5, -14, 14},
    {6, -14, 14},
    {7, -13, 13},
    {8, -13, 13},
    {9, -12, 12},
    {10, -11, 11},
    {11, -10, 10},
    {12, -9, 9},
    {13, -7, 7},
    {14, -4, 4},
    {999, 0, 0},
};

static LOSTBL Edge_Offsets_N15[] = {
    {-15, -4, 4},
    {-14, -7, 7},
    {-13, -9, 9},
    {-12, -10, 10},
    {-11, -11, 11},
    {-10, -12, 12},
    {-9, -13, 13},
    {-8, -14, 14},
    {-7, -15, 15},
    {-6, -15, 15},
    {-5, -15, 15},
    {-4, -15, 15},
    {-3, -15, 15},
    {-2, -15, 15},
    {-1, -15, 15},
    {0, -15, 15},
    {1, -15, 15},
    {2, -15, 15},
    {3, -15, 15},
    {4, -15, 15},
    {5, -15, 15},
    {6, -15, 15},
    {7, -15, 15},
    {8, -14, 14},
    {9, -13, 13},
    {10, -12, 12},
    {11, -11, 11},
    {12, -10, 10},
    {13, -9, 9},
    {14, -7, 7},
    {15, -4, 4},
    {999, 0, 0},
};

static LOSTBL Edge_Offsets_N16[] = {
    {-16, -4, 4},
    {-15, -7, 7},
    {-14, -9, 9},
    {-13, -10, 10},
    {-12, -11, 11},
    {-11, -12, 12},
    {-10, -13, 13},
    {-9, -14, 14},
    {-8, -15, 15},
    {-7, -15, 15},
    {-6, -16, 16},
    {-5, -16, 16},
    {-4, -16, 16},
    {-3, -16, 16},
    {-2, -16, 16},
    {-1, -16, 16},
    {0, -16, 16},
    {1, -16, 16},
    {2, -16, 16},
    {3, -16, 16},
    {4, -16, 16},
    {5, -16, 16},
    {6, -16, 16},
    {7, -15, 15},
    {8, -15, 15},
    {9, -14, 14},
    {10, -13, 13},
    {11, -12, 12},
    {12, -11, 11},
    {13, -10, 10},
    {14, -9, 9},
    {15, -7, 7},
    {16, -4, 4},
    {999, 0, 0},
};

static LOSTBL Edge_Offsets_T0[] = {
    {0, 0, 0},
    {999, 0, 0},
};

static LOSTBL Edge_Offsets_T1[] = {
    {-1, -1, 0},
    {0, -1, 0},
    {1, -1, 0},
    {999, 0, 0},
};

static LOSTBL Edge_Offsets_T2[] = {
    {-2, -1, 0},
    {-1, -2, 1},
    {0, -2, 1},
    {1, -2, 1},
    {2, -1, 0},
    {999, 0, 0},
};

static LOSTBL Edge_Offsets_T3[] = {
    {-3, -1, 0},
    {-2, -2, 1},
    {-1, -3, 2},
    {0, -3, 2},
    {1, -3, 2},
    {2, -2, 1},
    {3, -1, 0},
    {999, 0, 0},
};

static LOSTBL Edge_Offsets_T4[] = {
    {-4, -1, 0},
    {-3, -2, 1},
    {-2, -3, 2},
    {-1, -4, 3},
    {0, -4, 3},
    {1, -4, 3},
    {2, -3, 2},
    {3, -2, 1},
    {4, -1, 0},
    {999, 0, 0},
};

static LOSTBL Edge_Offsets_T5[] = {
    {-5, -2, 1},
    {-4, -3, 2},
    {-3, -4, 3},
    {-2, -5, 4},
    {-1, -5, 4},
    {0, -5, 4},
    {1, -5, 4},
    {2, -5, 4},
    {3, -4, 3},
    {4, -3, 2},
    {5, -2, 1},
    {999, 0, 0},
};

static LOSTBL Edge_Offsets_T6[] = {
    {-6, -2, 1},
    {-5, -3, 2},
    {-4, -4, 3},
    {-3, -5, 4},
    {-2, -6, 5},
    {-1, -6, 5},
    {0, -6, 5},
    {1, -6, 5},
    {2, -6, 5},
    {3, -5, 4},
    {4, -4, 3},
    {5, -3, 2},
    {6, -2, 1},
    {999, 0, 0},
};

static LOSTBL Edge_Offsets_T7[] = {
    {-7, -2, 1},
    {-6, -4, 3},
    {-5, -4, 3},
    {-4, -6, 5},
    {-3, -7, 6},
    {-2, -7, 6},
    {-1, -7, 6},
    {0, -7, 6},
    {1, -7, 6},
    {2, -7, 6},
    {3, -7, 6},
    {4, -6, 5},
    {5, -4, 3},
    {6, -4, 3},
    {7, -2, 1},
    {999, 0, 0},
};

static LOSTBL Edge_Offsets_T8[] = {
    {-8, -2, 1},
    {-7, -4, 3},
    {-6, -5, 4},
    {-5, -6, 5},
    {-4, -7, 6},
    {-3, -8, 7},
    {-2, -8, 7},
    {-1, -8, 7},
    {0, -8, 7},
    {1, -8, 7},
    {2, -8, 7},
    {3, -8, 7},
    {4, -7, 6},
    {5, -6, 5},
    {6, -5, 4},
    {7, -4, 3},
    {8, -2, 1},
    {999, 0, 0},
};

static LOSTBL Edge_Offsets_T9[] = {
    {-9, -3, 2},
    {-8, -5, 4},
    {-7, -6, 5},
    {-6, -7, 6},
    {-5, -8, 7},
    {-4, -8, 7},
    {-3, -9, 8},
    {-2, -9, 8},
    {-1, -9, 8},
    {0, -9, 8},
    {1, -9, 8},
    {2, -9, 8},
    {3, -9, 8},
    {4, -8, 7},
    {5, -8, 7},
    {6, -7, 6},
    {7, -6, 5},
    {8, -5, 4},
    {9, -3, 2},
    {999, 0, 0},
};

static LOSTBL Edge_Offsets_T10[] = {
    {-10, -3, 2},
    {-9, -6, 5},
    {-8, -7, 6},
    {-7, -8, 7},
    {-6, -9, 8},
    {-5, -9, 8},
    {-4, -10, 9},
    {-3, -10, 9},
    {-2, -10, 9},
    {-1, -10, 9},
    {0, -10, 9},
    {1, -10, 9},
    {2, -10, 9},
    {3, -10, 9},
    {4, -10, 9},
    {5, -9, 8},
    {6, -9, 8},
    {7, -8, 7},
    {8, -7, 6},
    {9, -6, 5},
    {10, -3, 2},
    {999, 0, 0},
};

static LOSTBL Edge_Offsets_T11[] = {
    {-11, -3, 2},
    {-10, -6, 5},
    {-9, -7, 6},
    {-8, -8, 7},
    {-7, -9, 8},
    {-6, -10, 9},
    {-5, -10, 9},
    {-4, -11, 10},
    {-3, -11, 10},
    {-2, -11, 10},
    {-1, -11, 10},
    {0, -11, 10},
    {1, -11, 10},
    {2, -11, 10},
    {3, -11, 10},
    {4, -11, 10},
    {5, -10, 9},
    {6, -10, 9},
    {7, -9, 8},
    {8, -8, 7},
    {9, -7, 6},
    {10, -6, 5},
    {11, -3, 2},
    {999, 0, 0},
};

static LOSTBL Edge_Offsets_T12[] = {
    {-12, -3, 2},
    {-11, -6, 5},
    {-10, -8, 7},
    {-9, -9, 8},
    {-8, -10, 9},
    {-7, -11, 10},
    {-6, -11, 10},
    {-5, -12, 11},
    {-4, -12, 11},
    {-3, -12, 11},
    {-2, -12, 11},
    {-1, -12, 11},
    {0, -12, 11},
    {1, -12, 11},
    {2, -12, 11},
    {3, -12, 11},
    {4, -12, 11},
    {5, -12, 11},
    {6, -11, 10},
    {7, -11, 10},
    {8, -10, 9},
    {9, -9, 8},
    {10, -8, 7},
    {11, -6, 5},
    {12, -3, 2},
    {999, 0, 0},
};

static LOSTBL Edge_Offsets_T13[] = {
    {-13, -4, 3},
    {-12, -7, 6},
    {-11, -8, 7},
    {-10, -9, 8},
    {-9, -10, 9},
    {-8, -11, 10},
    {-7, -12, 11},
    {-6, -13, 12},
    {-5, -13, 12},
    {-4, -13, 12},
    {-3, -13, 12},
    {-2, -13, 12},
    {-1, -13, 12},
    {0, -13, 12},
    {1, -13, 12},
    {2, -13, 12},
    {3, -13, 12},
    {4, -13, 12},
    {5, -13, 12},
    {6, -13, 12},
    {7, -12, 11},
    {8, -11, 10},
    {9, -10, 9},
    {10, -9, 8},
    {11, -8, 7},
    {12, -7, 6},
    {13, -4, 3},
    {999, 0, 0},
};

static LOSTBL Edge_Offsets_T14[] = {
    {-14, -4, 3},
    {-13, -7, 6},
    {-12, -9, 8},
    {-11, -10, 9},
    {-10, -11, 10},
    {-9, -12, 11},
    {-8, -13, 12},
    {-7, -13, 12},
    {-6, -14, 13},
    {-5, -14, 13},
    {-4, -14, 13},
    {-3, -14, 13},
    {-2, -14, 13},
    {-1, -14, 13},
    {0, -14, 13},
    {1, -14, 13},
    {2, -14, 13},
    {3, -14, 13},
    {4, -14, 13},
    {5, -14, 13},
    {6, -14, 13},
    {7, -13, 12},
    {8, -13, 12},
    {9, -12, 11},
    {10, -11, 10},
    {11, -10, 9},
    {12, -9, 8},
    {13, -7, 6},
    {14, -4, 3},
    {999, 0, 0},
};

static LOSTBL Edge_Offsets_T15[] = {
    {-15, -4, 3},
    {-14, -7, 6},
    {-13, -9, 8},
    {-12, -10, 9},
    {-11, -11, 10},
    {-10, -12, 11},
    {-9, -13, 12},
    {-8, -14, 13},
    {-7, -15, 14},
    {-6, -15, 14},
    {-5, -15, 14},
    {-4, -15, 14},
    {-3, -15, 14},
    {-2, -15, 14},
    {-1, -15, 14},
    {0, -15, 14},
    {1, -15, 14},
    {2, -15, 14},
    {3, -15, 14},
    {4, -15, 14},
    {5, -15, 14},
    {6, -15, 14},
    {7, -15, 14},
    {8, -14, 13},
    {9, -13, 12},
    {10, -12, 11},
    {11, -11, 10},
    {12, -10, 9},
    {13, -9, 8},
    {14, -7, 6},
    {15, -4, 3},
    {999, 0, 0},
};

static LOSTBL Edge_Offsets_T16[] = {
    {-16, -4, 3},
    {-15, -7, 6},
    {-14, -8, 7},
    {-13, -10, 9},
    {-12, -11, 10},
    {-11, -12, 11},
    {-10, -13, 12},
    {-9, -13, 12},
    {-8, -14, 13},
    {-7, -15, 14},
    {-6, -15, 14},
    {-5, -15, 14},
    {-4, -16, 15},
    {-3, -16, 15},
    {-2, -16, 15},
    {-1, -16, 15},
    {0, -16, 15},
    {1, -16, 15},
    {2, -16, 15},
    {3, -16, 15},
    {4, -15, 14},
    {5, -15, 14},
    {6, -15, 14},
    {7, -14, 13},
    {8, -13, 12},
    {9, -13, 12},
    {10, -12, 11},
    {11, -11, 10},
    {12, -10, 9},
    {13, -8, 7},
    {14, -7, 6},
    {15, -4, 3},
    {999, 0, 0},
};

static LOSTBL* NormalLOS[17] = {
    Edge_Offsets_N0,
    Edge_Offsets_N1,
    Edge_Offsets_N2,
    Edge_Offsets_N3,
    Edge_Offsets_N4,
    Edge_Offsets_N5,
    Edge_Offsets_N6,
    Edge_Offsets_N7,
    Edge_Offsets_N8,
    Edge_Offsets_N9,
    Edge_Offsets_N10,
    Edge_Offsets_N11,
    Edge_Offsets_N12,
    Edge_Offsets_N13,
    Edge_Offsets_N14,
    Edge_Offsets_N15,
    Edge_Offsets_N16,
};

static LOSTBL* SquareLOS[17] = {
    Edge_Offsets_T0,
    Edge_Offsets_T1,
    Edge_Offsets_T2,
    Edge_Offsets_T3,
    Edge_Offsets_T4,
    Edge_Offsets_T5,
    Edge_Offsets_T6,
    Edge_Offsets_T7,
    Edge_Offsets_T8,
    Edge_Offsets_T9,
    Edge_Offsets_T10,
    Edge_Offsets_T11,
    Edge_Offsets_T12,
    Edge_Offsets_T13,
    Edge_Offsets_T14,
    Edge_Offsets_T15,
    Edge_Offsets_T16,
};

struct VC_LOG {
    int values[9];
};

static VC_LOG VCALL_LOG[0x400];
static int VCALL_LOG_HEAD = -1;
static int VCALL_LOG_TAIL = -1;

static void log_map_call(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7, int param_8, int param_9) {
    // Source of truth: visible.cpp.decomp @ 0x0053D150
    int iVar1 = VCALL_LOG_HEAD + 1;
    if (iVar1 < 0x400) {
        if (-1 < VCALL_LOG_TAIL) {
            VCALL_LOG_TAIL = VCALL_LOG_HEAD + 2;
            if (0x3FF < VCALL_LOG_TAIL) {
                VCALL_LOG_TAIL = 0;
            }
        }
    } else {
        iVar1 = 0;
        VCALL_LOG_TAIL = 1;
    }

    VCALL_LOG_HEAD = iVar1;
    VCALL_LOG[iVar1].values[0] = param_1;
    VCALL_LOG[iVar1].values[1] = param_2;
    VCALL_LOG[iVar1].values[2] = param_3;
    VCALL_LOG[iVar1].values[3] = param_4;
    VCALL_LOG[iVar1].values[4] = param_5;
    VCALL_LOG[iVar1].values[5] = param_6;
    VCALL_LOG[iVar1].values[6] = param_7;
    VCALL_LOG[iVar1].values[7] = param_8;
    VCALL_LOG[iVar1].values[8] = param_9;
}

RGE_Visible_Map::RGE_Visible_Map(RGE_Map* param_1, RGE_Player* param_2) {
    // Fully verified. Source of truth: visible.cpp.decomp @ 0x0053C1B0
    this->world = param_2->world;
    this->player = param_2;
    this->map = param_1;
    this->widthValue = param_1->map_width;
    this->heightValue = param_1->map_height;
    this->numberTilesExploredValue = 0;
    this->numberTotalTilesValue = this->heightValue * this->widthValue;

    if (this->widthValue < 1 || this->heightValue < 1) {
        this->visible_map = nullptr;
        this->map_offsets = nullptr;
    } else {
        this->visible_map = (uchar*)calloc(this->heightValue * this->widthValue, 1);
        this->map_offsets = (uchar**)calloc(this->heightValue, 4);
        for (int i = 0; i < this->heightValue; ++i) {
            this->map_offsets[i] = this->visible_map + i * this->widthValue;
        }
        memset(this->visible_map, 0xFF, (size_t)(this->heightValue * this->widthValue));
    }

    ulong visible_mask = 1UL << ((uchar)param_2->id & 0x1F);
    this->input_csum = 0;
    this->PlayerVisibleMaskValue = visible_mask;
    this->PlayerVisibleMaskInvertValue = ~visible_mask;
    this->PlayerExploredMaskValue = visible_mask << 16;
    this->PlayerExploredMaskInvertValue = ~(visible_mask << 16);
}

RGE_Visible_Map::RGE_Visible_Map(int param_1, RGE_Game_World* param_2) {
    // Fully verified. Source of truth: visible.cpp.decomp @ 0x0053C290
    this->world = param_2;
    this->map = param_2->map;
    this->numberTilesExploredValue = 0;

    rge_read(param_1, &this->widthValue, 4);
    rge_read(param_1, &this->heightValue, 4);
    if (save_game_version >= 6.7f) {
        rge_read(param_1, &this->numberTilesExploredValue, 4);
    }

    short player_id = 0;
    rge_read(param_1, &player_id, 2);

    this->numberTotalTilesValue = this->heightValue * this->widthValue;
    this->player = param_2->players[player_id];

    if (this->widthValue < 1 || this->heightValue < 1) {
        this->visible_map = nullptr;
        this->map_offsets = nullptr;
    } else {
        this->visible_map = (uchar*)calloc(this->numberTotalTilesValue, 1);
        this->map_offsets = (uchar**)calloc(this->heightValue, 4);
        for (int i = 0; i < this->heightValue; ++i) {
            this->map_offsets[i] = this->visible_map + i * this->widthValue;
        }
        rge_read(param_1, this->visible_map, this->numberTotalTilesValue);
    }

    ulong visible_mask = 1UL << ((uchar)player_id & 0x1F);
    this->input_csum = 0;
    this->PlayerVisibleMaskValue = visible_mask;
    this->PlayerExploredMaskValue = visible_mask << 16;
    this->PlayerExploredMaskInvertValue = ~(visible_mask << 16);
    this->PlayerVisibleMaskInvertValue = ~visible_mask;
}

RGE_Visible_Map::~RGE_Visible_Map() {
    // Fully verified. Source of truth: visible.cpp.decomp @ 0x0053C3C0
    if (this->visible_map != nullptr) {
        free(this->visible_map);
        this->visible_map = nullptr;
    }
    if (this->map_offsets != nullptr) {
        free(this->map_offsets);
        this->map_offsets = nullptr;
    }
    this->player = nullptr;
    this->map = nullptr;
}

void RGE_Visible_Map::save(int param_1) {
    // Fully verified. Source of truth: visible.cpp.decomp @ 0x0053C400
    rge_write(param_1, &this->widthValue, 4);
    rge_write(param_1, &this->heightValue, 4);
    if (save_game_version >= 6.7f) {
        rge_write(param_1, &this->numberTilesExploredValue, 4);
    }
    rge_write(param_1, &this->player->id, 2);
    if (this->widthValue > 0 && this->heightValue > 0) {
        rge_write(param_1, this->visible_map, this->heightValue * this->widthValue);
    }
}

uchar RGE_Visible_Map::get_visible(int col, int row) {
    // Source of truth: visible.cpp.decomp @ 0x0053C490
    if (this->player == nullptr || row < 0 || col < 0) {
        return 0;
    }
    if (row >= 0x100 || unified_map_offsets[row] == nullptr) {
        return 0;
    }

    ulong tile_mask = unified_map_offsets[row][col];
    if ((tile_mask & this->player->mutualVisibleMask) != 0) {
        return 0x0F;
    }
    return (uchar)(((this->player->mutualExploredMask & tile_mask) != 0) ? 0x80 : 0x00);
}

float RGE_Visible_Map::percentExplored() {
    // Fully verified. Source of truth: visible.cpp.decomp @ 0x0053C670
    if (this->numberTotalTilesValue == 0) {
        return 0.0f;
    }
    return (float)this->numberTilesExploredValue / (float)this->numberTotalTilesValue;
}

LOSTBL* RGE_Visible_Map::get_los_table(int param_1, int param_2) {
    // Fully verified. Source of truth: visible.cpp.decomp @ 0x0053C6C0
    if (0x10 < param_1) {
        param_1 = 0x10;
    }
    if (param_1 < 0) {
        param_1 = 0;
    }
    if (param_2 != 0) {
        return SquareLOS[param_1];
    }
    return NormalLOS[param_1];
}

int RGE_Visible_Map::explore_terrain(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6) {
    // Fully verified. Source of truth: visible.cpp.decomp @ 0x0053C6F0
    int iVar8 = param_3;
    int Revealed = 0;

    log_map_call(this->world->world_time, (int)this->player->id, 1, param_6, param_1, param_2, param_3, param_4, Map_Update_Suppresion);
    if (Map_Update_Suppresion != 0) {
        return 0;
    }

    uint uVar4 = (uint)this->input_csum << 3;
    uVar4 = ((((uVar4 | ((uint)this->input_csum >> 0x1D)) ^ 0x01010101U) << 2) | (uVar4 >> 0x1E)) ^ (uint)(int)this->player->id;
    uVar4 = ((uVar4 << 3) | (uVar4 >> 0x1D)) ^ (uint)param_1;
    uVar4 = ((uVar4 << 4) | (uVar4 >> 0x1C)) ^ (uint)param_2;
    this->input_csum = (ulong)((((uVar4 << 3) | (uVar4 >> 0x1D)) ^ (uint)param_3) + (uint)param_4);

    RGE_Player* cur_player = (this->world != nullptr) ? this->world->players[this->world->curr_player] : nullptr;
    bool bVar10 = false;
    if (cur_player != nullptr) {
        bVar10 = cur_player->mutualAlly[this->player->id] == 1;
    }
    RGE_Player* curVisPlayer = bVar10 ? cur_player : nullptr;

    if (0x10 < iVar8) {
        iVar8 = 0x10;
    }

    LOSTBL* offsets = (param_4 == 0) ? NormalLOS[iVar8] : SquareLOS[iVar8];
    int idx = 0;
    int y_delta = offsets[idx].y_delta;
    while (y_delta != 999) {
        int y = param_2 + y_delta;
        if (-1 < y && y < this->heightValue) {
            int x = offsets[idx].x_left + param_1;
            if (x < 0) {
                x = 0;
            }
            int x2 = offsets[idx].x_right + param_1;
            if (this->widthValue <= x2) {
                x2 = this->widthValue - 1;
            }

            uchar* pVis = this->map_offsets[y] + x;
            ulong* pUnified = unified_map_offsets[y] + x;
            uintptr_t tile_addr = 0;
            if (param_5 != 0) {
                tile_addr = (uintptr_t)(this->map->map_row_offset[y] + x);
            }

            for (; x <= x2; ++x) {
                uchar uVar3 = (uchar)(*pVis + 1);
                if (uVar3 == 0) {
                    Revealed = Revealed + 1;
                    this->numberTilesExploredValue = this->numberTilesExploredValue + 1;
                    this->player->tile_list.add_node(x, y);
                    if (bVar10 && curVisPlayer != nullptr) {
                        curVisPlayer->diam_tile_list.add_node(x, y);
                    }
                    uVar3 = 1;
                    *pUnified |= this->PlayerExploredMaskValue;
                }
                if (uVar3 == 1) {
                    if (param_5 != 0) {
                        ((RGE_Tile*)tile_addr)->draw_as = 0x0F;
                    }
                    *pUnified |= this->PlayerVisibleMaskValue;
                }
                if (uVar3 == 0xFA) {
                    uVar3 = 0xF9;
                }

                *pVis = uVar3;
                ++pVis;
                ++pUnified;
                tile_addr = tile_addr + sizeof(RGE_Tile);
            }
        }
        idx = idx + 1;
        y_delta = offsets[idx].y_delta;
    }

    return Revealed;
}

void RGE_Visible_Map::unexplore_terrain(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6) {
    // Fully verified. Source of truth: visible.cpp.decomp @ 0x0053C920
    log_map_call(this->world->world_time, (int)this->player->id, 3, param_6, param_1, param_2, param_3, param_4, Map_Update_Suppresion);
    if (Map_Update_Suppresion != 0) {
        return;
    }

    uint uVar2 = (uint)this->input_csum << 3;
    uVar2 = ((((uVar2 | ((uint)this->input_csum >> 0x1D)) ^ 0x20202020U) << 2) | (uVar2 >> 0x1E)) ^ (uint)(int)this->player->id;
    uVar2 = ((uVar2 << 3) | (uVar2 >> 0x1D)) ^ (uint)param_1;
    uVar2 = ((uVar2 << 4) | (uVar2 >> 0x1C)) ^ (uint)param_2;
    this->input_csum = (ulong)((((uVar2 << 3) | (uVar2 >> 0x1D)) ^ (uint)param_3) + (uint)param_4);

    if (0x10 < param_3) {
        param_3 = 0x10;
    }

    LOSTBL* offsets = (param_4 == 0) ? NormalLOS[param_3] : SquareLOS[param_3];
    int idx = 0;
    int y_delta = offsets[idx].y_delta;
    while (y_delta != 999) {
        int y = param_2 + y_delta;
        if (-1 < y && y < this->heightValue) {
            int x = offsets[idx].x_left + param_1;
            if (x < 0) {
                x = 0;
            }
            int x2 = offsets[idx].x_right + param_1;
            if (this->widthValue <= x2) {
                x2 = this->widthValue - 1;
            }

            uchar* pVis = this->map_offsets[y] + x;
            ulong* pUnified = unified_map_offsets[y] + x;
            uintptr_t tile_addr = 0;
            if (param_5 != 0) {
                tile_addr = (uintptr_t)(this->map->map_row_offset[y] + x);
            }

            for (; x <= x2; ++x) {
                uchar uVar5 = (uchar)(*pVis + 0xFF);
                if (uVar5 == 0xFF) {
                    uVar5 = 0;
                }
                if (uVar5 == 0) {
                    if (param_5 != 0) {
                        ((RGE_Tile*)tile_addr)->draw_as = 0x80;
                    }
                    *pUnified &= this->PlayerVisibleMaskInvertValue;
                }

                *pVis = uVar5;
                ++pVis;
                ++pUnified;
                tile_addr = tile_addr + sizeof(RGE_Tile);
            }
        }

        idx = idx + 1;
        y_delta = offsets[idx].y_delta;
    }
}

int RGE_Visible_Map::explore_terrain_sq(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6) {
    // Fully verified. Source of truth: visible.cpp.decomp @ 0x0053CAC0
    int Revealed = 0;

    log_map_call(this->world->world_time, (int)this->player->id, 2, param_6, param_1, param_2, param_3, param_4, Map_Update_Suppresion);
    if (Map_Update_Suppresion != 0) {
        return 0;
    }

    RGE_Player* cur_player = (this->world != nullptr) ? this->world->players[this->world->curr_player] : nullptr;
    bool bVar7 = false;
    if (cur_player != nullptr) {
        bVar7 = cur_player->mutualAlly[this->player->id] == 1;
    }

    uint uVar4 = (uint)this->input_csum << 3;
    uVar4 = ((((uVar4 | ((uint)this->input_csum >> 0x1D)) ^ 0x34343434U) << 2) | (uVar4 >> 0x1E)) ^ (uint)param_1;
    uVar4 = ((uVar4 << 4) | (uVar4 >> 0x1C)) ^ (uint)param_2;
    uVar4 = ((uVar4 << 3) | (uVar4 >> 0x1D)) ^ (uint)param_3;
    this->input_csum = (ulong)(((uVar4 << 3) | (uVar4 >> 0x1D)) ^ (uint)param_4);

    RGE_Player* curVisPlayer = bVar7 ? cur_player : nullptr;

    int iVar1 = this->widthValue;
    int iVar2 = this->heightValue;
    if (param_1 < iVar1 && -1 < param_3 && param_2 < iVar2 && -1 < param_4) {
        if (param_1 < 0) {
            param_1 = 0;
        }
        if (iVar1 <= param_3) {
            param_3 = iVar1 - 1;
        }
        if (param_2 < 0) {
            param_2 = 0;
        }
        if (iVar2 <= param_4) {
            param_4 = iVar2 - 1;
        }

        for (; param_2 <= param_4; ++param_2) {
            ulong* pUnified = unified_map_offsets[param_2] + param_1;
            uchar* pVis = this->map_offsets[param_2] + param_1;
            int x = param_1;
            uintptr_t tile_addr = 0;
            if (param_5 != 0) {
                tile_addr = (uintptr_t)(this->map->map_row_offset[param_2] + param_1);
            }

            for (; x <= param_3; ++x) {
                uchar uVar3 = (uchar)(*pVis + 1);
                if (uVar3 == 0) {
                    Revealed = Revealed + 1;
                    this->numberTilesExploredValue = this->numberTilesExploredValue + 1;
                    this->player->tile_list.add_node(x, param_2);
                    if (bVar7 && curVisPlayer != nullptr) {
                        curVisPlayer->diam_tile_list.add_node(x, param_2);
                    }
                    uVar3 = 1;
                    *pUnified |= this->PlayerExploredMaskValue;
                }
                if (uVar3 == 1) {
                    if (param_5 != 0) {
                        ((RGE_Tile*)tile_addr)->draw_as = 0x0F;
                    }
                    *pUnified |= this->PlayerVisibleMaskValue;
                }
                if (uVar3 == 0xFA) {
                    uVar3 = 0xF9;
                }
                *pVis = uVar3;
                ++pVis;
                ++pUnified;
                tile_addr = tile_addr + sizeof(RGE_Tile);
            }
        }

        return Revealed;
    }

    return 0;
}

void RGE_Visible_Map::unexplore_terrain_sq(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6) {
    // Fully verified. Source of truth: visible.cpp.decomp @ 0x0053CCF0
    log_map_call(this->world->world_time, (int)this->player->id, 4, param_6, param_1, param_2, param_3, param_4, Map_Update_Suppresion);
    if (Map_Update_Suppresion != 0) {
        return;
    }

    uint uVar2 = (uint)this->input_csum;
    uVar2 = (((uVar2 << 3) | (uVar2 >> 0x1D)) ^ 0x56565656U);
    uVar2 = ((uVar2 << 2) | (uVar2 >> 0x1E)) ^ (uint)param_1;
    uVar2 = ((uVar2 << 4) | (uVar2 >> 0x1C)) ^ (uint)param_2;
    uVar2 = ((uVar2 << 3) | (uVar2 >> 0x1D)) ^ (uint)param_3;
    this->input_csum = (ulong)(((uVar2 << 3) | (uVar2 >> 0x1D)) ^ (uint)param_4);

    int iVar6 = this->widthValue;
    int iVar1 = this->heightValue;
    if (param_1 < iVar6 && -1 < param_3 && param_2 < iVar1 && -1 < param_4) {
        if (param_1 < 0) {
            param_1 = 0;
        }
        if (iVar6 <= param_3) {
            param_3 = iVar6 - 1;
        }
        if (param_2 < 0) {
            param_2 = 0;
        }
        if (iVar1 <= param_4) {
            param_4 = iVar1 - 1;
        }

        for (; param_2 <= param_4; ++param_2) {
            uchar* pVis = this->map_offsets[param_2] + param_1;
            ulong* pUnified = unified_map_offsets[param_2] + param_1;
            uintptr_t tile_addr = 0;
            if (param_5 != 0) {
                tile_addr = (uintptr_t)(this->map->map_row_offset[param_2] + param_1);
            }

            if (param_1 <= param_3) {
                int remaining = (param_3 - param_1) + 1;
                do {
                    uchar uVar4 = (uchar)(*pVis + 0xFF);
                    if (uVar4 == 0xFF) {
                        uVar4 = 0;
                    }
                    if (uVar4 == 0) {
                        if (param_5 != 0) {
                            ((RGE_Tile*)tile_addr)->draw_as = 0x80;
                        }
                        *pUnified &= this->PlayerVisibleMaskInvertValue;
                    }

                    *pVis = uVar4;
                    ++pVis;
                    ++pUnified;
                    tile_addr = tile_addr + sizeof(RGE_Tile);
                    remaining = remaining - 1;
                } while (remaining != 0);
            }
        }
    }
}
