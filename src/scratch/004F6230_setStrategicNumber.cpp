// VA: 004F6230 setStrategicNumber (133B)
// taitacmd.cpp

class TribeAICommand {
public:
    char gap4[0x190];
    int field_194;
    
    void setStrategicNumber(int idx, int value);
};

void TribeAICommand::setStrategicNumber(int idx, int value) {
    if (idx < 0) return;
    if (idx >= 0xE2) return;
    
    field_194 = value;
}
