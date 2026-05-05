// 00501190 TribeTacticalAIModule::selectBestCommander(TacticalAIGroup*)
// Source: taitacmd.cpp lines 11755-11801
// Attempt log:
// - Replaced stub with full best-commander scan and score comparison logic.
// - Exact match: keep `self` and `bestUnit` as explicit locals, and model the
//   object vfunc at vtable +0x10C as a float-returning virtual method.

#define VPAD1(n) virtual void vpad##n() {}
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)
#define VPAD32(n) VPAD16(n) VPAD16(n##_16)
#define VPAD64(n) VPAD32(n) VPAD32(n##_32)

class MasterObject { public: char gap_00[0x10]; short id; };

class RGE_Static_Object {
public:
    VPAD64(0) VPAD2(64) VPAD1(66)
    virtual float specialScore();

    char gap_04[4];
    MasterObject* master_obj;
    char gap_0C[0x30 - 0x0C];
    float score;
};

class TribeMainDecisionAIModule {
public:
    RGE_Static_Object* object(int id);
};

class TacticalAIGroup {
public:
    int numberUnits();
    int unit(int index);
};

class TribeTacticalAIModule {
public:
    char gap_000[0xF0];
    TribeMainDecisionAIModule* md;
    char gap_0F4[0x2C0 - 0x0F4];
    int commanderSelectionMode;

    int selectBestCommander(TacticalAIGroup* group);
};

int TribeTacticalAIModule::selectBestCommander(TacticalAIGroup* group)
{
    TribeTacticalAIModule* self;
    int bestUnit;
    int bestScore;
    int i;
    int score;
    RGE_Static_Object* obj;
    int mode;

    self = this;
    bestScore = -1;
    bestUnit = -1;
    i = 0;
    if (group->numberUnits() > 0) {
        do {
            obj = self->md->object(group->unit(i));
            if (obj != 0) {
                if (obj->master_obj->id != 0x7D) {
                    if (self->commanderSelectionMode == 2) {
                        score = (int)obj->specialScore();
                    }
                    else {
                        score = (int)obj->score;
                    }
                    mode = self->commanderSelectionMode;
                    if (mode == 1 || mode == 3) {
                        if (bestScore == -1 || score < bestScore) {
                            bestUnit = group->unit(i);
                            bestScore = score;
                        }
                    }
                    else {
                        if (bestScore == -1 || score > bestScore) {
                            bestUnit = group->unit(i);
                            bestScore = score;
                        }
                    }
                }
            }
            i = i + 1;
        } while (i < group->numberUnits());
    }
    return bestUnit;
}
