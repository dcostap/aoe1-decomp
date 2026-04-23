class RGE_Player {
public:
    char gap_00[0x120];
    short selected_start_col;
    short selected_start_row;
    short selected_end_col;
    short selected_end_row;

    void select_area(short start_col, short start_row, short end_col, short end_row);
};

void RGE_Player::select_area(short start_col, short start_row, short end_col, short end_row) {
    this->selected_start_col = start_col;
    this->selected_start_row = start_row;
    this->selected_end_col = end_col;
    this->selected_end_row = end_row;
}
