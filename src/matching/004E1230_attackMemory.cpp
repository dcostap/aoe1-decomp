struct AttackMemory {
    char data[24];
};

class TribeInformationAIModule {
public:
    char gap_00[0x1FC];
    int maxAttackMemories;
    AttackMemory* attackMemories;

    AttackMemory* attackMemory(int index);
};

AttackMemory* TribeInformationAIModule::attackMemory(int index) {
    if (index >= 0 && index < this->maxAttackMemories)
        return this->attackMemories + index;
    return 0;
}
