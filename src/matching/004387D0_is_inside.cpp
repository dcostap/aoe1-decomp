class RGE_Tile;
class TPanel {
public:
    char gap_00[0x20];
    long clip_left;
    long clip_top;
    long clip_right;
    long clip_bottom;
    char gap_34[0x38];
    int active;
    int is_inside(long x, long y);
};

class RGE_Diamond_Map : public TPanel {
public:
    int pick_tile(long x, long y, short* out_x, short* out_y, RGE_Tile** out_tile);
    int is_inside(long x, long y);
};

int RGE_Diamond_Map::is_inside(long x, long y) {
    short out_x;
    short out_y;
    RGE_Tile* tile;

    if (TPanel::is_inside(x, y))
        return this->pick_tile(x, y, &out_x, &out_y, &tile);
    return 0;
}
