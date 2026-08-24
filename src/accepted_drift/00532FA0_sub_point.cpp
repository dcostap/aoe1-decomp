// ACCEPTED_DRIFT: linked-list miss path is laid out differently but tests the same point nodes, unlinks/frees the same matching node, and shares the same return behavior.
// tried the direct pointer-to-pointer unlink shape first; the remaining mismatch is the second compare inside the list walk
// the loop/body structure is behaviorally right, but VC5 is still choosing the wrong compare/branch basin
// leaving this in scratch because the remaining gap is localized and low-risk

extern "C" void __cdecl free(void* block);

#ifndef VICTORY_CONTEXT_H
class RGE_Victory_Point_Entry {
public:
    char gap_00[0x18];
    RGE_Victory_Point_Entry* next;
};

class RGE_Victory_Conditions {
public:
    char gap_00[0x14];
    RGE_Victory_Point_Entry* victory_point_list;
    long point_list_num;

    void sub_point(RGE_Victory_Point_Entry* entry);
};
#endif

void RGE_Victory_Conditions::sub_point(RGE_Victory_Point_Entry* entry) {
    RGE_Victory_Point_Entry* node = this->victory_point_list;
    RGE_Victory_Point_Entry** link = &this->victory_point_list;
    if (node != 0) {
        while (node != entry) {
            link = &node->next;
            node = node->next;
            if (node == 0) {
                return;
            }
        }
        *link = node->next;
        free(node);
        this->point_list_num--;
    }
}
