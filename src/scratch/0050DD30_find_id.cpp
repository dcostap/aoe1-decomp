class RGE_Static_Object;

struct RGE_Time_Entry {
    char gap_00[0x04];
    unsigned char command;
    char gap_05[0x17];
    RGE_Static_Object* this_obj;
    short this_obj_id;
    char gap_22[0x0A];
    RGE_Time_Entry* next;
};

class RGE_Timeline {
public:
    char gap_00[0x08];
    RGE_Time_Entry* time_list;

    short find_id(RGE_Static_Object* object);
};

short RGE_Timeline::find_id(RGE_Static_Object* object) {
    RGE_Time_Entry* entry = this->time_list;

    if (entry == 0) {
        return -1;
    }
    while ((entry->command != 1) || (entry->this_obj != object)) {
        entry = entry->next;
        if (entry == 0) {
            return -1;
        }
    }
    return entry->this_obj_id;
}
