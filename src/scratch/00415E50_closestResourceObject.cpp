// VA: 00415E50 closestResourceObject (235B)
// aiuaimod.cpp

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    char gap4[0x4];
    void* field_08;
    char gapC[0x28];
    int field_34;
    
    int closestResourceObject(int resourceType);
};

int __cdecl sub_00545D30(int a1);
int __cdecl sub_0041A0D0(int a1);

int UnitAIModule::closestResourceObject(int resourceType) {
    for (int i = 0; i < 100; i++) {
        int obj = sub_0041A0D0(i);
        if (obj) {
            int objInfo = sub_00545D30(obj);
            if (objInfo) {
                field_34 = obj;
                return obj;
            }
        }
    }
    return -1;
}
