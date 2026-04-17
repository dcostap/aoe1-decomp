class TTextPanel {
public:
    unsigned char gap_00[0xF8];
    short num_lines;

    int append_line(char* text, long value);
    int insert_line(long line, char* text, long value);
};

int TTextPanel::append_line(char* text, long value) {
    return insert_line((int)num_lines, text, value);
}
