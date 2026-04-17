class TTextPanel {
public:
    unsigned char gap_00[0xF8];
    short num_lines;

    int append_line(long a1, long a2, long a3);
    int insert_line(long line, long a1, long a2, long a3);
};

int TTextPanel::append_line(long a1, long a2, long a3) {
    return insert_line((int)num_lines, a1, a2, a3);
}
