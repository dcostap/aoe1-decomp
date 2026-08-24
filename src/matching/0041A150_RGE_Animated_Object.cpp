// VA: 0041A150 RGE_Animated_Object::RGE_Animated_Object
// PDB owner: ani_obj.cpp lines 29-32; body boundary: 0041A150-0041A1D2.
// BINARY NOTE: aiuaimod.cpp UnitAIModule::logDebug ends at 0041A14D.
// The next normal PDB-owned function starts at 0041A150 in ani_obj.cpp.
// The inherited virtual surface naturally publishes the derived vtable.

#ifndef ANI_OBJ_SHARED_CONTEXT
class RGE_Game_World;
class RGE_Master_Static_Object;
class RGE_Master_Animated_Object;
class RGE_Player;

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    RGE_Static_Object(RGE_Master_Static_Object* master, RGE_Player* player,
                      float a, float b, float c, int flag);
};

class RGE_Animated_Object : public RGE_Static_Object {
public:
    RGE_Animated_Object(RGE_Master_Animated_Object* master, RGE_Player* player,
                        float a, float b, float c, int doSetup);
    int setup(RGE_Master_Animated_Object* master, RGE_Player* player,
              float a, float b, float c);
};
#endif

// 0041A150 - 131 bytes
RGE_Animated_Object::RGE_Animated_Object(RGE_Master_Animated_Object* master,
    RGE_Player* player, float a, float b, float c, int doSetup)
    : RGE_Static_Object((RGE_Master_Static_Object*)master, player, a, b, c, 0) {
    if (doSetup != 0) {
        setup(master, player, a, b, c);
    }
}
