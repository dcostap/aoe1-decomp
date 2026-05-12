// VA: 00533940 RGE_View::setup(TDrawArea*, TPanel*, long, long, long, long, unsigned char, int, char*)
// PDB source: view.cpp lines 488-526
// attempt 1: natural setup body with local sprintf buffer, new TShape, and pick-list calloc loop.
// attempt 2: add TPanel vptr context/sizeof(TShape)=0x20 and use one running pick-size pointer like original.
// attempt 3: use the start of the 260-byte local buffer; VC5 places it at the original stack window.

extern "C" int __cdecl sprintf(char*, const char*, ...);
extern "C" void* __cdecl calloc(unsigned int, unsigned int);

extern "C" __declspec(dllimport) void* __stdcall GetStockObject(int);
extern "C" __declspec(dllimport) void* __stdcall CreatePen(int, int, unsigned int);

class TDrawArea;
class TPanel {
public:
    virtual void v00();
    long setup(TDrawArea* draw, TPanel* parent, long x, long y, long w, long h, unsigned char flag);
};

class TShape {
public:
    char gap_00[0x20];
    TShape(char* filename, int id);
};

class RGE_View : public TPanel {
public:
    char gap_04[0xF0];
    void* cur_render_area;       // +0xF4
    int calc_draw_count;         // +0xF8
    char gap_FC[0x2A];
    short start_scr_col;         // +0x126
    short start_scr_row;         // +0x128
    short start_map_col;         // +0x12A
    short start_map_row;         // +0x12C
    char gap_12E[0x0A];
    float last_view_x;           // +0x138
    float last_view_y;           // +0x13C
    unsigned char function_mode; // +0x140
    char gap_141[0x17];
    void* white_pen;             // +0x158
    void* red_pen;               // +0x15C
    void* hollow_brush;          // +0x160
    TShape* border_line_shape;   // +0x164
    char gap_168[0x194];
    void* pick_list_0;           // +0x2FC
    void* pick_list_1;           // +0x300
    void* pick_list_2;           // +0x304
    void* pick_list_3;           // +0x308
    void* pick_list_4;           // +0x30C
    int pick_list_size_0;        // +0x310
    int pick_list_size_1;        // +0x314
    int pick_list_size_2;        // +0x318
    int pick_list_size_3;        // +0x31C
    int pick_list_size_4;        // +0x320

    long setup(TDrawArea* draw, TPanel* parent, long x, long y, long w, long h, unsigned char flag, int calc_count, char* shape_name);
    void Init_Tile_Edge_Tables();
};

long RGE_View::setup(TDrawArea* draw, TPanel* parent, long x, long y, long w, long h, unsigned char flag, int calc_count, char* shape_name)
{
    char str[260];

    TPanel::setup(draw, parent, x, y, w, h, flag);

    this->cur_render_area = 0;
    this->calc_draw_count = calc_count;
    this->start_scr_col = 0;
    this->start_scr_row = 0;
    this->start_map_col = 0;
    this->start_map_row = 0;
    this->last_view_x = -9999.0f;
    this->last_view_y = -9999.0f;
    this->function_mode = 0;

    this->white_pen = GetStockObject(6);
    this->red_pen = CreatePen(0, 1, 0xff);
    this->hollow_brush = GetStockObject(5);

    sprintf(str, "%s.shp", shape_name);
    this->border_line_shape = new TShape(str, -1);

    this->Init_Tile_Edge_Tables();

    int* pick_size = &this->pick_list_size_0;
    int i = 5;
    do {
        *(void**)(pick_size - 5) = calloc(0x40, 0x14);
        *pick_size = 0;
        pick_size++;
        i--;
    } while (i != 0);

    return 1;
}
