// tried a direct strcpy/strlen spelling first; it compiled too small (96 bytes) versus the 107-byte original
// tried a literal decompiler-style loop with ppcVar4; size matched but prolog drifted with an extra ebp save
// current remaining gap is localized to the early prolog/register basin around the first arg load

class RGE_Scenario {
public:
    char gap_000[0x12C8];
    char* BuildList[16];

    void Set_BuildList(int param_1, char* param_2, int param_3);
};

void RGE_Scenario::Set_BuildList(int param_1, char* param_2, int param_3) {
    char* source;
    char* destination;
    int length;

    source = param_2;
    destination = this->BuildList[param_1];
    if (param_2 != 0) {
        while (*param_2 != 0) {
            *destination = *param_2;
            destination++;
            param_2++;
        }
        *destination = 0;
    }
    else {
        this->BuildList[param_1][0] = 0;
    }

    if (param_3 == 1) {
        length = 0;
        while (*source != 0) {
            source++;
            length++;
        }
        this->BuildList[param_1][length - 4] = 0;
    }
}
