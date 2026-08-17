// 004C2970 RGE_Static_Object::draw_frame_3d_square_back
// Attempt log:
// 1: Prior candidate used an approximate owner/map layout, direct GDI calls,
//    and the wrong radius/corner ordering; it saved ESI in the prologue and
//    was broadly different from the oracle.
// 2: Clean typed reconstruction: owner->world->map, outline radii at AC/B0,
//    imported GDI surface, and the four binary-observed projections. Baseline
//    check recorded; the duplicate branch-local stock calls are retained.
// 3: Receiver alias, declaration-order, register-qualified receiver, and
//    initializer probes were codegen duplicates; restored the natural source.
// 4: Direct repeated screen-coordinate expressions were broad and wrong
//    (521B, 0x14 frame); restored the short coordinate locals.
// 5: Widening the coordinate locals to int fixes the receiver/prologue and
//    reaches the best 473B / 289-byte diagnostic basin; the remaining hunk
//    is the VC5 screen-offset/FPU schedule and two-byte tail size drift.
// 6: Swapped x/y assignment order and split compound additions were either
//    slightly worse or codegen duplicates; retaining the best int-local form.
// 7: Reversed each screen-offset addition to follow the original field-load
//    order; VC5 emitted the same code, so restored the best natural form.
// 8: Replaced the decompiler union output aliases with four typed short
//    corner locals and kept the two draw calls in the natural corner order;
//    this kept the size and call set but worsened instruction shape, so the
//    best union-backed source was restored.
// 9: Changed only RGE_Map::get_point screen-coordinate formals from int to
//    signed short; emitted code was unchanged, so the ABI probe was restored.
// 10: Mutated the incoming short x/y parameters after pen selection to mirror
//     the oracle's whole-word parameter-home loads at 004C2A28/004C2A3A;
//     VC5 changed the prologue and worsened the function to 477B/313 diff,
//     so the clean int-local source was restored.
// 11: Widened only the incoming x/y declaration to int. This reproduced the
//     original 471-byte size and reduced the localized coordinate drift to
//     95 bytes, confirming the whole-word parameter-home lead; restored the
//     metadata-supported short signature as the clean source.
// 12: Narrowed only the coordinate locals to short while retaining the short
//     draw-parameter ABI, using the square-front donor's 16-bit offset shape.
//     This duplicated an earlier short-local basin and worsened the prologue
//     to 475B/300; restored the clean typed source.
// 13: The natural source mutates the short x/y parameters after pen selection.
//     Short get_point screen arguments and this mutation reproduce all 471 bytes.
//     Typed panel, master, draw-area, and screen-point layouts preserve the match.

extern int dword_0062C50C;
extern "C" __declspec(dllimport) void* __stdcall SelectClipRgn(void* hdc, void* rgn);
extern "C" __declspec(dllimport) void* __stdcall SelectObject(void* hdc, void* obj);
extern "C" __declspec(dllimport) void* __stdcall GetStockObject(int id);
extern "C" __declspec(dllimport) int __stdcall MoveToEx(void* hdc, int x, int y, void* pt);
extern "C" __declspec(dllimport) int __stdcall LineTo(void* hdc, int x, int y);

class RGE_Map;
class RGE_Game_World {
public:
    char gap_00[0x28];
    RGE_Map* map;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x38];
    RGE_Game_World* world;
};

class TDrawArea {
public:
    void* DrawSystem;
    char gap_04[4];
    unsigned char* Bits;
    char gap_0C[0x2C];
    void* DrawDc;
    void* DrawSurface;
    void Unlock(char* tag);
    void* GetDc(char* tag);
    void ReleaseDc(char* tag);
    unsigned char* Lock(char* tag, int flag);
};

class TPanel {
public:
    virtual ~TPanel();
    char gap_04[0x84];
    void* clip_region;
};

class RGE_Map {
public:
    void get_point(short* out_x, short* out_y, float rx, float ry, float rz,
                   short sx, short sy);
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual int run();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual void set_prog_mode(int);
    virtual void set_game_mode(int, int);
    virtual void set_player(short);
    virtual int get_error_code();
    virtual char* get_string(int, long, char*, int);
    virtual char* get_string(long, char*, int);
    virtual char* get_string(long);
    virtual char* get_string2(int, long, long, char*, int);
    virtual TPanel* get_view_panel();
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char pad_04[0xA8];
    float outline_radius_x;
    float outline_radius_y;
};

extern RGE_Base_Game* rge_base_game;
static char tag[] = "stat_obj::draw_frame_3d_square_back";

class RGE_Static_Object {
public:
    virtual void v00();
    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char pad_10[0x18];
    short screen_x_offset;
    short screen_y_offset;
    char pad_2c[0x4C];
    int groupCommanderValue;

    void draw_frame_3d_square_back(TDrawArea* area, short x, short y);
};

struct ScreenPoint {
    short y;
    short x;
};

void RGE_Static_Object::draw_frame_3d_square_back(TDrawArea* area, short x, short y)
{
    RGE_Map* map;
    float fVar1;
    TPanel* view;
    short y2;
    short x2;
    ScreenPoint point;
    float ry1;
    float local_4;

    map = this->owner->world->map;
    ry1 = this->master_obj->outline_radius_x;
    local_4 = this->master_obj->outline_radius_y;
    view = rge_base_game->get_view_panel();
    if (view != 0) {
        area->Unlock(tag);
        if (area->GetDc(tag) != 0) {
            SelectClipRgn(area->DrawDc, view->clip_region);
            if (dword_0062C50C == 1 &&
                this->groupCommanderValue == this->id && this->id >= 0) {
                SelectObject(area->DrawDc, GetStockObject(7));
            } else {
                SelectObject(area->DrawDc, GetStockObject(6));
            }

            x += this->screen_x_offset;
            y += this->screen_y_offset;

            fVar1 = -local_4;
            map->get_point(&x2, &y2, ry1, fVar1, 0.0f, x, y);
            map->get_point(&point.x, &point.y, ry1, local_4, 0.0f, x, y);
            MoveToEx(area->DrawDc, x2, y2, 0);
            LineTo(area->DrawDc, point.x, point.y);
            map->get_point(&x2, &y2, ry1, fVar1, 0.0f, x, y);
            map->get_point(&point.x, &point.y, -ry1, fVar1, 0.0f, x, y);
            MoveToEx(area->DrawDc, x2, y2, 0);
            LineTo(area->DrawDc, point.x, point.y);
            SelectClipRgn(area->DrawDc, 0);
            area->ReleaseDc(tag);
        }
        area->Lock(tag, 1);
    }
}
