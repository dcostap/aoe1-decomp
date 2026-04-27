// VA: 004E9730 ~TribeStrategyAIModule dtor (232B)
// taistrmd.cpp
// EH frame (/GX)

class TribeStrategyAIModule {
public:
    int* vtable;
    char gap4[0x10];
    int field_14;
    
    ~TribeStrategyAIModule();
};

TribeStrategyAIModule::~TribeStrategyAIModule() {
    vtable = (int*)0x575698;
    if (field_14) {
        field_14 = 0;
    }
}
