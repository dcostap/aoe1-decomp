#ifndef PNL_TXT_TU_CONTEXT
class TTextPanel {
public:
    unsigned char gap_00[0x100];
    short cur_line;

    void set_line(long line);
    void calc_draw_info(int recalc_scrollbar);
};
#endif

void TTextPanel::set_line(long line) {
    cur_line = (short)line;
    calc_draw_info(1);
}
