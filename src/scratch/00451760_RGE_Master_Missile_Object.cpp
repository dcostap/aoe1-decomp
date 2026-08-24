#include "../../include/m_mi_obj_context.h"

#ifndef M_MI_OBJ_SHARED_CONTEXT
class Base_RGE_Master_Missile_Object {
public:
    virtual ~Base_RGE_Master_Missile_Object();
};

class RGE_Master_Missile_Object : public Base_RGE_Master_Missile_Object {
public:
    virtual ~RGE_Master_Missile_Object();
};
#endif

RGE_Master_Missile_Object::~RGE_Master_Missile_Object() {
}
