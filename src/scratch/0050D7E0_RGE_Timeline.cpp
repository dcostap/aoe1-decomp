// VA: 0050D7E0 RGE_Timeline::~RGE_Timeline (70 B, 23 asm)
// PDB source: Timeline.cpp lines 90-103
//
// BLOCKER: Systematic esi/edi register swap + push eax vs mov ecx,eax+push ecx.
//
// Attempt log:
// 1.  Prior scratch (RGE_Timeline* timeline + pRVar1): 72% diff.
// 2.  Removed timeline local (this-> directly): same esi/edi swap.
// 3.  do-while with void* temp for free(): same.
// 4.  Function-scope next (declared before list): same.
// 5.  while(this->time_list) with if-guard: same.
// 6.  /GX flag (EH context): same.
// 7.  Reordered field stores: same.
// 8.  Manual free declaration (no stdlib): same.
// 9.  Explicit (void*) cast on free arg: same.
// 10. my_free wrapper (inlined): same.
// 11. do-while with next as loop condition: same.
//
// Remaining differences (all systematic register/codegen choices):
// - push esi vs push edi (prologue saved register for 'this')
// - mov esi,ecx vs mov edi,ecx (which reg holds this)
// - mov ecx,eax; push ecx vs push eax (free() arg passing style)
// - Resulting je/jne offset differences from the 3B vs 1B arg push

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
    RGE_Time_Entry* next;  // at +0x2C
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
