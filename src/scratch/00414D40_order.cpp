// VA: 00414D40 order (306B)
// aiuaimod.cpp

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    char gap4[0x4];
    void* field_08;
    char gapC[0x24];
    int field_30;
    
    void order(int a1, int a2, int a3);
};

void UnitAIModule::order(int a1, int a2, int a3) {
    int* cmd = *(int**)((char*)field_08 + 0x30);
    if (!cmd) return;
    
    // Process command
    *(int*)((char*)cmd + 0x10) = a1;
    *(int*)((char*)cmd + 0x14) = a2;
    *(int*)((char*)cmd + 0x18) = a3;
    
    field_30 = 1;
}
