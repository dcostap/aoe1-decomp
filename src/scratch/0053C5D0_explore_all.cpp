// tried the direct decompiler-shaped nested loops first; the remaining mismatch moved into the loop-body indexing
// switching to explicit row-pointer walks for map_offsets and unified_map_offsets
// if it stays non-exact, the remaining gap is likely just loop/register shape

extern unsigned long* unified_map_offsets[256];
extern void __cdecl log_map_call(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7, int param_8, int param_9);

class RGE_Game_World {
public:
    void* vtable_ptr;
    unsigned long world_time;
};

class RGE_Tile_List {
public:
    int list_size;
    int num_active;
    int new_count;
    int collapse_list;
    void* list;

    void add_node(int x, int y);
};

class RGE_Player {
public:
    char gap_00[0x4A];
    short id;
    char gap_4C[0x0C];
    RGE_Tile_List tile_list;
};

class RGE_Visible_Map {
public:
    unsigned char** map_offsets;
    RGE_Game_World* world;
    RGE_Player* player;
    void* map;
    unsigned char* visible_map;
    int widthValue;
    int heightValue;
    int numberTilesExploredValue;
    int numberTotalTilesValue;
    char gap_20[0x0C];
    unsigned long PlayerExploredMaskValue;

    void explore_all(void);
};

void RGE_Visible_Map::explore_all(void) {
    log_map_call(this->world->world_time, (int)this->player->id, 6, 0, 0, 0, 0, 0, 0);

    int y = 0;
    unsigned char** rowPtr = this->map_offsets;
    unsigned long** exploredPtr = unified_map_offsets;
    if (this->heightValue > 0) {
        do {
            int x = 0;
            if (this->widthValue > 0) {
                unsigned char* row = *rowPtr;
                unsigned long* explored = *exploredPtr;
                do {
                    if (row[x] == 0xFF) {
                        row[x] = 0;
                        this->numberTilesExploredValue++;
                        explored[x] |= this->PlayerExploredMaskValue;
                        this->player->tile_list.add_node(x, y);
                    }
                    x++;
                } while (x < this->widthValue);
            }
            y++;
            rowPtr++;
            exploredPtr++;
        } while (y < this->heightValue);
    }
    this->player->tile_list.collapse_list = 1;
}
