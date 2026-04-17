class RGE_View {
public:
    char gap_00[0x108];
    short tile_wid;
    short tile_hgt;
    short tile_half_wid;
    short tile_half_hgt;

    void get_tile_sizes(short* width, short* height, short* half_width, short* half_height);
};

void RGE_View::get_tile_sizes(short* width, short* height, short* half_width, short* half_height) {
    if (width != 0) {
        *width = tile_wid;
    }
    if (height != 0) {
        *height = tile_hgt;
    }
    if (half_width != 0) {
        *half_width = tile_half_wid;
    }
    if (half_height != 0) {
        *half_height = tile_half_hgt;
    }
}
