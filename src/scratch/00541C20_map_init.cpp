// RGE_Game_World::map_init
// VA: 00541C20
// World.cpp:831-833
// 97 bytes, 21 diff bytes (21.65%)
// EH frame scheduling differences (TU-context):
//   - push 0 (handler) vs push real handler address
//   - Shared vs separate epilogue structure
//   - load ecx before vs after store map
// 8+ source forms tried (new, operator_new, placement new, try/catch).
// With /GX flag (World.cpp TU was compiled with EH).

// Attempt log:
// v1: new RGE_Map(...) — correct sizeof(0x8DD0), almost-right EH frame.
//     Remaining: push 0 vs push handler (TU), epilogue sharing (TU).
// v2: operator_new + explicit construct call — no EH frame (64 bytes).
// v3: try/catch — 73% diff, way off.
// v4-GX+new: 21% diff, best result. EH handler addr + epilogue sharing are TU-context.

#include "../../include/game_globals.h"

class RGE_Game_World {
public:
    char gap_00[0x28];
    void* map;           // +0x28
    char gap_2C[4];      // +0x2C padding
    void* sounds;        // +0x30

    void map_init(int param_1, void* param_2);
};

class RGE_Map {
public:
    char gap[0x8DD0];
    RGE_Map(int param_1, void* sounds, int param_3);
};

void RGE_Game_World::map_init(int param_1, void* param_2) {
    RGE_Map* new_map = new RGE_Map(param_1, this->sounds, 1);
    this->map = new_map;
}
