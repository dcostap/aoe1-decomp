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
    TRIBE_Combat_Object(TRIBE_Master_Combat_Object* tobj, RGE_Player* obj_owner, float x,
                        float y, float z, int do_setup);
    TRIBE_Combat_Object(int infile, RGE_Game_World* gworld, int do_setup);
    virtual ~TRIBE_Combat_Object();

    virtual RGE_Action_List* create_action_list();
    virtual void save(int outfile);
    virtual unsigned char update();
    virtual void modify(float amount, unsigned char flag);
    virtual void transform(RGE_Master_Static_Object* obj);
    virtual void set_object_state(unsigned char new_object_state);
    virtual void cancel_object();
    virtual void die_die_die();
    virtual void damage(int weapon_num, RGE_Armor_Weapon_Info* damage, float attack_modifier,
                        RGE_Player* attacking_player, RGE_Static_Object* attackingObject);
    virtual float calc_attack_modifier(RGE_Static_Object* target);
    virtual unsigned char attack(RGE_Static_Object* target, RGE_Combat_Object* attacker);
    virtual unsigned char do_attack(RGE_Static_Object* target, RGE_Combat_Object* attacker,
                                    float x, float y, float z);
    virtual void get_armor(short& cur_armor_in, short& orig_armor_in);
    virtual void get_pierce_armor(short& cur_armor_in, short& orig_armor_in);
    void reposition_artifact();
    void do_repair(RGE_Static_Object* obj);
    int can_debark();
    virtual int higher_check_for_cliff(RGE_Static_Object* target, int XTileInt, int YTileInt,
                                       float StartX, float StartY, float DestX, float DestY,
                                       RGE_Map* Map, RGE_Static_Object* LastCliffObject,
                                       float& AngleToTarget, int& HigherCalc);
    virtual int higher_than_target(RGE_Static_Object* target);
    virtual int hunt(int targetID, int unconditional);
    virtual int convert(int targetID, int unconditional);
    virtual int heal(int targetID, int unconditional);
protected:
    virtual unsigned char heal(float healing);
public:
    virtual int repair(int targetID, int unconditional);
    virtual int build(int targetID, int unconditional);
    virtual int trade(int targetID, int unconditional);
    virtual unsigned char keepGatheringWhenObjectIsOut(int oType) const;
    virtual unsigned char produceWhenKilledBy(int oGroup) const;
    virtual unsigned char useSameZoneDropsite() const;

protected:
    virtual void initUnitAI();
    virtual int setup(TRIBE_Master_Combat_Object* tobj, RGE_Player* obj_owner, float x,
                      float y, float z);
    virtual int setup(int infile, RGE_Game_World* gworld);
    virtual void change_ownership(RGE_Player* new_owner);
    virtual unsigned char area_attack(float x, float y, float z, RGE_Combat_Object* attacker,
                                      RGE_Static_Object* ignore_object);
    virtual int canRepair();

public:
    unsigned char own_master;
};

typedef char tribe_combat_object_own_master_offset_check[
    (offsetof(TRIBE_Combat_Object, own_master) == 0x1C4) ? 1 : -1];
typedef char tribe_combat_object_size_check[
    (sizeof(TRIBE_Combat_Object) == 0x1C8) ? 1 : -1];

#endif  // AOE1_T_C_OBJ_H
