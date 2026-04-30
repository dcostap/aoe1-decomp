// 00501B90 TribeTacticalAIModule::numberAvailableStoragePits
// PDB: taitacmd.cpp:12296-12337, 222 bytes
// __thiscall, int, ret 0Ch (3 params)
// FLAGS: default
//
// Attempt log:
// probe 1: 43.2% - block layout wrong (jne vs je)
// probe 2: 10.4% - layout fixed (if != -1 {main} else {alt})
//   remaining: register encoding only (esi for md, edi for capacity)
// probe 3: 28.4% - explicit md var, worse register allocation
//
// left in scratch: best was probe 2 (10.4%). Remaining drift is VC5
// register allocation: ESI overwritten with md (instead of using EDI),
// EDI used for capacity save (instead of ESI). Same instructions,
// different register encodings (8b b6 vs 8b be, 8b f8 vs 8b f0).
// All semantically equivalent. Stable VC5 decision at single-function scope.

#include <stdlib.h>

class BuildAIModule {
public:
    int numberUnbuiltItemsOfType(int type, int unk);  // 00409D40h, ret 8
    int numberItemsOfType(int type, int unk);          // 00409C70h, ret 8
};

class TribeResourceAIModule {
public:
    int resource(int type);                          // 004E6C70h, ret 4
};

class TribeInformationAIModule {
public:
    int numberAvailableStoragePits(int type);        // 004E3E90h, ret 4
};

class MainDecisionAIModule {
public:
    char gap_00[0xF0];
    void* player;              // +0xF0
    char gap_F4[0x10];         // up to +0x103
    BuildAIModule buildAI;     // +0x104
};

class TribeTacticalAIModule {
public:
    char gap_00[0xF0];
    MainDecisionAIModule* md;  // +0xF0
    char gap_F4[0x2F8];        // +0xF4 to +0x3EB
    int sn_3EC;                // +0x3EC (storage pit count?)
    char gap_3F0[0x9C];        // +0x3F0 to +0x48B
    int sn_array_48C[1];       // +0x48C indexed by resource type

    int numberAvailableStoragePits(int& param1, int& param2, int param3);
};

int TribeTacticalAIModule::numberAvailableStoragePits(int& param1, int& param2, int param3) {
    int unbuilt = ((BuildAIModule*)((char*)this->md + 0x104))->numberUnbuiltItemsOfType(0x67, 0);
    param2 = unbuilt;
    if (unbuilt > 0) {
        return 0;
    }

    int resource_val = ((TribeResourceAIModule*)((char*)this->md + 0x10D7C))->resource(param3);
    if (this->sn_array_48C[param3] <= resource_val) {
        return 0;
    }

    int storage_pit_count = this->sn_3EC;
    if (storage_pit_count != -1) {
        void* player = this->md->player;
        int capacity = (int)*(float*)((char*)*(void**)((char*)player + 0x50) + 0x18);
        if (capacity == 0) {
            capacity = 1;
        }
        capacity *= storage_pit_count;
        int count = ((BuildAIModule*)((char*)this->md + 0x104))->numberItemsOfType(0x67, 0);
        param1 = count;
        return (capacity - count < 0) ? 0 : capacity - count;
    } else {
        int count = ((BuildAIModule*)((char*)this->md + 0x104))->numberItemsOfType(0x67, 0);
        param1 = count;
        return ((TribeInformationAIModule*)((char*)this->md + 0xCEC))->numberAvailableStoragePits(param3);
    }
}
