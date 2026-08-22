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
// sa-9ae8878f-r1 pass: the clean baseline revalidated at 224B/179 with 9/9
// ordered calls, the original prologue, and matching CFG signals. Direct type
// comparisons recovered the receiver-preload and node-spill shape but added an
// 8-byte frame and reached 260B/246; naming the first receiver reached 251B/243.
// Register-qualified cursor, action, and receiver forms, a post-guard action
// alias, explicit short casts, and narrow virtual surfaces were duplicates or
// worse. Preloading curr before the first type call reached 240B/233 with a
// frame and broad drift. Restore the clean typed source; the remaining gap is
// VC5 local-home/register allocation, not a behavior or call-set mismatch.
// sa-43054adb-r1 pass: revalidated the clean source and tested assignment-in-
// comparison, branch-scoped curr, an early first-action guard, a direct first
// comparison with a loop short local, a typed self alias, and fully qualified
// owner accesses. The assignment, curr scope, self alias, and qualification
// forms were codegen duplicates. First-action/direct-comparison forms added a
// frame and broadened drift. The clean 224B/179 source remains authoritative;
// its 9/9 ordered calls, four returns, typed owners, and natural three-tail
// control flow match, while the node spill and short-result home remain open.
// sa-49f2c4d6-r1 pass: seventeen focused natural probes found duplicate or
// worse basins. Ghidra's first-action preload and loop-action locals added a
// frame; separate type locals, node aliases, declaration orders, and register
// qualifiers did not move codegen. Restored and validated the pinned source at
// 224B/179 with 9/9 ordered calls; the VC5 spill/register basin remains open.
// sa-5ca1a6a6-r1 pass: twenty new evidence-led probes tested allocator-result
// typing, same-TU node lifetime, preloaded action receivers, split short homes,
// loop receiver locals, guard forms, and sequenced comparisons. Typed calloc,
// top-level node plus sizeof(*node), short references, and split results were
// codegen duplicates. Named receivers and next-action locals added an 8-byte
// frame or broader drift. The best new expression reached 223B/173, but its
// VC5 order called the list type before the new action type and changed the
// this register, so it is not a supported reconstruction. The final source is
// restored to 224B/179. The oracle still proves an early node home store and
// two-byte result home that the natural source does not recover.
// sa-9200e5fe-r1 TU pass: 256 ambient declaration prefixes, period allocator
// headers, Windows.h combinations, debug flags, exact queue-donor prefixes,
// target-following suffixes, full RGE_Action/Object declaration surfaces,
// factory constructors, and calloc ABI spellings were tested. The ambient
// sweep and every supported header/declaration surface were exact codegen
// duplicates of 224B/179. Exact donor bodies before or after this function
// also left codegen unchanged. Risky flags either stayed in the same basin
// or changed the frame/prologue; default /O2 /Oy remains required. Preserve
// the clean source. The TU context is not the cause of the two missing homes.
// sa-45f7b14a-r1 source-gate audit:
// - Replaced the narrow object overlay with the inventory-backed named
//   RGE_Static_Object -> RGE_Animated_Object -> RGE_Moving_Object ->
//   RGE_Action_Object ownership. The object_state offset remains +0x48.
// - Kept the complete named RGE_Action surface. Its virtual deleting
//   destructor, type(), and first_in_stack() slots are required by the calls.
// - Removed the action_type spill local and the impossible outer curr-null
//   wrapper. Kept the inner null tail because the original has that call site.
// - Replaced the hand-written calloc declaration with the period CRT header.
//   The original direct calloc call and the eight-byte node remain.
// - Audit source is behavior-clean but not exact: 256 bytes, 9 ordered calls,
//   4 returns, and 7 conditional branches. Direct type calls add an 0x8 frame.
// sa-f6a17cfa-r1 continuation: restored the full named hierarchy with the
// cached short type and inner curr-null guard. H12-H18 tested full-hierarchy
// control, declaration, two-short, address-taken, guard-scoped, and cursor
// scopes. They all emitted the same natural 224B/179 result, with no frame,
// 9/9 ordered calls, 8 conditional branches, and 42.72% exact blocks.
// H19/H22 used node->action for all three notification tails. They reached
// 234B/156, 49.51% exact blocks, and no frame, but added node memory reads to
// every call tail. The oracle loads the action vtable from EBX, so this is not
// a supported source or drift candidate. H20 used a slot-compatible second
// notification class and returned to 224B/179. H21 used node ownership only
// for the unreachable tail and reached 230B/178. H23 named first_action and
// reached 255B/244 with a frame. H24 restored action-owned tails. H25's
// explicit node zero was a duplicate. H26 added the proven trailing action
// object fields and was a duplicate. H27 combined the list guard and type
// test and was a duplicate. Two structured labs tested allocation, type
// order, loop form, and all eight notification-tail combinations across 243
// variants. No exact result occurred. The tail lab's best 232B/156 group
// used node tails and remains rejected for the proven memory-order difference.
#include <stdlib.h>

