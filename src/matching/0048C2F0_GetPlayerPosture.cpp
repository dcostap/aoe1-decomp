#ifndef SCENARIO_TU
class RGE_Scenario {
public:
    char gap_00[0x188C];
    int PlayerPosture[16];

    int GetPlayerPosture(int player);
};
#endif

int RGE_Scenario::GetPlayerPosture(int player) {
    if (player < 0) {
        return 0;
    }
    if (player >= 9) {
        return 0;
    }

    switch (this->PlayerPosture[player]) {
    case 0:
        return 0;
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 3;
    case 4:
        return 4;
    case 5:
        return 5;
    }

    return 0;
}
