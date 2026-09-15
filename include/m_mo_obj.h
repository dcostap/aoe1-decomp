#ifndef AOE1_M_MO_OBJ_H
#define AOE1_M_MO_OBJ_H

#include "m_an_obj.h"

class RGE_Master_Moving_Object : public RGE_Master_Animated_Object {
public:
    virtual ~RGE_Master_Moving_Object();
    virtual void copy_obj(RGE_Master_Static_Object* source);
    virtual void modify(float amount, unsigned char flag);
    virtual void modify_delta(float amount, unsigned char flag);
    virtual void modify_percent(float amount, unsigned char flag);
    virtual void save(int outfile);
    virtual RGE_Static_Object* make_new_obj(RGE_Player* owner, float x, float y, float z);
    virtual RGE_Master_Static_Object* make_new_master();

    RGE_Master_Moving_Object(RGE_Master_Moving_Object* other_object, int do_setup);
    RGE_Master_Moving_Object(int infile, RGE_Sprite** sprites, RGE_Sound** sounds, int do_setup);
    RGE_Master_Moving_Object(FILE* infile, RGE_Sprite** sprites, RGE_Sound** sounds, short in_id, int do_setup);

protected:
    int setup(RGE_Master_Moving_Object* other_object);
    int setup(int infile, RGE_Sprite** sprites, RGE_Sound** sounds);
    int setup(FILE* infile, RGE_Sprite** sprites, RGE_Sound** sounds, short in_id);

public:
    RGE_Sprite* move_sprite;
    RGE_Sprite* run_sprite;
    float turn_speed;
    unsigned char size_class;
    short obj_trail_id;
    unsigned char obj_trail_options;
    float obj_trail_spacing;
    unsigned char move_algorithem;
};

typedef char rge_master_moving_object_size_check[
    (sizeof(RGE_Master_Moving_Object) == 0xD8) ? 1 : -1];

#endif
