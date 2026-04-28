// VA: 0048AB10 RGE_Scenario_Header::RGE_Scenario_Header(RGE_Scenario*)
// Source: scenario.cpp lines 29-50
// Size: 158 bytes, __thiscall, ret 4 (1 param)
// MATCH (0% diff, 5 relocations masked)
// Key: uninitialized int len keeps edi as zero register (xor edi,edi);
//      len=strlen(d)+1 generates inc ebx (not lea);
//      description[len-1]=0 matches [ebx+ecx-1] encoding;
//      un-nested control flow for correct jmps;
//      (int*)0x572120 for vtable address

#include <stdlib.h>
#include <string.h>
#include <time.h>

struct RGE_Scenario {
    char* Get_description();
};

struct RGE_Scenario_Header {
    int* vftable;       // +0x00
    int error_code;     // +0x04
    int version;        // +0x08
    int checksum;       // +0x0C
    char* description;  // +0x10

    RGE_Scenario_Header(RGE_Scenario* scenario);
};

RGE_Scenario_Header::RGE_Scenario_Header(RGE_Scenario* scenario) {
    this->vftable = (int*)0x572120;
    this->error_code = 0;
    this->version = 2;
    this->checksum = time(0);

    int len;
    if (scenario->Get_description()) {
        char* d = scenario->Get_description();
        len = strlen(d) + 1;
        this->description = (char*)malloc(len);
    } else {
        this->description = 0;
    }

    if (this->description) {
        char* d2 = scenario->Get_description();
        strcpy(this->description, d2);
        this->description[len - 1] = 0;
    }
}
