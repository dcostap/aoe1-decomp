// VA: 00413090 ~UnitAIModule dtor (183B)
// aiuaimod.cpp
// EH frame (/GX)

void __cdecl sub_0054B660(void* ptr);

class UnitAIModule {
public:
    char gap4[0x14];
    void* field_18;
    
    virtual ~UnitAIModule();
};

UnitAIModule::~UnitAIModule() {
    if (field_18) {
        sub_0054B660(field_18);
        field_18 = 0;
    }
}
