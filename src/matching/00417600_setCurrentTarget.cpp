// UnitAIModule::setCurrentTarget
// Saves current to last, sets new target/type/xyz from params
// ret 14h = 5 stack params

struct UnitAIModule {
    char gap_0[0x34];
    int currentTarget;
    int currentTargetType;
    int currentTargetX;
    int currentTargetY;
    int currentTargetZ;
    char gap_48[0x10];
    int lastTarget;
    int lastTargetType;
};

void __fastcall setCurrentTarget(UnitAIModule* self, int, int target, int targetType, int x, int y, int z) {
    self->lastTarget = self->currentTarget;
    self->lastTargetType = self->currentTargetType;
    self->currentTarget = target;
    self->currentTargetType = targetType;
    self->currentTargetX = x;
    self->currentTargetY = y;
    self->currentTargetZ = z;
}
