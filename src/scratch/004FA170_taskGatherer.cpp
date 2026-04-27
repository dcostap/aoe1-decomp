// VA: 004FA170 taskGatherer (1712B)
// taitacmd.cpp

class TribeAICommand {
public:
    char gap4[0xEC];
    int field_F0;
    
    void taskGatherer(int a1);
};

void TribeAICommand::taskGatherer(int a1) {
    int* obj = (int*)field_F0;
    if (obj) {
        // Call method on obj
        field_F0 = a1;
    }
}
