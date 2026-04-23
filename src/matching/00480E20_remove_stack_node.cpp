struct Map_Stack {
    char gap_00[0x10];
    Map_Stack* next;
    Map_Stack* prev;
};

class RGE_Random_Map_Module {
public:
    void remove_stack_node(Map_Stack* node);
};

void RGE_Random_Map_Module::remove_stack_node(Map_Stack* node) {
    if (node->prev != 0) {
        node->prev->next = node->next;
    }
    if (node->next != 0) {
        node->next->prev = node->prev;
    }
    node->next = 0;
    node->prev = 0;
}
