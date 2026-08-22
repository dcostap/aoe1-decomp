// VA: 0050F8D0 check_tile_for_forest_change (434B)
// tmap.cpp
//
// Attempt log:
// baseline: clean reconstruction from the packet's forest/wood object-list
// behavior and the exact tmap.cpp tile layout.
// probes 2-8: switch dispatch, tile initializer order, byte/typed tile
// surfaces, parameter naming, and register declarations were tested; the
// switch form is the best structural basin (0x14 frame, 3 calls, 75.16%
// shape, 388-byte strict diff).
// probe 9: explicit pointer/count neighborhood loops were rejected; they
// increased the code to 454 bytes. Restored the natural nested loops.
// probes 11-13, 17: unqualified/qualified recursive calls, a reversed tile
// address, and an explicit zero guard were codegen duplicates. Probes 14-16
// changed bound declaration/address order but worsened the structural basin.
// probe 20: inlined the one-use terrain expression in the switch; this
// natural local-lifetime change improved strict diff 388 -> 384 bytes but
// left the first prologue hunk and recursive-call relocation unchanged.
// probe 35: declared the changed flag before object_found; VC5 moved the
// flag homes and reduced strict diff 384 -> 255 bytes, but did not fix the
// parameter colors or recursive relocation.
// probes 36-37: swapped parameter identifiers and used native bool flags;
// both were codegen duplicates. Probe 38: explicit row/tile pointers made
// the source less natural and widened the diff to 388 bytes; restored.
// probe 39: unqualified change_terrain calls were a codegen duplicate.
// sa-068dd50f-r1 pass: revalidated the typed tile stride (0x18), terrain byte
// (+5), object-list link (+0x10), master id (+0x14), object field (+0x48),
// map dimensions (+8/+C), and row table (+0x8D8C). Tested coordinate
// declaration order, flag order, pointer/count loops, tile initialization,
// register qualification, and coordinate aliases. Only the current clean
// direct-loop basin remained plausible; final validation is 423/434 bytes,
// 255 differing bytes, 0x14 frame, and 3 calls. The unresolved drift is
// parameter register coloring, forest-loop lowering, and self-call identity.
// sa-0cb5a865-r1 revisit: Ghidra-supported mutable-column traversal improved
// structural resync but worsened strict bytes; typed row cursors, map-row
// aliases, a proven vtable slot, declaration orders, and y/register qualifiers
// were worse or codegen duplicates. Restored the clean direct-loop source.
// sa-86e6c1ab-r1 revisit: signed terrain typing was a codegen duplicate. An
// int row/cell pointer-count loop reduced edit cost but kept 255 strict bytes;
// precomputed pointer guards and a named terrain byte worsened the basin.
// Restored the pinned direct-loop source. Final validation remains 255 differing
// bytes, 423/434 bytes, 0x14 frame, 3 calls, and unresolved self-call identity.
// sa-987bfe3a-r1 probes 46-54: qualifying both coordinate formals, swapping
// their formal order while preserving behavior, adding <stdlib.h>, and adding
// declaration-only polymorphic/full tmap map surfaces were all codegen
// duplicates at 255 differing bytes. Restored the pinned direct-loop source.
// left in scratch: behavior and field ownership are reconstructed; remaining
// drift is prologue/register scheduling plus recursive-call relocation. The
// best validated source is the flag-order variant at 255 differing bytes.

class RGE_Game_World;

class RGE_Master_Static_Object {
public:
    char gap_00[0x14];
    short id;
};

class RGE_Static_Object {
public:
    char gap_00[0x08];
    RGE_Master_Static_Object* master_obj;
    char gap_0C[0x3C];
    unsigned char field_48;
};

class RGE_Object_Node {
public:
    RGE_Static_Object* object;
    RGE_Object_Node* next;
};

class RGE_Tile {
public:
    char gap_00[0x05];
    unsigned char terrain;
    char gap_06[0x0A];
    RGE_Object_Node* object_list;
    char gap_14[0x04];
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
    void change_terrain(short x, short y, unsigned char terrain,
                        RGE_Game_World* world);
    void check_tile_for_forest_change(short x, short y,
                                      RGE_Game_World* world);
};

void TRIBE_Map::check_tile_for_forest_change(short x, short y,
                                             RGE_Game_World* world)
{
    RGE_Tile* tile = this->map_row_offset[y] + x;
    short x0 = x - 1;
    short x1 = x + 1;
    short y0 = y - 1;
    short y1 = y + 1;
    unsigned char changed = 0;
    unsigned char object_found = 0;
    if (x0 < 0)
        x0 = 0;
    if (y0 < 0)
        y0 = 0;
    if (x1 >= this->map_width)
        x1 = (short)this->map_width - 1;
    if (y1 >= this->map_height)
        y1 = (short)this->map_height - 1;

    switch (tile->terrain & 0x1F) {
    case 0x0A: {
        for (short row = y0; row <= y1; ++row) {
            for (short col = x0; col <= x1; ++col) {
                unsigned char nearby = (this->map_row_offset[row] + col)->terrain & 0x1F;
                if (nearby != 0x0A && nearby != 0x12)
                    changed = 1;
            }
        }

        if (changed)
            change_terrain(x, y, 0x12, world);
        break;
    }
    case 0x12: {
        for (RGE_Object_Node* node = tile->object_list; node != 0;
             node = node->next) {
            RGE_Static_Object* object = node->object;
            if (object->master_obj->id == 0x0F && object->field_48 < 8)
                object_found = 1;
        }

        if (!object_found) {
            change_terrain(x, y, 0, world);
            for (short row = y0; row <= y1; ++row) {
                for (short col = x0; col <= x1; ++col) {
                    if (col != x || row != y)
                        this->check_tile_for_forest_change(col, row, world);
                }
            }
        }
        break;
    }
    default:
        break;
    }
}
