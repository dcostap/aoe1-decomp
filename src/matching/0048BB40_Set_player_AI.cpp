// VA: 0048BB40 | RGE_Scenario::Set_player_AI(int,char*,int) | scenario.cpp:556-564 | 107 bytes
//
// Attempt log:
// [1] Sibling of Set_CityPlan (0048BAD0). AiRules at +0x1348 instead of CityPlan at +0x1308.
//     #pragma intrinsic(strcpy, strlen) for inline repne scasb + rep movsd/movsb.

#include "../../include/game_types.h"
#include <string.h>

#pragma intrinsic(strcpy, strlen)

#ifndef SCENARIO_TU
class RGE_Scenario {
public:
    char _gap_00[0x1348];
    char* AiRules[16]; // +0x1348

    void Set_player_AI(int index, char* str, int flag);
};
#endif

void RGE_Scenario::Set_player_AI(int index, char* str, int flag) {
    if (str != 0) {
        strcpy(AiRules[index], str);
    } else {
        *AiRules[index] = '\0';
    }

    if (flag == 1) {
        int len = strlen(str);
        AiRules[index][len - 4] = '\0';
    }
}
