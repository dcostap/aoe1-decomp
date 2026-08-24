// VA: 005467B0, RGE_Zone_Map::RGE_Zone_Map, 268 bytes
// Source: zone_map.cpp lines 78-112
// ACCEPTED_DRIFT: prologue register allocation differs (original loads
// param_2 into EAX before pushes; modern compiler saves registers first
// then loads param_2 into EDI). This cascading register name difference
// throughout the function body. All behavior identical.
//
// Remaining drift:
// 1. Prologue: original `mov eax, [esp+8]; push ebx; push esi; mov esi,
//    ecx; push edi` (param_2 in EAX). Rebuilt: `push ebx; push esi; push
//    edi; mov edi, [esp+14h]; mov esi, ecx` (param_2 in EDI). Different
//    ordering of param load vs register saves, different register.
// 2. Second calloc: original reloads `this->map` from [esi+518h] after
//    first calloc (because EAX was overwritten). Rebuilt keeps param_2
//    in EDI across the calloc calls, avoiding the reload.
// 3. Register names differ throughout (eax↔ecx, ecx↔edx, etc.) due to
//    the EAX/EDI prologue difference cascading.
//
// What matches: function size (268 bytes), loop structure (reloads
// this->map from [+518h] each iteration, scaled-index store, cmp/jl),
// all calloc calls, all rge_read calls with correct offsets (zone_info
// at +0x40C, this at 0, zone_map at +0x404, terrain_passability_rules
// at +0x510, rules_num at +0x514, map at +0x518), the if/else for
// terrain_passability_rules allocation, epilogues (return this, ret 8).
//
// Attempt log:
// - v1: loop didn't reload this->map from memory each iteration → 256 bytes
// - v2: forced reload via `this->map->map_height` → 268 bytes, prologue
//   register allocation difference persists
// - Conclusion: modern compiler optimizes param_2 register differently
//   (EDI instead of EAX), producing identical behavior with different
//   register names throughout.
// FLAGS: /nologo /c /O2 /Oy

#include <stdlib.h>

#ifndef ZONE_MAP_TU_BUILD
typedef unsigned char uchar;

void* calloc(size_t num, size_t size);

struct RGE_Map {
    char _pad_00[0x08];
    long map_width;      // +0x08
    long map_height;     // +0x0C
};

class RGE_Zone_Map {
public:
    int numberTilesInZoneValue[257];       // +0x000 (0x404 bytes)
    uchar* zone_map;                       // +0x404
    uchar** zone_map_rows;                 // +0x408
    uchar zone_info[257];                  // +0x40C
    char _pad_50D[3];                      // +0x50D
    float* terrain_passability_rules;      // +0x510
    long terrain_passability_rules_num;    // +0x514
    RGE_Map* map;                          // +0x518

    RGE_Zone_Map(int param_1, RGE_Map* param_2);
};
#endif

void rge_read(int handle, void* buf, int count);

RGE_Zone_Map::RGE_Zone_Map(int param_1, RGE_Map* param_2)
{
    this->map = param_2;

    this->zone_map = (uchar*)calloc(param_2->map_width * param_2->map_height, 1);
    this->zone_map_rows = (uchar**)calloc(param_2->map_height, 4);

    for (int i = 0; i < this->map->map_height; i++) {
        this->zone_map_rows[i] = this->zone_map + this->map->map_width * i;
    }

    rge_read(param_1, this->zone_info, 0xFF);
    rge_read(param_1, this, 0x3FC);

    rge_read(param_1, this->zone_map, this->map->map_height * this->map->map_width);

    rge_read(param_1, &this->terrain_passability_rules_num, 4);
    if (this->terrain_passability_rules_num > 0) {
        this->terrain_passability_rules = (float*)calloc(this->terrain_passability_rules_num, 4);
        rge_read(param_1, this->terrain_passability_rules, this->terrain_passability_rules_num * 4);
    } else {
        this->terrain_passability_rules = NULL;
    }
}
