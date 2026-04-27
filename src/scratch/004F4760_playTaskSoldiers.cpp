// VA: 004F4760 playTaskSoldiers (823B)
// taitacmd.cpp

class TribeAICommand {
public:
    char gap4[0x418];
    int field_41C;
    
    void playTaskSoldiers();
};

void TribeAICommand::playTaskSoldiers() {
    if (!field_41C) return;
    field_41C = 0;
}
