// VA: 00547270 RGE_Zone_Map_List::save (62 B, 31 asm)
// PDB source: zone_map.cpp lines 481-490
//
// Attempt log:
// 1. Current (prior work): do-while with int* count local, int i in block scope.
//    82% diff: wrong prologue order, esi saved inside if-block, missing redundant bounds check.
// 2. Inline &zone_map_num, for-loop at function scope, trying to fix prologue.

extern "C" void __cdecl rge_write(int handle, void* buffer, int count);

#ifndef ZONE_MAP_TU_BUILD
class RGE_Map;
class RGE_Zone_Map {
public:
    void save(int param);
};

class RGE_Zone_Map_List {
public:
    RGE_Zone_Map** zone_maps;     // +0x00
    int zone_map_num;             // +0x04
    RGE_Map* map;                 // +0x08

    void save(int param);
};
#endif

void RGE_Zone_Map_List::save(int param) {
    int i;

    rge_write(param, &zone_map_num, 4);
    if (zone_map_num > 0) {
        for (i = 0; i < zone_map_num; i++) {
            zone_maps[i]->save(param);
        }
    }
}
