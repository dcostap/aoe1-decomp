class RGE_Tile_List {
public:
    char gap_0[4];
    int field_4;
    char gap_8[8];
    int field_10;

    void get_list_info(int* out1, int* out2);
};

void RGE_Tile_List::get_list_info(int* out1, int* out2) {
    *out1 = this->field_10;
    *out2 = this->field_4;
}
