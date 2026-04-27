// attempt 1: EH-framed ctor sibling with the three-arg RGE_Static_Object base call and optional setup helper
// result: default flags were too small; /GX was required for the constructor/EH basin
// attempt 2: kept the natural base-call/vptr-store/setup order used by the sibling ctor

class RGE_Game_World;

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    RGE_Static_Object(int mode, RGE_Game_World* world, int doSetup);
    int setup(int mode, RGE_Game_World* world);
};

class RGE_Animated_Object : public RGE_Static_Object {
public:
    RGE_Animated_Object(int mode, RGE_Game_World* world, int doSetup);
    int setup(int mode, RGE_Game_World* world);
};

RGE_Animated_Object::RGE_Animated_Object(int mode, RGE_Game_World* world, int doSetup)
    : RGE_Static_Object(mode, world, 0) {
    *(void**)this = (void*)0x56EC10;
    if (doSetup != 0) {
        setup(mode, world);
    }
}
