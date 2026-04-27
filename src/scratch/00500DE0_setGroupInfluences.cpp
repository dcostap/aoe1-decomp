// VA: 00500DE0 setGroupInfluences (932B)
// taitacmd.cpp

class TribeAICommand {
public:
    char gap4[0x9D0];
    int field_9D4;
    int field_9D8;
    
    void setGroupInfluences(int a1);
};

void TribeAICommand::setGroupInfluences(int a1) {
    if (field_9D8) {
        field_9D4 = a1;
    }
}
