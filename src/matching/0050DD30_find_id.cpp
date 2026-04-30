// VA: 0050DD30 find_id (51B)
// Timeline.cpp - linked list traversal

class RGE_Timeline;

struct RGE_Time_Entry {
    char gap_00[4];
    unsigned char command;   // +0x04
    char gap_05[0x1C - 0x05];
    void* this_obj;          // +0x1C
    short this_obj_id;       // +0x20
    char gap_22[0x2C - 0x22];
    RGE_Time_Entry* next;    // +0x2C
};

class RGE_Timeline {
public:
    char gap_00[8];
    RGE_Time_Entry* time_list;  // +0x08

    short find_id(void* obj);
};

short RGE_Timeline::find_id(void* obj) {
    RGE_Time_Entry* entry = this->time_list;
    if (entry == 0) return -1;

    while (entry != 0) {
        if (entry->command == 1 && entry->this_obj == obj) {
            return entry->this_obj_id;
        }
        entry = entry->next;
    }
    return -1;
}
