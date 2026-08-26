// 005121A0 TRIBE_Player::make_scenario_obj
// tplayer.cpp lines 356-380
// Fresh 2026-05-19: replace stub with packet-derived virtual factory logic.

#ifndef AOE1_TPLAYER_TU_SHARED_CONTEXT
class RGE_Static_Object_Type;
class RGE_Static_Object;
class TRIBE_Building_Object;

class RGE_Player {
public:
    virtual void update();
    char gap_00[0x20];
    RGE_Static_Object_Type** object_types; // +0x24
};

class RGE_Static_Object_Type {
public:
    virtual void load();
    virtual void save();
    virtual void setup();
    virtual void clear();
    virtual void reset();
    virtual void initialize();
    virtual RGE_Static_Object* make_scenario_obj(RGE_Player* player, float x, float y, float z); // +0x18
    unsigned char object_group; // +0x04 (data layout for type records)
};

class RGE_Static_Object {
public:
    virtual void destroy();
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
    virtual void save(int);
    virtual void teleport();
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
    virtual void destroy_obj(); // +0x68
    virtual void die_die_die(); // +0x6C
    virtual void damage();
    virtual void calculateDamage();
    virtual void rotate();
    virtual void can_attack();
    virtual void set_attribute();
    virtual void set_attribute_amount();
    virtual void heal();
    virtual void canRepair();
    virtual void notify_of_relation();
    virtual void do_command();
    virtual void move_to();
    virtual void work();
    virtual void stop();
    virtual void set_attack();
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void minimumWeaponRange();
    virtual void new_angle(float f); // +0xB4
    char gap_04[4];
    RGE_Static_Object_Type* type; // +0x08
    char gap_0C[0x35 - 0x0C];
    unsigned char field_35;
};

class TRIBE_Building_Object : public RGE_Static_Object {
public:
    unsigned char build(float amount);
};

class TRIBE_Player : public RGE_Player {
public:
    virtual RGE_Static_Object* make_scenario_obj(float x, float y, float z, short type_id, unsigned char mode, float amount);
};
#endif

extern "C" long __cdecl _ftol();

RGE_Static_Object* TRIBE_Player::make_scenario_obj(float x, float y, float z, short type_id, unsigned char mode, float amount)
{
    RGE_Static_Object* obj = 0;
    RGE_Static_Object_Type* type = this->object_types[type_id];
    if (type) {
        obj = type->make_scenario_obj(this, x, y, z);
        if (mode >= 7) {
            obj->destroy_obj();
        }
        else if (mode > 2) {
            obj->die_die_die();
        }
        else {
            unsigned char group = (unsigned char)obj->master_obj->object_group;
            if (group > 0x1E && group < 0x5A) {
                obj->new_angle(amount);
            }
            else {
                obj->facet = (unsigned char)(int)amount;
            }
        }
        if (this->object_types[type_id]->object_group == 0x50 && mode == 2) {
            ((TRIBE_Building_Object*)obj)->build(10000.0f);
        }
    }
    return obj;
}
