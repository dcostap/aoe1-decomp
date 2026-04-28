// RGE_Main_View::fixup_pick_info
// VA: 00540680
// vw_main.cpp:1946-1956
// MATCH: 0.0000% diff, 4 relocations masked

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
