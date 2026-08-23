#ifndef RMM_BASE_SHARED_CONTEXT
class RGE_Map;
class RGE_Random_Map_Module;

class RGE_Random_Map_Module_List {
public:
    RGE_Random_Map_Module* module;
    RGE_Random_Map_Module_List* next;
};

class RGE_Random_Map_Module {
public:
    void* gap_00;
    void* gap_04;
    RGE_Random_Map_Module_List* list;
    RGE_Map* map;

    void update_map_info(RGE_Map* map);
    void update_child_map_info();
};
#endif

void RGE_Random_Map_Module::update_child_map_info() {
    RGE_Random_Map_Module_List* node;

    node = this->list;
    while (node != 0) {
        node->module->update_map_info(this->map);
        node = node->next;
    }
}
