// VA 004C2DF0 RGE_Static_Object::draw_frame_3d_cube_back
// stat_obj.cpp:1385-1462
// Attempt log:
// 1: Natural source from packet/decompiler with local object/map/draw-area surfaces.
// 2: First helper-shaped source compiled far too small (672 bytes) because the repeated get_point/MoveToEx/LineTo pattern was factored into a helper; helper source was removed.
// 3: Inlined all six edge segments explicitly: each has two RGE_Map::get_point calls followed by MoveToEx/LineTo.
// 4: Inlined version default /O2 /Oy is still size-short: configured 994 exceeds .text 976. It also uses an EBP frame and many stack locals, unlike original FPO/sub esp 24h schedule.
// 5: Probed /Ob0: still 976 bytes. Probed /Og- and /Od: exact 994 bytes but broad mismatch, 83.4004% positional, first mismatch offset 0; flags removed.
// 6: Implemented broad behavior/calls: master outline radii setup, owner->world->map lookup, rge_base_game view test, Unlock/GetDc, SelectClipRgn, stock pen selection based on startLoggingAI/id/groupCommanderValue, six back-cube edge projections, ReleaseDc, and relock.
// 7: Remaining blocker is FPU/local topology: original keeps precomputed radii in a tight FPO frame and schedules fld/fmul/fstp before GDI setup; natural C spills via EBP and is 18 bytes short under default flags.
// GIVEUP: left in scratch; no accepted_drift because natural build is size-short and exact-size diagnostic flags are broad from offset 0.

typedef void* HDC;
typedef void* HGDIOBJ;
typedef void* HRGN;
extern "C" int __stdcall SelectClipRgn(HDC, HRGN);
extern "C" HGDIOBJ __stdcall GetStockObject(int);
extern "C" HGDIOBJ __stdcall SelectObject(HDC, HGDIOBJ);
extern "C" int __stdcall MoveToEx(HDC, int, int, void*);
extern "C" int __stdcall LineTo(HDC, int, int);
extern int startLoggingAI;

class TDrawArea_004C2DF0 {
public:
    char gap_00[0x38];
    HDC DrawDc;
    void Unlock(char*);
    HDC GetDc(char*);
    void ReleaseDc(char*);
    unsigned char* Lock(char*, int);
};

class RGE_Map_004C2DF0 {
public:
    void get_point(short* x, short* y, float rx, float ry, float rz, int sx, int sy);
};

struct RGE_World_004C2DF0 { char gap[0x28]; RGE_Map_004C2DF0* map; };
struct RGE_Player_004C2DF0 { char gap[0x3C]; RGE_World_004C2DF0* world; };
struct MasterObj_004C2DF0 { char gap[0xAC]; float rx; float ry; float rz; };
class BaseGame_004C2DF0 { public: virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C(); virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1C(); virtual void vf20(); virtual void vf24(); virtual void vf28(); virtual void* get_view(); };
extern BaseGame_004C2DF0* rge_base_game;

class RGE_Static_Object_004C2DF0 {
public:
    char gap_00[4];
    int id;
    MasterObj_004C2DF0* master_obj;
    RGE_Player_004C2DF0* owner;
    char gap_10[0x18];
    short screen_x_offset;
    short screen_y_offset;
    char gap_2C[0x4C];
    int groupCommanderValue;

    void draw_frame_3d_cube_back(TDrawArea_004C2DF0* area, short sx, short sy);
};

void RGE_Static_Object_004C2DF0::draw_frame_3d_cube_back(TDrawArea_004C2DF0* area, short sx, short sy)
{
    MasterObj_004C2DF0* m = this->master_obj;
    float rx2 = m->rx;
    float ry2 = m->ry;
    float rzFull = m->rz;
    float rx1 = m->rx * 0.25f;
    float rz2 = m->rz * 0.25f;
    float rz3 = m->rz * 0.25f;
    float rz4 = m->rz * 0.75f;
    RGE_Map_004C2DF0* map = this->owner->world->map;

    void* view = rge_base_game->get_view();
    if (view == 0)
        return;

    area->Unlock(0);
    HDC dc = area->GetDc(0);
    if (dc != 0) {
        SelectClipRgn(area->DrawDc, *(HRGN*)((char*)view + 0x88));
        if (startLoggingAI == 1 && this->groupCommanderValue == this->id && this->id >= 0)
            SelectObject(area->DrawDc, GetStockObject(7));
        else
            SelectObject(area->DrawDc, GetStockObject(6));

        int px = sx + this->screen_x_offset;
        int py = sy + this->screen_y_offset;
        float negRy = -ry2;

        short x1, y1, x2, y2;
        map->get_point(&x1, &y1, rx2, negRy, 0.0f, px, py);
        map->get_point(&x2, &y2, rx2, negRy, rz3, px, py);
        MoveToEx(area->DrawDc, x1, y1, 0); LineTo(area->DrawDc, x2, y2);
        map->get_point(&x1, &y1, rx2, negRy, rz4, px, py);
        map->get_point(&x2, &y2, rx2, negRy, rzFull, px, py);
        MoveToEx(area->DrawDc, x1, y1, 0); LineTo(area->DrawDc, x2, y2);
        map->get_point(&x1, &y1, rx2, negRy, 0.0f, px, py);
        map->get_point(&x2, &y2, rx1, negRy, 0.0f, px, py);
        MoveToEx(area->DrawDc, x1, y1, 0); LineTo(area->DrawDc, x2, y2);
        map->get_point(&x1, &y1, -rx2, negRy, 0.0f, px, py);
        map->get_point(&x2, &y2, -rx1, negRy, 0.0f, px, py);
        MoveToEx(area->DrawDc, x1, y1, 0); LineTo(area->DrawDc, x2, y2);
        map->get_point(&x1, &y1, rx2, negRy, 0.0f, px, py);
        map->get_point(&x2, &y2, rx2, -rz2, 0.0f, px, py);
        MoveToEx(area->DrawDc, x1, y1, 0); LineTo(area->DrawDc, x2, y2);
        map->get_point(&x1, &y1, rx2, ry2, 0.0f, px, py);
        map->get_point(&x2, &y2, rx2, rz2, 0.0f, px, py);
        MoveToEx(area->DrawDc, x1, y1, 0); LineTo(area->DrawDc, x2, y2);

        SelectClipRgn(area->DrawDc, 0);
        area->ReleaseDc(0);
    }
    area->Lock(0, 1);
}
