// attempt 1: EH-framed ctor sibling with the three-arg RGE_Combat_Object base call and optional setup helper
// result: default flags were too small; /GX was required for the constructor/EH basin
// attempt 2: kept the natural base-call/vptr-store/setup order used by the sibling ctor

#ifndef T_C_OBJ_CONTEXT_H
class RGE_Game_World;
class RGE_Combat_Object {
public:
    virtual ~RGE_Combat_Object();
    RGE_Combat_Object(int mode, RGE_Game_World* world, int doSetup);
    int setup(int mode, RGE_Game_World* world);
};

class TRIBE_Combat_Object : public RGE_Combat_Object {
public:
    TRIBE_Combat_Object(int mode, RGE_Game_World* world, int doSetup);
    int setup(int mode, RGE_Game_World* world);
};
#endif

TRIBE_Combat_Object::TRIBE_Combat_Object(int mode, RGE_Game_World* world, int doSetup)
    : RGE_Combat_Object(mode, world, 0) {
    if (doSetup != 0) {
        setup(mode, world);
    }
}
