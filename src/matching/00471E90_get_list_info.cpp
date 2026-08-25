#ifndef PLAYER_GROUPED_TU
class RGE_Tile_List {
public:
    char gap_0[4];
    int field_4;
    char gap_8[8];
    int field_10;

    void get_list_info(int* out1, int* out2);
};
#endif

void RGE_Tile_List::get_list_info(int* out1, int* out2) {
    *out1 = this->list_size;
    *out2 = this->num_active;
}
