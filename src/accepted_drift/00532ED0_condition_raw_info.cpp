// ACCEPTED_DRIFT: traversal counter/register allocation drift only (edx vs ecx, reversed equality compare); same node walk, selected-node return, null return, and stack cleanup.
// STATUS: active lead
// control flow and byte count match, but VC5 still assigns the running counter to ecx and the wanted index to edx instead of the original edx/ecx split
// explicit wanted/count locals did not change that register family, so the remaining gap is localized to the counter/index register choice in the loop header

#ifndef VICTORY_CONTEXT_H
class RGE_Victory_Entry {
public:
    char gap_00[0x30];
    RGE_Victory_Entry* next;
};

class RGE_Victory_Conditions {
public:
    void* field_00;
    RGE_Victory_Entry* victory_list;

    RGE_Victory_Entry* condition_raw_info(long index);
};
#endif

RGE_Victory_Entry* RGE_Victory_Conditions::condition_raw_info(long index) {
    RGE_Victory_Entry* entry;
    long wanted;
    long count;

    entry = this->victory_list;
    wanted = index;
    count = 0;
    while (entry != 0) {
        if (count == wanted) {
            return entry;
        }
        entry = entry->next;
        count = count + 1;
    }
    return 0;
}
