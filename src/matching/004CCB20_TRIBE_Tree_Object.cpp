// attempt log:
// first pass: natural ctor lowering for the EH-framed tree object sibling
// second pass: add /GX because this ctor family is EH-framed and the default basin was too small
// target shape: base RGE_Static_Object(param1, world, 0), set vptr 0x574CB0, optional setup(param1, world)

class RGE_Game_World;

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char pad_00[0x88];
    RGE_Static_Object(int param_1, RGE_Game_World* world, int zero);
    int setup(int param_1, RGE_Game_World* world);
};

class TRIBE_Tree_Object : public RGE_Static_Object {
public:
    virtual ~TRIBE_Tree_Object();
    TRIBE_Tree_Object(int param_1, RGE_Game_World* world, int do_setup);
};

TRIBE_Tree_Object::TRIBE_Tree_Object(int param_1, RGE_Game_World* world, int do_setup)
    : RGE_Static_Object(param_1, world, 0) {
    *(void**)this = (void*)0x574CB0;
    if (do_setup != 0) {
        setup(param_1, world);
    }
}
