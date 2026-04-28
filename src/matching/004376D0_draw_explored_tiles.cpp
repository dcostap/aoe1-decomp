// 004376D0 draw_explored_tiles (137 bytes) — MATCHED
// PDB: diam_map.cpp (RGE_Diamond_Map::draw_explored_tiles)

extern char s_draw_explored_tiles[];

class RGE_Tile_List {
public:
    void get_list_info(void** list, int* count);
};

class TDrawArea {
public:
    void* Lock(char* debug_str, int flag);
    void Unlock(char* debug_str);
};

class RGE_Player {
public:
    char gap_6C[0x6C];
    RGE_Tile_List diam_tile_list;
};

class RGE_Diamond_Map {
public:
    char gap_F8[0xF8];
    RGE_Player* player;
    char gap_FC[0x6C];
    TDrawArea* save_area;  // at +0x168

    void draw_explored_tiles();
    void draw_tile(short x, short y, int param3, int param4);
};

void RGE_Diamond_Map::draw_explored_tiles()
{
    int list_size;
    int count;

    this->player->diam_tile_list.get_list_info((void**)&list_size, &count);

    if (count > 0) {
        if (this->save_area->Lock(s_draw_explored_tiles, 1)) {
            int i;
            i = 0;
            while (i < count) {
                this->draw_tile(*(short*)list_size, *(short*)(list_size + 4), 0, 0);
                i++;
                list_size += 8;
            }
            this->save_area->Unlock(s_draw_explored_tiles);
        }
    }
}
