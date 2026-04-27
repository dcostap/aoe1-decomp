// VA: 004171F0 runAwayFromAttackers (357B)
// aiuaimod.cpp

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    virtual int method_20();
    char gap4[0x4];
    void* field_08;
    char gapC[0x10];
    int field_1C;
    int field_20;
    
    void runAwayFromAttackers();
};

void __cdecl sub_00417350();
void __cdecl sub_00416FF0();

void UnitAIModule::runAwayFromAttackers() {
    method_20();
    
    sub_00417350();
    
    if (field_1C > 0) {
        sub_00416FF0();
        field_1C = 0;
    }
}
