// VA: 00416C80 evasiveMoveTo (674B)
// aiuaimod.cpp

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    virtual void method_DC(int a1, int a2);
    char gap4[0x4];
    void* field_08;
    char gapC[0x24];
    int field_30;
    
    void evasiveMoveTo(int x, int y);
};

void __cdecl sub_00416FF0();

void UnitAIModule::evasiveMoveTo(int x, int y) {
    if (field_30 == -1) {
        method_DC(-1, 0);
    }
    
    // Execute evasive movement
    sub_00416FF0();
}
