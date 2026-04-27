// RGE_Map::RGE_Map ctor — first pass
// VA: 00455000
#include "../../include/game_globals.h"

extern void __cdecl rge_read(int fd, void* buf, int size);

void __fastcall RGE_Map_ctor(void* _this, int _, int param_1, void* param_2, unsigned char param_3)
{
    *(int*)((char*)_this) = 0x570678;          // vtable
    *(int*)((char*)_this + 0x8DC4) = 0;         // map_zones = 0
    rge_read(param_1, _this, 0x8DD0);           // read map data
    void* world = *(void**)((int)rge_base_game + 0x3F4);
    *(int*)((char*)_this + 4) = 0;              // map = 0
    *(void**)((char*)_this + 0x8DC0) = world;   // game_world
    *(int*)((char*)_this + 0x8DB0) = 0;         // search_map = 0
    *(int*)((char*)_this + 0x8D8C) = 0;         // map_row_offset = 0
    *(int*)((char*)_this + 0x8DB4) = 0;         // search_map_rows = 0
}
