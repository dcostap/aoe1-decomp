#ifndef AOE1_ANI_OBJ_H
#define AOE1_ANI_OBJ_H

#include "stat_obj.h"
#include "m_an_obj.h"

class RGE_Animated_Object : public RGE_Static_Object {
public:
    RGE_Animated_Object(RGE_Master_Animated_Object*, RGE_Player*, float,
                        float, float, int);
    RGE_Animated_Object(int, RGE_Game_World*, int);

    virtual ~RGE_Animated_Object();
    virtual float getSpeed() const { return this->speed; }

protected:
    virtual int setup(RGE_Master_Animated_Object*, RGE_Player*, float, float,
                      float);
    virtual int setup(int, RGE_Game_World*);

public:
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*,
                                    float, float, float);
    virtual unsigned char update();
    virtual void save(int);
    virtual void transform(RGE_Master_Static_Object*);
    virtual void set_being_worked_on(RGE_Action_Object*, short,
                                     unsigned char);
    virtual void release_being_worked_on(RGE_Static_Object*);

    float speed;
};

typedef char rge_animated_object_size_check[
    (sizeof(RGE_Animated_Object) == 0x8C) ? 1 : -1];

#endif
