class UnitAIModule {
public:
    char gap_00[0x34];
    int currentTarget;
    int currentTargetType;
    int currentTargetX;
    int currentTargetY;
    int currentTargetZ;
    char gap_48[0x10];
    int lastTarget;
    int lastTargetType;

    void setCurrentTarget(int id, int type, int x, int y, int z);
};

void UnitAIModule::setCurrentTarget(int id, int type, int x, int y, int z) {
    this->lastTarget = this->currentTarget;
    this->lastTargetType = this->currentTargetType;
    this->currentTarget = id;
    this->currentTargetType = type;
    this->currentTargetX = x;
    this->currentTargetY = y;
    this->currentTargetZ = z;
}
