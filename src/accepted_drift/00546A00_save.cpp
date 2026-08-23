// VA: 00546A00 RGE_Zone_Map::save (129 B)
// PDB source: zone_map.cpp

extern int rge_write(void* file, void* data, int size);
#include "../../include/rge_zone_map_context.h"

// Helper to access fields at specific offsets
#define AT(type, base, offset) (*(type*)((char*)(base) + (offset)))

void RGE_Zone_Map::save(void* file)
{
    char* self = (char*)this;
    
    // Write name at +0x40C
    rge_write(file, self + 0x40C, 0xFF);
    
    // Write main data block (0 to 0x3FB)
    rge_write(file, self, 0x3FC);
    
    // Write zone data
    void* zh_ptr = *(void**)(self + 0x518);  // zone_header_ptr at +0x518
    int* zh = (int*)zh_ptr;
    int zone_size = zh[3] * zh[2];  // height * width at offsets +0xC and +0x8
    void* zone_data = *(void**)(self + 0x404);  // zone_data_ptr at +0x404
    rge_write(file, zone_data, zone_size);
    
    // Write item count at +0x514
    int* item_count_ptr = (int*)(self + 0x514);
    rge_write(file, item_count_ptr, 4);
    
    // Write item array if count > 0
    if (*item_count_ptr > 0) {
        void* array_ptr = *(void**)(self + 0x510);
        rge_write(file, array_ptr, *item_count_ptr * 4);
    }
}
