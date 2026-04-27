// VA: 00414040 updateGroup (1831B)
// aiuaimod.cpp

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    char gap4[0x4];
    void* field_08;
    char gapC[0x10];
    int field_1C;
    
    void updateGroup(int groupIndex);
};

void __cdecl sub_00404760(int a1);

void UnitAIModule::updateGroup(int groupIndex) {
    int* objData = *(int**)((char*)field_08 + 4);
    if (!objData) return;
    
    int* groupInfo = *(int**)((char*)objData + 0xA0);
    if (!groupInfo) return;
    
    // Update group based on current AI state
    for (int i = 0; i < groupIndex; i++) {
        if (groupInfo[i]) {
            sub_00404760(groupInfo[i]);
        }
    }
    
    field_1C = groupIndex;
}
