#ifndef PNL_TXT_TU_CONTEXT
class TTextPanel {
public:
    unsigned char gap_00[0xF8];
    short num_lines;

    int append_line(char* text1, char* text2, long value);
    int insert_line(long line, char* text1, char* text2, long value);
};
#endif

int TTextPanel::append_line(char* text1, char* text2, long value) {
    return insert_line((int)num_lines, text1, text2, value);
}
