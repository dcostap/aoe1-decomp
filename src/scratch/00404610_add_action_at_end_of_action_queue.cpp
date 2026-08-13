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
// fresh orch-actlist-01 pass: removing only the outer null-tail call fixed the
// activation call multiset but changed the prologue to sub-esp/EBX-this (211B);
// goto/while-next variants were broader (230B). A common notify tail plus the
// binary-observed inner null call reached 181B with 3 vf1C calls and exact
// prologue, but omitted the original outer null test, remained 24B short, and
// kept the calloc/local-store order wrong. curr=node, direct-parameter, and
// declaration-point node variants were emitted-code duplicates. Restored the
// pinned canonical source for pause.
// wave21 baseline: use the recovered RGE_Action ownership (virtual deleting
// destructor and first_in_stack/type slots) and the natural delete/typed-call
// surface instead of the earlier anonymous vf00/vf1C proxies.
// wave21 H2: remove only the impossible post-match curr-null arm; keep the
// binary-observed loop-exhaustion null tail and the ordinary front fallback.
// wave21 H3: make the post-match curr-null edge fall directly into the common
// notify tail, matching the original je to 004046F1 without front insertion.
// wave21 H5: materialize the new action's short type before each list-type
// call so the value is live across the virtual call, as in the oracle's word
// parameter-home spill/reload sequence.
// wave21 H6: naming both action records was a diagnostic only; VC5 added a
// 0xC frame and broad drift, so the clean direct-member form is retained.
// wave21 H7: place the persistent list cursor before the allocation local to
// test the donor-era declaration-order coloring without changing ownership.
// wave21 H8: use the direct node member/list assignment idiom of the exact
// same-TU add_action donor instead of a front-path curr alias.
// wave21 H9: bind the node at the calloc declaration point, matching the
// packet's line-388 allocation/local lifetime before the list scan.
// wave21 result: the H2-H5 control-flow family removes the extra notify call
// and aligns all 9 ordered calls/CFG signals; its clean 224B/179-byte result
// is retained. H6 named action records added a 0xC frame and was rolled back;
// H7-H9 declaration/front-node spellings were emitted-code duplicates. The
// remaining gap is structural: VC5 still folds the calloc/node spill and
// short type result into fewer instructions than the 242B oracle.
// orch-00404610-L H1: predeclaring node before the state guard was a codegen
// duplicate; restore-clean retained the calloc declaration-point form.
// H2: combined type assignments and H3: stdlib calloc context were duplicates.
// H4: an address-taken type pointer and H5: reversed local declaration order
// were duplicates. H6: volatile short type moved registers and worsened shape.
// H7: assigning curr before the first type test added a frame and broad drift.
// H8: sizeof(RGE_Action_Node) was a duplicate. H9: direct type-return
// comparisons added a frame and 18 bytes past the boundary. Final clean source
// remains 224B/179-byte diff with 9/9 ordered calls; structural spill/type
// allocation remains unresolved.
// shardB-00404610-scale: branch-scoped typed first_action and next_action
// locals before each new action type call added a 0xC frame and 262B; rolled back.
// sa-cc2bb81b-r1 reassess: first-type initializer was a duplicate; a named
// first action added a frame and 243B; both were rolled back.
// sa-cc2bb81b-r1 reassess: int action_type reached 234B and retained 179
// positional diff, but changed signed-return codegen; unsigned short reached
// 244B/146 diff but changed the signed type ABI and prologue; both rolled back.
// An explicit 16-bit cast returned to the clean 224B basin. The natural
// while-next guard added a frame and 233B; an owner alias was optimized away.
// Final clean source retains the typed three-tail reconstruction at 224B/179;
// the unresolved structural gap is the calloc/node spill and short-result
// home, not calls or behavior-backed control-flow topology.
class RGE_Action_List;
class RGE_Static_Object;
class RGE_Master_Action_Object;
class RGE_Task;

class RGE_Action_Object {
public:
    virtual ~RGE_Action_Object();
    char gap_04[0x44];
    unsigned char status;
};

class RGE_Action {
public:
    virtual ~RGE_Action();
    virtual int setup(RGE_Action_Object* object);
    virtual int setup(int value, RGE_Action_Object* object);
    virtual RGE_Action_List* create_action_list(RGE_Action_Object* object);
    virtual void rehook(void);
    virtual void save(int file);
    virtual short type(void);
    virtual void first_in_stack(unsigned char value);
    virtual unsigned char inside_obj_update(void);
    virtual unsigned char idle_update(void);
    virtual unsigned char update(void);
    virtual int stop(void);
    virtual int move_to(RGE_Static_Object* object, float x, float y, float z);
    virtual int work(RGE_Static_Object* object, float x, float y, float z);
    virtual unsigned char attack_response(RGE_Static_Object* object);
    virtual unsigned char relation_response(long value, unsigned char relation);
    virtual void copy_obj(RGE_Master_Action_Object* object);
    virtual void copy_obj_sprites(RGE_Master_Action_Object* object,
                                  RGE_Task* source, RGE_Task* dest);
    virtual void get_state_name(char* dest);
    virtual RGE_Static_Object* get_target_obj(void);
    virtual RGE_Static_Object* get_target_obj2(void);
    virtual void set_target_obj(RGE_Static_Object* object);
    virtual void set_target_obj2(RGE_Static_Object* object);
    virtual void set_state(unsigned char value);
};

class RGE_Action_Node {
public:
    RGE_Action* action;
    RGE_Action_Node* next;
};

class RGE_Action_List {
public:
    virtual RGE_Action* create_action(int value, short type);
    virtual RGE_Action* create_task_action(RGE_Task* task,
                                            RGE_Static_Object* object,
                                            float x, float y, float z);
    virtual unsigned char inside_obj_update(void);
    virtual unsigned char update(void);
    virtual void get_action_name(char* dest);
    virtual void copy_obj(RGE_Master_Action_Object* object);
    virtual void copy_obj_sprites(RGE_Master_Action_Object* object,
                                  RGE_Task* source, RGE_Task* dest);
    virtual ~RGE_Action_List();
    RGE_Action_Object* obj;
    RGE_Action_Node* list;

    void add_action_at_end_of_action_queue(RGE_Action* action);
};

extern "C" void* calloc(unsigned int count, unsigned int size);

void RGE_Action_List::add_action_at_end_of_action_queue(RGE_Action* action) {
    RGE_Action_Node* curr;
    short action_type;

    if (obj->status > 2) {
        if (action != 0) {
            delete action;
        }
        return;
    }

    RGE_Action_Node* node = (RGE_Action_Node*)calloc(1, 8);
    node->action = action;

    if (list != 0) {
        action_type = action->type();
        if (list->action->type() == action_type) {
            curr = list;
            if (curr != 0) {
                while (1) {
                    if (curr->next == 0) {
                        break;
                    }
                    action_type = action->type();
                    if (curr->next->action->type() != action_type) {
                        break;
                    }
                    curr = curr->next;
                    if (curr == 0) {
                        action->first_in_stack(1);
                        return;
                    }
                }
                node->next = curr->next;
                curr->next = node;
                action->first_in_stack(1);
                return;
            }
            goto notify;
        }
    }

    node->next = list;
    list = node;
notify:
    action->first_in_stack(1);
}
