#ifndef AOE1_PNL_LST_CONTEXT_H
class TListPanel {
public:
    char gap_00[0x10];
    long pnl_y;
    char gap_14[0xE8];
    short top_line;
    char gap_FE[0x42];
    long text_hgt;
    char gap_144[0x3C];
    long border_size;
    long spacer_size;

    short item_at(long param_1, long param_2);
};
#endif

short TListPanel::item_at(long, long param_2) {
    int rowsize = this->spacer_size;
    if (rowsize == 0) {
        rowsize = this->text_hgt;
    } else {
        rowsize = this->text_hgt + rowsize + rowsize - 1;
    }

    return (short)((((param_2 - this->border_size) - this->pnl_y) - this->spacer_size) / rowsize) + this->top_line;
}
