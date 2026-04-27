// VA: 004EB3A0 setSpecificCommander (135B)
// taitacmd.cpp

class TribeAICommand {
public:
    char gap4[0x160];
    int field_164;
    
    void setSpecificCommander(int a1, int a2);
};

void TribeAICommand::setSpecificCommander(int a1, int a2) {
    char buf[160];
    int val = field_164;
    if (val == -1) {
        field_164 = a1;
    }
}
