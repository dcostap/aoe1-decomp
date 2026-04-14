struct UnitAIModule {
    char gap_0[0x34];
    int currentTarget;
    int currentTargetType;
    char gap_3C[0x1C];
    int lastTarget;
    int lastTargetType;
};

void __fastcall removeCurrentTarget(UnitAIModule* self, int) {
    self->lastTarget = self->currentTarget;
    self->currentTarget = -1;
    self->lastTargetType = self->currentTargetType;
    self->currentTargetType = -1;
}
