#include <string.h>

#ifndef SCENARIO_TU
class RGE_Scenario {
public:
    char gap_00[0x0D];
    char player_name[16][0x100];

    void SetPlayerName(int index, char* name);
};
#endif

void RGE_Scenario::SetPlayerName(int index, char* name) {
    memcpy(this->player_name[index], name, strlen(name) + 1);
}
