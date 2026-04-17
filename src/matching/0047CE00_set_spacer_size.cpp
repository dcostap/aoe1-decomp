class TTextPanel {
public:
    unsigned char gap_00[0x184];
    int spacer_size;

    void set_spacer_size(int size);
    void calc_draw_info(int recalc_scrollbar);
};

void TTextPanel::set_spacer_size(int size) {
    spacer_size = size;
    calc_draw_info(1);
}
