struct UnitAIModule {
    char gap_0[0x34];
    int currentTarget;
    int currentTargetType;
    int currentTargetX;
    int currentTargetY;
    int currentTargetZ;
};

void __fastcall setCurrentTarget(UnitAIModule* self, int, int id, int type, int x, int y, int z) {
    self->currentTarget = id;
    self->currentTargetType = type;
    self->currentTargetX = x;
    self->currentTargetY = y;
    self->currentTargetZ = z;
}
