// target: VA 00471D70 RGE_Tile_List::add_node(int,int)
// pass notes: Direct member use keeps EBX as this. VC5 lowers the aggregate
// copy as rep movsd/movsb.
// Removing the cached source-list alias restores the original load lifetime.

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
    if (this->num_active >= this->list_size) {
        RGE_Tile_List_Node* new_list;
        new_list = (RGE_Tile_List_Node*)calloc(this->list_size * 2, sizeof(RGE_Tile_List_Node));
        memcpy(new_list, this->list, this->list_size * sizeof(RGE_Tile_List_Node));
        free(this->list);
        this->list = new_list;
        this->list_size = this->list_size * 2;
    }

    this->list[this->num_active].col = col;
    this->list[this->num_active].row = row;
    this->num_active++;
    this->new_count++;
}
