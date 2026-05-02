// VA: 0050D7E0 RGE_Timeline::~RGE_Timeline (70 B, 23 asm)
// PDB source: Timeline.cpp lines 90-103
//
// Attempt log:
// 1. Prior scratch: RGE_Timeline* timeline = this + pRVar1.
//    72% diff: esi↔edi swap + push eax vs mov ecx,eax+push ecx.
// 2-5. Various loop forms, void* temp, function-scope next: same systematic esi↔edi swap.
// 6. while(this->time_list) with guard to force reload pattern.

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
    this->vtable_ptr = (void*)0x5766F4;
    if (this->time_list != 0) {
        while (this->time_list != 0) {
            RGE_Time_Entry* current = this->time_list;
            RGE_Time_Entry* nxt = current->next;
            free(current);
            this->time_list = nxt;
        }
    }
    this->avail_id = 0;
    this->old_time = -1.0f;
    this->world = 0;
    this->list_num = 0;
}
