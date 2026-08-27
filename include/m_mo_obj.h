#ifndef AOE1_M_MO_OBJ_H
#define AOE1_M_MO_OBJ_H

#include "m_s_obj_context.h"

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Animated_Object();
    virtual void copy_obj(RGE_Master_Static_Object*);
    virtual void modify(float, unsigned char);
    virtual void modify_delta(float, unsigned char);
    virtual void modify_percent(float, unsigned char);
    virtual void save(int);
    virtual RGE_Static_Object* make_new_obj(RGE_Player*, float, float, float);
    virtual RGE_Master_Static_Object* make_new_master();

    RGE_Master_Animated_Object(RGE_Master_Animated_Object*, int);
    RGE_Master_Animated_Object(int, RGE_Sprite**, RGE_Sound**, int);
    RGE_Master_Animated_Object(FILE*, RGE_Sprite**, RGE_Sound**, short, int);

protected:
    int setup(RGE_Master_Animated_Object*);
    int setup(int, RGE_Sprite**, RGE_Sound**);
    int setup(FILE*, RGE_Sprite**, RGE_Sound**, short);

public:
    float speed;
};

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
    char pad_0CD[3];
    float obj_trail_spacing;
    unsigned char move_algorithem;
};

class RGE_Moving_Object : public RGE_Static_Object {
public:
    char gap_88[0xF8];

    RGE_Moving_Object(RGE_Master_Moving_Object*, RGE_Player*,
                      float, float, float, int);
};

typedef char rge_master_moving_object_size_check[
    (sizeof(RGE_Master_Moving_Object) == 0xD8) ? 1 : -1];
typedef char rge_moving_object_size_check[
    (sizeof(RGE_Moving_Object) == 0x180) ? 1 : -1];

#endif
