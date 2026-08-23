// VA: 0045A740 RGE_Missile_Object::RGE_Missile_Object (6-param constructor)
// PDB source: misl_obj.cpp
// Attempt log:
// - Uses real C++ inheritance + initializer list for EH frame under /GX
// - Base ctor takes 6 params (trailing 0)

#ifndef RGE_MISL_OBJ_SHARED_CONTEXT
class RGE_Combat_Object {
public:
    virtual ~RGE_Combat_Object();
    RGE_Combat_Object(void* p1, void* p2, float p3, float p4, float p5, int p6);
};

class RGE_Missile_Object : public RGE_Combat_Object {
public:
    float max_range;
    
    RGE_Missile_Object(void* p1, void* p2, float p3, float p4, float p5, int p6);
    int setup(void* p1, void* p2, float p3, float p4, float p5);
};
#endif

RGE_Missile_Object::RGE_Missile_Object(void* p1, void* p2, float p3, float p4, float p5, int p6)
    : RGE_Combat_Object(p1, p2, p3, p4, p5, 0)
{
    *(void**)this = (void*)0x5706F0;
    if (p6 != 0) {
        this->setup(p1, p2, p3, p4, p5);
    }
    *((unsigned char*)this + 0x4E) = 0x3C;
}
