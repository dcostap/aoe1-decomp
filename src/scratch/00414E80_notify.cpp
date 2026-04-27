// VA: 00414E80 notify (177B)
// aiuaimod.cpp

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    char gap4[0x4];
    void* field_08;
    char gapC[0x50];
    int field_5C;
    int field_60;
    int field_64;
    int field_68;
    int field_6C;
    int field_70;
    
    int notify(int a1, int a2, int a3);
};

int UnitAIModule::notify(int a1, int a2, int a3) {
    // Only process if module is active (field+48 == 2)
    if (*(unsigned char*)((char*)field_08 + 0x48) != 2) return 0;
    
    // Check message type
    if (a2 != 0x2BB) {
        // Handle other types
    } else {
        // Search list
    }
    
    return 1;
}
