// RGE_Action_Missile::RGE_Action_Missile (00404C90, ACT_misl.cpp)
// EH-framed constructor; /GX response file required.

#ifndef ACT_MISL_SHARED_CONTEXT
class RGE_Action_Object {};
class RGE_Static_Object {};

class RGE_Action {
public:
    virtual ~RGE_Action();
    RGE_Action(RGE_Action_Object* obj, int type);
    void set_target_obj(RGE_Static_Object* target);
    void set_target_obj2(RGE_Static_Object* target2);
};

class RGE_Action_Missile : public RGE_Action {
public:
    short action_type;
    char gap_06[0x1A];
    float velocity_x;
    float velocity_y;
    float velocity_z;

    RGE_Action_Missile(RGE_Action_Object* obj, RGE_Static_Object* target, RGE_Static_Object* target2,
                       float vx, float vy, float vz);
};
#endif

RGE_Action_Missile::RGE_Action_Missile(RGE_Action_Object* obj, RGE_Static_Object* target, RGE_Static_Object* target2,
                                       float vx, float vy, float vz) : RGE_Action(obj, 1) {
#ifdef ACT_MISL_SHARED_CONTEXT
    this->target_x = vx;
#else
    velocity_x = vx;
#endif
    action_type = 8;
#ifdef ACT_MISL_SHARED_CONTEXT
    this->target_y = vy;
    this->target_z = vz;
#else
    velocity_y = vy;
    velocity_z = vz;
#endif
    set_target_obj(target2);
    set_target_obj2(target);
}
