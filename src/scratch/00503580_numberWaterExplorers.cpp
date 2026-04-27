// VA: 00503580 numberWaterExplorers (123B)
// taitacmd.cpp

class TribeAICommand {
public:
    char gap4[0x9D0];
    int field_9D4;
    int field_9D8;
    
    int numberWaterExplorers();
};

int TribeAICommand::numberWaterExplorers() {
    int* ptr = (int*)field_9D8;
    if (ptr == (int*)&field_9D4) return 0;
    if (!ptr) return 0;
    return 1;
}
