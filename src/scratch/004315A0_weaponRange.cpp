#ifndef RGE_COM_OBJ_SHARED_CONTEXT
struct InnerObj_004315A0 {
    char gap_0[0x114];
    float weaponRange;
};

class RGE_Static_Object {
public:
    char gap_0[8];
    InnerObj_004315A0 *ptr;
    float weaponRange();
};
#endif

float RGE_Static_Object::weaponRange() {
    return this->ptr->weaponRange;
}
