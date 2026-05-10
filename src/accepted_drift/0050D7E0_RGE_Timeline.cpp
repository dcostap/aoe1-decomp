// VA: 0050D7E0 RGE_Timeline::~RGE_Timeline (70 B, 23 asm)
// PDB source: Timeline.cpp lines 90-103
//
// ACCEPTED_DRIFT: reviewed by Boss. Non-zero diff is localized to equivalent
// free-argument scheduling in the destructor loop: rebuilt pushes the current
// entry before loading next (`push eax; mov edi,[eax+2C]`) while original copies
// current to ecx, loads next, then pushes ecx. Both load next before free(), pass
// the same pointer, preserve stack cleanup, update time_list identically, and
// perform the same final reset stores. Remaining byte drift is branch displacement
// and NOP padding fallout from this two-byte scheduling difference.
//
// Attempt log:
// 1. Prior scratch (manual vptr, nonvolatile this, list/current/nxt locals):
//    default /O2 selected edi=this and esi=next; 72.86% positional diff.
// 2. Natural virtual destructor surface from matched ctor: same edi=this family,
//    plus vtable relocation masked in comparison; not better.
// 3. self local, register self, copy arg local, pointer-walking while, for-loop,
//    assign-in-condition, goto-loop, current-after-free guard: no exact; either
//    stayed edi=this or added extra blocks/registers.
// 4. volatile RGE_Timeline* self made VC5 select esi=this and edi=next, matching
//    the original register family and all final stores; kept this best variant.
// 5. Tried volatile member/current, loop condition on self->time_list vs nxt,
//    arg copy before/after nxt, register arg, int/pointer casts, reference casts,
//    char-offset next load, comma/ternary forms, and volatile temp stack forms.
//    None produced the original `mov ecx,eax` before the next load without extra
//    stack traffic or blocks.
// 6. /O2 /Oy- did not help. Prior lab notes: /O1 can get esi=this but changes
//    loop cleanup/final zeroing, not an exact flag fix.

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
    volatile RGE_Timeline* self = this;
    RGE_Time_Entry* list = (RGE_Time_Entry*)self->time_list;
    self->vtable_ptr = (void*)0x5766F4;
    if (list != 0) {
        RGE_Time_Entry* nxt;
        do {
            RGE_Time_Entry* current = (RGE_Time_Entry*)self->time_list;
            nxt = current->next;
            free(current);
            self->time_list = nxt;
        } while (nxt != 0);
    }
    self->avail_id = 0;
    self->old_time = -1.0f;
    self->world = 0;
    self->list_num = 0;
}
