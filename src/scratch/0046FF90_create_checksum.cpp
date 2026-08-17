// VA: 0046FF90 create_checksum (277B)
// PDB donor: player.cpp, lines 1144-1202
//
// Baseline reconstruction uses the canonical player/object/list ownership:
// attribute values feed an integer checksum, the live object list contributes
// object and position checksums, and the final checksum packs the four fields.
// Attempt log:
// - Scoped the integer attribute countdown inside its positive guard; this
//   recovered the six-dword frame and the exact five-call sequence.
// - Tried natural object checksum expression, sequenced waypoint addition,
//   direct compound steps, explicit temporaries, and a separate current sum.
//   The split waypoint form is the best source/codegen basin (277B, 5/5 calls,
//   0x14 frame); the original keeps a 0x18 frame and a loop-carried checksum
//   stack home that these natural forms do not reproduce.
// - Prefix operand/declaration reorderings were codegen-neutral. Variant lab
//   sweep found no size/frame-eligible exact form. Ten meaningful hypotheses
//   exhausted; left in scratch with no inline asm, fake volatility, or raw
//   vtable plumbing.
// - This pass reversed the sleeping/doppelganger prefix, used sequential +=
//   checksum updates, and hoisted scalar declarations; all were codegen-neutral.
// - A 40-variant accumulator/prefix/object-expression lab found no frame-0x18
//   candidate; the best natural basin remains 277B/0x14 with 5/5 calls.
// - A diagnostic six-field aggregate reproduced frame 0x18 but added 10B and
//   worsened the body; it was restored. Separate locals in the binary stack
//   order likewise collapsed back to the clean 0x14 output.
// Fresh bounded pass:
// - Full donor-backed RGE_Player ABI/0x220 layout worsened to 285B; full
//   RGE_Static_Object 0x88 layout and a natural while(node) form were neutral.
// - Direct repeated list->node rereads, including the post-waypoint reload
//   proven by the oracle, improved resync to 182B but shortened the body to
//   268B; the clean cached-object source remains the current canonical pin.
// - Separate per-object checksum temporary, named prefix-list pointers, and
//   combined prefix expression were worse; final prefix declaration ordering
//   was neutral. No exact frame-0x18 natural candidate emerged.
// Wave20 bounded pass:
// - A top-level signed attribute-count test reproduced the original movsx and
//   delayed countdown store, but remained 270B/0x14 and worsened the body.
// - Natural function-scope per-object checksum forms and direct list-node
//   rereads either duplicated prior 268B evidence or regressed; no new source
//   ownership lead survived review.
// - A period-plausible register current-checksum variant reproduced the 0x18
//   frame and stack-local count/prefix shape, but selected EBP=this/EBX-temp
//   instead of the oracle's EBX=this/EBP-current topology and emitted 285B.
// - Declaration reordering was codegen-identical. Restored the clean cached
//   object source; remaining evidence-backed lead is compiler register/lifetime
//   selection around the loop-carried object checksum, not a layout or call ABI
//   mismatch.
// - A state-first split checksum statement was tested to mirror the original
//   state-load/ftol order; it worsened to 228B and was restored.
// - Fresh pass: direct list->node rereads, including a hybrid cache through
//   waypoint and reread for position/action, reached 268B/0x14 and diff 182
//   with stronger shape, but did not recover the original frame or stack home.
// - A cumulative checksum split, a natural per-object temp, top-level locals,
//   long-width checksum/count locals, and reversed accumulator order were
//   neutral or worse. Restored the cached-object clean source; the blocker is
//   still the original loop-carried object checksum spill and frame-0x18 home.
// Fresh bounded pass (sa-7ad2b15f-r1):
// - Revalidated the clean source at 277B/0x14, diff 185, with all five calls
//   aligned. Sequential checksum updates and a local reference alias were
//   codegen-neutral.
// - Direct list->node rereads for position/action reproduced the stronger
//   268B/0x14, diff 182 basin, but did not recover the original frame.
// - A source model based on the external RGE_Player checksum reconstruction,
//   named held/master temporaries, decompiler local order, long-width locals,
//   and top-level declarations produced no new basin or exact result.
// - A two-field checksum aggregate and top-level signed attribute count were
//   worse. The aggregate stayed at frame 0x14; the count variant shortened the
//   body. Restored the pinned cached-object source before final validation.
// Revisit pass (sa-2f1d57b3-r1):
// - Typed sleeping-list, master-pointer, full node/list-layout, combined-prefix,
//   separate base/result, compound-update, and promoted-state forms were
//   neutral. A distinct object_sum carried through waypoint worsened to 227B.
// - Typed short prefix count locals worsened to 291B. A previous-checksum
//   snapshot optimized to the clean 277B basin. No natural form recovered the
//   original 0x18 frame or stack-carried object checksum.
// - Restored the pinned cached-object source. The remaining blocker is the
//   compiler's EBP temporary versus stack object-checksum allocation; exact
//   calls, widths, ownership, and loop behavior remain stable.
// Revisit pass (sa-da8d783f-r1):
// - Rechecked the pinned source and tested seven natural forms: a top-level
//   attribute count, a combined waypoint checksum, long and inner checksum
//   temporaries, direct state access, and named prefix counts.
// - The combined waypoint form recovered the 0x18 frame but reordered the
//   checksum conversion call and added 16 bytes. Other forms were neutral or
//   worse. Restored the pinned 277B/0x14 source with 5/5 calls.
// Fresh second pass (sa-849b4c05-r1):
// - Audited player, master, object, list, virtual-slot, width, call, and
//   fault-order ownership against the packet and same-TU donors.
// - A full typed RGE_Static_Object surface, typed player fields, the reviewed
//   Object_List ABI, and period standard headers all changed the basin and
//   worsened the body. They are not retained.
// - A reviewed master declaration changed the prefix load order, but its
//   incomplete local surface did not justify keeping it. The minimal donor
//   surface remains the cleanest supported declaration.
// - The executable rereads list->node after the waypoint call for position and
//   action. The direct rereads recover the call-block shape and improve the
//   result to 268B effective, diff 182, shape 81.82%, with 5/5 calls.
// - The original still has a 0x18 frame and a stack-carried object checksum.
//   Natural narrow-width forms did not recover that home. No exact result.

