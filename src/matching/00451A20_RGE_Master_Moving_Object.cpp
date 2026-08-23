// attempt 1: natural ctor body with the base ctor call, vtable store, and optional setup helper
// result: default flags were too small; /GX is justified for this ctor/EH basin
// attempt 2: keep the body minimal and exact, without any non-observed field init noise

#ifndef RGE_MO_OBJ_SHARED_CONTEXT
class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    RGE_Master_Static_Object(RGE_Master_Static_Object* object, int do_setup);
    int setup(RGE_Master_Static_Object* object);
};

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    char gap_0[0xB8];

    virtual ~RGE_Master_Animated_Object();
    RGE_Master_Animated_Object(RGE_Master_Animated_Object* object, int do_setup);
    int setup(RGE_Master_Animated_Object* object);
};

class RGE_Master_Moving_Object : public RGE_Master_Animated_Object {
public:
    RGE_Master_Moving_Object(RGE_Master_Moving_Object* param_1, int param_2);
    int setup(RGE_Master_Moving_Object* other);
};
#endif

RGE_Master_Moving_Object::RGE_Master_Moving_Object(RGE_Master_Moving_Object* param_1, int param_2)
    : RGE_Master_Animated_Object((RGE_Master_Animated_Object*)param_1, 0) {
    *(void**)this = (void*)0x5705A0;
    if (param_2 != 0) {
        setup(param_1);
    }
}
