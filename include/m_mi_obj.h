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
    RGE_Master_Missile_Object(RGE_Master_Missile_Object* other_object, int do_setup);
    RGE_Master_Missile_Object(int infile, RGE_Sprite** sprites, RGE_Sound** sounds, int do_setup);
    RGE_Master_Missile_Object(FILE* infile, RGE_Sprite** sprites, RGE_Sound** sounds, short in_id, int do_setup);

    virtual ~RGE_Master_Missile_Object();
    virtual RGE_Static_Object* make_new_obj(RGE_Player* owner, float x, float y, float z);
    virtual RGE_Master_Static_Object* make_new_master();
    virtual void copy_obj(RGE_Master_Static_Object* source);
    virtual void modify(float amount, unsigned char flag);
    virtual void modify_delta(float amount, unsigned char flag);
    virtual void modify_percent(float amount, unsigned char flag);
    virtual void save(int outfile);

  protected:
    int setup(RGE_Master_Missile_Object* other_object);
    int setup(int infile, RGE_Sprite** sprites, RGE_Sound** sounds);
    int setup(FILE* infile, RGE_Sprite** sprites, RGE_Sound** sounds, short in_id);

  public:
    unsigned char missile_type;
    unsigned char targetting_type;
    unsigned char missile_hit_info;
    unsigned char missile_die_info;
    unsigned char area_effect_specials;
    float ballistics_ratio;
};

typedef char m_mi_obj_master_missile_size_check[(sizeof(RGE_Master_Missile_Object) == 0x154) ? 1 : -1];
typedef char m_mi_obj_missile_type_offset_check[(offsetof(RGE_Master_Missile_Object, missile_type) == 0x148) ? 1 : -1];

#endif // AOE1_M_MI_OBJ_H
