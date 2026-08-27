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
    RGE_Combat_Object(RGE_Master_Combat_Object*, RGE_Player*, float, float,
                      float, int);
    RGE_Combat_Object(int, RGE_Game_World*, int);
    virtual ~RGE_Combat_Object();

protected:
    virtual int setup(int, RGE_Game_World*);

public:
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*,
                                    float, float, float);
    virtual void save(int);
    virtual void stop();
    virtual uchar area_attack(float, float, float, RGE_Combat_Object*,
                              RGE_Static_Object*);
    virtual uchar attack(float, float, float, RGE_Combat_Object*);
    virtual uchar attack(RGE_Static_Object*, RGE_Combat_Object*);
    virtual uchar do_attack(RGE_Static_Object*, RGE_Combat_Object*, float,
                            float, float);
    virtual void damage(int, RGE_Armor_Weapon_Info*, float, RGE_Player*,
                        RGE_Static_Object*);
    virtual uchar can_attack();
    virtual void get_armor(short&, short&);
    virtual void get_weapon(short&, short&);
    virtual void get_weapon_range(float&, float&);
    virtual void get_speed_of_attack(float&, float&);
    virtual void release_being_worked_on(RGE_Static_Object*);
    virtual void enter_obj(RGE_Static_Object*);
    virtual uchar update();
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void notify(int, int, int, long, long, long);
    virtual int attack(int, int);
    virtual int attack(float, float, float, int);
    virtual int moveTo(int, float, int);
    virtual int moveTo(float, float, float, float, int);
    virtual int moveTo(int, int);
    virtual int moveAwayFrom(int, int);
    virtual int gather(int, int);
    virtual int explore(int, int, int);
    virtual int enter(int, int);
    virtual int transport(float, float, float, int);
    virtual int unload(int, float, float, float);
    virtual int stopAction();
    virtual int pause();
    virtual float damageCapability();
    virtual float damageCapability(RGE_Static_Object*);
    virtual float rateOfFire();
    virtual int inAttackRange(RGE_Static_Object*);
    virtual int currentTargetID() const;
    virtual float currentTargetX() const;
    virtual float currentTargetY() const;
    virtual float currentTargetZ() const;
    virtual float weaponRange();
    virtual float minimumWeaponRange();
    virtual float teleport(float, float, float);
    virtual float calc_attack_modifier(RGE_Static_Object*);

    void reset_attack_timer();
    void get_weapon_range(short&, short&);
    void calc_attack_modifier();
    virtual void change_ownership(RGE_Player*);
    void set_something(int);
    virtual void new_sprite(RGE_Sprite*);
    virtual void play_move_sound(RGE_Sound*);
    float distance_to_object(RGE_Static_Object*);
    virtual float calculateDamage(int, RGE_Armor_Weapon_Info*, float,
                                  RGE_Player*, RGE_Static_Object*);

protected:
    virtual int setup(RGE_Master_Combat_Object*, RGE_Player*, float, float,
                      float);
    float base_teleport(float, float, float);
    uchar attack(RGE_Static_Object*, float, RGE_Combat_Object*, float, float);

public:
    // The base class ends at +0x194. These fields end the 0x1C4 object.
    VISIBLE_UNIT_REC* VUR_Ptrs[9];
    unsigned long Unified_Map_Value;
    float attack_timer;
    uchar capture_flag;
    uchar _pad_end[3];
};

typedef char rge_combat_object_vur_offset_check[
    (offsetof(RGE_Combat_Object, VUR_Ptrs) == 0x194) ? 1 : -1];
typedef char rge_combat_object_size_check[
    (sizeof(RGE_Combat_Object) == 0x1C4) ? 1 : -1];

#endif  // AOE1_COM_OBJ_H
