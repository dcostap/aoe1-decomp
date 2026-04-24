// quick-win attempt log:
// no existing work file for 00541C90; this is the same allocate-and-ctor helper shape
// as the other effects_init variant, but for RGE_Game_World. Start with the EH-framed
// local-temp spelling and the direct operator new + RGE_Effects constructor call.

class RGE_Effects {
public:
    RGE_Effects(int param_1);
};

class RGE_Game_World {
public:
    char pad_00[0x4C];
    RGE_Effects* effects;

    void effects_init(int param_1);
};

void RGE_Game_World::effects_init(int param_1) {
    RGE_Effects* effects = new RGE_Effects(param_1);
    this->effects = effects;
}
