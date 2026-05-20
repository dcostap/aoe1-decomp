// VA: 004163C0 UnitAIModule::attackRoundupObject
// aiuaimod.cpp
// Retry 2026-05-20 assigned pass in progress.

#define VPAD1(n) virtual void vpad##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)
#define VPAD32(n) VPAD16(n) VPAD16(n##_16)
#define VPAD64(n) VPAD32(n) VPAD32(n##_32)

class TargetLike;
class UnitLike;
class OwnerLike { public: char gap_00[0x3C]; class RGE_World* world; };
class RGE_World { public: TargetLike* object(int id); };
class TargetLike { public: char gap_00[0x38]; int x; int y; int z; };

class UnitAIModule {
public:
    virtual void vf00(); virtual void vf01(); virtual void vf02(); virtual void vf03();
    virtual void vf04(); virtual void vf05(); virtual void vf06(); virtual void vf07();
    virtual void vf08(); virtual void vf09(); virtual void vf10(); virtual void vf11();
    virtual void vf12(); virtual void vf13(); virtual void vf14(); virtual void vf15();
    virtual void vf16(); virtual void vf17(); virtual void vf18(); virtual void vf19();
    virtual int canAttack(TargetLike* target);
    UnitLike* unit;
    char gap_08[0x30 - 0x08];
    int currentAction;
    int currentTarget;
    void setCurrentAction(int action);
    void setCurrentTarget(int id, int x, int y, int z);
    int attackRoundupObject(int targetId);
};

class UnitLike {
public:
    VPAD64(0) VPAD2(64) VPAD1(66)
    virtual float vf_10c(int a, int b, int c, int d); // slot 67
    VPAD16(68)
    virtual int vf_150(int targetId, int flag);       // slot 84
    VPAD16(85)
    virtual int vf_194(int targetId, float f);        // slot 101
    char gap_04[0x08];
    OwnerLike* owner;
};

int UnitAIModule::attackRoundupObject(int targetId) {
    if (this->currentTarget != targetId) {
        TargetLike* target = this->unit->owner->world->object(targetId);
        if (target != 0) {
            if (this->canAttack(target)) {
                if (this->currentAction != -1) {
                    if (!this->unit->vf_194(targetId, this->unit->vf_10c(0, 0, -1, -1))) {
                        return 0;
                    }
                }
                if (this->unit->vf_150(targetId, 1) == 1) {
                    this->setCurrentAction(0x258);
                    this->setCurrentTarget(targetId, target->x, target->y, target->z);
                    return 1;
                }
            }
        }
    }
    return 0;
}
