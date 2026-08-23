// RGE_Main_View::fixup_pick_info
// VA: 00540680
// PDB-qualified owner/name: protected: void __thiscall RGE_Main_View::fixup_pick_info(RGE_Pick_Info*)
// PDB source: vw_main.cpp:1946-1956
// Original body boundary: 00540680-005406F6; next symbol: 00540700.
// MATCH: 0.0000% diff, 4 relocations masked
//
// BINARY NOTE: The executable rereads mapInfo for the y limit after the x
// path. Keep both member expressions direct to preserve fault order.
// Exact-finish: the typed MapInfo field and natural signed float comparisons
// reproduce the complete 119-byte body. No calls, frame, or cleanup differ.

#include "../../include/game_globals.h"

struct RGE_Pick_Info {
    float x;  // +0x00
    float y;  // +0x04
};

struct MapInfo {
    char gap_00[8];
    int width;   // +0x08
    int height;  // +0x0C
};

class RGE_Main_View {
public:
    char gap_00[0x104];
    MapInfo* mapInfo;  // +0x104

protected:
    void fixup_pick_info(RGE_Pick_Info* info);
};

void RGE_Main_View::fixup_pick_info(RGE_Pick_Info* info) {
    if (info->x < 0.0f) {
        info->x = 0.0f;
    } else {
        float maxX = (float)this->mapInfo->width;
        if (info->x >= maxX) {
            info->x = maxX - 1.0f;
        }
    }
    if (info->y < 0.0f) {
        info->y = 0.0f;
        return;
    } else {
        float maxY = (float)this->mapInfo->height;
        if (info->y >= maxY) {
            info->y = maxY - 1.0f;
            return;
        }
    }
}
