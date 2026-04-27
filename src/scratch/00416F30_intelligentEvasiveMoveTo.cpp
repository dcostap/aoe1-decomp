// VA: 00416F30 intelligentEvasiveMoveTo (666B)
// aiuaimod.cpp

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    virtual void method_DC(int a1, int a2);
    char gap4[0x4];
    void* field_08;
    char gapC[0x24];
    int field_30;
    
    void intelligentEvasiveMoveTo(int x, int y);
};

void __cdecl sub_00417010();
void __cdecl sub_00416FF0();

void UnitAIModule::intelligentEvasiveMoveTo(int x, int y) {
    if (field_30 == -1) {
        method_DC(-1, 0);
    }
    
    // Calculate evasive path
    sub_00417010();
    sub_00416FF0();
}
