// attempt 1: direct save/zero/call/restore shape from the asm
// result: compiled small because sorted was stubbed at offset 0 instead of 0x15c
// attempt 2: switched to the decompiler's named-temp spelling and unqualified member calls
// result: same code family; the real blocker is still the class layout
// attempt 3: move sorted to 0x15c so the member load/store lands on the observed offset

class TTextPanel {
public:
    char gap_0[0x15C];
    int sorted;

    int insert_line(long line, char* text1, char* text2, long value);
    int delete_line(long line);
    int change_line(long param_1, char* param_2, char* param_3, long param_4);
};

int TTextPanel::change_line(long param_1, char* param_2, char* param_3, long param_4) {
    int iVar1;
    int iVar2;

    iVar1 = this->sorted;
    this->sorted = 0;
    iVar2 = insert_line(param_1, param_2, param_3, param_4);
    if (iVar2 == 0) {
        this->sorted = iVar1;
        return 0;
    }

    delete_line(param_1 + 1);
    this->sorted = iVar1;
    return 1;
}
