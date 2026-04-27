// attempt log:
// first pass: natural constructor lowering with the EH frame, base call, vtable store, and optional setup call
// second pass: add a per-function /GX rsp because this ctor family is EH-framed and the default basin was too small
// target shape: base RGE_Master_Combat_Object(param_1, 0), set vtable to 0x576740, optionally call setup(param_1), return this

class RGE_Master_Combat_Object {
public:
    virtual ~RGE_Master_Combat_Object();
    RGE_Master_Combat_Object(RGE_Master_Combat_Object* source, int do_setup);
};

class TRIBE_Master_Combat_Object : public RGE_Master_Combat_Object {
public:
    virtual ~TRIBE_Master_Combat_Object();
    TRIBE_Master_Combat_Object(TRIBE_Master_Combat_Object* source, int do_setup);
    int setup(TRIBE_Master_Combat_Object* source);
};

TRIBE_Master_Combat_Object::TRIBE_Master_Combat_Object(TRIBE_Master_Combat_Object* source, int do_setup)
    : RGE_Master_Combat_Object(source, 0) {
    *(void**)this = (void*)0x576740;
    if (do_setup != 0) {
        setup(source);
    }
}
