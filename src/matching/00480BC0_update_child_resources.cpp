#ifndef RMM_BASE_SHARED_CONTEXT
class RGE_Random_Map_Module {
public:
    void update_resources();
    char gap_00[0x04];
    void* gap_08;
    void* gap_0C;
    void update_child_resources();
};

class RGE_Random_Map_Module_List {
public:
    RGE_Random_Map_Module* module;
    RGE_Random_Map_Module_List* next;
};

class RGE_Random_Map_Module_Base {
public:
    void* gap_00;
    void* gap_04;
    RGE_Random_Map_Module_List* list;
};
#endif

void RGE_Random_Map_Module::update_child_resources() {
    RGE_Random_Map_Module_List* node;

#ifdef RMM_BASE_SHARED_CONTEXT
    node = this->list;
#else
    node = ((RGE_Random_Map_Module_Base*)this)->list;
#endif
    while (node != 0) {
        node->module->update_resources();
        node = node->next;
    }
}
