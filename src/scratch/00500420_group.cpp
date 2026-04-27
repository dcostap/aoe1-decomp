// VA: 00500420 group (150B)
// taitacmd.cpp

class TribeAICommand {
public:
    char gap4[0x9D0];
    int field_9D4;
    int field_9D8;
    
    int group(int a1);
};

int TribeAICommand::group(int a1) {
    int* ptr = (int*)field_9D8;
    if (!ptr) return 0;
    field_9D4 = a1;
    return 1;
}
