// 004D5BB0 TribeBuildAIModule::numberBuiltOrInProgressItemsOfType
// Source: taibldmd.cpp lines 1658-1675
// public: virtual int __thiscall TribeBuildAIModule::numberBuiltOrInProgressItemsOfType(int,int)
//
// Attempt log:
// Probe 1: natural if-else, default flags — 8 byte diff (missing mov ebx,eax at fallback tail)
// Probe 2: added local for fallback — same diff
// Probe 3: unified return path with count variable

#ifndef TAIBLDMD_SHARED_CONTEXT
#include "..\..\include\game_globals.h"

class TribeMainDecisionAIModule;

class BuildAIModule {
public:
    int numberInProgressItemsOfType(int type, int flag);
    int numberBuiltOrInProgressItemsOfType(int type, int flag);
};

class TribeInformationAIModule {
public:
    int numberStoragePits();
    int numberGranaries();
};

class TribeMainDecisionAIModule {
public:
    char _gap_00[0xCEC];
    TribeInformationAIModule informationAI; // +0xCEC
};

class TribeBuildAIModule : public BuildAIModule {
public:
    char _gap_00[0x5BC];
    TribeMainDecisionAIModule* md; // +0x5BC (4)

    int numberBuiltOrInProgressItemsOfType(int type, int flag);
};
#endif

int TribeBuildAIModule::numberBuiltOrInProgressItemsOfType(int type, int flag)
{
    int count;
    if (flag == 0 && (type == 0x67 || type == 0x44)) {
        count = this->numberInProgressItemsOfType(type, 0);
        if (type == 0x67) {
            count += this->md->informationAI.numberStoragePits();
        } else {
            count += this->md->informationAI.numberGranaries();
        }
    } else {
        count = BuildAIModule::numberBuiltOrInProgressItemsOfType(type, flag);
    }
    return count;
}
