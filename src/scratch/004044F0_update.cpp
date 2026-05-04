// VA: 004044F0 RGE_Action_List::update (73B)
// give-up/pause after >10 focused attempts
// best source shape is a single-return form that forces the original early full prologue (push ebx/push esi/push edi),
// but VC5 still rewrites the empty-list path as `mov bl,1 / mov al,bl` instead of the original literal `mov al,1`,
// shifting the rest of the function by 2 bytes
// tried/rolled back: direct-return shapes (late shrink-wrapped pushes), top-level head/node/result variants, goto/no_list,
// result-width variants (char/int/bool), full real vtable surface, register locals, two focused variant-lab sweeps,
// and custom-flag probes (/O1, /Od, /Og-, /Ob0, /Os) with no exact basin
// 2026-05-04 retry: rechecked direct-return/goto forms; all still shrink-wrap to push edi first, then push esi/ebx only in the non-empty path
// 2026-05-04 Boss reassignment recheck: reconfirmed the retained best basin below; no new source/flag probe beat the single-return `mov bl,1 / mov al,bl` family.

class RGE_Static_Object;
class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual int setup(RGE_Static_Object* param_1);
    virtual int setup(int param_1, RGE_Static_Object* param_2);
    virtual void* create_action_list(RGE_Static_Object* param_1);
    virtual void rehook();
    virtual void save(int param_1);
    virtual short type();
    virtual void first_in_stack(unsigned char param_1);
    virtual unsigned char inside_obj_update();
    virtual unsigned char idle_update();
    virtual unsigned char update();
    virtual int stop();
    virtual int move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
    virtual int work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
};

class RGE_Action_Node {
public:
    RGE_Action* action;
    RGE_Action_Node* next;
};

class RGE_Action_List {
public:
    char gap_00[8];
    RGE_Action_Node* list;

    void remove_action(void);
    unsigned char update(void);
};

unsigned char RGE_Action_List::update(void) {
    RGE_Action_Node* node;
    unsigned char result;

    node = this->list;
    if (node == 0) {
        result = 1;
    } else {
        result = node->action->update();
        node = this->list;
        if (node != 0) {
            node = node->next;
            while (node != 0) {
                node->action->idle_update();
                node = node->next;
            }
            if (result == 1) {
                this->remove_action();
            }
        }
    }
    return result;
}
