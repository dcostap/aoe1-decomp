// VA: 0050DD70 RGE_Timeline::add
// Source: Timeline.cpp lines 340-378.
//
// ACCEPTED_DRIFT: insert-before stores the new node's fields in the reverse
// order from the original.  The list topology, count, and return paths agree.

#include "../../include/Timeline_context.h"
#include <stdlib.h>

RGE_Time_Entry* RGE_Timeline::add(float time)
{
    RGE_Time_Entry* node;
    RGE_Time_Entry** prev;

    node = this->time_list;
    prev = &this->time_list;
    if (node == 0) {
        node = (RGE_Time_Entry*)calloc(1, 0x30);
        *prev = node;
        node->time = time;
        this->list_num++;
        return *prev;
    }

    while (node != 0) {
        if (node->time > time) {
            RGE_Time_Entry* newNode = (RGE_Time_Entry*)calloc(1, 0x30);
            newNode->time = time;
            newNode->next = node;
            *prev = newNode;
            this->list_num++;
            return newNode;
        }
        prev = &node->next;
        node = node->next;
    }

    {
        RGE_Time_Entry* newNode = (RGE_Time_Entry*)calloc(1, 0x30);
        newNode->time = time;
        newNode->next = 0;
        *prev = newNode;
        this->list_num++;
        return newNode;
    }
}
