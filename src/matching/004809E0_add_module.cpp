extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);

class RGE_Random_Map_Module;

struct RGE_Random_Map_Module_List {
    RGE_Random_Map_Module* module;
    RGE_Random_Map_Module_List* next;
};

class RGE_Random_Map_Module {
public:
    char gap_00[0x08];
    RGE_Random_Map_Module_List* list;

    unsigned char add_module(RGE_Random_Map_Module* module);
};

unsigned char RGE_Random_Map_Module::add_module(RGE_Random_Map_Module* module) {
    RGE_Random_Map_Module_List* item;

    if (module == 0) {
        return 0;
    }
    item = (RGE_Random_Map_Module_List*)calloc(1, 8);
    item->next = this->list;
    item->module = module;
    this->list = item;
    return 1;
}
