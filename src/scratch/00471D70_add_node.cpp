// target: VA 00471D70 RGE_Tile_List::add_node(int,int)
// first pass: natural grow/copy/free then append node.

extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);
extern "C" void __cdecl free(void* ptr);

struct RGE_Tile_List_Node {
    int col;
    int row;
};

class RGE_Tile_List {
public:
    int list_size;
    int num_active;
    int new_count;
    char gap_0C[4];
    RGE_Tile_List_Node* list;

    void add_node(int col, int row);
};

void RGE_Tile_List::add_node(int col, int row) {
    RGE_Tile_List* self = this;
    if (self->num_active >= self->list_size) {
        RGE_Tile_List_Node* new_list;
        new_list = (RGE_Tile_List_Node*)calloc(self->list_size * 2, sizeof(RGE_Tile_List_Node));
        if (self->list_size != 0) {
            RGE_Tile_List_Node* src = self->list;
            RGE_Tile_List_Node* dst = new_list;
            int count = self->list_size;
            do {
                *dst = *src;
                src++;
                dst++;
                count--;
            } while (count != 0);
        }
        free(self->list);
        self->list = new_list;
        self->list_size = self->list_size * 2;
    }

    self->list[self->num_active].col = col;
    self->list[self->num_active].row = row;
    self->num_active++;
    self->new_count++;
}
