#ifndef VW_DIMAP_SHARED_CONTEXT
class RGE_Tile;
class TPanel {
public:
    long handle_mouse_down(unsigned char button, long x, long y, int ctrl, int shift);
};

class RGE_Diamond_Map {
public:
    virtual ~RGE_Diamond_Map();
    int pick_tile(long x, long y, short* tile_x, short* tile_y, RGE_Tile** tile);
};

class RGE_Diamond_Map_View : public RGE_Diamond_Map {
public:
    long handle_mouse_down(unsigned char button, long x, long y, int ctrl, int shift);
};
#endif

long RGE_Diamond_Map_View::handle_mouse_down(unsigned char button, long x, long y, int ctrl, int shift) {
    short tile_x;
    short tile_y;
    RGE_Tile* tile;
    if (this->pick_tile(x, y, &tile_x, &tile_y, &tile) == 0) {
        return 0;
    }
    return ((TPanel*)this)->handle_mouse_down(button, x, y, ctrl, shift);
}
