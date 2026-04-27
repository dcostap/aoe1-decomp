// PointMaker::Branch — real pass
// VA: 0044B540
#include "../../include/game_globals.h"

void __fastcall Branch_PointMaker(void* _this, int _, int param1)
{
    if (*(int*)((char*)_this + 0x101C) > 1) {  // CurrentNumberOfBranchLevels > 1
        int r = ((int(__fastcall*)(char*,int))0x4230A0)((char*)"fractal.cpp", 0x116);  // rand
        r = r % 100;
        int chance = *(int*)((char*)_this + 0xFC8);  // ChanceOfNextNode
        chance = chance * 10;  // chance * 5 * 2
        if (r < chance) {
            int probTiles = *(int*)((char*)_this + 0xFEC);
            int minTiles = *(int*)((char*)_this + 0xFDC);
            if (probTiles < minTiles * 2) {
                *(int*)((char*)_this + 0x101C) -= 1;  // CurrentNumberOfBranchLevels--
                int numSplits = *(int*)((char*)_this + 0xFC0);  // NumSplitsPerBranch
                for (int i = 0; i < numSplits; i++) {
                    *(int*)((char*)_this + 0xFB8) = *(int*)((char*)_this + 8 + param1 * 8 + 0);
                    *(int*)((char*)_this + 0xFBC) = *(int*)((char*)_this + 8 + param1 * 8 + 4);
                    int link = ((int(__fastcall*)(void*,int))0x44B760)(_this, 0);  // MakeNewLink
                    ((void(__fastcall*)(void*,int,int))0x44BB60)(_this, 0, link);  // DrawCurrentBranchIntoProbArray
                    ((void(__fastcall*)(void*,int,int))0x44B540)(_this, 0, link);  // Branch (recursive)
                }
            }
        }
    }
    int numSat = *(int*)((char*)_this + 0xFC4);  // NumberOfSatellites
    for (int i = 0; i < numSat; i++) {
        int link = ((int(__fastcall*)(void*,int))0x44B950)(_this, 0);  // MakeSatelliteLink
        ((void(__fastcall*)(void*,int,int))0x44BCD0)(_this, 0, link);  // DrawCurrentSatelliteIntoProbArray
    }
}
