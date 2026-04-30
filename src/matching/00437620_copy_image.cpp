// 00437620 RGE_Diamond_Map::copy_image (diam_map.cpp:575-654)

typedef struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
} RECT;

class TDrawArea {
public:
    void Copy(TDrawArea* src, int src_x, int src_y, RECT* rect, int flags);
};

class RGE_Diamond_Map {
public:
    void copy_image();

    char gap_00[0x0C];
    long pnl_x;              // +0x0C
    long pnl_y;              // +0x10
    long pnl_wid;            // +0x14
    long pnl_hgt;            // +0x18
    char gap_1C[4];
    void* render_area;       // +0x20
    char gap_24[0x144];
    TDrawArea* save_area;    // +0x168
};

void RGE_Diamond_Map::copy_image()
{
    RECT r;
    r.left = 0;
    r.top = 0;
    r.right = this->pnl_wid - 1;
    r.bottom = this->pnl_hgt - 1;
    this->save_area->Copy((TDrawArea*)this->render_area, this->pnl_x, this->pnl_y, &r, 0);
}
