// VA: 0050FF20 TRIBE_Map::find_cliff (245 bytes) — MATCHED
// PDB: tmap.cpp lines 463-485
// Calling convention: __thiscall
// Returns: RGE_Static_Object*
// Parameters: (long param_1, long param_2)
//
// Key insight: block-scoping each loop and returning by reading directly
// from node pointer (return *(RGE_Static_Object**)node) produces the exact
// original codegen. Avoiding per-loop temp variables (obj, master) and
// computing grid rows inline (y1 + 1) instead of a y2 local was critical.

#ifndef TMAP_GROUP_CONTEXT
struct RGE_Static_Object;

struct RGE_Tile {
    char gap_00[0x10];
    void* object_list;
    char pad[0x04];
};

class RGE_Map {
public:
    char gap_00[0x08];
    long map_width;
    long map_height;
    char gap_10[0x8D7C];
    RGE_Tile** map_row_offset;
};

class TRIBE_Map : public RGE_Map {
public:
    RGE_Static_Object* find_cliff(long param_1, long param_2);
};
#endif

RGE_Static_Object* TRIBE_Map::find_cliff(long param_1, long param_2) {
    long x1 = param_1 * 3 + 1;
    long y1 = param_2 * 3 + 1;

    if (x1 + 1 > this->map_width) return 0;
    if (y1 + 1 > this->map_height) return 0;

    RGE_Tile** grid = this->map_row_offset;
    long offset = x1 * 24;

    // Loop 1: tile(y1, x1).list
    {
        void* node = (char*)grid[y1] + offset;
        node = *(void**)((char*)node + 0x10);
        while (node) {
            void* master = *(void**)(*(char**)node + 8);
            short tid = *(short*)((char*)master + 0x10);
            if (tid >= 0x108 && tid <= 0x111)
                return *(RGE_Static_Object**)node;
            node = *(void**)((char*)node + 4);
        }
    }

    // Loop 2: tile(y1 + 1, x1).list
    {
        void* node = (char*)grid[y1 + 1] + offset;
        node = *(void**)((char*)node + 0x10);
        while (node) {
            void* master = *(void**)(*(char**)node + 8);
            short tid = *(short*)((char*)master + 0x10);
            if (tid >= 0x108 && tid <= 0x111)
                return *(RGE_Static_Object**)node;
            node = *(void**)((char*)node + 4);
        }
    }

    // Loop 3: tile(y1, x1 + 1).list (via tile1 + 0x28 = next tile + 0x10)
    {
        void* node = (char*)grid[y1] + offset;
        node = *(void**)((char*)node + 0x28);
        while (node) {
            void* master = *(void**)(*(char**)node + 8);
            short tid = *(short*)((char*)master + 0x10);
            if (tid >= 0x108 && tid <= 0x111)
                return *(RGE_Static_Object**)node;
            node = *(void**)((char*)node + 4);
        }
    }

    // Loop 4: tile(y1 + 1, x1 + 1).list (via tile2 + 0x28 = next tile + 0x10)
    {
        void* node = (char*)grid[y1 + 1] + offset;
        node = *(void**)((char*)node + 0x28);
        while (node) {
            void* master = *(void**)(*(char**)node + 8);
            short tid = *(short*)((char*)master + 0x10);
            if (tid >= 0x108 && tid <= 0x111)
                return *(RGE_Static_Object**)node;
            node = *(void**)((char*)node + 4);
        }
    }

    return 0;
}
