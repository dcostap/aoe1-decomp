// VA: 0044FF30 RGE_Master_Combat_Object::RGE_Master_Combat_Object
// Source: m_co_obj.cpp lines 45-48
// EH-framed constructor; requires /GX like the adjacent m_co_obj ctor overloads.

#include "..\..\include\game_globals.h"

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    RGE_Master_Static_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4, int param_5);
};

class RGE_Master_Action_Object : public RGE_Master_Static_Object {
public:
    RGE_Master_Action_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4, int param_5);
};

class RGE_Master_Combat_Object : public RGE_Master_Action_Object {
public:
    int setup(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4);

    RGE_Master_Combat_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4, int param_5);
};

RGE_Master_Combat_Object::RGE_Master_Combat_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4, int param_5)
    : RGE_Master_Action_Object(param_1, param_2, param_3, param_4, 0)
{
    if (param_5 != 0) {
        this->setup(param_1, param_2, param_3, param_4);
    }
}
