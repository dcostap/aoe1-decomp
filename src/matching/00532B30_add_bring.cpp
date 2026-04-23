class RGE_Static_Object;

class RGE_Victory_Entry {
public:
    unsigned char command;
    char _pad_0[0x3];
    long obj_type;
    void* target_player;
    float x0;
    float y0;
    float x1;
    float y1;
    long number;
    long count;
    RGE_Static_Object* this_obj;
    RGE_Static_Object* target_obj;
    unsigned char victory_group;
    unsigned char ally_flag;
    unsigned char state;
    unsigned char checked_flag;
    RGE_Victory_Entry* next;
};

class RGE_Victory_Conditions {
public:
    RGE_Victory_Entry* add(unsigned char param_1, unsigned char param_2);
    unsigned char add_bring(unsigned char param_1, RGE_Static_Object* param_2, float param_3, float param_4, float param_5, float param_6);
};

unsigned char RGE_Victory_Conditions::add_bring(unsigned char param_1, RGE_Static_Object* param_2, float param_3, float param_4, float param_5, float param_6) {
    RGE_Victory_Entry* entry = this->add(param_1, 0);
    if (entry != 0) {
        entry->command = 4;
        entry->this_obj = param_2;
        entry->x0 = param_3;
        entry->y0 = param_4;
        entry->x1 = param_5;
        entry->y1 = param_6;
        return 1;
    }
    return 0;
}
