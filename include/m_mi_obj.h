#ifndef AOE1_M_MI_OBJ_H
#define AOE1_M_MI_OBJ_H

#include "m_co_obj.h"
#include <stddef.h>
#include <stdio.h>

class RGE_Missile_Object;
class RGE_Player;
class RGE_Sound;
class RGE_Sprite;
class RGE_Static_Object;

// m_mi_obj.cpp owns the missile-master extension. The inherited fields and
// virtual slots come from the canonical RGE_Master_Combat_Object owner.
class RGE_Master_Missile_Object : public RGE_Master_Combat_Object {
public:
    RGE_Master_Missile_Object(RGE_Master_Missile_Object*, int);
    RGE_Master_Missile_Object(int, RGE_Sprite**, RGE_Sound**, int);
    RGE_Master_Missile_Object(FILE*, RGE_Sprite**, RGE_Sound**, short, int);

    virtual ~RGE_Master_Missile_Object();
    virtual RGE_Static_Object* make_new_obj(RGE_Player*, float, float, float);
    virtual RGE_Master_Static_Object* make_new_master();
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void modify(float, unsigned char);
    virtual void modify_delta(float, unsigned char);
    virtual void modify_percent(float, unsigned char);
    virtual void save(int);

protected:
    int setup(RGE_Master_Missile_Object*);
    int setup(int, RGE_Sprite**, RGE_Sound**);
    int setup(FILE*, RGE_Sprite**, RGE_Sound**, short);

public:
    unsigned char missile_type;
    unsigned char targetting_type;
    unsigned char missile_hit_info;
    unsigned char missile_die_info;
    unsigned char area_effect_specials;
    float ballistics_ratio;
};

typedef char m_mi_obj_master_missile_size_check[
    (sizeof(RGE_Master_Missile_Object) == 0x154) ? 1 : -1];
typedef char m_mi_obj_missile_type_offset_check[
    (offsetof(RGE_Master_Missile_Object, missile_type) == 0x148) ? 1 : -1];

#endif  // AOE1_M_MI_OBJ_H
