#ifndef RGE_VIEW_SHARED_CONTEXT
class RGE_View {
public:
    char gap_00[0x11A];
    short center_scr_col;
    short center_scr_row;
    char gap_11E[0x04];
    short center_map_col;
    short center_map_row;

    void get_center_coords(short* map_col, short* map_row, short* scr_col, short* scr_row);
};
#endif

void RGE_View::get_center_coords(short* map_col, short* map_row, short* scr_col, short* scr_row) {
    if (map_col != 0) {
        *map_col = center_map_col;
    }
    if (map_row != 0) {
        *map_row = center_map_row;
    }
    if (scr_col != 0) {
        *scr_col = center_scr_col;
    }
    if (scr_row != 0) {
        *scr_row = center_scr_row;
    }
}
