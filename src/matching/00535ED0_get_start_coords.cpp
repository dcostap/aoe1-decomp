class RGE_View {
public:
    char gap_00[0x126];
    short start_scr_col;
    short start_scr_row;
    short start_map_col;
    short start_map_row;

    void get_start_coords(short* map_col, short* map_row, short* scr_col, short* scr_row);
};

void RGE_View::get_start_coords(short* map_col, short* map_row, short* scr_col, short* scr_row) {
    if (map_col != 0) {
        *map_col = start_map_col;
    }
    if (map_row != 0) {
        *map_row = start_map_row;
    }
    if (scr_col != 0) {
        *scr_col = start_scr_col;
    }
    if (scr_row != 0) {
        *scr_row = start_scr_row;
    }
}
