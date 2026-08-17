#include <stdlib.h>

// STATUS: EXACT
// ATTEMPT LOG:
// - Recovered the guarded list delete, 2-byte type read, virtual action create,
//   zeroed 8-byte node allocation, and append-first list link flow.
// - A common tail=node statement after the branch matches the PDB line-83 band.
// - This source emits the exact 107-byte body and all four ordered calls.
// - The exact result uses the original EDI receiver and ESI action result.

class RGE_Action;
class RGE_Action_Object;

class RGE_Action_Node {
public:
    RGE_Action* action;
    RGE_Action_Node* next;
};

class RGE_Action_List {
public:
    virtual RGE_Action* create_action(int param_1, short param_2);

    RGE_Action_Object* obj;
    RGE_Action_Node* list;

    void delete_list(void);
    void load(int param_1);
};

void rge_read(int param_1, void* param_2, int param_3);
void* calloc(unsigned int param_1, unsigned int param_2);

void RGE_Action_List::load(int param_1) {
    RGE_Action* action;
    RGE_Action_Node* node;
    RGE_Action_Node* tail;
    short action_type;

    if (this->list != 0) {
        this->delete_list();
    }

    tail = 0;
    while (true) {
        rge_read(param_1, &action_type, 2);
        if (action_type == 0) {
            break;
        }

        action = this->create_action(param_1, action_type);
        node = (RGE_Action_Node*)calloc(1, 8);
        node->action = action;
        node->next = 0;
        if (tail) {
            tail->next = node;
        } else {
            this->list = node;
        }
        tail = node;
    }
}
