// ACCEPTED_DRIFT: linked-list miss path is laid out differently but tests the same nodes, unlinks/frees the same matching node, and shares the same empty/miss return behavior.
// tried the direct pointer-to-pointer unlink shape first; the remaining mismatch is the second compare inside the list walk
// tried an explicit top-test / advance / null-check loop next; same basin, so this is likely branch/layout drift
// leaving this in scratch because behavior is right and the gap is now localized

extern "C" void __cdecl free(void* block);

#include "../../include/victory_context.h"

void RGE_Victory_Conditions::sub(RGE_Victory_Entry* entry) {
    RGE_Victory_Entry* node = this->victory_list;
    RGE_Victory_Entry** link = &this->victory_list;
    if (node != 0) {
        for (;;) {
            if (node == entry) {
                break;
            }
            link = &node->next;
            node = node->next;
            if (node == 0) {
                return;
            }
        }
        *link = node->next;
        free(node);
        this->list_num--;
    }
}
