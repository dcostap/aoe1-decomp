// 0050DD70 RGE_Timeline::add
// Source: Timeline.cpp lines 340-378
// Size: 136 bytes
//
// Attempt log:
// Probe 1: 112/136 — loop + alloc blocks merged
// Probe 2: 136/136, 66% diff — store order and control flow differ

#include "..\..\include\game_globals.h"

struct TimeNode {
    float time;                 // +0x00
    char _gap_04[0x28];
    TimeNode* next;             // +0x2C
};

class RGE_Timeline {
public:
    char _gap_00[8];
    TimeNode* head;             // +0x08
    short count;                // +0x0C

    TimeNode* add(float time);
};

extern void* __cdecl calloc(int num, int size);

TimeNode* RGE_Timeline::add(float time)
{
    TimeNode* node = this->head;
    TimeNode** prev = &this->head;

    if (node == 0) {
        node = (TimeNode*)calloc(1, 0x30);
        *prev = node;
        node->time = time;
        this->count++;
        return node;
    }

    while (1) {
        if (time < node->time) {
            TimeNode* newNode = (TimeNode*)calloc(1, 0x30);
            newNode->time = time;
            newNode->next = node;
            *prev = newNode;
            this->count++;
            return newNode;
        }
        if (node->next == 0) {
            TimeNode* newNode = (TimeNode*)calloc(1, 0x30);
            newNode->time = time;
            *prev = newNode;
            this->count++;
            return newNode;
        }
        prev = &node->next;
        node = node->next;
    }
}