class RGE_Action_List;
class RGE_Action_Object;
class RGE_Static_Object;
class RGE_Master_Action_Object;
class RGE_Task;
class RGE_Master_Static_Object;
class RGE_Player;
class RGE_Sprite;
class RGE_Active_Sprite_List;
class RGE_Tile;
class RGE_Object_List;

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    RGE_Sprite* sprite;
    RGE_Sprite* old_sprite;
    RGE_Active_Sprite_List* sprite_list;
    RGE_Tile* tile;
    RGE_Static_Object* inside_obj;
    RGE_Object_List* objects;
    short screen_x_offset;
    short screen_y_offset;
    short shadow_x_offset;
    short shadow_y_offset;
    float hp;
    unsigned char curr_damage_percent;
    unsigned char facet;
    unsigned char selected;
    unsigned char selected_group;
    float world_x;
    float world_y;
    float world_z;
    float attribute_amount_held;
    unsigned char object_state;
    unsigned char sleep_flag;
    unsigned char dopple_flag;
    unsigned char goto_sleep_flag;
    short attribute_type_held;
    unsigned char type;
    unsigned char worker_num;
    char gap_50[0x38];
};

class RGE_Animated_Object : public RGE_Static_Object {
public:
    virtual ~RGE_Animated_Object();
    float speed;
};

class RGE_Moving_Object : public RGE_Animated_Object {
public:
    virtual ~RGE_Moving_Object();
    char gap_8C[0xF4];
};

class RGE_Action_Object : public RGE_Moving_Object {
public:
    virtual ~RGE_Action_Object();
    unsigned char waiting;
    unsigned char gap_181[3];
    RGE_Action_List* actions;
    unsigned char command_flag;
    unsigned char gap_189[3];
    int lastActionValue;
    int lastActionStateValue;
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

    short action_type;
    char gap_06[2];
    RGE_Action_Object* obj;
    unsigned char state;
    char gap_0D[3];
    RGE_Static_Object* target_obj;
    RGE_Static_Object* target_obj2;
    int targetID;
    int target2ID;
    float target_x;
    float target_y;
    float target_z;
    float timer;
    RGE_Task* task;
    RGE_Action_List* sub_actions;
    RGE_Sprite* sprite;
    unsigned char subActionValue;
    char gap_3D[3];
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

void RGE_Action_List::add_action_at_end_of_action_queue(RGE_Action* action) {
    RGE_Action_Node* node;

    if (obj->object_state > 2) {
        if (action != 0) {
            delete action;
        }
        return;
    }

    node = (RGE_Action_Node*)calloc(1, sizeof(RGE_Action_Node));
    node->action = action;

    if (list != 0) {
        short action_type;
        action_type = action->type();
        if (list->action->type() == action_type) {
            RGE_Action_Node* curr = list;
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
