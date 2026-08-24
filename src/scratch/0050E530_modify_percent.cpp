#include "..\..\include\tm_b_obj_context.h"

#ifndef TM_B_OBJ_SHARED_CONTEXT
class TRIBE_Master_Building_Object {
public:
    void target_0050E530(int a, int b);
    void modify_percent(int a, int b);
};

void TRIBE_Master_Building_Object::modify_percent(int a, int b) {
    this->target_0050E530(a, b);
}
#else
void TRIBE_Master_Building_Object::modify_percent(float value, unsigned char attribute) {
    TRIBE_Master_Combat_Object::modify_percent(value, attribute);
}
#endif
