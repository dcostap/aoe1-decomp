// VA: 00502F30 processCoopAttack (144B)
// taitacmd.cpp

class TribeAICommand {
public:
    char gap4[0xE14];
    int field_E18;
    char gapE1C[0x4];
    int field_E20;
    
    int processCoopAttack();
};

int TribeAICommand::processCoopAttack() {
    if (!field_E18) return 0;
    field_E20 = 1;
    return 1;
}
