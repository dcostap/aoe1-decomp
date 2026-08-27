#ifndef AOE1_M_MO_OBJ_H
#define AOE1_M_MO_OBJ_H

#include "m_an_obj.h"

class RGE_Master_Moving_Object : public RGE_Master_Animated_Object {
public:
    virtual ~RGE_Master_Moving_Object();
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void modify(float, unsigned char);
    virtual void modify_delta(float, unsigned char);
    virtual void modify_percent(float, unsigned char);
    virtual void save(int);
    virtual RGE_Static_Object* make_new_obj(RGE_Player*, float, float, float);
    virtual RGE_Master_Static_Object* make_new_master();

    RGE_Master_Moving_Object(RGE_Master_Moving_Object*, int);
    RGE_Master_Moving_Object(int, RGE_Sprite**, RGE_Sound**, int);
    RGE_Master_Moving_Object(FILE*, RGE_Sprite**, RGE_Sound**, short, int);

protected:
    int setup(RGE_Master_Moving_Object*);
    int setup(int, RGE_Sprite**, RGE_Sound**);
    int setup(FILE*, RGE_Sprite**, RGE_Sound**, short);

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
