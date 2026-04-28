// 0040DD90 AIModuleID::AIModuleID
// PDB: aimodule.cpp:29-34, 92 bytes
// __thiscall, ret 8
// FLAGS: default
//
// Probe 1: constructor with name string copy

#include <string.h>

struct AIModuleID {
    void* vtable;      // +0x00
    int id;            // +0x04
    char name[64];     // +0x08

    AIModuleID(char* name_str, int id_value);
};

AIModuleID::AIModuleID(char* name_str, int id_value) {
    this->id = id_value;
    this->vtable = (void*)0x0056E928;

    if (name_str != NULL) {
        strncpy(this->name, name_str, 0x3F);
    } else {
        strcpy(this->name, "");
    }
}
