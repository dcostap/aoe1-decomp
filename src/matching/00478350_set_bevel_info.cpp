// TListPanel::set_bevel_info — matches except JA displacement in switch bounds check
// Blocked: VC5 switch-table pivot produces different JA target (1f vs 29) for the
// out-of-range fallthrough. All in-range case dispatch (param_1=1..7) is exact.
// All subsequent code (base class calls, field_180 check) is identical.
// Relocations masked: 3 (jump table addr + 2 CALL targets)

class TListPanel {
public:
    char gap_00[0x180];
    int field_180;
    int field_184;

    void set_bevel_info(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7);
};

class TTextPanel {
public:
    void set_bevel_info(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7);
    void calc_draw_info(int param_1);
};

void TListPanel::set_bevel_info(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7) {
    switch (param_1) {
    case 3:
    case 6:
        this->field_184 = 2;
        break;
    case 4:
    case 7:
        this->field_184 = 3;
        break;
    case 1:
    case 2:
    case 5:
        this->field_184 = 1;
        break;
    default:
        this->field_184 = 1;
        break;
    }
    ((TTextPanel*)this)->set_bevel_info(param_1, param_2, param_3, param_4, param_5, param_6, param_7);
    if (this->field_180 == 0) {
        this->field_180 = 1;
        ((TTextPanel*)this)->calc_draw_info(1);
    }
}
