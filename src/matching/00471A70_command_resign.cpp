struct ManagerHost {
    void helper(int a, int b, int c);
};

class CommandResignHost {
public:
    unsigned char command_resign(int a, int b);
    char gap_00[0x3C];
    char* field_3C;
    char gap_40[0x0A];
    short field_4A;
    char gap_4C[0x34];
    unsigned char field_80;
};

unsigned char CommandResignHost::command_resign(int a, int b) {
    if (!this->field_80) {
        ((ManagerHost*)*(void**)(this->field_3C + 0x58))->helper((int)this->field_4A, a, b);
        return 1;
    }
    return 0;
}
