// VA: 0050DD70 RGE_Timeline::add
// Source: Timeline.cpp lines 340-378
// FLAGS: /nologo /c /O2 /Oy
//
// Attempt log:
// 6: use separate newNode var for append path too
// === ACCEPTED_DRIFT ===
// Remaining drift is a localized scheduling swap in the insert-before path after calloc:
// original stores time then next, rebuilt stores next then time before the same stack cleanup.
// The stores are independent and write the same values to the same new node fields; all control flow,
// append-at-end path, empty-list path, count increment, and epilogues match.

#include <stdlib.h>

struct RGE_Time_Entry {
    float time;                 // +0x00
    char gap_04[0x2C - 0x04];
    RGE_Time_Entry* next;       // +0x2C
};

class RGE_Timeline {
public:
    char gap_00[8];
    RGE_Time_Entry* head;       // +0x08
    short count;                // +0x0C

    RGE_Time_Entry* add(float time);
};

RGE_Time_Entry* RGE_Timeline::add(float time)
{
    RGE_Time_Entry* node;
    RGE_Time_Entry** prev;

    node = this->head;
    prev = &this->head;
    if (node == 0) {
        node = (RGE_Time_Entry*)calloc(1, 0x30);
        *prev = node;
        node->time = time;
        this->count++;
        return *prev;
    }

    while (node != 0) {
        if (node->time > time) {
            RGE_Time_Entry* newNode = (RGE_Time_Entry*)calloc(1, 0x30);
            newNode->time = time;
            newNode->next = node;
            *prev = newNode;
            this->count++;
            return newNode;
        }
        prev = &node->next;
        node = node->next;
    }

    // Append at end
    {
        RGE_Time_Entry* newNode = (RGE_Time_Entry*)calloc(1, 0x30);
        newNode->time = time;
        newNode->next = 0;
        *prev = newNode;
        this->count++;
        return newNode;
    }
}
