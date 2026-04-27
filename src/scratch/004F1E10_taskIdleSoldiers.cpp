// VA: 004F1E10 taskIdleSoldiers (989B)
// taitacmd.cpp

class TribeAICommand {
public:
    char gap4[0xF7C];
    int field_F80;
    
    void taskIdleSoldiers();
};

void TribeAICommand::taskIdleSoldiers() {
    int val = field_F80;
    if (val != -1) {
        field_F80 = 0;
    }
}
