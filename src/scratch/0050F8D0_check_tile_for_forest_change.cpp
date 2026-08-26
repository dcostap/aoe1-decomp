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
// sa-557c93eb-r1: restored the PDB line-212 center-tile initializer, y-bound
// declaration order, a byte switch selector, and the decompiler-supported
// typed counted forest scan. The result has the exact 434-byte boundary,
// frame, calls, CFG counts, and first 102 instructions through +0x12C.
// The strict diff fell from 255 to 76 bytes. The remaining emitted drift is
// localized to forest row-slot addressing: the executable materializes the
// current row slot, while VC5 folds that slot into the first indexed load and
// biases the later cursor to the next row. Equivalent typed cursor order,
// split assignments, a named row table, and a named next-row pointer were
// duplicates. Pre-increment forms changed the complete register basin.
// sa-13047c13-r1 grouped context: the owner-include wrapper compiled this
// owner and 0050FA90 in PDB order with /O2 /Oy /GX. Exact sibling anchors
// 0050F410, 0050F760, 0050F7A0, 0050F7B0, 0050F7F0, 0050F800, and 0050F860
// stayed exact in fresh standalone checks. The grouped owner symbol is
// PDB-qualified. The context-enabled owner now emits 433 bytes with the same
// 76-byte diff in both isolated and grouped builds. The grouped context does
// not recover the row-slot load; the prior clean source was 434 bytes.
// sa-7e83054e-r1 fresh context gate: module tmap.cpp, source band 210-259,
// owner TRIBE_Map, address sequence 0050F8D0 then 0050FA90, and exact wrapper
// anchors through 0050F860 are proved by the PDB line map and grouped checks.
// The copied prior journal already rejects equivalent cursor-order forms. A
// fresh loop-local scope edit was attempted, then restored after its compile
// error. The remaining drift is the forest row-slot lowering and the
// diagnostic recursive-call identity.

#include <stdlib.h>

#ifndef TMAP_GROUP_CONTEXT
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
#else
// The tmap translation-unit wrapper supplies src/tmap_context_local.h.
#endif

void TRIBE_Map::check_tile_for_forest_change(short x, short y,
                                             RGE_Game_World* world)
{
    RGE_Tile* tile = this->map_row_offset[y] + x;
    short y0 = y - 1;
    short y1 = y + 1;
    short x0 = x - 1;
    short x1 = x + 1;
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

    unsigned char terrain = tile->terrain & 0x1F;
    switch (terrain) {
    case 0x0A: {
        RGE_Tile** row_cursor;
        RGE_Tile* row_tile;
        row_tile = this->map_row_offset[y0] + x0;
        row_cursor = this->map_row_offset + y0;
        if (y0 <= y1) {
            int row_count = (int)y1 - (int)y0 + 1;
            do {
                if (x0 <= x1) {
                    RGE_Tile* scan = row_tile;
                    int col_count = (int)x1 - (int)x0 + 1;
                    do {
                        unsigned char nearby = scan->terrain & 0x1F;
                        if (nearby != 0x0A && nearby != 0x12)
                            changed = 1;
                        ++scan;
                    } while (--col_count != 0);
                }
                row_tile = row_cursor[1] + x0;
                ++row_cursor;
            } while (--row_count != 0);
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
