// VA: 004E9820 update (1391B)
// taistrmd.cpp

class TribeStrategyAIModule {
public:
    char gap4[0x230];
    int field_234;
    char gap238[0x8];
    int field_240;
    
    void update();
};

void TribeStrategyAIModule::update() {
    field_234++;
    if (field_234 < 0) {
        field_240 = 0;
    }
}
