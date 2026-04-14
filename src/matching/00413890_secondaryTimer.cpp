struct UnitAIObjectRef {
    char pad_00[4];
    int id_;
    char pad_08[4];
    int owner_;
};

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    UnitAIObjectRef* object_;
    int mood_;
    int objectCategory_;
    int orderQueueSize_;
    char gap_14[0x14];
    int currentOrder_;
    int currentOrderPriority_;
    int currentAction_;
    int currentTarget_;
    int currentTargetType_;
    float currentTargetX_;
    float currentTargetY_;
    float currentTargetZ_;
    float desiredTargetDistance_;
    char gap_4C[4];
    int lastOrder_;
    int lastAction_;
    int lastTarget_;
    int lastTargetType_;
    char gap_60[4];
    int numberAttackingUnits_;
    char gap_68[0x88];
    int waypointQueueSize_;
    unsigned long lastUpdateTime_;
    unsigned long idleTimer_;
    char gap_FC[4];
    unsigned long idleTimeout_;
    unsigned long secondaryTimer_;
    char gap_108[0x18];
    float defenseBuffer_;

    unsigned long secondaryTimer();
};

unsigned long UnitAIModule::secondaryTimer() {
    return this->secondaryTimer_;
}
