// 0050DE50 RGE_Timeline::add_create
// Source: Timeline.cpp lines 404-431
// Size: 149 bytes

#include "..\..\include\game_globals.h"

class RGE_Static_Object;
class RGE_Player;

class RGE_Master_Static_Object {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual RGE_Static_Object* create(RGE_Player* player, float x, float y, int z);
    char gap_04[0x20];
    RGE_Static_Object** objects; // +0x24-ish unused
};

class RGE_Player {
public:
    char gap_00[0x24];
    RGE_Master_Static_Object** master_objects; // +0x24
};

class RGE_World {
public:
    char gap_00[0x40];
    RGE_Player** players; // +0x40
};

struct TimeNode {
    float time;             // +0x00
    unsigned char command;  // +0x04
    short obj_type;         // +0x06
    unsigned char player;   // +0x08
    char gap_09[3];
    int x;                  // +0x0C
    int y;                  // +0x10
    int z;                  // +0x14
    char gap_18[4];
    RGE_Static_Object* this_obj;   // +0x1C
    short this_obj_id;      // +0x20
    char gap_22[0x2C - 0x22];
    TimeNode* next;         // +0x2C
};

class RGE_Timeline {
public:
    char _gap_00[4];
    RGE_World* world;       // +0x04
    TimeNode* head;         // +0x08
    char gap_0C[2];
    short avail_id;         // +0x0E

    TimeNode* add(float time);
    TimeNode* add_create(float time, short type, unsigned char player, float x, float y, float z);
};

TimeNode* RGE_Timeline::add_create(float time, short type, unsigned char player, float x, float y, float z)
{
    RGE_Static_Object* obj = 0;
    TimeNode* node = this->add(time);
    RGE_Player* p = this->world->players[player];
    RGE_Master_Static_Object* master = p->master_objects[type];
    if (master != 0)
        obj = master->create(p, x, y, 0);

    if (node != 0 && master != 0) {
        node->player = player;
        node->obj_type = type;
        node->this_obj = obj;
        node->this_obj_id = this->avail_id;
        this->avail_id++;
        node->x = *(int*)&x;
        node->y = *(int*)&y;
        node->z = *(int*)&z;
        node->command = 1;
    }
    return node;
}
