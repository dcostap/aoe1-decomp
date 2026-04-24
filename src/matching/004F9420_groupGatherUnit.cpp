class TribeGatherAI {
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
    virtual int groupGatherUnit(int owner, int param_1, int constant, int param_2, int minus1,
                                float param_3, float param_4, float param_5, float param_6,
                                int one, int zero, int param_7);

    char gap_04[0x46];
    short owner_id;
};

class TribeMainDecisionAIModule {
public:
    char gap_00[0xF0];
    TribeGatherAI* group_ai;
};

class TribeTacticalAIModule {
public:
    char gap_00[0xF0];
    TribeMainDecisionAIModule* md;

    int groupGatherUnit(int param_1, int param_2, float param_3, float param_4, float param_5, float param_6, int param_7);
};

int TribeTacticalAIModule::groupGatherUnit(int param_1, int param_2, float param_3, float param_4, float param_5, float param_6, int param_7) {
    TribeGatherAI* ai = this->md->group_ai;
    ai->groupGatherUnit((int)ai->owner_id, param_1, 0x2D4, param_2, -1, param_3, param_4, param_5, param_6, 1, 0, param_7);
    return 1;
}
