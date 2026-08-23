#ifndef RGE_MO_OBJ_CONTEXT_H
#define RGE_MO_OBJ_CONTEXT_H

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
    RGE_Master_Animated_Object(void*, void**, void**, int, int);

    int setup(RGE_Master_Animated_Object*);
    int setup(RGE_Master_Static_Object*);
    int setup(int, RGE_Sprite**, RGE_Sound**);
    int setup(int, RGE_Sprite**, RGE_Sound**, short);
    int setup(FILE*, RGE_Sprite**, RGE_Sound**, short);
    int setup(void*, void**, void**, int, int);

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
    RGE_Master_Moving_Object(void*, void**, void**, int, int);

protected:
    int setup(RGE_Master_Moving_Object*);
    int setup(void*, void**, void**, int);
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

#endif
