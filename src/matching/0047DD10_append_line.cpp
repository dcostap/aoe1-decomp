#ifndef PNL_TXT_TU_CONTEXT
class TTextPanel {
public:
    unsigned char gap_00[0xF8];
    short num_lines;

    int append_line(long a1, long a2);
    int insert_line(long line, long a1, long a2);
};
#endif

int TTextPanel::append_line(long a1, long a2) {
    return insert_line((int)num_lines, a1, a2);
}
