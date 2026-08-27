#ifndef AOE1_T_C_OBJ_H
#define AOE1_T_C_OBJ_H

#include "com_obj.h"
#include <stddef.h>

class RGE_Action_List;
class RGE_Game_World;
class RGE_Map;
class RGE_Master_Static_Object;
class RGE_Player;
class RGE_Static_Object;
class RGE_Task;
class TRIBE_Master_Building_Object;
class TRIBE_Master_Combat_Object;
class TRIBE_Action_List;

struct RGE_Armor_Weapon_Info;

// t_c_obj.cpp owns the tribal combat-object extension.  All inherited state
// comes from the canonical RGE_Combat_Object owner.
class TRIBE_Combat_Object : public RGE_Combat_Object {
public:
    TRIBE_Combat_Object(TRIBE_Master_Combat_Object*, RGE_Player*, float,
                        float, float, int);
    TRIBE_Combat_Object(int, RGE_Game_World*, int);
    virtual ~TRIBE_Combat_Object();

protected:
    virtual int setup(TRIBE_Master_Combat_Object*, RGE_Player*, float, float,
                      float);
    virtual int setup(int, RGE_Game_World*);

public:
    virtual RGE_Action_List* create_action_list();
    virtual void save(int);
    virtual unsigned char update();
    virtual void modify(float, unsigned char);
    virtual void transform(RGE_Master_Static_Object*);
    virtual void set_object_state(unsigned char);
    virtual void die_die_die();
    virtual void damage(int, RGE_Armor_Weapon_Info*, float, RGE_Player*,
                        RGE_Static_Object*);

protected:
    virtual void change_ownership(RGE_Player*);

public:
    virtual unsigned char attack(RGE_Static_Object*, RGE_Combat_Object*);
    virtual unsigned char do_attack(RGE_Static_Object*, RGE_Combat_Object*,
                                    float, float, float);
    virtual float calc_attack_modifier(RGE_Static_Object*);
    virtual void get_armor(short&, short&);
    virtual void get_pierce_armor(short&, short&);
    void reposition_artifact();
    int can_debark();
    virtual int hunt(int, int);
    virtual int convert(int, int);
    virtual int heal(int, int);
    virtual int repair(int, int);
    virtual int build(int, int);
    virtual int trade(int, int);
    virtual RGE_Task* make_action(RGE_Static_Object*, float, float, float);

protected:
    virtual void initUnitAI();

public:
    virtual unsigned char produceWhenKilledBy(int) const;
    virtual void cancel_object();
    virtual unsigned char keepGatheringWhenObjectIsOut(int) const;
    virtual unsigned char useSameZoneDropsite() const;

protected:
    virtual unsigned char heal(float);

public:
    virtual int higher_check_for_cliff(RGE_Static_Object*, int, int, float,
                                       float, float, float, RGE_Map*,
                                       RGE_Static_Object*, float&, int&);
    virtual int higher_than_target(RGE_Static_Object*);

protected:
    virtual unsigned char area_attack(float, float, float, RGE_Combat_Object*,
                                      RGE_Static_Object*);
    virtual int canRepair();

public:
    void do_repair(RGE_Static_Object*);

    unsigned char own_master;
};

typedef char tribe_combat_object_own_master_offset_check[
    (offsetof(TRIBE_Combat_Object, own_master) == 0x1C4) ? 1 : -1];
typedef char tribe_combat_object_size_check[
    (sizeof(TRIBE_Combat_Object) == 0x1C8) ? 1 : -1];

#endif  // AOE1_T_C_OBJ_H
