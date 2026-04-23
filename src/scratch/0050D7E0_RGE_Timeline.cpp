// attempt log:
// started with the direct destructor shape: set the vtable, free the time_list chain, then clear the trailing fields
// tried the literal decompiler loop, a copied-timeline local, and a direct field-walk variant; the remaining mismatch stayed on the prologue register basin (esi vs edi)
// left in scratch because the logic is right but VC5 keeps choosing the wrong this-register family
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
    RGE_Time_Entry* next;
};

class RGE_Timeline {
public:
    void* vtable_ptr;
    RGE_Game_World* world;
    RGE_Time_Entry* time_list;
    short list_num;
    short avail_id;
    float old_time;

    ~RGE_Timeline();
};

RGE_Timeline::~RGE_Timeline() {
    RGE_Timeline* timeline = this;
    RGE_Time_Entry* pRVar1;

    pRVar1 = timeline->time_list;
    timeline->vtable_ptr = (void*)0x5766F4;
    while (pRVar1 != 0) {
        pRVar1 = timeline->time_list->next;
        free(timeline->time_list);
        timeline->time_list = pRVar1;
    }
    timeline->avail_id = 0;
    timeline->old_time = -1.0f;
    timeline->world = 0;
    timeline->list_num = 0;
}
