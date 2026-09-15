#ifndef AOE1_COM_OBJ_H
#define AOE1_COM_OBJ_H

#include "act_obj.h"
#include <stddef.h>

typedef unsigned char uchar;

class RGE_Combat_Object;
class RGE_Game_World;
class RGE_Master_Combat_Object;
class RGE_Master_Static_Object;
class RGE_Player;
class RGE_Sound;
class RGE_Static_Object;
class RGE_Sprite;
struct RGE_Armor_Weapon_Info;
struct VISIBLE_UNIT_REC;

// The combat object owns the combat additions to RGE_Action_Object.
class RGE_Combat_Object : public RGE_Action_Object {
public:
    RGE_Combat_Object(RGE_Master_Combat_Object* tobj, RGE_Player* obj_owner, float x, float y, float z, int do_setup);
    RGE_Combat_Object(int infile, RGE_Game_World* gworld, int do_setup);
    virtual ~RGE_Combat_Object();

    virtual void recycle_in_to_game(RGE_Master_Static_Object* tobj, RGE_Player* obj_owner, float x, float y, float z);
    virtual void save(int outfile);
    virtual void stop();
    virtual uchar area_attack(float x, float y, float z, RGE_Combat_Object* attacker, RGE_Static_Object* ignore_object);
    // VC5 reverses this adjacent overload pair in the emitted vtable.
    virtual uchar attack(RGE_Static_Object* target, RGE_Combat_Object* attacker);
    virtual uchar attack(float target_x, float target_y, float target_z, RGE_Combat_Object* attacker);
    virtual uchar do_attack(RGE_Static_Object* target, RGE_Combat_Object* attacker, float x, float y, float z);
    virtual void damage(int weapon_num, RGE_Armor_Weapon_Info* damage,
                        float attack_modifier, RGE_Player* attacking_player,
                        RGE_Static_Object* attackingObject);
    virtual uchar can_attack();
    virtual void get_armor(short& cur_armor_in, short& orig_armor_in);
    virtual void get_weapon(short& cur_weapon_in, short& orig_weapon_in);
    virtual void get_weapon_range(float& cur_weapon_range_in, float& orig_weapon_range_in);
    virtual void get_speed_of_attack(float& cur_speed_of_attack_in, float& orig_speed_of_attack_in);
    virtual void release_being_worked_on(RGE_Static_Object* caller);
    virtual void enter_obj(RGE_Static_Object* target);
    virtual uchar update();
    virtual void copy_obj(RGE_Master_Static_Object* source2);
    virtual void notify(int caller, int recipient, int mType, long p1, long p2, long p3);
    virtual int attack(int targetID, int unconditional);
    virtual int attack(float x, float y, float z, int unconditional);
    virtual int moveTo(int targetID, float minRange, int unconditional);
    virtual int moveTo(float x, float y, float z, float minRange, int unconditional);
    virtual int moveTo(int targetID, int unconditional);
    virtual int moveAwayFrom(int targetID, int unconditional);
    virtual int gather(int targetID, int unconditional);
    virtual int explore(int tX, int tY, int unconditional);
    virtual int enter(int targetID, int unconditional);
    virtual int transport(float tX, float tY, float tZ, int unconditional);
    virtual int unload(int unconditional, float x, float y, float z);
    virtual int stopAction();
    virtual int pause();
    virtual float damageCapability();
    virtual float damageCapability(RGE_Static_Object* attackingUnit);
    virtual float rateOfFire();
    virtual int inAttackRange(RGE_Static_Object* target);
    virtual int currentTargetID() const;
    virtual float currentTargetX() const;
    virtual float currentTargetY() const;
    virtual float currentTargetZ() const;
    virtual float weaponRange();
    virtual float minimumWeaponRange();
    virtual float teleport(float x, float y, float z);
    virtual float calc_attack_modifier(RGE_Static_Object* target);

    void reset_attack_timer();
    void get_weapon_range(short&, short&);
    void calc_attack_modifier();
    void set_something(int);
    void play_move_sound(RGE_Sound*);
    virtual float calculateDamage(int weapon_num,
                                  RGE_Armor_Weapon_Info* damage,
                                  float attack_modifier,
                                  RGE_Player* attacking_player,
                                  RGE_Static_Object* attackingObject);

protected:
    virtual int setup(int infile, RGE_Game_World* gworld);
    virtual int setup(RGE_Master_Combat_Object* tobj, RGE_Player* obj_owner, float x, float y, float z);
    float base_teleport(float, float, float);
    uchar attack(RGE_Static_Object*, float, RGE_Combat_Object*, float, float);

public:
    // The base class ends at +0x194. These fields end the 0x1C4 object.
    VISIBLE_UNIT_REC* VUR_Ptrs[9];
    unsigned long Unified_Map_Value;
    float attack_timer;
    uchar capture_flag;
};

typedef char rge_combat_object_vur_offset_check[
    (offsetof(RGE_Combat_Object, VUR_Ptrs) == 0x194) ? 1 : -1];
typedef char rge_combat_object_size_check[
    (sizeof(RGE_Combat_Object) == 0x1C4) ? 1 : -1];

#endif  // AOE1_COM_OBJ_H
