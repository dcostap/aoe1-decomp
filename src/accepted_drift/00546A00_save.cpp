// VA: 00546A00 RGE_Zone_Map::save (129 B)
// PDB source: zone_map.cpp

extern int rge_write(void* file, void* data, int size);

// Layout derived from save function:
// +0x000: main_data[0x3FC] (1020 bytes, bulk write)
// +0x3FC: gap[8] (two ints or zone geometry data)
// +0x404: zone_data_ptr
// +0x408: gap[4]
// +0x40C: name[0xFF]
// +0x50B: gap[5]
// +0x510: array_ptr
// +0x514: item_count
// +0x518: zone_header_ptr

struct RGE_Zone_Map {
    // Main data block (0 to 0x3FB)
    char bulk_data[0x3FC];
    
    // +0x3FC: gap area containing zone geometry data
    
    // Save function:
    void save(void* file);
};

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
