// VA: 00416470 huntObject (211B)
// aiuaimod.cpp

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    virtual int method_DC(int a1, int a2);
    char gap4[0x4];
    void* field_08;
    char gapC[0x24];
    int field_30;
    
    int huntObject(int obj);
};

int __cdecl sub_00545D30(int a1);

int UnitAIModule::huntObject(int obj) {
    int objParams = sub_00545D30(obj);
    if (!objParams) return 0;
    
    if (field_30 == -1) {
        method_DC(-1, 0);
    }
    
    return 1;
}
