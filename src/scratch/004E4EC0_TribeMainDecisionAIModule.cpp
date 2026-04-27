// VA: 004E4EC0 ~TribeMainDecisionAIModule dtor (213B)
// taimdmd.cpp
// EH frame (/GX)

class TribeMainDecisionAIModule {
public:
    int* vtable;
    char gap4[0x14];
    int field_18;
    char gap1C[0x1245C];
    int field_12478;
    
    ~TribeMainDecisionAIModule();
};

TribeMainDecisionAIModule::~TribeMainDecisionAIModule() {
    vtable = (int*)0x5755C8;
    
    int count = field_12478;
    if (count > 0) {
        field_18 = count;
    }
}
