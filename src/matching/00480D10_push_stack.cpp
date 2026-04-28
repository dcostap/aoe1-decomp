// RGE_Random_Map_Module::push_stack
// VA: 00480D10
// rmm_base.cpp:355-395
// 136 bytes

#include "../../include/game_globals.h"

struct Map_Stack {
    int x;
    int y;
    int cost;
    float tot_cost;
    Map_Stack* next;
    Map_Stack* prev;
};

class RGE_Random_Map_Module {
public:
    void remove_stack_node(Map_Stack* node);
    void add_stack_node(Map_Stack* target, Map_Stack* node);
    
    char gap_00[0x2C];
    Map_Stack** stack_offsets;

    void push_stack(Map_Stack* list, long param_2, long param_3, float param_4, float param_5);
};

void RGE_Random_Map_Module::push_stack(Map_Stack* list, long param_2, long param_3, float param_4, float param_5) {
    Map_Stack* node = &this->stack_offsets[param_3][param_2];
    this->remove_stack_node(node);

    Map_Stack* current = list->next;

    if (current != 0 && current->tot_cost < param_5) {
        Map_Stack* prev;
        do {
            prev = current;
            current = current->next;
        } while (current != 0 && current->tot_cost < param_5);

        this->add_stack_node(prev, node);
        node->cost = *(int*)&param_4;
        node->tot_cost = param_5;
        return;
    }

    this->add_stack_node(list, node);
    node->cost = *(int*)&param_4;
    node->tot_cost = param_5;
}
