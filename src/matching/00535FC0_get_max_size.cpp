#ifndef RGE_VIEW_SHARED_CONTEXT
class RGE_View {
public:
    char gap_00[0x116];
    short max_col_num;
    short max_row_num;

    void get_max_size(short* cols, short* rows);
};
#endif

void RGE_View::get_max_size(short* cols, short* rows) {
    *cols = max_col_num;
    *rows = max_row_num;
}
