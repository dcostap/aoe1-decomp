// VA: 00413AB0 update (1372B)
// aiuaimod.cpp

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    virtual void method_20();
    char gap4[0x4];
    void* field_08;
    char gapC[0x10];
    int field_1C;
    
    void update();
};

void __cdecl sub_00404760(int a1);

void UnitAIModule::update() {
    // Main update - check state and execute AI logic
    if (field_1C <= 0) return;
    
    // Process various AI phases
    method_20();
    
    int* objData = *(int**)((char*)field_08 + 4);
    if (!objData) return;
    
    sub_00404760(*(int*)((char*)objData + 0x184));
}
