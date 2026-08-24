#ifndef RGE_COM_OBJ_SHARED_CONTEXT
struct InnerObj_00431490 {
    char gap_0[0x120];
    float rateOfFire;
};

class RGE_Static_Object {
public:
    char gap_0[8];
    InnerObj_00431490 *ptr;
    float rateOfFire();
};
#endif

float RGE_Static_Object::rateOfFire() {
    return this->ptr->rateOfFire;
}
