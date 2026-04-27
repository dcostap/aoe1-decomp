// attempt 1: EH-framed ctor with the base RGE_Action(..., 0) call, vtable store, and optional setup helper
// result: default flags were too small; the EH basin wants a fuller RGE_Action surface with a visible virtual dtor
// attempt 2: keep the ctor body natural and let the class layout drive the unwind frame

class RGE_Action_Object;
class RGE_Action {
public:
    virtual ~RGE_Action();
    RGE_Action_Object* obj;
    char gap_04[0x40 - 0x8];

    RGE_Action(RGE_Action_Object* object, int do_setup);
    int setup(RGE_Action_Object* object);
};

class TRIBE_Action : public RGE_Action {
public:
    TRIBE_Action(RGE_Action_Object* object, int do_setup);
    int setup(RGE_Action_Object* object);
};

TRIBE_Action::TRIBE_Action(RGE_Action_Object* object, int do_setup)
    : RGE_Action(object, 0) {
    *(void**)this = (void*)0x5753E0;
    if (do_setup != 0) {
        setup(object);
    }
}
