extern "C" void __cdecl free(void* ptr);
extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);

class RGE_Tile_List {
public:
    int list_size;
    int num_active;
    int new_count;
    int collapse_list;
    void* list;

    void del_list(void);
};

void RGE_Tile_List::del_list(void) {
    this->num_active = 0;
    this->new_count = 0;

    if (this->collapse_list != 0) {
        free(this->list);
        this->list_size = 8;
        this->list = calloc(8, 8);
        this->collapse_list = 0;
    }
}
