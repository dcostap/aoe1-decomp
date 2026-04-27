// VA: 0048BAD0 | RGE_Scenario::Set_CityPlan(int,char*,int) | scenario.cpp:546-552 | 107 bytes
//
// Attempt log:
// [1] strcpy/memcpy generated CRT calls, too small (96 vs 107 bytes).
// [2] strlen+memcpy same issue.
// [3] Manual byte-copy loop, too small.
// [4] Try #pragma intrinsic for strcpy/strlen to force inline rep movsd/movsb.

#include "../../include/game_types.h"
#include <string.h>

#pragma intrinsic(strcpy, strlen)

class RGE_Scenario {
public:
    char _gap_00[0x1308];
    char* CityPlan[16]; // +0x1308

    void Set_CityPlan(int index, char* str, int flag);
};

void RGE_Scenario::Set_CityPlan(int index, char* str, int flag) {
    if (str != 0) {
        strcpy(CityPlan[index], str);
    } else {
        *CityPlan[index] = '\0';
    }

    if (flag == 1) {
        int len = strlen(str);
        CityPlan[index][len - 4] = '\0';
    }
}
