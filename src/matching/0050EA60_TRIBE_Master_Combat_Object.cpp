// VA: 0050EA60 TRIBE_Master_Combat_Object::TRIBE_Master_Combat_Object
// Source: tm_co_ob.cpp lines 44-47
// FLAGS: /GX (needed for EH prolog; same ctor family as adjacent exact overloads)

class RGE_Sprite;
class RGE_Sound;

class RGE_Master_Combat_Object {
public:
    virtual ~RGE_Master_Combat_Object();
    RGE_Master_Combat_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4, int param_5);
};

class TRIBE_Master_Combat_Object : public RGE_Master_Combat_Object {
public:
    virtual ~TRIBE_Master_Combat_Object();
    TRIBE_Master_Combat_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4, int param_5);
    int setup(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4);
};

TRIBE_Master_Combat_Object::TRIBE_Master_Combat_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4, int param_5)
    : RGE_Master_Combat_Object(param_1, param_2, param_3, param_4, 0) {
    if (param_5 != 0) {
        setup(param_1, param_2, param_3, param_4);
    }
}
