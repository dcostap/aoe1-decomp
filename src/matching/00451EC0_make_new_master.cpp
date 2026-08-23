// attempt log:
// first pass: direct new-expression for the EH-framed factory helper
// target shape: return new RGE_Master_Moving_Object(this, 1); with 0xD8 allocation size

#ifndef RGE_MO_OBJ_SHARED_CONTEXT
class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char pad_4[0xB8 - 0x4];
};

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    char pad_B8[0xBC - 0xB8];
};

class RGE_Master_Moving_Object : public RGE_Master_Animated_Object {
public:
    char pad_BC[0xD8 - 0xBC];
    RGE_Master_Moving_Object(RGE_Master_Moving_Object* source, int do_setup);
    RGE_Master_Static_Object* make_new_master(void);
};
#endif

RGE_Master_Static_Object* RGE_Master_Moving_Object::make_new_master(void) {
    return new RGE_Master_Moving_Object((RGE_Master_Moving_Object*)this, 1);
}
