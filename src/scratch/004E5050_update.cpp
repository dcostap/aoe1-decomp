// VA: 004E5050 update (3397B)
// taimdmd.cpp
// EH frame (/GX)

class TribeMainDecisionAIModule {
public:
    char gap4[0x4];
    int field_8;
    char gapC[0xC];
    int field_18;
    char gap1C[0x20];
    int field_3C;
    
    void update();
};

void TribeMainDecisionAIModule::update() {
    if (field_8) {
        field_18 = field_8;
        field_3C = 0;
    }
}
