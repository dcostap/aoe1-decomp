#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
extern float DAT_00574720;

class RGE_Static_Object {
public:
    void* vtable_ptr;
    long id;
    void* master_obj;
    void* owner;
    void* sprite;
    void* old_sprite;
    void* sprite_list;
    void* tile;
    void* inside_obj;
    void* objects;
    short screen_x_offset;
    short screen_y_offset;
    short shadow_x_offset;
    short shadow_y_offset;
    float hp;
    unsigned char curr_damage_percent;
    unsigned char facet;
    unsigned char selected;
    unsigned char selected_group;
    float world_x;
    float world_y;
    float world_z;
    float attribute_amount_held;
    unsigned char object_state;
    unsigned char sleep_flag;
    unsigned char dopple_flag;
    unsigned char goto_sleep_flag;
    short attribute_type_held;
    unsigned char type;
    unsigned char worker_num;

    void set_sleep_flag(unsigned char value);
    void release_being_worked_on(RGE_Static_Object* unused);
};

#endif

void RGE_Static_Object::release_being_worked_on(RGE_Static_Object* unused) {
    if (this->worker_num > 0) {
        this->worker_num--;
    }
    if (this->worker_num == 0) {
        unsigned char state = this->object_state;
        if (state == 2) {
            if (!(this->hp < DAT_00574720)) {
                goto sleep_it;
            }
        }
        if (state != 6) {
            return;
        }
    sleep_it:
        set_sleep_flag(1);
    }
}
