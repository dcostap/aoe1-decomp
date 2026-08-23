// TListPanel::set_bevel_info — exact Pnl_lst.cpp owner.
// The complete canonical TListPanel declaration restores the VC5 switch-table
// pivot and keeps the base call and border correction in the original order.

#ifndef AOE1_PNL_LST_CONTEXT_H
class TListPanel {
public:
    char gap_00[0x180];
    int border_size;
    int spacer_size;

    void set_bevel_info(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7);
};

class TTextPanel {
public:
    void set_bevel_info(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7);
    void calc_draw_info(int param_1);
};
#endif

void TListPanel::set_bevel_info(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7) {
    switch (param_1) {
    case 3:
    case 6:
        this->spacer_size = 2;
        break;
    case 4:
    case 7:
        this->spacer_size = 3;
        break;
    case 1:
    case 2:
    case 5:
        this->spacer_size = 1;
        break;
    default:
        this->spacer_size = 1;
        break;
    }
#ifdef AOE1_PNL_LST_CONTEXT_H
    TTextPanel::set_bevel_info(param_1, param_2, param_3, param_4,
                               param_5, param_6, param_7);
#else
    ((TTextPanel*)this)->set_bevel_info(param_1, param_2, param_3, param_4, param_5, param_6, param_7);
#endif
    if (this->border_size == 0) {
        this->border_size = 1;
        ((TTextPanel*)this)->calc_draw_info(1);
    }
}
