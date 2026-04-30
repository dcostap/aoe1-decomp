// 004D3990 TRIBE_Action::update (alias from taiinfmd.cpp 'update')
// Source: TACTION.cpp lines 31-34 (same code as TRIBE_Action ctor at 004D3980)
// The PDB has this function overlapping with TRIBE_Action(004D3980).
// This is the same constructor body starting 5 bytes into 004D3980 (after SEH setup).
// Size: 239 bytes (extends through padding + helpers up to 004D3A7F)

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
