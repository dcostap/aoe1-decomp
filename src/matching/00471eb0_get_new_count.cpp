class RGE_Tile_List {
public:
    char gap_00[8];
    int new_count_;

    int get_new_count();
};

int RGE_Tile_List::get_new_count() {
    int c = this->new_count_;
    this->new_count_ = 0;
    return c;
}
