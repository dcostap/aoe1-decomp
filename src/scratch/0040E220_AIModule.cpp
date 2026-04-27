// VA: 0040E220 AIModule::AIModule (default ctor)
// aimodule.cpp lines 161-165

// attempt 2: proper initializer list for sub-object
// 132 bytes

class AIModuleID {
public:
    AIModuleID(char* str, int param);
    char gap_00[0x48];
};

class AIModule {
public:
    char vtable[4];             // +0x00
    AIModuleID id;              // +0x04
    int some_id;                // +0x4C
    int field_90;               // +0x90
    int field_94;               // +0x94
    int field_98;               // +0x98
    int field_9C;               // +0x9C
    int field_A0;               // +0xA0
    int field_E4;               // +0xE4
    int field_E8;               // +0xE8
    int field_EC;               // +0xEC

    AIModule();
    AIModule(int a, int b);
};

AIModule::AIModule() : id((char*)0x592A40, -1) {
    some_id = -1;
    field_90 = 0;
    field_94 = 0;
    field_98 = 0;
    field_9C = 0;
    field_A0 = 0;
    field_E4 = 5;
    field_E8 = 50;
    field_EC = 0;
}
