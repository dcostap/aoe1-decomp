// VA: 0050FA90 change_terrain (427B)
// tmap.cpp
//
// Attempt log:
// baseline: clean reconstruction from the tmap.cpp packet and the exact
// set_terrain_absolute donor's tile/XOR ownership.
// probes 2-7: raw byte addressing, parameter-home cursor reuse, border-nibble
// scheduling, and packet-local aliases were tested; the typed/raw structure
// stabilized at an exact 0x1c frame with three correctly aligned calls.
// probes 8-9: <=0 current-player spelling and alias declaration order changed
// branch/layout families without resolving the saved-this/top scheduling gap.
// fresh pass: typed RGE_Tile fields and a separate inner col cursor preserved
// the best structural basin (347 differing bytes, 0x1c frame, 3 aligned calls).
// Live initial x/y aliases and a retained map-row alias were duplicates or
// broader. A terrain-byte pointer moved the metric to 337 but was restored as
// unsupported scheduling scaffolding. The positive player-validity predicate
// was a duplicate of the older 421-byte basin and was restored.
// shardA4-50FA90-r1: declaration-initialized the first typed tile, but VC5
// emitted the same 439-byte basin; restored to the clean assignment form.
// shardA4-50FA90-r1: used the direct terrain XOR expression from the exact
// map donor; VC5 again emitted the same basin, so kept the named old byte.
// shardD10_50FA90: gave RGE_Player its canonical polymorphic surface while
// preserving diam_tile_list at +0x6C for the typed notification call; this
// was a codegen duplicate, so restored the narrow local surface.
// shard-dd8102ca: direct typed map indexing and a terrain-byte pointer reduced
// strict diff to 337, but worsened the block shape and were restored. Widened
// x/y aliases changed only clipping LEAs. A full RGE_Map vptr surface was a
// codegen duplicate. Keeping old_border masked before get_border_type matched
// the oracle's live-byte ordering better than a late mask.
// left in scratch: canonical neighborhood behavior and field ownership are
// reconstructed; remaining drift is VC5 prologue/register scheduling. The
// rebuilt body remains 12 bytes longer than the 427-byte oracle.
// sa-44c7d2a6-r1: local Ghidra evidence supports distinct narrow and widened
// coordinate lives, but typed alias variants were duplicates or worse. A
// guarded do-while rewrite changed the CFG and frame, so the natural for
// loops remain authoritative. The unresolved gap is structural codegen only.
// sa-956e4590-r1: verified the target's row/column roles against the original
// map access and tested swapped parameter naming and coordinate expressions;
// both emitted the same or worse nonexact structural basin. Restored the
// pinned natural map_row_offset[y] + x reconstruction for final validation.
// sa-961a69cd-r1: tested the original bound-store topology. The clean
// col_end=x; if (x != width-1) ++col_end form emitted two pre/post stores and
// a 439-byte body. Conditional bound assignments emitted the original
// common post-branch stores, exact 427-byte size, 142 instructions, and
// 93.66% shape similarity. Retained the conditional form as the best natural
// structural reconstruction. Direct/raw tile forms, coordinate aliases,
// register hints, and loop-scope changes were duplicates or worse.
// Earlier accepted-drift audit: do not promote the old source. It read the
// external tile byte before the incoming terrain byte and changed fault state.
// sa-557c93eb-r1: the exact later tmap.cpp stdlib context plus a natural byte
// accumulator recovered the executable's input-byte-first terrain transform.
// The first 0x88 bytes then matched exactly. Binary stack homes prove that
// col_start and row_start are int values. Restoring those widths also recovered
// every neighbor-bound block and both lower-bound LEAs. The remaining basin is
// one byte longer: VC5 reads x into DI, while the executable reads the complete
// incoming dword into EDI. Short lower bounds restore that load but lose the
// proved int-bound LEA. Scoped aliases, register hints, declaration timing,
// and the polymorphic map prefix were duplicates or worse. The retained source
// preserves the executable's tile-fault read order and all map writes/calls.
// sa-13047c13-r1 grouped context: the owner-include wrapper compiled this
// owner after 0050F8D0 in PDB order with /O2 /Oy /GX. Exact sibling anchors
// 0050F410, 0050F760, 0050F7A0, 0050F7B0, 0050F7F0, 0050F800, and 0050F860
// stayed exact in fresh standalone checks. The grouped owner symbol is
// PDB-qualified, but the target remains 428 bytes with a 392-byte diff. The
// grouped context does not recover the original EDI dword load.

#include <stdlib.h>

#ifndef TMAP_GROUP_CONTEXT
class RGE_Tile_List {
public:
    void add_node(int x, int y);
};

class RGE_Tile {
public:
    char gap_00[5];
    unsigned char terrain;
    unsigned char border;
    char gap_07[0x11];
};

class RGE_Player {
public:
    char gap_00[0x6C];
    RGE_Tile_List diam_tile_list;
};

class RGE_Game_World {
public:
    char gap_00[0x1D];
    unsigned char game_state;
    char gap_1E[0x1E];
    short player_num;
    char gap_3E[0x2];
    RGE_Player** players;
    char gap_44[0x38];
    short curr_player;
};

class RGE_Map {
public:
    char gap_00[0x8];
    long map_width;
    long map_height;
    char gap_10[0x8D7C];
    RGE_Tile** map_row_offset;

    void get_border_type(short row, short col);
};

class TRIBE_Map : public RGE_Map {
public:
    void change_terrain(short x, short y, unsigned char terrain,
                        RGE_Game_World* world);
};
#else
#include "../../include/tmap_context.h"
#endif

void TRIBE_Map::change_terrain(short x, short y, unsigned char terrain,
                               RGE_Game_World* world)
{
    RGE_Player* player;
    RGE_Tile* tile;
    unsigned char old_border;
    int col_start;
    short col_end;
    int row_start;
    short row_end;
    short col;

    tile = this->map_row_offset[y] + x;
    old_border = terrain;
    old_border ^= tile->terrain;
    old_border &= 0x1F;
    old_border ^= tile->terrain;
    tile->terrain = old_border;

    if (world->curr_player <= 0 || world->curr_player >= world->player_num)
        player = 0;
    else
        player = world->players[world->curr_player];

    if (player != 0 && world->game_state != 3)
        player->diam_tile_list.add_node(x, y);

    if (x == 0)
        col_start = 0;
    else
        col_start = x - 1;

    if (y == 0)
        row_start = 0;
    else
        row_start = y - 1;

    col_end = (x == this->map_width - 1) ? x : x + 1;
    row_end = (y == this->map_height - 1) ? y : y + 1;

    y = row_start;
    for (; y <= row_end; ++y) {
        col = col_start;
        for (; col <= col_end; ++col) {
            tile = this->map_row_offset[y] + col;
            old_border = tile->border;
            terrain = old_border >> 4;
            old_border &= 0x0F;

            this->get_border_type(col, y);

            if (player != 0) {
                if ((tile->border & 0x0F) != old_border ||
                    (tile->border >> 4) != terrain) {
                    if (world->game_state != 3)
                        player->diam_tile_list.add_node(col, y);
                }
            }
        }
    }
}
