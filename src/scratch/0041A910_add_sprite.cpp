// tried ppPrev before/after first loop; tried for-loop and while-loop forms
// tried moving ppPrev init inside/outside loop; tried do-while for second loop
// variant lab: 6 variants across 2 runs, all produce 160 bytes (2 too large)
// prior best mismatch at offset 38: VC5 loads [esi+4] into eax instead of ecx, then add esi,4 instead of lea edi,[esi+4]
// tried reversing local decl order, while vs for, early pp init: no change in register basin
// Fresh pass 2026-05-19:
// try 1: baseline exact-size 158B, 47/158 positional, first mismatch +38.
// try 2: corrected RGE_Active_Sprite::set_offset to virtual slot +4 and calloc(0xc,1); improved to
//        exact-size 158B, 36/158 positional, 26 edit bytes; kept.
// try 3: register self=this; no change.
// try 4: register ppPrev; no change.
// try 5: explicit head local; worsened to 43/158 and extra tests; rolled back.
// try 6: reference alias for list; no change.
// try 7: register pp; no change.
// try 8: explicit goto loop labels; no change.
// try 9: volatile ppPrev; badly worsened prologue/stack, 85% mismatch; rolled back.
// Remaining issue is a codegen basin: VC5 modifies this pointer (esi) into &list instead of keeping
// this in esi and using edi for ppPrev; this also flips duplicate-hit count temp (al/ecx) and new-node
// register (edi/esi). Original preserves esi (this) through traversal and uses edi for pointer-to-pointer.
// Not accepted-drift safe; diff spans traversal, allocation/insertion registers, and early-return tail.
// Retry 2026-05-20 assigned pass: 15 more probes. Tried natural double-for, ppPrev declaration after first loop, self alias, list reference alias, class surface with explicit gap vs virtual dtor, local declaration order, int priority param, calloc argument order, first-loop for form, second-loop break form, combined loop forms, and flags /Og /Ot /Ob0 /G5 /GB /Oa. All sane source/flag variants stayed in the same ESI-mutated-to-&list basin (or worsened). GIVEUP, no accepted_drift: mismatch is broad register/topology drift spanning first traversal, duplicate-count tail, insertion traversal, new-node register, and final insertion stores, not a localized equivalent hunk.
// Retry 2026-05-21 Boss pass: 10 more probes. Tried natural two-while, ppPrev declaration after first loop, self alias, member-direct second loop, manual integer ppPrev, register pp/ppPrev, goto form with extra self touch, explicit count temp, named new_node allocation, and reversed calloc argument source. All sane variants stayed in the same exact-size 158B / 22.7848% positional / 16.4557% edit basin with first mismatch +38; calloc-order variants worsened. Still blocked on VC5 choosing to mutate ESI into &list instead of preserving this in ESI and using EDI as ppPrev. Leaving in scratch; no accepted_drift because drift spans traversal, duplicate tail, allocation, and insertion stores.
// Retry 2026-05-24 Boss pass: 10 more probes. Rechecked baseline at exact-size 158B, 36/158 positional, first mismatch +38.
// Tried self alias, volatile self (worse stack frame), ppPrev-before-pp / *ppPrev reload, ppStart alias, and flags /Ob0 /Og /Ot /Oa /G5 /GB /O1.
// All non-worsening variants stayed in the same ESI-mutated-to-&list basin; /Oa and volatile worsened. Removed temporary flag file.
// GIVEUP again; no accepted_drift proposal because the remaining diff is structural across traversal registers, duplicate-count tail, allocation register, and final insertion stores.
// Retry 2026-05-26 Boss pass: 10 more probes. Revalidated baseline exact-size 158B,
// 36 positional / 26 edit, first mismatch +38. Tried forcing `this` liveness after the
// first loop (worse broad drift), moving ppPrev init after the duplicate scan, raw int
// ppPrev, for-loop second scan, bottom-test/goto second scan, self alias, volatile order
// byte, early node/asp declarations, explicit count temp for duplicate hit, and reversed
// order compare. All non-worsening variants stayed in the same basin: VC5 mutates ESI
// into &list and uses EDI for the allocated node, while original preserves ESI=this and
// uses EDI=ppPrev / ESI=new node. No accepted_drift: mismatch remains structural.
// Retry 2026-08-02 Luna-41A910: baseline rebuilt at 158B, 36 positional bytes, 26 edit bytes, first mismatch +38.
// Restored the complete known polymorphic list surface; emitted code was unchanged.
// Separate head/scan cursors (including decompiler initialization order and top-declared locals) entered a 43-byte basin with an extra head test; restored.
// Swapping traversal declaration/initialization order and a focused 4-variant alias/head lab did not move the 36-byte basin; all variants remained 158B with exact call-set parity.
// left in scratch: VC5 still folds this into ESI=&list/EDI=new-node instead of original ESI=this/EDI=ppPrev; drift spans traversal, duplicate-hit tail, allocation, and insertion stores.
// Retry 2026-08-02 Luna41A910: baseline rechecked after claiming this target; clean source remains 158B with 36 positional bytes / 26 edit bytes, first mismatch +38.
// New hypotheses: exact decompiler head/scan cursor forms (43B), swapped cursor ownership (same 43B), canonical Active_Sprite destructor/full virtual surface (same 36B), compound head initialization (same), CRT <stdlib.h> calloc declaration (same), scan-node reuse (same), and positive outer guard (same). `sizeof(Node)` allocation worsened to 38B and was restored.
// Final clean-source choice: retain the prior period-plausible typed list insertion candidate; unresolved drift is broad register/liveness topology, not a localized behavior-equivalent hunk.

extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);

class RGE_Sprite;
class RGE_Static_Object;

class RGE_Active_Sprite {
public:
    virtual void destroy(int);
    virtual void set_offset(long, long);
    RGE_Sprite* sprite;
    int check_for_shadows();
};

class RGE_Sprite {
public:
    int check_for_shadows();
    RGE_Active_Sprite* make_active_sprite();
};

class RGE_Static_Object { public: void remove_shadows(); };
class RGE_Color_Table;
class TDrawArea;

class RGE_Active_Sprite_Node {
public:
    RGE_Active_Sprite* node;
    unsigned char order;
    unsigned char count;
    char gap_06[0x2];
    RGE_Active_Sprite_Node* next;
};

class RGE_Active_Sprite_List {
public:
    virtual ~RGE_Active_Sprite_List();
    virtual short frame(RGE_Sprite*);
    virtual void update(float, float);
    virtual void draw(short, short, short, short, short, RGE_Color_Table*, TDrawArea*);
    virtual void normal_draw(short, short, short, RGE_Color_Table*, TDrawArea*);
    virtual void shadow_draw(short, short, short, RGE_Color_Table*, TDrawArea*, unsigned char);
    virtual unsigned char is_animating(RGE_Sprite*);
    virtual void set_frame(RGE_Sprite*, short);
    virtual unsigned char frame_passed(RGE_Sprite*, short);
    virtual unsigned char looped(RGE_Sprite*);
    virtual short get_facetindex(RGE_Sprite*, short);
    virtual unsigned char load_node(int, unsigned char, RGE_Sprite**);
    RGE_Active_Sprite_Node* list;
    RGE_Static_Object* owner;
    void add_sprite(RGE_Sprite* param_1, unsigned char param_2, long param_3, long param_4);
};

void RGE_Active_Sprite_List::add_sprite(RGE_Sprite* param_1, unsigned char param_2, long param_3, long param_4) {
    RGE_Active_Sprite_Node* pp;
    RGE_Active_Sprite_Node** ppPrev;

    if (param_1 == 0) { return; }

    if (param_1->check_for_shadows() && this->owner) {
        this->owner->remove_shadows();
    }

    pp = this->list;
    ppPrev = &this->list;
find_existing:
    if (pp) {
        if (pp->node->sprite == param_1) {
            pp->count++;
            return;
        }
        pp = pp->next;
        goto find_existing;
    }

    pp = this->list;
find_insert:
    if (pp && pp->order <= param_2) {
        ppPrev = &pp->next;
        pp = pp->next;
        goto find_insert;
    }

    RGE_Active_Sprite_Node* node = (RGE_Active_Sprite_Node*)calloc(0xc, 1);
    RGE_Active_Sprite* asp = param_1->make_active_sprite();
    node->node = asp;
    asp->set_offset(param_3, param_4);
    node->order = param_2;
    node->next = *ppPrev;
    *ppPrev = node;
}
