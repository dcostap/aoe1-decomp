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
    char gap_00[0x3C];
    RGE_Game_World* world;
};

class TDrawArea {
public:
    char gap_00[0x38];
    void* DrawDc;
    void Unlock(char* tag);
    void* GetDc(char* tag);
    void ReleaseDc(char* tag);
    unsigned char* Lock(char* tag, int flag);
};

class RGE_Map {
public:
    void get_point(short* out_x, short* out_y, float rx, float ry, float rz,
                   int sx, int sy);
};

class RGE_Game {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual char* show_map();
};

class MasterObject {
public:
    char pad_00[0xAC];
    float radius_x;
    float radius_y;
};

extern RGE_Game* rge_base_game;

class RGE_Static_Object {
public:
    virtual void v00();
    long id;
    MasterObject* master_obj;
    RGE_Player* owner;
    char pad_10[0x18];
    short screen_x;
    short screen_y;
    char pad_2c[0x4C];
    long selected_id;

    void draw_frame_3d_square_back(TDrawArea* area, short x, short y);
};

void RGE_Static_Object::draw_frame_3d_square_back(TDrawArea* area, short x, short y)
{
    RGE_Map* map;
    float fVar1;
    void* view;
    int sx;
    int sy;
    short y1;
    short x1;
    short y2;
    short x2;
    float rx1;
    float ry1;
    float local_4;

    map = this->owner->world->map;
    ry1 = this->master_obj->radius_x;
    local_4 = this->master_obj->radius_y;
    view = rge_base_game->show_map();
    if (view != 0) {
        area->Unlock((char*)0x5871A4);
        if (area->GetDc((char*)0x5871A4) != 0) {
            SelectClipRgn(area->DrawDc, *(void**)((char*)view + 0x88));
            if (dword_0062C50C == 1 &&
                this->selected_id == this->id && this->id >= 0) {
                SelectObject(area->DrawDc, GetStockObject(7));
            } else {
                SelectObject(area->DrawDc, GetStockObject(6));
            }

            fVar1 = -local_4;
            sy = y + this->screen_y;
            sx = x + this->screen_x;
            map->get_point(&x2, &y2, ry1, fVar1, 0.0f, sx, sy);
            map->get_point((short*)((char*)&rx1 + 2),
                          (short*)&rx1, ry1, local_4, 0.0f, sx, sy);
            MoveToEx(area->DrawDc, x2, y2, 0);
            LineTo(area->DrawDc, ((short*)((char*)&rx1 + 2))[0],
                   ((short*)&rx1)[0]);
            map->get_point(&x2, &y2, ry1, fVar1, 0.0f, sx, sy);
            map->get_point((short*)((char*)&rx1 + 2),
                          (short*)&rx1, -ry1, fVar1, 0.0f, sx, sy);
            MoveToEx(area->DrawDc, x2, y2, 0);
            LineTo(area->DrawDc, ((short*)((char*)&rx1 + 2))[0],
                   ((short*)&rx1)[0]);
            SelectClipRgn(area->DrawDc, 0);
            area->ReleaseDc((char*)0x5871A4);
        }
        area->Lock((char*)0x5871A4, 1);
    }
}
