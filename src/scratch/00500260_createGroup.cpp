// VA: 00500260 createGroup (187B)
// taitacmd.cpp
// EH frame (/GX)

class TribeAICommand {
public:
    char gap4[0x4];
    int field_8;
    
    int createGroup();
};

int TribeAICommand::createGroup() {
    int val = field_8;
    if (val) {
        field_8 = 0;
        return val;
    }
    return 0;
}
