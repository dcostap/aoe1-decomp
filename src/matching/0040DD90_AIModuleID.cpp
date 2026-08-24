// 0040DD90 AIModuleID::AIModuleID
// PDB: aimodule.cpp:29-34, 92 bytes
// __thiscall, ret 8
// FLAGS: default
//
// Probe 1: constructor with name string copy

#include <string.h>

#ifndef AOE1_AIMODULE_TU_CONTEXT
class AIModuleID {
    virtual ~AIModuleID();
    int id;            // +0x04
    char name[64];     // +0x08

    AIModuleID(char* name_str, int id_value);
};
#endif

AIModuleID::AIModuleID(char* name_str, int id_value) {
    this->id = id_value;

    if (name_str != NULL) {
        strncpy(this->name, name_str, 0x3F);
    } else {
        strcpy(this->name, "");
    }
}
