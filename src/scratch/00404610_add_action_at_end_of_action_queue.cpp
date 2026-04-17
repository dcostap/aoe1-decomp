// STATUS: active
// NOTE: local no-asm probe; best shape recovers the original push-save prolog and size, but still mismatches at the early branch target / later notify-tail layout
class RGE_Action;

class RGE_Action_Object {
public:
    char gap_00[0x48];
    unsigned char status;
};

class RGE_Action {
public:
    virtual void vf00(int value);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual short vf18(void);
    virtual void vf1C(int value);
};

class RGE_Action_Node {
public:
    RGE_Action* action;
    RGE_Action_Node* next;
};

class RGE_Action_List {
public:
    void* vftable;
    RGE_Action_Object* obj;
    RGE_Action_Node* list;

    void add_action_at_end_of_action_queue(RGE_Action* action);
};

extern "C" void* calloc(unsigned int count, unsigned int size);

void RGE_Action_List::add_action_at_end_of_action_queue(RGE_Action* action) {
    RGE_Action* queued_action;
    RGE_Action_Node* node;
    RGE_Action_Node* curr;
    short action_type;

    queued_action = action;
    if (obj->status > 2) {
        if (queued_action != 0) {
            queued_action->vf00(1);
        }
        return;
    }

    node = (RGE_Action_Node*)calloc(1, 8);
    node->action = queued_action;

    if (list != 0) {
        if (list->action->vf18() == (action_type = queued_action->vf18())) {
            curr = list;
            if (curr != 0) {
                while (1) {
                    if (curr->next == 0) {
                        break;
                    }
                    if (curr->next->action->vf18() != (action_type = queued_action->vf18())) {
                        break;
                    }
                    curr = curr->next;
                    if (curr == 0) {
                        queued_action->vf1C(1);
                        return;
                    }
                }
                node->next = curr->next;
                curr->next = node;
                queued_action->vf1C(1);
                return;
            }
            queued_action->vf1C(1);
            return;
        }
    }

    curr = node;
    curr->next = list;
    list = curr;
    queued_action->vf1C(1);
}
