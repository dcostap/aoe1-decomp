#ifndef PLAYER_GROUPED_TU
class RGE_Tile_List {
public:
    char gap_00[0x10];
    void* list;

    ~RGE_Tile_List();
};
#endif

extern "C" void __cdecl free(void* ptr);

RGE_Tile_List::~RGE_Tile_List() {
    if (this->list) {
        free(this->list);
    }
}
