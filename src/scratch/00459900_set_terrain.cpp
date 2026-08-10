// set_terrain — clean period-plausible reconstruction
// VA: 00459900
// Source: map.cpp lines 2563-2597
//
// The map stores 24-byte tiles behind a row-offset table.  The low five bits
// of byte 5 are the terrain type; the upper bits are preserved when changing
// terrain.  A changed tile is redrawn, queued on the current player's
// diamond list unless the world is in state 3, and has its terrain objects
// rebuilt.
//
// Attempt log:
// - Baseline established the natural world/player/tile ownership and matched
//   frame, saved-register set, CFG, and all six call targets; it was 259 bytes
//   versus the original 255 with broad register/topology drift.
// - Corrected RGE_Map::game_world to +0x8DC0 and RGE_Tile to sizeof 0x18;
//   this was the best structural basin (205 positional differing bytes).
// - Tested direct tile-byte, declaration-order, initializer, retained-byte,
//   and parameter-reload variants.  They either emitted the same basin or
//   worsened structure/call parity.  The final source is restored to the
//   typed, period-plausible candidate; exact matching remains unresolved.
// Main-agent audit restored the canonical RGE_Player destructor surface at
// unchanged offsets; the validated 205-byte codegen gap is unchanged.
// Current TU pass: moving typed tile/old-terrain computation before the player
// setup made the function exact-sized but worsened positional drift to 248
// bytes; restored.  Adding the proven RGE_Map/RGE_Game_World virtual prefixes
// while preserving field offsets was a codegen duplicate of the clean source.
// Main-agent audit restored canonical polymorphic world/map ownership and kept
// natural typed tile and terrain-object operations.
// Current worker: assigning old_terrain directly in the comparison was a
// codegen duplicate; VC5 still hoisted the terrain-byte load and kept the
// same 205-byte structural gap. Restored the clean source.
// orch-map-01 pass: binary-backed local aggregate {short old_terrain,
// owner, cur_player} reproduced the +0x10/+0x14/+0x18 stack window and raised
// shape to 92.93%/60.61% exact blocks, but was 260 bytes and 213 positional
// differences; restored as diagnostic evidence. A five-body natural-source
// lab (raw byte, row/column cursors, tile pointer, explicit duplicate border
// tail) found no size/frame/call-set eligible exact variant. Removing map/world
// virtual declarations with corrected offsets was an emitted-code duplicate.

class RGE_Tile_List {
public:
    char gap_00[0x6C];
    void add_node(int col, int row);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x68];
    RGE_Tile_List diam_tile_list;
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0x19];
    unsigned char game_state;
    char gap_1E[0x22];
    RGE_Player** players;
    char gap_44[0x38];
    short curr_player;
};

class RGE_Tile {
public:
    char gap_00[5];
    unsigned char terrain_type;
    char gap_06[0x12];
};

class RGE_Map {
public:
    virtual ~RGE_Map();
    char gap_04[0x8D88];
    RGE_Tile** map_row_offset;
    char gap_8D90[0x30];
    RGE_Game_World* game_world;

    void set_terrain(RGE_Game_World* gw, short row, short col,
        unsigned char terrain, int param5, int param6);
    void request_redraw(int x0, int y0, int x1, int y1, unsigned char val);
    int clear_terrain_object(RGE_Game_World* gw, short col, short row,
        short old_terrain, int remove_now, int param5, int param6);
    void place_terrain_object(RGE_Player* player, RGE_Game_World* gw,
        short col, short row, int value, int flag);
    void get_border_type(short row, short col);
};

void RGE_Map::set_terrain(RGE_Game_World* gw, short row, short col,
    unsigned char terrain, int param5, int param6)
{
    RGE_Player* obj_owner;
    RGE_Player* cur_player;
    RGE_Tile* tile;
    short old_terrain;

    obj_owner = *gw->players;
    cur_player = this->game_world->players[this->game_world->curr_player];
    tile = &this->map_row_offset[col][row];
    old_terrain = (short)(tile->terrain_type & 0x1F);

    if (old_terrain != terrain) {
        tile->terrain_type = (terrain ^ tile->terrain_type) & 0x1F ^ tile->terrain_type;

        if (obj_owner != 0) {
            request_redraw((int)row, (int)col, (int)row, (int)col, 0);
            if (gw->game_state != 3) {
                cur_player->diam_tile_list.add_node((int)row, (int)col);
            }
            int value = clear_terrain_object(gw, col, row, old_terrain,
                1, param5, param6);
            place_terrain_object(obj_owner, gw, col, row, value, 0);
        }
    }

    get_border_type(row, col);
}
