#ifndef PNL_TXT_TU_CONTEXT
class TTextPanel {
public:
    unsigned char gap_00[0xF8];
    short num_lines;
    unsigned char gap_FA[0x6];
    short cur_line;

    long get_line();
};
#endif

long TTextPanel::get_line() {
    if (num_lines == 0) {
        return -1;
    }
    return cur_line;
}
