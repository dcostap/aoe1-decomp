// tried direct field assignment, then pointer-loop forms, then biased-pointer forms
// current blocker: build stays 112 bytes vs. 123-byte target, so this is a paused near-match
// remaining lead is codegen family/initial prolog shape, not call boundaries or behavior

struct Player_Start_Info {
    int Gold;
    int Wood;
    int Food;
    int Stone;
};

class T_Scenario {
public:
    char gap_0[0x188C];
    int PlayerPosture[16];
    int PlType[16];
    int PlCivilization[16];
    int PlActive[16];
    char gap_1[0x44];
    Player_Start_Info player_info[16];

    void InitializePlayerValues();
};

void T_Scenario::InitializePlayerValues() {
    int* piVar1;
    int* piVar2;
    int iVar3;

    iVar3 = 0;
    piVar1 = &this->PlType[0] - 1;
    piVar2 = &this->player_info[0].Gold - 2;
    do {
        iVar3 = iVar3 + 1;
        piVar1 = piVar1 + 1;
        piVar2 = piVar2 + 4;
        piVar2[-2] = 0;
        piVar2[-1] = 0;
        *piVar2 = 0;
        piVar2[1] = 0;
        piVar1[0x20] = 0;
        piVar2[-2] = 0;
        piVar2[-1] = 200;
        *piVar2 = 200;
        piVar2[1] = 150;
        *piVar1 = 0;
        piVar1[0x10] = iVar3;
        piVar1[-0x10] = 4;
        piVar1[0xcb7] = 0;
        piVar1[0xe0d] = 0;
    } while (iVar3 < 16);
    this->PlType[0] = 1;
}
