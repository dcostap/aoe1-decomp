class RGE_Static_Object;
class RGE_Player {
public:
    char gap_00[0x4A];
    unsigned char id;
};

class RGE_Static_Object {
public:
    char gap_00[0xC];
    RGE_Player* owner;
};

class RGE_Time_Entry {
public:
    char gap_00[4];
    unsigned char command;
    char gap_05[3];
    unsigned char player;
    char gap_09[0x13];
    RGE_Static_Object* this_obj;
    short this_obj_id;
    char gap_22[2];
    RGE_Static_Object* target_obj;
    short target_obj_id;
    char gap_2A[0x10];
};

class RGE_Timeline {
public:
    RGE_Time_Entry* add(float time);
    short find_id(RGE_Static_Object* object);
    RGE_Time_Entry* add_attack(float time, RGE_Static_Object* object, RGE_Static_Object* target);
};

RGE_Time_Entry* RGE_Timeline::add_attack(float time, RGE_Static_Object* object, RGE_Static_Object* target) {
    RGE_Time_Entry* entry = this->add(time);
    if (entry != 0) {
        entry->this_obj = object;
        entry->player = object->owner->id;
        entry->this_obj_id = this->find_id(object);
        entry->target_obj = target;
        entry->target_obj_id = this->find_id(object);
        entry->command = 0;
    }
    return entry;
}
