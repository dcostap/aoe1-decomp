// 0050DF40 RGE_Timeline::add_delete
// Source: Timeline.cpp
// Size: 144 bytes
//
// Attempt log:
// Probe 1: structural stub — calls add() then fills deletion data

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
    TimeNode* add_delete(float time, int type, int id, int b, int c);
};

TimeNode* RGE_Timeline::add_delete(float time, int type, int id, int b, int c)
{
    TimeNode* node = this->add(time);
    return node;
}
