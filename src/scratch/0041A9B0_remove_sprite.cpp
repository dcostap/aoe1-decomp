// tried 130+ variants across 13 variant lab runs (labs 1-13)
// class layout findings:
//   - explicit void* vtable_ptr + virtual destroy = WRONG (sprite at offset 8, cmp [edx+8])
//   - explicit void* vtable_ptr + non-virtual destroy = CORRECT (sprite at offset 4, cmp [edx+4])
//   - no vtable_ptr + virtual destroy = CORRECT layout but destroy devirtualized (no vtable generated)
// loop structure findings:
//   - for-loop: 112 bytes, mismatch offset 24 (extra null check after loop, shifts je targets)
//   - do-while with goto: 128 bytes, too large (virtual destroy call adds 16 bytes of vtable dispatch)
//   - while-loop: 128 bytes, too large (same as do-while)
//   - for-loop + goto found: 112 bytes, same as for-loop (goto doesn't eliminate extra null check)
// cleanup code findings:
//   - devirtualized destroy call saves 7 bytes vs original virtual dispatch
//   - missing this->owner null check (VC5 optimizes it away with minimal class stub)
//   - check_for_shadows int temp vs inline: no codegen difference
// count check findings: p->count + 0xff, p->count--, p->count > 0: all same codegen
// best result: for-loop + no-virtual destroy + minimal class = 112 bytes, mismatch at offset 24
// remaining gap: extra null check after loop (5 bytes) + devirtualized destroy (-7 bytes) + missing owner check (-5 bytes) = net -7 bytes
// but other parts of code differ by +8 bytes, so net +1 byte (112 vs 111)
// this is a codegen basin / TU context issue: original compiled with full class hierarchy (vtable dispatch)
// and full TU context (owner null check not optimized away)

extern "C" void __cdecl free(void* block);

class RGE_Sprite;
class RGE_Static_Object;

class RGE_Active_Sprite {
public:
    void* vtable_ptr;
    RGE_Sprite* sprite;
    void destroy(int);
    int check_for_shadows();
};

class RGE_Sprite {};
class RGE_Static_Object { public: void remove_shadows(); };

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
    void* vtable_ptr;
    RGE_Active_Sprite_Node* list;
    RGE_Static_Object* owner;
    void remove_sprite(RGE_Sprite* param_1);
};

void RGE_Active_Sprite_List::remove_sprite(RGE_Sprite* param_1) {
    RGE_Active_Sprite_Node* p;
    RGE_Active_Sprite_Node** ppPrev;

    ppPrev = &this->list;
    for (p = this->list; p && p->node->sprite != param_1; p = p->next) {
        ppPrev = &p->next;
    }
    if (p == 0) { return; }
    if (p->count != 0) { p->count = p->count + 0xff; return; }
    *ppPrev = p->next;
    if (p->node->check_for_shadows() != 0 && this->owner != 0) { this->owner->remove_shadows(); }
    if (p->node != 0) { p->node->destroy(1); }
    free(p);
}
