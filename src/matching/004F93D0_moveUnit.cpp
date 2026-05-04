// mirrored the matched stopUnit/groupGatherUnit sibling surface: direct virtual call through md->unit with owner-id at +0x4A

class TribeMoveAI {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual int moveUnit(int owner, int param_1, int constant, int minus1_a, int minus1_b,
                         float param_2, float param_3, float one_a, float one_b,
                         int one, int zero, int param_4);

    char gap_04[0x46];
    short owner_id;
};

class TribeMainDecisionAIModule {
public:
    char gap_00[0xF0];
    TribeMoveAI* unit;
};

class TribeTacticalAIModule {
public:
    char gap_00[0xF0];
    TribeMainDecisionAIModule* md;

    int moveUnit(int param_1, float param_2, float param_3, int param_4);
};

int TribeTacticalAIModule::moveUnit(int param_1, float param_2, float param_3, int param_4) {
    TribeMoveAI* ai = this->md->unit;
    ai->moveUnit((int)ai->owner_id, param_1, 0x2C6, -1, -1, param_2, param_3, 1.0f, 1.0f, 1, 0, param_4);
    return 1;
}
