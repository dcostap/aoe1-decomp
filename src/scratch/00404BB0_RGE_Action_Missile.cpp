// VA: 00404BB0 RGE_Action_Missile ctor (163B)
// ACT_misl.cpp lines 30-38
// Has EH frame, needs /GX

class RGE_Action {
public:
    virtual ~RGE_Action();
};

class RGE_Action_Object {
};

class RGE_Action_Missile : public RGE_Action {
public:
    short typeAt4;              // +04 (always 8)
    char gap6[0x3A];
    int velocity_x;             // +40
    int velocity_y;             // +44
    int velocity_z;             // +48
    int ballistic_velocity;     // +4C
    int ballistic_acceleration; // +50
    
    RGE_Action_Missile(int a1, RGE_Action_Object* obj);
};

extern void __cdecl rge_read(int fd, void* buf, int size);
void __cdecl RGE_Action_ctor(void* this_, int a1, void* obj, int flag);

RGE_Action_Missile::RGE_Action_Missile(int a1, RGE_Action_Object* obj) {
    RGE_Action_ctor(this, a1, obj, 1);
    
    typeAt4 = 8;
    
    rge_read(a1, &velocity_x, 4);
    rge_read(a1, &velocity_y, 4);
    rge_read(a1, &velocity_z, 4);
    rge_read(a1, &ballistic_velocity, 4);
    rge_read(a1, &ballistic_acceleration, 4);
}
