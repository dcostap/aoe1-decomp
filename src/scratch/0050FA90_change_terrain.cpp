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
// left in scratch: canonical neighborhood behavior and field ownership are
// reconstructed; remaining drift is VC5 local/register scheduling.

class RGE_Tile_List {
public:
    void add_node(int x, int y);
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
    unsigned char** map_row_offset;

    void get_border_type(short row, short col);
};

class TRIBE_Map : public RGE_Map {
public:
    void change_terrain(short x, short y, unsigned char terrain,
                        RGE_Game_World* world);
};

void TRIBE_Map::change_terrain(short x, short y, unsigned char terrain,
                               RGE_Game_World* world)
{
    RGE_Player* player;
    unsigned char* tile;
    unsigned char old_border;
    short col_start;
    short col_end;
    short row_start;
    short row_end;

    tile = this->map_row_offset[y] + (int)x * 24;
    old_border = tile[5];
    tile[5] = (terrain ^ old_border) & 0x1F ^ old_border;

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

    col_end = x;
    if (x != this->map_width - 1)
        ++col_end;

    row_end = y;
    if (y != this->map_height - 1)
        ++row_end;

    y = row_start;
    for (; y <= row_end; ++y) {
        x = col_start;
        for (; x <= col_end; ++x) {
            tile = this->map_row_offset[y] + (int)x * 24;
            old_border = tile[6];
            terrain = old_border >> 4;
            old_border &= 0x0F;

            this->get_border_type(x, y);

            if (player != 0) {
                if ((tile[6] & 0x0F) != old_border ||
                    (tile[6] >> 4) != terrain) {
                    if (world->game_state != 3)
                        player->diam_tile_list.add_node(x, y);
                }
            }
        }
    }
}
