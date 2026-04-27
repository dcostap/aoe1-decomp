// VA: 004E7690 execute (5554B)
// taistrmd.cpp

class TribeStrategyAIModule {
public:
    char gap4[0x4];
    int field_8;
    char gapC[0x14];
    int field_20;
    
    void execute(int cmd, int a2);
};

void TribeStrategyAIModule::execute(int cmd, int a2) {
    if (cmd < 0) return;
    if (cmd >= 0x0D) return;
    
    a2--;
    if (a2 > 0x30) return;
    
    field_20 = cmd;
}
