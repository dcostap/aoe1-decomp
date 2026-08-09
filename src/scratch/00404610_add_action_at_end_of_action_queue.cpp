// STATUS: paused
// NOTE: local no-asm probe; best shape recovers the original push-save prolog and size, but still mismatches at the early branch target / later notify-tail layout
// ATTEMPTS:
// baseline: named node/current/action ownership, calloc(1, 8), and grouped type scan; 247B, 184 positional diff, 4 activate calls.
// removed the impossible-null activation fallthrough / used a front-insert goto: call count fixed, but VC5 changed to an 8-byte sub-esp frame and 211 diff.
// direct parameter, declaration-order, and separate short-result variants were codegen duplicates of baseline.
// parameter-home word alias worsened to 236B and changed the virtual call surface; rolled back.
// explicit first/next action locals (function-wide and branch-scoped) added a 0xC frame and 273B; rolled back.
// final best remains the binary-backed three-tail source; the apparently
// redundant null tails preserve three observed vf1C call sites. Main-agent
// audit restored canonical polymorphic ownership only.
class RGE_Action;

class RGE_Action_Object {
public:
    virtual ~RGE_Action_Object();
    char gap_04[0x44];
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
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual ~RGE_Action_List();
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
