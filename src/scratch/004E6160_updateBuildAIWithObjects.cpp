// VA: 004E6160 updateBuildAIWithObjects (236B)
// taimdmd.cpp

class TribeMainDecisionAIModule {
public:
    char gap4[0xF4];
    int field_F8;
    char gapFC[0x4];
    int field_100;
    char gap104[0xC];
    int field_110;
    
    void updateBuildAIWithObjects();
};

void TribeMainDecisionAIModule::updateBuildAIWithObjects() {
    int count = field_F8;
    if (count > 0) {
        int maxIdx = field_100 - 1;
        field_110 = maxIdx;
    }
}
