// VA: 0040E2D0 AIModule::AIModule(int, int)
// aimodule.cpp lines 188-202

// attempt 1: takes two params through AIModuleID ctor
// 137 bytes

class AIModuleID {
public:
    AIModuleID(char* str, int param);
    char gap_00[0x48];
};

class AIModule {
public:
    char vtable[4];
    AIModuleID id;
    int field_4C;
    int field_90;
    int field_94;
    int field_98;
    int field_9C;
    int field_A0;
    int field_E4;
    int field_E8;
    int field_EC;

    AIModule();
    AIModule(int a, int b);
};

AIModule::AIModule(int a, int b) : id((char*)b, a) {
    field_4C = a;
    field_90 = 0;
    field_94 = 0;
    field_98 = 0;
    field_9C = 0;
    field_A0 = 0;
    field_E4 = 5;
    field_E8 = 50;
    field_EC = 0;
}
