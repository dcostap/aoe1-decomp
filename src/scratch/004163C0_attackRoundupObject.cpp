// VA: 004163C0 attackRoundupObject (167B)
// aiuaimod.cpp

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    virtual int method_50(int a1);
    virtual int method_DC(int a1, int a2);
    char gap4[0x4];
    void* field_08;
    char gapC[0x24];
    int field_30;
    int field_34;
    
    int attackRoundupObject(int obj);
};

int __cdecl sub_00545D30(int a1);

int UnitAIModule::attackRoundupObject(int obj) {
    if (field_34 == obj) return 0;
    
    int objInfo = sub_00545D30(obj);
    if (!objInfo) return 0;
    
    if (!method_50(objInfo)) return 0;
    
    if (field_30 == -1) {
        method_DC(-1, 0);
    }
    
    return 0;
}
