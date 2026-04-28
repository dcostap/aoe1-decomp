// 004C5B90 RGE_Static_Object::damage
// PDB: stat_obj.cpp:3099-3109, 74 bytes
// FLAGS: default
//
// Fixed: removed redundant `void* vtable_ptr` member (pushed hp from +0x30 to
// +0x34) and changed `1.0f` to `1.0` (original uses fcomp qword with double).
struct RGE_Armor_Weapon_Info {
    char gap_00[2];
    short value;
};

class RGE_Player;

class RGE_Static_Object {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual float calculateDamage(int count, RGE_Armor_Weapon_Info* info, float scale, RGE_Player* player, RGE_Static_Object* object);

    long id;
    void* master_obj;
    RGE_Player* owner;
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

    void damage(int count, RGE_Armor_Weapon_Info* info, float scale, RGE_Player* player, RGE_Static_Object* object);
    void set_sleep_flag(unsigned char value);
};

void RGE_Static_Object::damage(int count, RGE_Armor_Weapon_Info* info, float scale, RGE_Player* player, RGE_Static_Object* object) {
    float damage_amount;

    damage_amount = this->calculateDamage(count, info, scale, player, object);
    this->hp = this->hp - damage_amount;
    if (this->hp < 1.0) {
        this->hp = 0.0f;
        this->set_sleep_flag(0);
    }
}
