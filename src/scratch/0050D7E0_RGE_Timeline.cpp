// VA: 0050D7E0 RGE_Timeline::~RGE_Timeline (70 B, 23 asm)
// PDB source: Timeline.cpp lines 90-103
//
// FLAGS: /GX (testing if EH changes register allocation)
//
// Attempt log:
// 1-6. Various loop forms, scope/temp vars: systematic esi↔edi swap.
// 7. Try with /GX to see if EH context changes register allocator behavior.

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
            RGE_Time_Entry* cur = this->time_list;
            RGE_Time_Entry* nxt = cur->next;
            free(cur);
            this->time_list = nxt;
        } while (this->time_list != 0);
    }
    this->avail_id = 0;
    this->old_time = -1.0f;
    this->world = 0;
    this->list_num = 0;
}
