extern "C" void* __cdecl calloc(unsigned int, unsigned int);

#ifndef PLAYER_GROUPED_TU
class RGE_Tile_List_ctor {
public:
    RGE_Tile_List_ctor* ctor(int max_tiles);
    int max_count;
    int field_04;
    int field_08;
    int field_0C;
    void* tiles;
};

RGE_Tile_List_ctor* RGE_Tile_List_ctor::ctor(int max_tiles) {
    this->tiles = calloc(max_tiles, 8);
    this->max_count = max_tiles;
    this->field_04 = 0;
    this->field_08 = 0;
    this->field_0C = 0;
    return this;
}
#else
RGE_Tile_List::RGE_Tile_List(int max_tiles) {
    this->list = calloc(max_tiles, 8);
    this->list_size = max_tiles;
    this->num_active = 0;
    this->new_count = 0;
    this->collapse_list = 0;
}
#endif
