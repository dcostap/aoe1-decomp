class RGE_View {
public:
    char gap_00[0x11A];
    short center_scr_col;
    short center_scr_row;

    void get_center_screen_pos(short* row, short* col);
};

void RGE_View::get_center_screen_pos(short* row, short* col) {
    *row = center_scr_row;
    *col = center_scr_col;
}
