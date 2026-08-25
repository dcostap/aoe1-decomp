// player.cpp:734-749, 102 bytes
// attempt 1: 61.8%, vtable offsets wrong (createObj at +0 vs +0x18, vfs at +0/+4/+8 vs +0x68/+0x6C/+0xB4)
// attempt 2: pad vtables to match original slot offsets
#ifdef PLAYER_GROUPED_TU
#include "../player_tu_context.h"
#endif

#ifndef PLAYER_GROUPED_TU
class RGE_Static_Object {
public:
    virtual void recycle_in_to_game();
    virtual void recycle_out_of_game();
    virtual void draw();
    virtual void shadow_draw();
    virtual void normal_draw();
    virtual void draw_front_frame();
    virtual void draw_back_frame();
    virtual void draw_frame();
    virtual void update();
    virtual void check_damage_sprites();
    virtual void rehook();
    virtual void save();
    virtual float teleport();
    virtual void new_sprite();
    virtual void add_overlay_sprite();
    virtual void remove_overlay_sprite();
    virtual void change_ownership();
    virtual void modify();
    virtual void modify_delta();
    virtual void modify_percent();
    virtual void transform();
    virtual void copy_obj();
    virtual void set_object_state();
    virtual void remove_visible_resource();
    virtual void create_doppleganger_when_dying();
    virtual void destroy_obj();
    virtual void die_die_die();
    virtual void damage();
    virtual void calculateDamage();
    virtual void rotate();
    virtual void can_attack();
    virtual void set_attribute();
    virtual void set_attribute_amount();
    virtual void heal();
    virtual void heal_float();
    virtual void canRepair();
    virtual void notify_of_relation();
    virtual void do_command();
    virtual void move_to();
    virtual void work();
    virtual void stop();
    virtual void set_attack();
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void new_angle(float);
};

class RGE_Master_Static_Object {
public:
    virtual void destroy();
    virtual void copy_obj();
    virtual void modify();
    virtual void modify_delta();
    virtual void modify_percent();
    virtual void save();
    virtual void* make_new_obj(void*, float, float, float);
};

class RGE_Player {
public:
    char gap_00[0x24];
    RGE_Master_Static_Object** master_objects; // +0x24

    RGE_Static_Object* make_scenario_obj(float x, float y, float z, short typeID, unsigned char objType, float param6);
};
#endif

RGE_Static_Object* RGE_Player::make_scenario_obj(float x, float y, float z, short typeID, unsigned char objType, float param6) {
    RGE_Static_Object* obj = 0;
    RGE_Master_Static_Object* master = this->master_objects[typeID];
    if (master != 0) {
        obj = (RGE_Static_Object*)master->make_new_obj(this, x, y, z);
        if (objType >= 7) {
            obj->destroy_obj();
        } else if (objType > 2) {
            obj->die_die_die();
        } else {
            obj->new_angle(param6);
        }
    }
    return obj;
}
