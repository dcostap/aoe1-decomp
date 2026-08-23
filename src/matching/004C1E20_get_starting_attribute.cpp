#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
class RGE_Master_Static_Object {
public:
    void* vtable_ptr;
    unsigned char master_type;
    unsigned char gap_05[0x3];
    char* name;
    short string_id;
    short string_id2;
    short id;
    short copy_id;
    short object_group;
    unsigned char gap_16[0x2];
    void* sprite;
    void* death_sprite;
    void* undead_sprite;
    unsigned char undead_flag;
    unsigned char gap_25[0x1];
    short hp;
    float los;
    unsigned char obj_max;
    unsigned char gap_2D[0x3];
    float radius_x;
    float radius_y;
    float radius_z;
    void* selected_sound;
    void* created_sound;
    void* death_sound;
    short death_spawn_obj_id;
    unsigned char sort_number;
    unsigned char can_be_built_on;
    short button_pict;
    unsigned char hide_in_scenario_editor;
    unsigned char gap_4F[0x1];
    short portrait_pict;
    unsigned char available;
    unsigned char gap_53[0x1];
    short tile_req1;
    short tile_req2;
    short center_tile_req1;
    short center_tile_req2;
    float construction_radius_x;
    float construction_radius_y;
    unsigned char elevation_flag;
    unsigned char fog_flag;
    short terrain;
    unsigned char movement_type;
    unsigned char gap_69[0x1];
    short attribute_type_held[3];
    float attribute_amount_held[3];
    short attribute_max_amount;
    unsigned char gap_7E[0x2];
    float attribute_rot;
    float multiple_attribute_mod;
    unsigned char attribute_flag[3];
};

class RGE_Static_Object {
public:
    void* vtable_ptr;
    long id;
    RGE_Master_Static_Object* master_obj;
    char gap_0C[0x38];
    float attribute_amount_held;
    unsigned char object_state;
    unsigned char sleep_flag;
    unsigned char dopple_flag;
    unsigned char goto_sleep_flag;
    short attribute_type_held;

    void get_starting_attribute();
};

#endif

void RGE_Static_Object::get_starting_attribute()
{
    RGE_Master_Static_Object* master;
    unsigned char* attr_flag;
    short* attr_type;
    float* attr_amount;
    int count;

    master = this->master_obj;
    this->attribute_type_held = -1;
    this->attribute_amount_held = 0;
    attr_flag = master->attribute_flag;
    attr_amount = master->attribute_amount_held;
    attr_type = master->attribute_type_held;
    count = 3;
    do {
        if (*attr_flag == 0 && *attr_type != -1) {
            this->attribute_type_held = *attr_type;
            this->attribute_amount_held = *attr_amount;
        }
        attr_type++;
        attr_amount++;
        attr_flag++;
        count--;
    } while (count != 0);
}
