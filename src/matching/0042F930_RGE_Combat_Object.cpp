#ifndef RGE_COM_OBJ_SHARED_CONTEXT
class RGE_Player;
class RGE_Master_Combat_Object;

class RGE_Action_Object {
public:
    virtual ~RGE_Action_Object();
    RGE_Action_Object(RGE_Master_Combat_Object* master_obj, RGE_Player* player, float x, float y, float z, int do_setup);
};

class RGE_Combat_Object : public RGE_Action_Object {
public:
    RGE_Combat_Object(RGE_Master_Combat_Object* master_obj, RGE_Player* player, float x, float y, float z, int do_setup);
    virtual ~RGE_Combat_Object();
    virtual int setup(RGE_Master_Combat_Object* master_obj, RGE_Player* player, float x, float y, float z);
};
#endif

RGE_Combat_Object::RGE_Combat_Object(RGE_Master_Combat_Object* master_obj, RGE_Player* player, float x, float y, float z, int do_setup)
    : RGE_Action_Object(master_obj, player, x, y, z, 0) {
    if (do_setup != 0) {
        setup(master_obj, player, x, y, z);
    }
}
