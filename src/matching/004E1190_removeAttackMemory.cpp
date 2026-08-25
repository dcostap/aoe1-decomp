// 004E1190 TribeInformationAIModule::removeAttackMemory
// Size: 153 bytes

#ifndef TAIINFMD_PREFIX_CONTEXT
#ifndef TAIINFMD_PREFIX_CONTEXT
struct AttackMemory {
    int id;                 // +0x00
    char type;              // +0x04
    char minX;              // +0x05
    char minY;              // +0x06
    char maxX;              // +0x07
    char maxY;              // +0x08
    char attackingOwner;    // +0x09
    char targetOwner;       // +0x0A
    short kills;            // +0x0C
    char success;           // +0x0E
    char gap_0F[5];
    int play;               // +0x14
};

class TribeInformationAIModule {
public:
    char gap_00[0x1FC];
    int maxAttackMemories;               // +0x1FC
    AttackMemory* attackMemories;        // +0x200

    void removeAttackMemory(int index);
};
#endif

#endif
void TribeInformationAIModule::removeAttackMemory(int index) {
    if (index < 0 || index >= this->maxAttackMemories) {
        return;
    }

    this->attackMemories[index].id = -1;
    this->attackMemories[index].type = 0;
    this->attackMemories[index].minX = 0;
    this->attackMemories[index].minY = 0;
    this->attackMemories[index].maxX = 0;
    this->attackMemories[index].maxY = 0;
    this->attackMemories[index].attackingOwner = -1;
    this->attackMemories[index].targetOwner = -1;
    this->attackMemories[index].kills = 0;
    this->attackMemories[index].success = 0;
    this->attackMemories[index].play = -1;
}
