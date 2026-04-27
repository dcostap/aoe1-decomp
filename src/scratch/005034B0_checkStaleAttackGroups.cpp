// VA: 005034B0 checkStaleAttackGroups (194B)
// taitacmd.cpp

class TribeAICommand {
public:
    char gap4[0xE14];
    int field_E18;
    
    void checkStaleAttackGroups();
};

void TribeAICommand::checkStaleAttackGroups() {
    if (!field_E18) return;
    field_E18 = 0;
}
