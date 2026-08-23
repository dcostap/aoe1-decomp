#include "../../include/rge_zone_queue_context.h"

extern "C" void* __cdecl calloc(unsigned int num, unsigned int size);

void __cdecl zone_push(Zone_Queue** head, Zone_Queue** tail, long x, long y) {
    Zone_Queue* node = (Zone_Queue*)calloc(1, 0xC);

    if (*tail != 0) {
        (*tail)->next = node;
    }
    node->x = x;
    node->y = y;
    *tail = node;
    if (*head == 0) {
        *head = node;
    }
}
