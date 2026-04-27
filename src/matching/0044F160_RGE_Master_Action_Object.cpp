// VA: 0044F160 RGE_Master_Action_Object::RGE_Master_Action_Object (5-param constructor)
// PDB source: m_ac_obj.cpp

class RGE_Master_Moving_Object {
public:
    virtual ~RGE_Master_Moving_Object();
    RGE_Master_Moving_Object(void* p1, void* p2, void* p3, short p4, int p5);
};

class RGE_Master_Action_Object : public RGE_Master_Moving_Object {
public:
    RGE_Master_Action_Object(void* p1, void* p2, void* p3, short p4, int p5);
    int setup(void* p1, void* p2, void* p3, short p4);
};

RGE_Master_Action_Object::RGE_Master_Action_Object(void* p1, void* p2, void* p3, short p4, int p5)
    : RGE_Master_Moving_Object(p1, p2, p3, p4, 0)
{
    *(void**)this = (void*)0x570448;
    if (p5 != 0) {
        this->setup(p1, p2, p3, p4);
    }
}
