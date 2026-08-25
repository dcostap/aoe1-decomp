#ifndef TAITACMD_SHARED_CONTEXT
// 00501C70 TribeTacticalAIModule::numberAvailableGranaries(int&,int&)
// Source: taitacmd.cpp lines 12343-12370
// Attempt log:
// - Replaced stub with unbuilt-count/resource/SN gates and final informationAI query.
// - Exact match: spell the granary cap check as `value >= this->sn_97` so VC5
//   emits `cmp eax,ecx; jl continue` rather than the reversed `cmp ecx,eax; jg`.

#ifndef TAITACMD_SHARED_CONTEXT
class BuildAIModule {
public:
    int numberItemsOfType(int type, int unk);
    int numberUnbuiltItemsOfType(int type, int unk);
};

class TribeResourceAIModule {
public:
    int resource(int type);
};

class TribeInformationAIModule {
public:
    int numberAvailableGranaries();
};

class TribeMainDecisionAIModule {
public:
    char gap_000[0x104];
    BuildAIModule buildAI;
};

class TribeTacticalAIModule {
public:
    char gap_000[0xF0];
    TribeMainDecisionAIModule* md;
    char gap_0F4[0x3F0 - 0xF4];
    int sn_97;
    char gap_3F4[0x48C - 0x3F4];
    int sn_BE;

    int numberAvailableGranaries(int& count, int& unbuilt);
};

#endif
int TribeTacticalAIModule::numberAvailableGranaries(int& count, int& unbuilt)
{
    int value;

    value = ((BuildAIModule*)((char*)this->md + 0x104))->numberUnbuiltItemsOfType(0x44, 0);
    unbuilt = value;
    if (value > 0) {
        return 0;
    }
    value = ((TribeResourceAIModule*)((char*)this->md + 0x10D7C))->resource(0);
    if (this->sn_BE <= value) {
        return 0;
    }
    if (this->sn_97 != -1) {
        value = ((BuildAIModule*)((char*)this->md + 0x104))->numberItemsOfType(0x44, 0);
        count = value;
        if (value >= this->sn_97) {
            return 0;
        }
    }
    value = ((BuildAIModule*)((char*)this->md + 0x104))->numberItemsOfType(0x44, 0);
    count = value;
    return ((TribeInformationAIModule*)((char*)this->md + 0xCEC))->numberAvailableGranaries();
}
#else
int TribeTacticalAIModule::numberAvailableGranaries(int& count, int& unbuilt) {
    return 0;
}
#endif
