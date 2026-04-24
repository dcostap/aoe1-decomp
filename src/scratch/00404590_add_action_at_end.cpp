// tried multiple loop forms, class layouts, variable names
// BLOCKER: rebuilt always has extra 'push edi' in prolog (offset 3)
//           size correct (114) but register allocation differs
//           original uses edx for loop, rebuilt uses edi

class RGE_Action {
public:
    virtual void vf00(int);
    char gap_04[0x18];
    virtual void vf1C(int);
};

struct RGE_Action_Node {
    RGE_Action_Node* next;
    RGE_Action* action;
};

struct RGE_Action_List_State {
    char gap_00[0x48];
    unsigned char max_actions;
};

class RGE_Action_List {
public:
    char gap_00[0x04];
    RGE_Action_List_State* state;
    RGE_Action_Node* list;

    void add_action_at_end(RGE_Action* action);
};

void* calloc(size_t, size_t);

void RGE_Action_List::add_action_at_end(RGE_Action* action) {
    if (this->state->max_actions > 2) {
        if (action) {
            action->vf00(1);
        }
        return;
    }
    if (action) {
        RGE_Action_Node* node = (RGE_Action_Node*)calloc(1, 8);
        node->next = 0;
        node->action = action;
        RGE_Action_Node* p = this->list;
        if (p) {
            while (p->next) {
                p = p->next;
            }
            p->next = node;
        } else {
            this->list = node;
        }
        action->vf1C(1);
    }
}
