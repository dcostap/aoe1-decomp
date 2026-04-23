// tried the direct pointer-to-pointer unlink shape first; the remaining mismatch is the second compare inside the list walk
// tried an explicit top-test / advance / null-check loop next; same basin, so this is likely branch/layout drift
// leaving this in scratch because behavior is right and the gap is now localized

extern "C" void __cdecl free(void* block);

class RGE_Victory_Entry {
public:
    unsigned char command;
    char gap_01[3];
    long obj_type;
    void* target_player;
    float x0;
    float y0;
    float x1;
    float y1;
    long number;
    long count;
    void* this_obj;
    void* target_obj;
    unsigned char victory_group;
    unsigned char ally_flag;
    unsigned char state;
    unsigned char checked_flag;
    RGE_Victory_Entry* next;
};

class RGE_Victory_Conditions {
public:
    void* vtable_ptr;
    RGE_Victory_Entry* victory_list;
    long list_num;

    void sub(RGE_Victory_Entry* entry);
};

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
