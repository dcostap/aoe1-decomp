// quick-win attempt log:
// target is 005059A0 TribePriestUnitAIModule::attackObject from taiuaimd.cpp
// first pass follows the asm structure closely: virtual +0xC4 gate, virtual +0x6C fallback,
// -1 guard on +0x28, computerPlayer() test, then the +0x10C float call and +0x94 send.

class RGE_Player {
public:
    int computerPlayer();
    virtual float vf10C(int);
};

class AIModuleTarget {
public:
    virtual int vf00();
    virtual int vf04();
    virtual int vf08();
    virtual int vf0C();
    virtual int vf10();
    virtual int vf14();
    virtual int vf18();
    virtual int vf1C();
    virtual int vf20();
    virtual int vf24();
    virtual int vf28();
    virtual int vf2C();
    virtual int vf30();
    virtual int vf34();
    virtual int vf38();
    virtual int vf3C();
    virtual int vf40();
    virtual int vf44();
    virtual int vf48();
    virtual int vf4C();
    virtual int vf50();
    virtual int vf54();
    virtual int vf58();
    virtual int vf5C();
    virtual int vf60();
    virtual int vf64();
    virtual int vf68();
    virtual int vf6C(int, int);
    virtual int vf70();
    virtual int vf74();
    virtual int vf78();
    virtual int vf7C();
    virtual int vf80();
    virtual int vf84();
    virtual int vf88();
    virtual int vf8C();
    virtual int vf90();
    virtual int vf94(int, float);
    virtual int vf98();
    virtual int vf9C();
    virtual int vfA0();
    virtual int vfA4();
    virtual int vfA8();
    virtual int vfAC();
    virtual int vfB0();
    virtual int vfB4();
    virtual int vfB8();
    virtual int vfBC();
    virtual int vfC0();
    virtual int vfC4(int);
    RGE_Player* player;
    char pad_08[0x20];
    int field_28;
};

class TribePriestUnitAIModule : public AIModuleTarget {
public:
    int attackObject(int param_1, int param_2);
};

extern int __stdcall computerPlayer(RGE_Player*);

int TribePriestUnitAIModule::attackObject(int param_1, int param_2) {
    if (vfC4(param_1) == 0) {
        if (field_28 == -1) {
            if (computerPlayer(player) != 0) {
                return vf94(param_1, player->vf10C(param_2));
            }
        }
        return 0;
    }
    return vf6C(param_1, param_2);
}
