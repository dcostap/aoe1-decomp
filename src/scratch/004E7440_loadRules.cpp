// VA: 004E7440 loadRules (394B)
// taistrmd.cpp

class TribeStrategyAIModule {
public:
    char gap4[0x100];
    int field_104;
    
    void loadRules(const char* filename);
};

void TribeStrategyAIModule::loadRules(const char* filename) {
    if (!filename) return;
    
    const char* defaultRules = (const char*)0x57F350;
    field_104 = (int)filename;
}
