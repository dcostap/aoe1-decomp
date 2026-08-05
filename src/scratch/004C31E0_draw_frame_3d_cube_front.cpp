// VA 004C31E0 RGE_Static_Object::draw_frame_3d_cube_front
// PDB source: stat_obj.cpp lines 1466-1620
// Baseline: natural period-plausible reconstruction of the front cube outline.
// Attempt log:
// - baseline initially omitted one front-cube edge pair: 2264 bytes and 78 calls.
// - restored all 18 explicit get_point/MoveToEx/LineTo pairs: exact size/call set,
//   but VC5 selected a 0x2C frame instead of the original 0x28.
// - inlined the repeated negative quarter-radius expression and reordered output
//   locals; emitted code was unchanged. A short-output union diagnostic was also
//   unchanged and was reverted to ordinary short locals.
// - reusing the incoming x/y parameter homes as moving offsets regressed broadly;
//   reverted. Short sx/sy temporaries recovered the closest basin (737/736 strict
//   diff bytes) but still eagerly save EDI and retain the 0x2C frame.
// - reversing y-then-x coordinate initialization moved one byte closer; final
//   output-local declaration ordering was a duplicate. Calls, cleanup, and all
//   18 edge behaviors are aligned; remaining drift is prologue/local topology.
// r1 (2026-08-06):
// - geometry audit: edge-5 FIRST point (line 1527) passes the Z radius (rx1),
//   not 0.0f; original loads [esp+1Ch]. Fixed. (The 0.0f was a decompiler
//   artifact that coincidentally offset the +3 size of the 0x2C frame.)
// - inline-vs-named negations are codegen-neutral (VC5 CSEs both into the same
//   dead parameter slots: neg_ry->x-slot, neg_ry2->area-slot, -ry*0.25->y-slot).
// - KEY: declaring the four get_point output shorts (y2/x2/y1/x1) at the
//   FUNCTION TOP (before the radius locals) fixes both the frame (0x2C -> 0x28)
//   and the float slot layout (rz*0.25@F20, rz*0.75@F24 now match original).
// - with shorts-at-top, int sy/sx recovers exact size 2375 and diff 791
//   (best correct-geometry state); short sy/sx keeps 872 instructions but is
//   +3 size (movsx form).
// - remaining drift: register basin (rebuilt keeps `this` in esi/edi, original
//   in ebx with delayed push edi) and the screen-offset arithmetic form
//   (original: 16-bit member loads into ax/dx + 32-bit param loads + adds with
//   garbage-high bits; rebuilt: movsx-based). Frame, FPU prologue, output LEAs,
//   all 82 calls, and all 36 get_point float args now match the original.

extern "C" {
__declspec(dllimport) int __stdcall SelectClipRgn(void* hdc, void* rgn);
__declspec(dllimport) void* __stdcall GetStockObject(int id);
__declspec(dllimport) void* __stdcall SelectObject(void* hdc, void* object);
__declspec(dllimport) int __stdcall MoveToEx(void* hdc, int x, int y, void* point);
__declspec(dllimport) int __stdcall LineTo(void* hdc, int x, int y);
}

extern int startLoggingAI;

class TDrawArea {
public:
    char gap_00[0x38];
    void* DrawDc;
    void Unlock(char* name);
    void* GetDc(char* name);
    void ReleaseDc(char* name);
    unsigned char* Lock(char* name, int wait);
};

class RGE_Map {
public:
    void get_point(short* out_x, short* out_y,
                   float rx, float ry, float rz, int sx, int sy);
};

class RGE_World {
public:
    char gap_00[0x28];
    RGE_Map* map;
};

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_World* world;
};

class RGE_Master_Static_Object {
public:
    char gap_00[0xAC];
    float outline_radius_x;
    float outline_radius_y;
    float outline_radius_z;
};

class RGE_View {
public:
    char gap_00[0x88];
    void* clip_rgn;
};

class RGE_Base_Game {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual RGE_View* get_view();
};

extern RGE_Base_Game* rge_base_game;

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    int id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x18];
    short screen_x_offset;
    short screen_y_offset;
    char gap_2C[0x4C];
    int groupCommanderValue;

    void draw_frame_3d_cube_front(TDrawArea* area, short x, short y);
};

