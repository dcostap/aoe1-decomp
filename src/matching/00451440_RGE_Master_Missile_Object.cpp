// first pass: natural ctor lowering with the EH frame, base call, vtable store, and optional setup call
// if this is sticky, the remaining gap should be only EH/prolog basin drift around the ctor/body split
class RGE_Master_Missile_Object;

class RGE_Master_Combat_Object {
public:
    virtual ~RGE_Master_Combat_Object();
    RGE_Master_Combat_Object(RGE_Master_Combat_Object* source, int do_setup);
};

class RGE_Master_Missile_Object : public RGE_Master_Combat_Object {
public:
    virtual ~RGE_Master_Missile_Object();
    RGE_Master_Missile_Object(RGE_Master_Missile_Object* source, int do_setup);
    int setup(RGE_Master_Missile_Object* source);
};

RGE_Master_Missile_Object::RGE_Master_Missile_Object(RGE_Master_Missile_Object* source, int do_setup)
    : RGE_Master_Combat_Object(source, 0) {
    *(void**)this = (void*)0x570560;
    if (do_setup != 0) {
        setup(source);
    }
}
