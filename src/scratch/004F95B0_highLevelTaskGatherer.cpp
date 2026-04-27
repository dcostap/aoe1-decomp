// VA: 004F95B0 highLevelTaskGatherer (1018B)
// taitacmd.cpp

class TribeAICommand {
public:
    char gap4[0x9C8];
    int field_9CC;
    
    void highLevelTaskGatherer(int a1);
};

void TribeAICommand::highLevelTaskGatherer(int a1) {
    int val = field_9CC;
    if (val) {
        field_9CC = a1;
    }
}
