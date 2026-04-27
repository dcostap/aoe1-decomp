// attempt 1: EH-framed ctor sibling with the three-arg RGE_Action base call and optional setup helper
// result: default flags were too small; /GX was required for the constructor/EH basin
// attempt 2: kept the natural base-call/vptr-store/setup order used by the sibling ctor

class RGE_Action_Object;
class RGE_Action {
public:
    virtual ~RGE_Action();
    RGE_Action(int mode, RGE_Action_Object* object, int doSetup);
    int setup(int mode, RGE_Action_Object* object);
};

class TRIBE_Action : public RGE_Action {
public:
    TRIBE_Action(int mode, RGE_Action_Object* object, int doSetup);
    int setup(int mode, RGE_Action_Object* object);
};

TRIBE_Action::TRIBE_Action(int mode, RGE_Action_Object* object, int doSetup)
    : RGE_Action(mode, object, 0) {
    *(void**)this = (void*)0x5753E0;
    if (doSetup != 0) {
        setup(mode, object);
    }
}
