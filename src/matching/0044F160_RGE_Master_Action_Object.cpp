// VA: 0044F160 RGE_Master_Action_Object::RGE_Master_Action_Object (5-param constructor)
// PDB source: m_ac_obj.cpp

#include <stdio.h>

#ifndef RGE_MAC_OBJ_SHARED_CONTEXT
class RGE_Sprite;
class RGE_Sound;

class RGE_Master_Moving_Object {
public:
    virtual ~RGE_Master_Moving_Object();
    RGE_Master_Moving_Object(FILE* p1, RGE_Sprite** p2, RGE_Sound** p3,
                             short p4, int p5);
};

class RGE_Master_Action_Object : public RGE_Master_Moving_Object {
public:
    RGE_Master_Action_Object(FILE* p1, RGE_Sprite** p2, RGE_Sound** p3,
                             short p4, int p5);
    int setup(FILE* p1, RGE_Sprite** p2, RGE_Sound** p3, short p4);
};
#endif

RGE_Master_Action_Object::RGE_Master_Action_Object(FILE* p1, RGE_Sprite** p2,
                                                   RGE_Sound** p3, short p4,
                                                   int p5)
    : RGE_Master_Moving_Object(p1, p2, p3, p4, 0)
{
    if (p5 != 0) {
        this->setup(p1, p2, p3, p4);
    }
}
