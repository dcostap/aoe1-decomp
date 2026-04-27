// VA: 004EB030 removeUnit (129B)
// taitacmd.cpp

class TribeAICommand {
public:
    char gap4[0x18];
    int field_1C;
    
    void removeUnit(int a1);
};

void TribeAICommand::removeUnit(int a1) {
    if (field_1C == a1) {
        field_1C = -1;
    }
}
