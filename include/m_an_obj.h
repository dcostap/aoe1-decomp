#ifndef AOE1_M_AN_OBJ_H
#define AOE1_M_AN_OBJ_H

#include "m_s_obj.h"

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
    RGE_Master_Animated_Object(_iobuf*, RGE_Sprite**, RGE_Sound**, short, int);

protected:
    int setup(RGE_Master_Animated_Object*);
    int setup(int, RGE_Sprite**, RGE_Sound**);
    int setup(_iobuf*, RGE_Sprite**, RGE_Sound**, short);

    float speed;
};

typedef char m_an_obj_animated_size[
    (sizeof(RGE_Master_Animated_Object) == 0xBC) ? 1 : -1];

#endif
