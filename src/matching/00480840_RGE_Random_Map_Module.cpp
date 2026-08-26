// 00480840 RGE_Random_Map_Module::~RGE_Random_Map_Module
// Source: rmm_base.cpp lines 64-91. 113 bytes. __thiscall.
//
// MATCHED. Exact 113-byte match confirmed via local check_function.py.
// The canonical virtual class surface supplies the compiler-managed dispatch state.
// The if(this->parent == 0) form places the no-parent path inline, matching
// the original branch order with the else path at the end.

void operator_delete(void* ptr);

#ifndef RMM_BASE_SHARED_CONTEXT
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
    virtual ~RGE_Random_Map_Module();
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

    void destroy_shared_resources();
    void remove_module(RGE_Random_Map_Module* child);
    virtual unsigned char generate();
};
#endif

RGE_Random_Map_Module::~RGE_Random_Map_Module() {
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
