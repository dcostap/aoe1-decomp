// VA: 00417B50 processOrder (1269B)
// aiuaimod.cpp
// EH frame (/GX)

class UnitAIModule {
public:
    char gap4[0x4];
    void* field_08;
    char gapC[0x78];
    int* field_84;
    
    void processOrder(int a1, int a2);
};

int __cdecl sub_0041A0D0(int a1);

void UnitAIModule::processOrder(int a1, int a2) {
    int* objData = *(int**)((char*)field_08 + 4);
    if (!objData) return;
    
    if (a1 == 1) {
        // Attack order
        field_84 = (int*)a2;
    } else if (a1 == 2) {
        // Move order
        int target = sub_0041A0D0(a2);
        if (target) {
            field_84 = (int*)target;
        }
    }
}
