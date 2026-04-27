// VA: 004EAFA0 addUnit (129B)
// taitacmd.cpp

class TribeAICommand {
public:
    char gap4[0x18];
    int field_1C;
    char gap20[0x4];
    int field_24;
    
    void addUnit(int a1);
};

void TribeAICommand::addUnit(int a1) {
    if (field_1C == -1) {
        field_1C = a1;
        field_24 = 0;
    }
}
