// attempt 1: natural constructor body with the base ctor call, vtable store, and optional setup helper
// result: default flags were too small; /GX is justified for this ctor/EH basin
// attempt 2: remove the non-observed speed init and let the constructor shape stay close to the asm

#ifndef RGE_MAN_OBJ_SHARED_CONTEXT
class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    RGE_Master_Static_Object(RGE_Master_Static_Object* object, int do_setup);
    int setup(RGE_Master_Static_Object* object);
};

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    float speed; // +0xB8

    RGE_Master_Animated_Object(RGE_Master_Animated_Object* param_1, int param_2);
protected:
    int setup(RGE_Master_Animated_Object* other);
};
#endif

RGE_Master_Animated_Object::RGE_Master_Animated_Object(RGE_Master_Animated_Object* param_1, int param_2)
    : RGE_Master_Static_Object((RGE_Master_Static_Object*)param_1, 0) {
    *(void**)this = (void*)0x570488;
    if (param_2 != 0) {
        setup(param_1);
    }
}
