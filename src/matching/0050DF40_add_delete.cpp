// 0050DF40 RGE_Timeline::add_delete
// Source: Timeline.cpp
// Size: 144 bytes
//
// Attempt log:
// Probe 1: structural stub — calls add() then fills deletion data

#include "..\..\include\game_globals.h"

class RGE_Static_Object {
public:
    virtual void v0(int);
    char gap_04[4];
    void* master_obj;       // +0x08
    void* owner;            // +0x0C
    char gap_10[0x38 - 0x10];
    int world_x;            // +0x38
    int world_y;            // +0x3C
};

struct TimeNode {
    float time;             // +0x00
    unsigned char command;  // +0x04
    short obj_type;         // +0x06
    unsigned char player;   // +0x08
    char gap_09[3];
    int x;                  // +0x0C
    int y;                  // +0x10
    char gap_14[0x1C - 0x14];
    RGE_Static_Object* this_obj;   // +0x1C
    short this_obj_id;      // +0x20
    char gap_22[2];
    RGE_Static_Object* target_obj; // +0x24
    char gap_28[4];
    TimeNode* next;         // +0x2C
};

class RGE_Timeline {
public:
    char _gap_00[4];
    void* world;
    TimeNode* head;
    short count;

    TimeNode* add(float time);
    TimeNode* add_delete(float time, RGE_Static_Object* obj);
};

TimeNode* RGE_Timeline::add_delete(float time, RGE_Static_Object* obj)
{
    if (obj == 0)
        return 0;

    TimeNode* node = this->add(time);
    if (node != 0) {
        TimeNode* cur = this->head;
        while (cur != 0) {
            if (obj == cur->this_obj) {
                unsigned char cmd = cur->command;
                cur->this_obj = 0;
                if (cmd == 1)
                    node->this_obj_id = cur->this_obj_id;
            }
            if (obj == cur->target_obj)
                cur->target_obj = 0;
            cur = cur->next;
        }

        node->player = *(unsigned char*)((char*)obj->owner + 0x4A);
        node->obj_type = *(short*)((char*)obj->master_obj + 0x10);
        node->command = 4;
        node->x = obj->world_x;
        node->y = obj->world_y;
        obj->v0(1);
    }
    return node;
}
