// RGE_Action_Missile::RGE_Action_Missile (00404C90, 126 bytes, ACT_misl.cpp)
// Attempt 1

class RGE_Action_Object {};
class RGE_Static_Object {};

class RGE_Action {
public:
    RGE_Action();
    RGE_Action(RGE_Action_Object* obj, int type);
    void set_target_obj(RGE_Static_Object* target);
    void set_target_obj2(RGE_Static_Object* target2);
};

class RGE_Action_Missile : public RGE_Action {
public:
    char gap_00[0x20];
    float velocity_x;
    float velocity_y;
    float velocity_z;

    RGE_Action_Missile(RGE_Action_Object* obj, RGE_Static_Object* target, RGE_Static_Object* target2,
                       float vx, float vy, float vz);
};

RGE_Action_Missile::RGE_Action_Missile(RGE_Action_Object* obj, RGE_Static_Object* target, RGE_Static_Object* target2,
                                       float vx, float vy, float vz) {
    RGE_Action::RGE_Action(obj, 1);
    this->velocity_x = vx;
    this->velocity_y = vy;
    this->velocity_z = vz;
    ((void**)this)[0] = (void*)0x56E320;
    ((unsigned short*)this)[2] = 8;
    RGE_Action::set_target_obj(target);
    RGE_Action::set_target_obj2(target2);
}