extern "C" long __cdecl __ftol(void);

class RGE_Static_Object;
class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x0C];
    short id;
};

class RGE_Object_Node {
public:
    RGE_Static_Object* node;
    RGE_Object_Node* next;
};

class RGE_Object_List {
public:
    virtual ~RGE_Object_List();
    RGE_Object_Node* list;
    short number_of_objects;
};

// The two checksum methods are slots 0x1D0 and 0x1D4 in RGE_Static_Object.
// Keep the intervening virtual surface so these remain real typed calls.
#define VPAD1(n) virtual void vf_##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)
#define VPAD32(n) VPAD16(n) VPAD16(n##_16)
#define VPAD64(n) VPAD32(n) VPAD32(n##_32)

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    VPAD64(1)
    VPAD32(2)
    VPAD16(3)
    VPAD2(4)
    VPAD1(5)
    virtual long get_action_checksum();
    virtual long get_waypoint_checksum();

    long id;
    RGE_Master_Static_Object* master_obj;
    char gap_0C[0x2C];
    float world_x;
    float world_y;
    float world_z;
    float attribute_amount_held;
    unsigned char object_state;
};

#undef VPAD64
#undef VPAD32
#undef VPAD16
#undef VPAD8
#undef VPAD4
#undef VPAD2
#undef VPAD1

class RGE_Player {
public:
    virtual ~RGE_Player();

    char gap_04[0x10];
    long checksum;
    long position_checksum;
    long action_checksum;
    unsigned char checksum_created_this_update;
    char gap_21[1];
    short master_object_num;
    RGE_Master_Static_Object** master_objects;
    RGE_Object_List* objects;
    RGE_Object_List* sleeping_objects;
    RGE_Object_List* doppleganger_objects;
    void* victory_conditions;
    void* visible;
    void* world;
    void* doppleganger_creator;
    char* name;
    unsigned char type;
    char gap_49[1];
    short id;
    short attribute_num;
    char gap_4E[2];
    float* attributes;

    long create_checksum(void);
};

long RGE_Player::create_checksum(void) {
    long result = (long)this->id;
    this->checksum_created_this_update = 1;
    this->action_checksum = 0;

    result += this->sleeping_objects->number_of_objects;
    int object_checksum = 0;
    result += this->doppleganger_objects->number_of_objects;
    int attribute_checksum = 0;
    float position_checksum = 0.0f;
    int object_count = 0;

    if ((int)this->attribute_num > 0) {
        int attribute_count = (int)this->attribute_num;
        float* attribute = this->attributes;
        do {
            attribute_checksum += (int)*attribute;
            ++attribute;
            --attribute_count;
        } while (attribute_count != 0);
    }

    for (RGE_Object_Node* list = this->objects->list;
         list != 0;
         list = list->next) {
        RGE_Static_Object* object = list->node;
        unsigned char state = object->object_state;
        object_checksum = (int)state
            + (int)object->attribute_amount_held
            + (int)object->master_obj->id
            + object_checksum;
        object_checksum += object->get_waypoint_checksum();
        ++object_count;
        position_checksum = list->node->world_x + position_checksum;
        position_checksum += list->node->world_y;
        position_checksum += list->node->world_z;
        this->action_checksum += list->node->get_action_checksum();
    }

    result = (result * 0x100 + object_count) * 0x100 + object_checksum;
    result = result * 0x100 + attribute_checksum;
    this->checksum = result;
    this->position_checksum = (long)position_checksum;
    return result;
}
