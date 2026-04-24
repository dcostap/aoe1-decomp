class RGE_Static_Object;

struct RGE_Time_Entry {
    char gap_00[0x4];
    unsigned char command;
    char gap_05[3];
    unsigned char player;
    char gap_09[3];
    float x;
    float y;
    float z;
    char gap_18[4];
    RGE_Static_Object* this_obj;
    short this_obj_id;
    char gap_22[0xA];
    RGE_Time_Entry* next;
};

class RGE_Timeline {
public:
    char gap_00[0x8];
    RGE_Time_Entry* time_list;

    RGE_Time_Entry* add(float time);
    short find_id(RGE_Static_Object* object);
    RGE_Time_Entry* add_move(float time, RGE_Static_Object* object, float x, float y, float z);
};

RGE_Time_Entry* RGE_Timeline::add_move(float time, RGE_Static_Object* object, float x, float y, float z) {
    RGE_Time_Entry* entry = this->add(time);
    if (entry != 0) {
        entry->player = *(unsigned char*)(((char*)*(void**)((char*)object + 0xC)) + 0x4A);
        entry->this_obj = object;
        entry->this_obj_id = this->find_id(object);
        entry->x = x;
        entry->y = y;
        entry->z = z;
        entry->command = 2;
    }
    return entry;
}
