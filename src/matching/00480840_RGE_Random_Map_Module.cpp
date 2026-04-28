// 00480840 RGE_Random_Map_Module::~RGE_Random_Map_Module
// Source: rmm_base.cpp lines 64-91. 113 bytes. __thiscall.
//
// MATCHED. Exact 113-byte match confirmed via local check_function.py.
// Key fixes: (1) vtable address uses (void*)0x571E30 literal not extern
// (avoids relocation placeholder). (2) if(this->parent == 0) places no-parent
// path inline matching original branch order with else path at end.

void operator_delete(void* ptr);

class RGE_Random_Map_Module;
class RGE_Map;
class RGE_Tile;
class Map_Stack;

class RGE_Random_Map_Module_List {
public:
    RGE_Random_Map_Module* module;
    RGE_Random_Map_Module_List* next;
};

class RGE_Random_Map_Module {
public:
    void* vtable_ptr;
    RGE_Random_Map_Module* parent;
    RGE_Random_Map_Module_List* list;
    RGE_Map* map;
    RGE_Tile** map_row_offset;
    long map_width;
    long map_height;
    float schedule;
    unsigned char* search_map;
    unsigned char** search_map_rows;
    Map_Stack* stack_array;
    Map_Stack** stack_offsets;

    ~RGE_Random_Map_Module();
    void destroy_shared_resources();
    void remove_module(RGE_Random_Map_Module* child);
};

RGE_Random_Map_Module::~RGE_Random_Map_Module() {
    this->vtable_ptr = (void*)0x571E30;

    while (this->list != 0) {
        RGE_Random_Map_Module* module = this->list->module;
        if (module != 0) {
            module->~RGE_Random_Map_Module();
            operator_delete(module);
        }
    }

    if (this->parent == 0) {
        this->destroy_shared_resources();
    } else {
        this->parent->remove_module(this);
        this->search_map = 0;
        this->search_map_rows = 0;
        this->stack_array = 0;
        this->stack_offsets = 0;
    }

    this->map = 0;
    this->map_row_offset = 0;
    this->map_width = 0;
    this->map_height = 0;
}
