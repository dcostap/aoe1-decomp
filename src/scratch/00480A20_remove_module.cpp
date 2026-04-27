// first pass: remove the first matching module from the singly linked list at +8, then free the removed node
// tried the direct head-check form and a pointer-to-next loop; mismatch tightened to the link/update basin and final free/return layout
// pausing in scratch for now because the remaining gap is localized VC5 code shape, not behavior
class RGE_Random_Map_Module;
class RGE_Random_Map_Module_List;

extern void free(void* ptr);

class RGE_Random_Map_Module_List {
public:
    RGE_Random_Map_Module* module;
    RGE_Random_Map_Module_List* next;
};

class RGE_Random_Map_Module {
public:
    char pad_00[0x8];
    RGE_Random_Map_Module_List* list;

    unsigned char remove_module(RGE_Random_Map_Module* module);
};

unsigned char RGE_Random_Map_Module::remove_module(RGE_Random_Map_Module* module) {
    RGE_Random_Map_Module_List* current;
    RGE_Random_Map_Module_List** link;
    RGE_Random_Map_Module_List* removed;

    current = this->list;
    removed = 0;
    if (current != 0) {
        if (current->module == module) {
            this->list = current->next;
            removed = current;
        }
        else {
            link = &current->next;
            current = current->next;
            while (current != 0) {
                if (current->module == module) {
                    *link = current->next;
                    removed = current;
                }
                link = &(*link)->next;
                current = *link;
            }
        }
    }

    if (removed == 0) {
        return 0;
    }

    free(removed);
    return 1;
}
