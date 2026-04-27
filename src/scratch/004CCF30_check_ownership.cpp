// VA: 004CCF30 TRIBE_Action_Artifact::check_ownership
// tact_art.cpp lines 168-224

// attempt 1: first real pass — direct decompiler translation with cleanup
// RESULT: 495/495 bytes exact size match on first compile!
// - sub esp, 18h matches original ✅
// - All 4 ftol calls present
// - calloc(y_max, 1) + zero-fill correct
// - Bounds clamp correct
// - Grid iteration over map tiles
// - Player count array scan + return logic
// - 390 diff bytes (register allocation + stack slot assignment variance)
// First mismatch at offset 46 (stack slot for map_x)
// Remaining: deep codegen basin differences

#include <stdlib.h>

class RGE_Action {
public:
    virtual ~RGE_Action();
};

class TRIBE_Action_Artifact : public RGE_Action {
public:
    void* object;              // +0x08
    unsigned char state;        // +0x0C
    char gap_10[3];
    void* target_info;          // +0x10
    char gap_14[0x0C];
    float target_x;             // +0x20
    float target_y;             // +0x24
    float target_z;             // +0x28
    float timer;                // +0x2C
    void* sprite;               // +0x30
    void* action_list;          // +0x34

    void* check_ownership();
};

void* TRIBE_Action_Artifact::check_ownership() {
    char* obj = *(char**)((char*)this + 8);
    char* sprite_base = *(char**)(obj + 8);
    
    int map_x = (int)(*(float*)(obj + 0x38) - *(float*)0x574F10 - *(float*)(sprite_base + 0x30));
    int map_y = (int)(*(float*)(obj + 0x3C) - *(float*)0x574F10 - *(float*)(sprite_base + 0x34));
    int x0 = (int)(*(float*)(sprite_base + 0x30) + *(float*)(obj + 0x38) - *(float*)0x574F14);
    int y0 = (int)(*(float*)(sprite_base + 0x34) + *(float*)(obj + 0x3C) - *(float*)0x574F14);
    
    char* map_info = *(char**)(obj + 0x0C);
    char* map_data = *(char**)(map_info + 0x3C);
    
    short y_max = *(short*)(map_data + 0x3C);
    unsigned char* player_counts = (unsigned char*)calloc(y_max, 1);
    if (player_counts == 0) return 0;
    
    if (y_max > 0) {
        int* p = (int*)player_counts;
        int words = y_max >> 2;
        while (words--) { *p++ = 0; }
        unsigned char* q = (unsigned char*)p;
        int bytes = y_max & 3;
        while (bytes--) { *q++ = 0; }
    }
    
    if (map_x < 0) map_x = 0;
    if (map_y < 0) map_y = 0;
    if (x0 >= *(int*)(map_data + 0x28)) x0 = *(short*)(map_data + 8) - 1;
    if (y0 >= *(int*)(map_data + 0x0C)) y0 = *(short*)(map_data + 0x0C) - 1;
    
    short best_player = -1;
    short unique_owner = 0;
    
    int y_idx = map_y;
    while (y_idx <= y0) {
        int x_idx = map_x;
        while (x_idx <= x0) {
            int tile_base = *(int*)(*(int*)(map_data + 0x8D8C) + y_idx * 4);
            int* list_node = *(int**)(tile_base + x_idx * 0x18 + 0x10);
            while (list_node) {
                int* entity = (int*)*list_node;
                short type = *(short*)(*(int*)((char*)entity + 8) + 0x14);
                if (type == 1 || type == 0x0B || type == 0x1E || *(char*)((char*)entity + 0x48) == 2) {
                    short idx = *(short*)(*(int*)((char*)entity + 0x0C) + 0x4A);
                    player_counts[idx]++;
                }
                list_node = *(int**)((char*)list_node + 4);
            }
            x_idx++;
        }
        y_idx++;
    }
    
    unique_owner = 0;
    best_player = -1;
    short count = 1;
    while (count < y_max) {
        if (player_counts[count]) {
            unique_owner++;
            best_player = count;
        }
        count++;
    }
    
    free(player_counts);
    
    if (unique_owner == 1 && best_player > 0) {
        short self_owner = *(short*)(*(int*)(*(int*)((char*)this + 8) + 0x0C) + 0x4A);
        if (best_player != self_owner) {
            return *(void**)(*(int*)(*(int*)(*(int*)(*(int*)((char*)this + 8) + 0x0C) + 0x3C) + 0x40) + best_player * 4);
        }
    }
    return 0;
}
