// VA: 00488870 | TRIBE_RMM_Database_Controller::generate() | rmm_tdbc.cpp:614-629 | 103 bytes
//
// Attempt log:
// [1] Used `unsigned char* entry` temp + separate row/ent counters. Compiler chose edi for this.
//     Diff: 86.4%
// [2] Removed `entry` temp, used direct double-access pattern. Got esi for this, inner loop body matches!
//     Diff: 90.3%. Issues: redundant double tests from `if`+`for`, instruction reordering.
// [3] Remove outer/inner `if` guards, just use `for` loops to match original single-test pattern.

#ifndef RMM_TDBC_SHARED_CONTEXT
#include "../../include/game_types.h"

// Local class stubs for this function.
// Only fields relevant to the function are declared; gaps preserve correct offsets.
class RGE_Random_Map_Module {
public:
    char _gap_00[0x10];
    unsigned char** map_row_offset; // +0x10
    int map_width;                  // +0x14
    int map_height;                 // +0x18
};

class RGE_RMM_Database_Controller : public RGE_Random_Map_Module {
public:
    unsigned char generate();
};

class TRIBE_RMM_Database_Controller : public RGE_RMM_Database_Controller {
public:
    unsigned char generate();
};
#endif

unsigned char TRIBE_RMM_Database_Controller::generate() {
    unsigned char result = RGE_RMM_Database_Controller::generate();

    for (int row = 0; row < map_height; row++) {
        for (int ent = 0; ent < map_width; ent++) {
            if ((((unsigned char**)map_row_offset)[row][ent * 0x18 + 5] & 0x1F) == 0x10) {
                ((unsigned char**)map_row_offset)[row][ent * 0x18 + 5] &= 0xE0;
            }
        }
    }

    return result;
}
