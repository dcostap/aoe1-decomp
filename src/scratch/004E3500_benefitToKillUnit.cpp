struct World {
    char data[4];
};

struct TribeInformationAIModule {
    char gap_0[0x100];
    World* mainDecisionAI;
};

int __stdcall get_benefit(World*, int);

int __fastcall benefitToKillUnit(TribeInformationAIModule* self, int, int unitId) {
    World* w = self->mainDecisionAI;
    if (!w)
        return 0;
    return get_benefit(w, unitId);
}
