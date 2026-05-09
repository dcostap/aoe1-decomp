// VA: 0050D7E0 RGE_Timeline::~RGE_Timeline (70 B, 23 asm)
// PDB source: Timeline.cpp lines 90-103
//
// BLOCKER: default /O2 VC5 in this isolated TU consistently selects edi for
// `this` and esi for `next`; original selects esi for `this` and edi for `next`.
// The remaining behavioral model is clear: restore vtable, free each time_list
// node through its +0x2C next link, then reset avail_id/old_time/world/list_num.
//
// Attempt log:
// 1. Prior scratch (RGE_Timeline* timeline + pRVar1): 72% diff.
// 2. Removed timeline local (this-> directly): same esi/edi swap.
// 3. do-while with void* temp for free(): same.
// 4. Function-scope next (declared before list): same.
// 5. while(this->time_list) with if-guard: same.
// 6. /GX flag (EH context): same.
// 7. Reordered final field stores: same.
// 8. Manual free declaration (no stdlib): same.
// 9. Explicit (void*) cast on free arg: same.
// 10. my_free wrapper (inlined): same.
// 11. do-while with next as loop condition: same.
// 12. variant_lab over include/free decl, virtual/manual class, vptr timing,
//     current-nxt/list-walk/direct/assign-cond loop surfaces, and vc5-small
//     flags: only six asm families; all default-family variants keep edi=this,
//     esi=next and push eax before loading next.
// 13. variant_lab with vc5-risky flags: /O1 gets esi=this, but changes loop
//     body (shorter branch, push eax, pop ecx cleanup, and and-zero stores), so
//     it is not an exact or acceptable flag fix.
// 14. Donor constructor TU context before dtor caused wrong symbol extraction;
//     not kept.
// 15. Explicit self local, delete current, volatile current/time_list: no change
//     from the default edi=this / esi=next family.

#include <stdlib.h>

class RGE_Game_World;
class RGE_Time_Entry {
public:
    float time;
    unsigned char command;
    unsigned char _pad_0[1];
    short obj_type;
    unsigned char player;
    unsigned char _pad_1[3];
    float x;
    float y;
    float z;
    short task;
    unsigned char _pad_2[2];
    void* this_obj;
    short this_obj_id;
    unsigned char _pad_3[2];
    void* target_obj;
    short target_obj_id;
    unsigned char _pad_4[2];
    RGE_Time_Entry* next;  // +0x2C
};

class RGE_Timeline {
public:
    void* vtable_ptr;          // +0x00
    RGE_Game_World* world;     // +0x04
    RGE_Time_Entry* time_list; // +0x08
    short list_num;            // +0x0C
    short avail_id;            // +0x0E
    float old_time;            // +0x10

    ~RGE_Timeline();
};

RGE_Timeline::~RGE_Timeline() {
    RGE_Time_Entry* list = this->time_list;
    this->vtable_ptr = (void*)0x5766F4;
    if (list != 0) {
        do {
            RGE_Time_Entry* current = this->time_list;
            RGE_Time_Entry* nxt = current->next;
            free(current);
            this->time_list = nxt;
        } while (this->time_list != 0);
    }
    this->avail_id = 0;
    this->old_time = -1.0f;
    this->world = 0;
    this->list_num = 0;
}
