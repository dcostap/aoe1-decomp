// attempt log:
// first pass: natural ctor lowering with the EH frame, base call, vtable store, and optional setup call
// second pass: add a per-function /GX rsp because this ctor family is clearly EH-framed
// target shape: base RGE_Master_Action_Object(param_1, 0), set vtable to 0x5704C0, optionally call setup(param_1), return this

class RGE_Master_Action_Object {
public:
    virtual ~RGE_Master_Action_Object();
    RGE_Master_Action_Object(RGE_Master_Action_Object* source, int do_setup);
};

class RGE_Master_Combat_Object : public RGE_Master_Action_Object {
public:
    virtual ~RGE_Master_Combat_Object();
    RGE_Master_Combat_Object(RGE_Master_Combat_Object* source, int do_setup);
    int setup(RGE_Master_Combat_Object* source);
};

RGE_Master_Combat_Object::RGE_Master_Combat_Object(RGE_Master_Combat_Object* source, int do_setup)
    : RGE_Master_Action_Object(source, 0) {
    *(void**)this = (void*)0x5704C0;
    if (do_setup != 0) {
        setup(source);
    }
}
