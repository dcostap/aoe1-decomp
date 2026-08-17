// VA 004C2DF0 RGE_Static_Object::draw_frame_3d_cube_back
// stat_obj.cpp:1385-1462
// Attempt log:
// 1: Natural source from packet/decompiler with local object/map/draw-area surfaces.
// 2: First helper-shaped source compiled far too small (672 bytes) because the repeated get_point/MoveToEx/LineTo pattern was factored into a helper; helper source was removed.
// 3: Inlined all six edge segments explicitly: each has two RGE_Map::get_point calls followed by MoveToEx/LineTo.
// 4: Inlined version default /O2 /Oy is still size-short: configured 994 exceeds .text 976. It also uses an EBP frame and many stack locals, unlike original FPO/sub esp 24h schedule.
// 5: Probed /Ob0: still 976 bytes. Probed /Og- and /Od: exact 994 bytes but broad mismatch, 83.4004% positional, first mismatch offset 0; flags removed.
// 6: Implemented broad behavior/calls: master outline radii setup, owner->world->map lookup, rge_base_game view test, Unlock/GetDc, SelectClipRgn, stock pen selection based on startLoggingAI/id/groupCommanderValue, six back-cube edge projections, ReleaseDc, and relock.
// 7: Restored the absolute game globals/rdata constants and IAT function-pointer ABI; all 34 calls now align, with the remaining drift localized to prologue/liveness and coordinate scheduling.
// 8: Mirrored the exact cube-front donor's function-scope output locals and declaration order; corrected the radius_y quarter field used by the final two edges. This reached 998B with 100% ordered-call parity and 79.6% resync similarity.
// 9: Compound-assignment radius probes introduced broad fmulp/liveness drift and were rolled back.
// 10: External/const/volatile rdata declaration probes and split coordinate assignments were codegen duplicates or lost absolute relocation identity; restored the natural absolute, direct-member source.
// 11: Reversed each projected segment to the binary's natural endpoint order: get_point x2/y2 first, then x1/y1, followed by MoveToEx(x2,y2) and LineTo(x1,y1).
// 12: Followed the first structural hunk by testing direct master-member radius expressions; emitted code was unchanged.
// 13: Moved view preparation before the radii; it changed scheduling but called get_view too early and worsened block alignment, so it was reverted.
// 14: Matched cube-front declaration topology and delayed map derivation; both emitted duplicates.
// 15: Restored master-before-owner declaration order; duplicate.
// 16: Added the proven virtual class surface, typed view ownership, and CRT header; all were codegen duplicates.
// 17: Tested int coordinate parameters against raw original stack loads; size improved by 2 bytes but structural drift worsened, so restored short ABI.
// 18: Query_abi confirmed RGE_Map::get_point uses short screen coordinates; the exact local ABI surface is retained, with no codegen change.
// 19: Binary decompiler assignment order places owner->world->map between full x and y/z radius loads; the positive view guard and this order are codegen duplicates.
// 20: Exact player/world virtual surfaces preserve proven offsets (+3C and +28); emitted code is unchanged.
// 21: A short coordinate-local diagnostic reached 994 bytes but emitted 16-bit additions, unlike the original 32-bit parameter-home additions; rolled back.
// 22-25: Re-tested widened parameters, reversed declaration order, master class surface,
//        and owner/map aliases. They did not improve the 994B / 105-byte-diff basin.
// 26: An ambient declaration sweep (64 samples) kept size, frame, calls, and the
//     same first mismatch. Translation-unit declaration count is not the blocker.
// 27: Split map declaration and assignment was a codegen duplicate. The best source
//     uses literal 0.25f/0.75f pools and mutates the short coordinate parameters.
// GIVEUP: left in scratch after 27 meaningful hypotheses; no accepted_drift because
// the clean natural source remains 994B with 105 strict-diff bytes.

#include <stdlib.h>

typedef void* HDC;
typedef void* HGDIOBJ;
typedef void* HRGN;
extern "C" __declspec(dllimport) int __stdcall SelectClipRgn(HDC, HRGN);
extern "C" __declspec(dllimport) HGDIOBJ __stdcall GetStockObject(int);
extern "C" __declspec(dllimport) HGDIOBJ __stdcall SelectObject(HDC, HGDIOBJ);
extern "C" __declspec(dllimport) int __stdcall MoveToEx(HDC, int, int, void*);
extern "C" __declspec(dllimport) int __stdcall LineTo(HDC, int, int);


