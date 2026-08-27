#ifndef AOE1_ACT_MISL_H
#define AOE1_ACT_MISL_H

#include "action.h"

class RGE_Action_Missile : public RGE_Action {
public:
    RGE_Action_Missile(int, RGE_Action_Object*);
    RGE_Action_Missile(RGE_Action_Object*, RGE_Static_Object*,
                       RGE_Static_Object*, float, float, float);

    virtual void first_in_stack(unsigned char);
    virtual unsigned char update();
    virtual void save(int);

protected:
    virtual void set_state(unsigned char);
    void intercept(float&, float&, float&);

public:
    float velocity_x;
    float velocity_y;
    float velocity_z;
    float ballistic_velocity;
    float ballistic_acceleration;
};

typedef char rge_action_missile_size_check[
    (sizeof(RGE_Action_Missile) == 0x54) ? 1 : -1];

#endif  // AOE1_ACT_MISL_H
