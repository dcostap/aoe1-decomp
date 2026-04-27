// VA: 004E8D20 modifyForDifficultyLevel (969B)
// taistrmd.cpp

class TribeStrategyAIModule {
public:
    char gap4[0x4];
    int field_8;
    char gapC[0x14];
    int field_20;
    char gap24[0x10];
    int field_34;
    
    void modifyForDifficultyLevel(int* params);
};

void TribeStrategyAIModule::modifyForDifficultyLevel(int* params) {
    if (!params) return;
    
    for (int i = 0; i < params[0]; i++) {
        field_20 = params[i];
    }
}
