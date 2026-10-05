#ifndef AOE1_ACT_MISL_H
#define AOE1_ACT_MISL_H

#include "action.h"

class RGE_Action_Missile : public RGE_Action {
  public:
    RGE_Action_Missile(int infile, RGE_Action_Object* obj_in);
    RGE_Action_Missile(
        RGE_Action_Object* obj_in, RGE_Static_Object* launcher, RGE_Static_Object* target, float x, float y, float z
    );

    virtual void first_in_stack(unsigned char first_time);
    virtual unsigned char update();
    virtual void save(int outfile);

  protected:
    virtual void set_state(unsigned char new_state);
    void intercept(float& tx, float& ty, float& tz);

  public:
    float velocity_x;
    float velocity_y;
    float velocity_z;
    float ballistic_velocity;
    float ballistic_acceleration;
};

typedef char rge_action_missile_size_check[(sizeof(RGE_Action_Missile) == 0x54) ? 1 : -1];

#endif // AOE1_ACT_MISL_H
