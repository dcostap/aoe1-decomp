// first pass: pop the head queue node, copy out x/y, unlink it, free it, and clear tail when list becomes empty
// if this misses, the remaining mismatch is likely only argument/register shaping around the free call

extern "C" void __cdecl free(void* block);
#include "../../include/rge_zone_queue_context.h"

unsigned char __cdecl zone_pop(Zone_Queue** head, Zone_Queue** tail, long* x_out, long* y_out) {
    Zone_Queue* node = *head;
    if (node == 0) {
        return 0;
    }

    *x_out = node->x;
    *y_out = node->y;
    *head = node->next;
    free(node);
    if (*head == 0) {
        *tail = 0;
    }
    return 1;
}
