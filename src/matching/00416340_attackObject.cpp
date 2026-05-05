// 00416340 UnitAIModule::attackObject
// natural virtual declarations with observed slot padding.

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
    void setCurrentAction(int action);
    void setCurrentTarget(int id, int x, int y, int z);
    int attackObject(int targetId, int flag);
};

class UnitLike {
public:
    virtual void uvf00(); virtual void uvf01(); virtual void uvf02(); virtual void uvf03();
    virtual void uvf04(); virtual void uvf05(); virtual void uvf06(); virtual void uvf07();
    virtual void uvf08(); virtual void uvf09(); virtual void uvf10(); virtual void uvf11();
    virtual void uvf12(); virtual void uvf13(); virtual void uvf14(); virtual void uvf15();
    virtual void uvf16(); virtual void uvf17(); virtual void uvf18(); virtual void uvf19();
    virtual void uvf20(); virtual void uvf21(); virtual void uvf22(); virtual void uvf23();
    virtual void uvf24(); virtual void uvf25(); virtual void uvf26(); virtual void uvf27();
    virtual void uvf28(); virtual void uvf29(); virtual void uvf30(); virtual void uvf31();
    virtual void uvf32(); virtual void uvf33(); virtual void uvf34(); virtual void uvf35();
    virtual void uvf36(); virtual void uvf37(); virtual void uvf38(); virtual void uvf39();
    virtual void uvf40(); virtual void uvf41(); virtual void uvf42(); virtual void uvf43();
    virtual void uvf44(); virtual void uvf45(); virtual void uvf46(); virtual void uvf47();
    virtual void uvf48(); virtual void uvf49(); virtual void uvf50(); virtual void uvf51();
    virtual void uvf52(); virtual void uvf53(); virtual void uvf54(); virtual void uvf55();
    virtual void uvf56(); virtual void uvf57(); virtual void uvf58(); virtual void uvf59();
    virtual void uvf60(); virtual void uvf61(); virtual void uvf62(); virtual void uvf63();
    virtual void uvf64(); virtual void uvf65(); virtual void uvf66(); virtual void uvf67();
    virtual void uvf68(); virtual void uvf69(); virtual void uvf70(); virtual void uvf71();
    virtual void uvf72(); virtual void uvf73(); virtual void uvf74(); virtual void uvf75();
    virtual void uvf76(); virtual void uvf77(); virtual void uvf78(); virtual void uvf79();
    virtual void uvf80(); virtual void uvf81(); virtual void uvf82(); virtual void uvf83();
    virtual int vf_150(int targetId, int flag);
    char gap_04[0x08];
    OwnerLike* owner;
};

int UnitAIModule::attackObject(int targetId, int flag) {
    if (flag != 0 || this->currentAction == -1) {
        TargetLike* target = this->unit->owner->world->object(targetId);
        if (target != 0) {
            if (this->canAttack(target)) {
                if (this->unit->vf_150(targetId, flag) == 1) {
                    this->setCurrentAction(0x258);
                    this->setCurrentTarget(targetId, target->x, target->y, target->z);
                    return 1;
                }
            }
        }
    }
    return 0;
}