void RGE_Static_Object::draw_frame_3d_cube_front(TDrawArea* area, short x, short y)
{
    short y2, x2, y1, x1;
    int sy, sx;
    float neg_ry, neg_ry2, neg_local_10;
    RGE_Master_Static_Object* master = this->master_obj;
    RGE_Player* owner = this->owner;
    RGE_Map* map = owner->world->map;
    float local_10 = master->outline_radius_x * 0.25f;
    float rx2 = master->outline_radius_y * 0.25f;
    float rz3 = master->outline_radius_z * 0.25f;
    float local_4 = master->outline_radius_z * 0.75f;
    float ry2 = master->outline_radius_x;
    float rz4 = master->outline_radius_y;
    float rx1 = master->outline_radius_z;
    RGE_View* view = rge_base_game->get_view();

    if (view != 0) {
        area->Unlock(0);
        if (area->GetDc(0) != 0) {
            SelectClipRgn(area->DrawDc, view->clip_rgn);
            if (startLoggingAI == 1 && this->groupCommanderValue == this->id && this->id >= 0) {
                SelectObject(area->DrawDc, GetStockObject(7));
            } else {
                SelectObject(area->DrawDc, GetStockObject(6));
            }

            sy = y + this->screen_y_offset - 0x10;
            sx = x + this->screen_x_offset;
            neg_ry = -rz4;

            map->get_point(&x2, &y2, ry2, neg_ry, rx1, sx, sy);
            map->get_point(&x1, &y1, local_10, neg_ry, rx1, sx, sy);
            MoveToEx(area->DrawDc, x2, y2, 0);
            LineTo(area->DrawDc, x1, y1);

            neg_ry2 = -ry2;
            neg_local_10 = -local_10;
            map->get_point(&x2, &y2, neg_ry2, neg_ry, rx1, sx, sy);
            map->get_point(&x1, &y1, neg_local_10, neg_ry, rx1, sx, sy);
            MoveToEx(area->DrawDc, x2, y2, 0);
            LineTo(area->DrawDc, x1, y1);

            map->get_point(&x2, &y2, ry2, rz4, rx1, sx, sy);
            map->get_point(&x1, &y1, local_10, rz4, rx1, sx, sy);
            MoveToEx(area->DrawDc, x2, y2, 0);
            LineTo(area->DrawDc, x1, y1);

            map->get_point(&x2, &y2, neg_ry2, rz4, rx1, sx, sy);
            map->get_point(&x1, &y1, neg_local_10, rz4, rx1, sx, sy);
            MoveToEx(area->DrawDc, x2, y2, 0);
            LineTo(area->DrawDc, x1, y1);

            map->get_point(&x2, &y2, ry2, rz4, rx1, sx, sy);
            map->get_point(&x1, &y1, ry2, rx2, rx1, sx, sy);
            MoveToEx(area->DrawDc, x2, y2, 0);
            LineTo(area->DrawDc, x1, y1);

            map->get_point(&x2, &y2, ry2, neg_ry, rx1, sx, sy);
            map->get_point(&x1, &y1, ry2, -rx2, rx1, sx, sy);
            MoveToEx(area->DrawDc, x2, y2, 0);
            LineTo(area->DrawDc, x1, y1);

            map->get_point(&x2, &y2, neg_ry2, rz4, rx1, sx, sy);
            map->get_point(&x1, &y1, neg_ry2, rx2, rx1, sx, sy);
            MoveToEx(area->DrawDc, x2, y2, 0);
            LineTo(area->DrawDc, x1, y1);

            map->get_point(&x2, &y2, neg_ry2, neg_ry, rx1, sx, sy);
            map->get_point(&x1, &y1, neg_ry2, -rx2, rx1, sx, sy);
            MoveToEx(area->DrawDc, x2, y2, 0);
            LineTo(area->DrawDc, x1, y1);

            map->get_point(&x2, &y2, neg_ry2, neg_ry, 0.0f, sx, sy);
            map->get_point(&x1, &y1, neg_ry2, -rx2, 0.0f, sx, sy);
            MoveToEx(area->DrawDc, x2, y2, 0);
            LineTo(area->DrawDc, x1, y1);

            map->get_point(&x2, &y2, neg_ry2, rz4, 0.0f, sx, sy);
            map->get_point(&x1, &y1, neg_ry2, rx2, 0.0f, sx, sy);
            MoveToEx(area->DrawDc, x2, y2, 0);
            LineTo(area->DrawDc, x1, y1);

            map->get_point(&x2, &y2, ry2, rz4, 0.0f, sx, sy);
            map->get_point(&x1, &y1, local_10, rz4, 0.0f, sx, sy);
            MoveToEx(area->DrawDc, x2, y2, 0);
            LineTo(area->DrawDc, x1, y1);

            map->get_point(&x2, &y2, neg_ry2, rz4, 0.0f, sx, sy);
            map->get_point(&x1, &y1, neg_local_10, rz4, 0.0f, sx, sy);
            MoveToEx(area->DrawDc, x2, y2, 0);
            LineTo(area->DrawDc, x1, y1);

            map->get_point(&x2, &y2, neg_ry2, rz4, 0.0f, sx, sy);
            map->get_point(&x1, &y1, neg_ry2, rz4, rz3, sx, sy);
            MoveToEx(area->DrawDc, x2, y2, 0);
            LineTo(area->DrawDc, x1, y1);

            map->get_point(&x2, &y2, neg_ry2, rz4, local_4, sx, sy);
            map->get_point(&x1, &y1, neg_ry2, rz4, rx1, sx, sy);
            MoveToEx(area->DrawDc, x2, y2, 0);
            LineTo(area->DrawDc, x1, y1);

            map->get_point(&x2, &y2, neg_ry2, neg_ry, 0.0f, sx, sy);
            map->get_point(&x1, &y1, neg_ry2, neg_ry, rz3, sx, sy);
            MoveToEx(area->DrawDc, x2, y2, 0);
            LineTo(area->DrawDc, x1, y1);

            map->get_point(&x2, &y2, neg_ry2, neg_ry, local_4, sx, sy);
            map->get_point(&x1, &y1, neg_ry2, neg_ry, rx1, sx, sy);
            MoveToEx(area->DrawDc, x2, y2, 0);
            LineTo(area->DrawDc, x1, y1);

            map->get_point(&x2, &y2, ry2, rz4, 0.0f, sx, sy);
            map->get_point(&x1, &y1, ry2, rz4, rz3, sx, sy);
            MoveToEx(area->DrawDc, x2, y2, 0);
            LineTo(area->DrawDc, x1, y1);

            map->get_point(&x2, &y2, ry2, rz4, local_4, sx, sy);
            map->get_point(&x1, &y1, ry2, rz4, rx1, sx, sy);
            MoveToEx(area->DrawDc, x2, y2, 0);
            LineTo(area->DrawDc, x1, y1);

            SelectClipRgn(area->DrawDc, 0);
            area->ReleaseDc(0);
        }
        area->Lock(0, 1);
    }
}
