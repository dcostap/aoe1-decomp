// VA: 0050DFD0 RGE_Timeline::sub(RGE_Time_Entry*) (100 B)
// PDB source: Timeline.cpp lines 499-530
// Attempt log: see bottom

extern "C" void __cdecl free(void* block);

class RGE_Time_Entry {
public:
    float time;
    unsigned char command;
    char gap_05[0x27];
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
    RGE_Time_Entry* cur;
    RGE_Time_Entry** pp;
    cur = this->time_list;
    if (cur == 0) return;
    pp = &this->time_list;

    while (1) {
        if (cur == entry) break;
        pp = &cur->next;
        cur = cur->next;
        if (cur == 0) return;
    }

    *pp = cur->next;
    if (cur->command == 1) {
        cur = this->time_list;
        if (cur != 0) {
            while (cur->next != 0) {
                cur = cur->next;
            }
        }
    }

    this->sub(cur);
    free(entry);
    --this->list_num;
}
