#include "..\..\include\tm_b_obj_context.h"

#ifndef TM_B_OBJ_SHARED_CONTEXT
class TRIBE_Master_Combat_Object {
public:
    virtual void modify_delta(float value, unsigned char attribute);
};

class TRIBE_Master_Building_Object : public TRIBE_Master_Combat_Object {
public:
    char gap_04[0x16A];
    short building_facet;

    virtual void modify_delta(float value, unsigned char attribute);
};
#endif

void TRIBE_Master_Building_Object::modify_delta(float value, unsigned char attribute) {
    if (attribute != 0x11) {
        TRIBE_Master_Combat_Object::modify_delta(value, attribute);
        return;
    }
    this->building_facet = this->building_facet + (short)value;
}
