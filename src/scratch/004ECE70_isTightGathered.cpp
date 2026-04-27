// VA: 004ECE70 isTightGathered (159B)
// taitacmd.cpp

class TribeAICommand {
public:
    char gap4[0x18];
    int field_1C;
    char gap20[0x4];
    int field_24;
    
    int isTightGathered();
};

int TribeAICommand::isTightGathered() {
    int val = field_1C;
    if (val == -1) {
        field_24 = 1;
        return 0;
    }
    return 1;
}
