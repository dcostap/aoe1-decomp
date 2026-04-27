// VA: 004F81A0 idleCivilian (976B)
// taitacmd.cpp

class TribeAICommand {
public:
    char gap4[0xF4];
    int field_F8;
    
    void idleCivilian();
};

void TribeAICommand::idleCivilian() {
    int count = field_F8;
    if (count <= 0) return;
    field_F8 = count - 1;
}
