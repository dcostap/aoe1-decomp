// target: VA 00471D70 RGE_Tile_List::add_node(int,int)
// pass notes: natural loop copy uses ESI as this and emits element loop. Original uses EBX=this and VC5 lowers aggregate copy as rep movsd/movsb.
// tried explicit self local: no change. Need source/context to force EBX and memcpy/aggregate-copy basin.

extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);
extern "C" void __cdecl free(void* ptr);
extern "C" void* __cdecl memcpy(void* dst, const void* src, unsigned int size);

struct RGE_Tile_List_Node {
    int col;
    int row;
};

#ifndef PLAYER_GROUPED_TU
class RGE_Tile_List {
public:
    int list_size;
    int num_active;
    int new_count;
    char gap_0C[4];
    RGE_Tile_List_Node* list;

    void add_node(int col, int row);
};
#endif

void RGE_Tile_List::add_node(int col, int row) {
    RGE_Tile_List_Node* tiles = (RGE_Tile_List_Node*)this->list;
    if (this->num_active >= this->list_size) {
        RGE_Tile_List_Node* new_list;
        new_list = (RGE_Tile_List_Node*)calloc(this->list_size * 2, sizeof(RGE_Tile_List_Node));
        memcpy(new_list, tiles, this->list_size * sizeof(RGE_Tile_List_Node));
        free(tiles);
        this->list = new_list;
        this->list_size = this->list_size * 2;
    }

    tiles = (RGE_Tile_List_Node*)this->list;
    tiles[this->num_active].col = col;
    tiles[this->num_active].row = row;
    this->num_active++;
    this->new_count++;
}
