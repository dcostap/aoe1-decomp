// VA: 00480790 RGE_Random_Map_Module::RGE_Random_Map_Module (constructor)
// rmm_base.cpp:23-59

#ifndef RMM_BASE_SHARED_CONTEXT
class RGE_Map {
public:
    virtual ~RGE_Map();
    void* give_up_map_offsets();
    int get_map_width();
    int get_map_height();
};

class RGE_Random_Map_Module_List;

struct Map_Stack;

class RGE_Random_Map_Module {
public:
    int vtable;         // +0x00
    RGE_Random_Map_Module* parent;  // +0x04
    RGE_Random_Map_Module_List* list; // +0x08
    RGE_Map* map;       // +0x0C
    void* map_row_offset; // +0x10
    int map_width;      // +0x14
    int map_height;     // +0x18
    char gap_1C[4];     // +0x1C (unused)
    unsigned char* search_map;  // +0x20
    unsigned char** search_map_rows; // +0x24
    Map_Stack* stack_array;     // +0x28
    Map_Stack** stack_offsets;  // +0x2C

    RGE_Random_Map_Module(RGE_Map* map, RGE_Random_Map_Module* parent, unsigned char createShared);
    unsigned char add_module(RGE_Random_Map_Module* module);
    void create_shared_resources();
    void share_resources(void* a, void* b, void* c, void* d);
};
#endif

RGE_Random_Map_Module::RGE_Random_Map_Module(RGE_Map* map, RGE_Random_Map_Module* parent, unsigned char createShared) {
#ifndef RMM_BASE_SHARED_CONTEXT
    this->vtable = 0x571E30;
#endif
    this->parent = parent;
    this->map = map;

    if (map != 0) {
        this->map_row_offset = map->give_up_map_offsets();
        this->map_width = this->map->get_map_width();
        this->map_height = this->map->get_map_height();
    } else {
        this->map_row_offset = 0;
        this->map_width = 0;
        this->map_height = 0;
    }

    // BINARY NOTE: Publish empty state before a parent receives this object.
    this->list = 0;
    this->search_map = 0;
    this->search_map_rows = 0;
    this->stack_array = 0;
    this->stack_offsets = 0;

    if (this->parent == 0) {
        if (createShared != 0) {
            this->create_shared_resources();
        }
    } else {
        this->parent->add_module(this);
        this->parent->share_resources(&this->search_map, &this->search_map_rows,
                                      &this->stack_array, &this->stack_offsets);
    }
}
