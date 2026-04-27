// attempt 1: linked-list unlink with the recursive tail/null sub path
// attempt 2: tried a broader local layout, but the compiler added an extra saved register; reverting to a leaner pointer-only shape
// attempt 3: trying the decompiler-shaped pp/entry locals and the explicit tail-to-null scan
// attempt 4: narrowing the locals to ppRVar1/pRVar2 only; the remaining gap may just be the duplicate early null-test basin
// left paused in scratch: current source is behavior-plausible, but VC5 keeps landing at 96 bytes instead of the 100-byte target
// if this is resumed, the next probe is the exact early-check / register-pressure basin around the null head test

extern "C" void __cdecl free(void* block);

class RGE_Time_Entry {
public:
    float time;
    unsigned char command;
    char gap_05[3];
    short obj_type;
    unsigned char player;
    char gap_09[3];
    float x;
    float y;
    float z;
    short task;
    char gap_1A[2];
    void* this_obj;
    short this_obj_id;
    char gap_22[2];
    void* target_obj;
    short target_obj_id;
    char gap_2A[2];
    RGE_Time_Entry* next;
};

class RGE_Timeline {
public:
    void* vtable_ptr;
    void* world;
    RGE_Time_Entry* time_list;
    short list_num;
    short avail_id;
    float old_time;

    void sub(RGE_Time_Entry* entry);
};

void RGE_Timeline::sub(RGE_Time_Entry* entry) {
    RGE_Time_Entry **ppRVar1;
    RGE_Time_Entry *pRVar2;

    pRVar2 = this->time_list;
    if (pRVar2 == 0) {
        return;
    }
    ppRVar1 = &this->time_list;
    if (pRVar2 == 0) {
        return;
    }

    while (pRVar2 != entry) {
        ppRVar1 = &pRVar2->next;
        pRVar2 = pRVar2->next;
        if (pRVar2 == 0) {
            return;
        }
    }

    *ppRVar1 = pRVar2->next;
    if (pRVar2->command == 1) {
        entry = this->time_list;
        if (entry != 0) {
            do {
                entry = entry->next;
            } while (entry != 0);
            entry = 0;
        }
    }

    this->sub(entry);
    free(pRVar2);
    this->list_num = this->list_num + -1;
}
