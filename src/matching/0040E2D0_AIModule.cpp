// VA: 0040E2D0 AIModule::AIModule(int, int, int, int) (137 B)
// PDB source: aimodule.cpp lines 188-202
// Attempt log: see bottom

#include <string.h>

struct AIModuleID {
    char gap_00[0x48];
    AIModuleID(int a, char* str);
};

struct AIModule {
    void* vtable;           // +0x00
    AIModuleID id;          // +0x04, sizeof 0x48 → ends at +0x4C
    int field_4C;           // +0x4C
    char name[0x40];        // +0x50, string buffer
    int field_90;           // +0x90
    int field_94;           // +0x94
    int field_98;           // +0x98
    int field_9C;           // +0x9C
    int field_A0;           // +0xA0
    char gap_A4_to_E4[0x40]; // +0xA4 to +0xE3
    int field_E4;           // +0xE4
    int field_E8;           // +0xE8
    int field_EC;           // +0xEC

    AIModule();
    AIModule(int a, int b, int c, int d);
};

// External vtable symbol
extern void* AIModule_vtable;

AIModule::AIModule(int a, int b, int c, int d) : id(a, (char*)b) {
    field_4C = c;
    field_90 = 0;
    field_94 = 0;
    field_98 = 0;
    field_9C = 0;
    field_A0 = 0;
    field_E4 = 5;
    field_E8 = 50;
    field_EC = 0;
    vtable = &AIModule_vtable;
    strcpy(name, "");
}
