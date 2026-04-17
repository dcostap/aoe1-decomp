class RGE_Game_World;

class RGE_Action_Object {
public:
    virtual ~RGE_Action_Object();
    RGE_Action_Object(int handle, RGE_Game_World* world, int do_setup);
};

class RGE_Combat_Object : public RGE_Action_Object {
public:
    RGE_Combat_Object(int handle, RGE_Game_World* world, int do_setup);
    virtual ~RGE_Combat_Object();
    virtual int setup(int handle, RGE_Game_World* world);
};

RGE_Combat_Object::RGE_Combat_Object(int handle, RGE_Game_World* world, int do_setup)
    : RGE_Action_Object(handle, world, 0) {
    if (do_setup != 0) {
        setup(handle, world);
    }
}
