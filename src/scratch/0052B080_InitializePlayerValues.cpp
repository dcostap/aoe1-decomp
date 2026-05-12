// 0052B080 T_Scenario::InitializePlayerValues (tscenaro.cpp:260-277)
// 123 bytes, 40 asm lines
// Default flags
//
// Attempt 17: Pre-increment form: while (++i < 16)

class RGE_Scenario {
public:
    char gap_000[0x18CC];
    int fields_188C[16];
    int PlType[16];
    int PlCivilization[16];
    int PlActive[16];
    char gap_198C[4];
    int player_res[16 * 4];
    char gap_1A90[0x4BA8 - 0x1A90];
    int far_fields_1[16];
    char gap_4BE8[0x5100 - 0x4BE8];
    int far_fields_2[16];
};

class T_Scenario : public RGE_Scenario {
public:
    void InitializePlayerValues();
};

void T_Scenario::InitializePlayerValues() {
    int i = 1;
    int* base = this->PlType;
    int* block = this->player_res;

    do {
        base++;
        block += 4;
        block[-4] = 0;
        block[-3] = 0;
        block[-2] = 0;
        block[-1] = 0;
        base[31] = 0;
        block[-4] = 0;
        block[-3] = 200;
        block[-2] = 200;
        block[-1] = 150;
        base[-1] = 0;
        base[15] = i;
        *(int*)((char*)base - 68) = 4;
    } while (++i < 17);
    this->PlType[0] = 1;
}
