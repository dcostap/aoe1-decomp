// Attempt log for 004C2B50 RGE_Static_Object::draw_frame_3d_square_front
// try 1: natural reconstruction from packet/decompiler with local stubs and IAT-style extern pointers; exact size but owner/master swapped and sx/sy narrowed.
// try 2: fix object field order, virtual slot, and use int sx/sy; first mismatch at offset 27 due movsx vs 16-bit add shape.
// try 3: compute sx/sy from int params in separate statements; int params improved but still movsx offset loads.
// try 4: make screen offsets unsigned short; much worse, rolled back.
// try 5: restore signed offsets.
// try 6: /Oy- flag probe; too small 640B, rolled back.
// try 7: /O1 flag probe; too small 640B, rolled back.
// try 8: reviewed draw/get_point ordering; broad structure follows original but register/offset-load basin differs.
// try 9: reviewed final FillRect formulas; behavior likely approximate, not safe for drift.
// try 10: kept best exact-size default build.
// BLOCKER: exact 668B size but broad mismatch from early screen-offset calculation and downstream get_point/FPU scheduling. Original uses partial 16-bit loads into cx/dx then adds to edi/ebx; rebuilt sign-extends offsets before add. Not accepted_drift-safe.

class TDrawArea { public: void* pad[14]; void* DrawDc; void Unlock(char*); void* GetDc(char*); void ReleaseDc(char*); unsigned char Lock(char*, int); void FillRect(long,long,long,long,long); };
class RGE_Map { public: void get_point(short*, short*, float, float, float, short, short); };
class World { public: char pad[0x28]; RGE_Map* map; };
class Owner { public: char pad[0x3c]; World* world; };
class Master { public: char pad[0x38]; float radius_z; char pad3c[0x70]; float outline_radius_x; float outline_radius_y; };
class RGE_Static_Object { public: void* vt; int id; Master* master_obj; Owner* owner; char pad10[0x18]; short screen_x_offset; short screen_y_offset; char pad2c[4]; float frame; char pad34[0x44]; int groupCommanderValue; void draw_frame_3d_square_front(TDrawArea*, int, int); };
class Game { public: virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void* get_panel(); };
extern Game* rge_base_game;
extern int startLoggingAI;
extern "C" int (__stdcall* const SelectClipRgn)(void*, void*);
extern "C" void* (__stdcall* const GetStockObject)(int);
extern "C" void* (__stdcall* const SelectObject)(void*, void*);
extern "C" int (__stdcall* const MoveToEx)(void*, int, int, void*);
extern "C" int (__stdcall* const LineTo)(void*, int, int);
extern "C" long __cdecl _ftol(void);
static char tag[] = "stat_obj::draw_frame_3d_square_front";

void RGE_Static_Object::draw_frame_3d_square_front(TDrawArea* area, int x, int y)
{
    short y1, x1, y2, x2;
    float ry1;
    float rx1;
    float local_10;
    RGE_Static_Object* self;
    float rz2;
    float local_4;
    self = this;
    RGE_Map* map = this->owner->world->map;
    rx1 = this->master_obj->outline_radius_y;
    local_10 = this->master_obj->outline_radius_x;
    local_4 = this->master_obj->radius_z;
    void* panel = rge_base_game->get_panel();
    if (panel) {
        area->Unlock(tag);
        int sx = x;
        int sy = y;
        sx += this->screen_x_offset;
        sy += this->screen_y_offset;
        if (area->GetDc(tag)) {
            SelectClipRgn(area->DrawDc, *(void**)((char*)panel + 0x88));
            if (startLoggingAI == 1 && self->groupCommanderValue == self->id && self->id >= 0)
                SelectObject(area->DrawDc, GetStockObject(7));
            else
                SelectObject(area->DrawDc, GetStockObject(6));
            map->get_point(&x1, &y1, -local_10, -rx1, 0.0f, sx, sy);
            map->get_point(&x2, &y2, -local_10, rx1, 0.0f, sx, sy);
            MoveToEx(area->DrawDc, x1, y1, 0);
            LineTo(area->DrawDc, x2, y2);
            map->get_point(&x1, &y1, local_10, rx1, 0.0f, sx, sy);
            map->get_point(&x2, &y2, -local_10, rx1, 0.0f, sx, sy);
            MoveToEx(area->DrawDc, x1, y1, 0);
            LineTo(area->DrawDc, x2, y2);
            SelectClipRgn(area->DrawDc, 0);
            area->ReleaseDc(tag);
        }
        area->Lock(tag, 1);
        int value = (int)this->frame;
        if (value > 0) {
            map->get_point(&x1, &y1, local_10, -rx1, local_4, sx, sy);
            if (value < 1) value = 0;
            int denom = *(short*)((char*)self->owner + 0x26);
            if (denom > 0) {
                area->FillRect(x1 - 12, y1 - 12 + 24, x1 - 1, y1 - 12 + 24, 0x97);
                area->FillRect(x1 - 12, y1 - 12, ((value * 24) / denom) + x1 - 12, y1 - 1, 0x4a);
            }
        }
    }
}
