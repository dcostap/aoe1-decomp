// VA: 0053C920
// PDB: visible.cpp lines 665-767
// RGE_Visible_Map::unexplore_terrain(int a, int b, int c, int d, int e, int f)
// FLAGS: default

// Attempt log:
// v1: Basic class layout attempt. 90% diff.
// v2: Refined log_map_call parameter order and hash computation. 91% diff.
//
// Remaining gap: 366/401 bytes differ (91%).
// The function has complex features that need careful iteration:
// 1. EBP frame with 3 locals (push ebp; mov ebp, esp; sub esp, 0Ch)
// 2. 6 __thiscall parameters + this = ret 18h
// 3. log_map_call with 9 parameters (complex parameter reordering)
// 4. Hash: rol/xor/add chain with multiple rounds
// 5. LOS table lookup (NormalLOS vs SquareLOS based on param_4)
// 6. Nested loop over LOS table entries (3-int tuples, terminated by 999)
// 7. Inner loop over terrain cells with byte decrement/clamp
// 8. Array access through this->field_00 as base pointer
// 9. unified_map_offsets at [886808h]
// 10. this->map->row_offsets at [+0x8D8C] for tile struct (0x18 stride)
//
// Left in scratch: requires careful iteration through each of the above
// components to match the complex pointer arithmetic and loop structure.

#include <windows.h>

extern int Map_Update_Suppresion;
extern int* unified_map_offsets;
extern int NormalLOS[];
extern int SquareLOS[];

void log_map_call(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9);

class RGE_Player {
public:
    char gap_00[0x4A];
    short id;
};

class RGE_Map {
public:
    char gap_00[0x8D8C];
    int* row_offsets;
};

class RGE_Visible_Map {
public:
    char gap_00[0x04];
    RGE_Player* player;
    void* field_08;
    RGE_Map* map;
    char gap_10[0x04];
    int widthValue;
    int heightValue;
    char gap_1C[0x0C];
    int mask_invert;
    char gap_2C[0x08];
    int input_csum;
    
    void unexplore_terrain(int a, int b, int c, int d, int e, int f);
};

void RGE_Visible_Map::unexplore_terrain(int a, int b, int c, int d, int e, int f)
{
    RGE_Visible_Map* self = this;
    int tile_ptr = 0;
    int pl_id;
    
    log_map_call(
        Map_Update_Suppresion,
        d, c, b, a, f, 3,
        *(short*)((char*)this->field_08 + 0x4A),
        *(int*)((char*)this->player + 4)
    );
    
    if (Map_Update_Suppresion != 0)
        return;
    
    int csum = this->input_csum;
    int map_id = *(short*)((char*)this->field_08 + 0x4A);
    
    csum = (csum << 3) | ((unsigned int)csum >> 29);
    csum ^= 0x20202020;
    csum = (csum << 2) | ((unsigned int)csum >> 30);
    csum ^= map_id;
    csum = (csum << 3) | ((unsigned int)csum >> 29);
    csum ^= a;
    csum = (csum << 4) | ((unsigned int)csum >> 28);
    csum ^= b;
    csum = (csum << 3) | ((unsigned int)csum >> 29);
    csum ^= c;
    csum += d;
    
    this->input_csum = csum;
    
    if (c > 16) c = 16;
    
    int* los_table;
    if (d != 0)
        los_table = &SquareLOS[c];
    else
        los_table = &NormalLOS[c];
    
    int los_val = *los_table;
    while (los_val != 999) {
        los_val += b;
        
        if (los_val >= 0 && los_val < this->heightValue) {
            int x1 = los_table[1] + a;
            if (x1 < 0) x1 = 0;
            
            int x2 = los_table[2] + a;
            if (x2 >= this->widthValue)
                x2 = this->widthValue - 1;
            
            unsigned char* map_cells = (unsigned char*)(*(int*)self + los_val * 4) + x1;
            int* vis_map = (int*)(unified_map_offsets[los_val] + x1);
            
            if (e != 0) {
                int* rows = (int*)this->map->row_offsets;
                int row_base = (int)rows[los_val];
                tile_ptr = (int)((char*)row_base + (x1 * 2 + x1) * 8 + x1);
            }
            
            if (x1 <= x2) {
                int count = x2 - x1 + 1;
                do {
                    unsigned char val = *map_cells - 1;
                    if ((unsigned char)val == 0xFF)
                        val = 0;
                    
                    if (val == 0) {
                        if (e != 0)
                            ((char*)tile_ptr)[9] = (char)0x80;
                        *vis_map &= this->mask_invert;
                    }
                    
                    *map_cells = val;
                    map_cells++;
                    vis_map++;
                    tile_ptr += 0x18;
                    count--;
                } while (count != 0);
            }
        }
        
        los_table += 3;
        los_val = *los_table;
    }
}
