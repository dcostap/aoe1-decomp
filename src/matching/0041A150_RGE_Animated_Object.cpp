// VA: 0041A150 RGE_Animated_Object::RGE_Animated_Object
// ani_obj.cpp lines 29-32

// attempt 1: natural C++ using sibling pattern from already-matched 0041A210

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

// 0041A150 - 131 bytes
RGE_Animated_Object::RGE_Animated_Object(RGE_Master_Animated_Object* master,
    RGE_Player* player, float a, float b, float c, int doSetup)
    : RGE_Static_Object((RGE_Master_Static_Object*)master, player, a, b, c, 0) {

    *(void**)this = (void*)0x56EC10;

    if (doSetup != 0) {
        setup(master, player, a, b, c);
    }
}
