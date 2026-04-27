// VA: 00416A50 unload (148B)
// aiuaimod.cpp

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    virtual void method_20();
    virtual int method_50(int a1);
    virtual int method_184(int a1, int a2, int a3, int a4);
    char gap4[0x4];
    int field_08;
    void* field_0C;
    char gap10[0x20];
    int field_30;
    
    void unload(int a1);
};

void __cdecl sub_00413970(UnitAIModule* obj, int a1);

void UnitAIModule::unload(int a1) {
    int result = method_184(a1, a1, a1, 0);
    if (result == 1) {
        sub_00413970(this, 0x26D);
        if (field_08) {
            method_50(0);
            method_50(0);
        }
    }
}
