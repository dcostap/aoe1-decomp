struct UnitAIModule {
    char gap_0[0x34];
    int currentTarget;       // 0x34
    int currentTargetType;   // 0x38
    float currentTargetX;    // 0x3C
    float currentTargetY;    // 0x40
    float currentTargetZ;    // 0x44
    char gap_48[0x10];
    int lastTarget;          // 0x58
    int lastTargetType;      // 0x5C
};

void __fastcall removeCurrentTarget(UnitAIModule* self, int) {
    self->lastTarget = self->currentTarget;
    self->lastTargetType = self->currentTargetType;
    self->currentTarget = -1;
    self->currentTargetType = -1;
    self->currentTargetX = -1.0f;
    self->currentTargetY = -1.0f;
    self->currentTargetZ = -1.0f;
}
