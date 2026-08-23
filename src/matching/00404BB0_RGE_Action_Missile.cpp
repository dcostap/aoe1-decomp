#ifndef ACT_MISL_SHARED_CONTEXT
class RGE_Action_Object {
};

class RGE_Action {
public:
    RGE_Action(int file, RGE_Action_Object* object, int flag);
    virtual ~RGE_Action();
};

class RGE_Action_Missile : public RGE_Action {
public:
    short typeAt4;
    char gap6[0x3A];
    int velocity_x;
    int velocity_y;
    int velocity_z;
    int ballistic_velocity;
    int ballistic_acceleration;

    RGE_Action_Missile(int file, RGE_Action_Object* object);
};

extern void __cdecl rge_read(int file, void* buffer, int size);
#endif

RGE_Action_Missile::RGE_Action_Missile(int file, RGE_Action_Object* object)
    : RGE_Action(file, object, 1)
{
#ifdef ACT_MISL_SHARED_CONTEXT
    this->action_type = 8;
#else
    typeAt4 = 8;
#endif
    rge_read(file, &velocity_x, 4);
    rge_read(file, &velocity_y, 4);
    rge_read(file, &velocity_z, 4);
    rge_read(file, &ballistic_velocity, 4);
    rge_read(file, &ballistic_acceleration, 4);
}
