// VA: 00412F00 UnitAIModule ctor (356B)
// aiuaimod.cpp
// EH frame (/GX)

class UnitAIModule {
public:
    char gap4[0x4];
    int field_08;
    int field_0C;
    char gap10[0x8];
    int field_18;
    char gap1C[0x14];
    int field_30;
    
    UnitAIModule(int a1);
};

void __cdecl sub_00421F20(void* obj, int a1);

UnitAIModule::UnitAIModule(int a1) {
    field_08 = a1;
    field_0C = 0;
    field_18 = 0;
    field_30 = -1;
    
    sub_00421F20(this, a1);
}
