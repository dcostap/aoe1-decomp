// VA: 004F7870 numberWarshipsWithPriority (1300B)
// taitacmd.cpp

class TribeAICommand {
public:
    char gap4[0x144];
    int field_148;
    
    int numberWarshipsWithPriority();
};

int TribeAICommand::numberWarshipsWithPriority() {
    int val = field_148;
    if (val) {
        field_148 = 0;
        return 0;
    }
    return 0;
}