#define startLoggingAI (*(int*)0x0062C50C)

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
    void get_point(short* x, short* y, float rx, float ry, float rz, short sx, short sy);
};

class RGE_World_004C2DF0 {
public:
    char gap[0x28];
    RGE_Map_004C2DF0* map;
};
class RGE_Player_004C2DF0 {
public:
    char gap[0x3C];
    RGE_World_004C2DF0* world;
};
class MasterObj_004C2DF0 {
public:
    virtual ~MasterObj_004C2DF0();
    char gap[0xA8];
    float rx;
    float ry;
    float rz;
};
struct RGE_View_004C2DF0 { char gap[0x88]; HRGN clip_rgn; };
class BaseGame_004C2DF0 { public: virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C(); virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1C(); virtual void vf20(); virtual void vf24(); virtual void vf28(); virtual RGE_View_004C2DF0* get_view(); };
#define rge_base_game (*(BaseGame_004C2DF0**)0x0062C574)
#define DAT_00574734 (*(float*)0x00574734)
#define DAT_00574738 (*(float*)0x00574738)

class RGE_Static_Object_004C2DF0 {
public:
    virtual ~RGE_Static_Object_004C2DF0();
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
    short y2, x2, y1, x1;
    float negRy;
    MasterObj_004C2DF0* m = this->master_obj;
    float ry1, rz2, rz3, rz4, rx2, ry2, rzFull;
    ry1 = m->rx * 0.25f;
    rz2 = m->ry * 0.25f;
    rz3 = m->rz * 0.25f;
    rz4 = m->rz * 0.75f;
    rx2 = m->rx;
    RGE_Map_004C2DF0* map = this->owner->world->map;
    ry2 = m->ry;
    rzFull = m->rz;
    RGE_View_004C2DF0* view = rge_base_game->get_view();

    if (view != 0) {
        area->Unlock(0);
        HDC dc = area->GetDc(0);
        if (dc != 0) {
        SelectClipRgn(area->DrawDc, view->clip_rgn);
        if (startLoggingAI == 1 && this->groupCommanderValue == this->id && this->id >= 0)
            SelectObject(area->DrawDc, GetStockObject(7));
        else
            SelectObject(area->DrawDc, GetStockObject(6));

        sx += this->screen_x_offset;
        sy += this->screen_y_offset;
        negRy = -ry2;

        map->get_point(&x2, &y2, rx2, negRy, 0.0f, sx, sy);
        map->get_point(&x1, &y1, rx2, negRy, rz3, sx, sy);
        MoveToEx(area->DrawDc, x2, y2, 0); LineTo(area->DrawDc, x1, y1);
        map->get_point(&x2, &y2, rx2, negRy, rz4, sx, sy);
        map->get_point(&x1, &y1, rx2, negRy, rzFull, sx, sy);
        MoveToEx(area->DrawDc, x2, y2, 0); LineTo(area->DrawDc, x1, y1);
        map->get_point(&x2, &y2, rx2, negRy, 0.0f, sx, sy);
        map->get_point(&x1, &y1, ry1, negRy, 0.0f, sx, sy);
        MoveToEx(area->DrawDc, x2, y2, 0); LineTo(area->DrawDc, x1, y1);
        map->get_point(&x2, &y2, -rx2, negRy, 0.0f, sx, sy);
        map->get_point(&x1, &y1, -ry1, negRy, 0.0f, sx, sy);
        MoveToEx(area->DrawDc, x2, y2, 0); LineTo(area->DrawDc, x1, y1);
        map->get_point(&x2, &y2, rx2, negRy, 0.0f, sx, sy);
        map->get_point(&x1, &y1, rx2, -rz2, 0.0f, sx, sy);
        MoveToEx(area->DrawDc, x2, y2, 0); LineTo(area->DrawDc, x1, y1);
        map->get_point(&x2, &y2, rx2, ry2, 0.0f, sx, sy);
        map->get_point(&x1, &y1, rx2, rz2, 0.0f, sx, sy);
        MoveToEx(area->DrawDc, x2, y2, 0); LineTo(area->DrawDc, x1, y1);

        SelectClipRgn(area->DrawDc, 0);
        area->ReleaseDc(0);
        }
        area->Lock(0, 1);
    }
}
