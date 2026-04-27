// VA: 004EA280 setVictoryCondition (1231B)
// taistrmd.cpp

class TribeStrategyAIModule {
public:
    char gap4[0xF0];
    int field_F4;
    char gapF8[0x140];
    int field_238;
    
    void setVictoryCondition(int a1);
};

void TribeStrategyAIModule::setVictoryCondition(int a1) {
    field_F4 = a1;
    field_238 = a1;
}
