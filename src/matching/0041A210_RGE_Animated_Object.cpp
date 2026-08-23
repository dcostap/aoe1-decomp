// VA: 0041A210 RGE_Animated_Object::RGE_Animated_Object
// PDB owner: ani_obj.cpp lines 38-41; body boundary: 0041A210-0041A275.
// BINARY NOTE: 0041A150 is the preceding ani_obj.cpp constructor and ends at
// 0041A1D2. The compiler-generated deleting destructor starts at 0041A1E0.
// The next normal PDB-owned function is this constructor at 0041A210.
// BINARY NOTE: The constructor publishes the inherited virtual ABI after its
// base call. Keep that publication, cleanup, and setup order natural.

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
    if (doSetup != 0) {
        setup(mode, world);
    }
}
