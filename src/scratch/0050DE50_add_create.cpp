// 0050DE50 RGE_Timeline::add_create
// Source: Timeline.cpp lines 404-431
// Size: 149 bytes
//
// Attempt log:
// Probe 1: structural stub — calls add() then complex pointer chasing

#include "..\..\include\game_globals.h"

struct TimeNode {
    float time;
    char _gap_04[0x28];
    TimeNode* next;
};

class RGE_Timeline {
public:
    char _gap_00[4];
    void* world;
    TimeNode* head;
    short count;

    TimeNode* add(float time);
    TimeNode* add_create(float time, int type, int id);
};

extern void* __cdecl calloc(int num, int size);

TimeNode* RGE_Timeline::add_create(float time, int type, int id)
{
    TimeNode* node = this->add(time);
    // Look up creation data from world and fill node
    return node;
}
