// 004C2970 RGE_Static_Object::draw_frame_3d_square_back
// Attempt log:
// 1: Natural reconstruction from packet: unlock/getdc, GDI pen/draw, map get_point corner projections, relock.
// 2: Reordered map/radius loads and introduced draw_area local: still broad mismatch from early ESI save.
// 3: Tried /Ob0 (no change), /O1 (too-small 457-byte text), /Od (83.65% broad mismatch); removed flags.
// 4: Reshape as positive visible block to try delaying ESI save: first mismatch moved earlier, no real fix.
// 5: BLOCKER: Behavior is approximate and GDI/map call set is mostly identified, but source/register topology is wrong from prologue. Original saves only EBX/EBP/EDI, performs owner/map and master radius loads plus `rge_base_game->show_map`, then saves ESI only after the visible check. Current VC5 saves ESI in the prologue (or shifts the first conditional), changing stack offsets and causing broad cascade. Need recover delayed-area-local lifetime and exact short local layout (`ry1`, temp, x/y shorts) before fine-tuning corner coordinate calls.

extern int dword_0062C50C;
extern void* rge_base_game;
extern "C" void* __stdcall SelectObject(void* hdc, void* obj);
extern "C" void* __stdcall GetStockObject(int id);
extern "C" int __stdcall MoveToEx(void* hdc, int x, int y, void* pt);
extern "C" int __stdcall LineTo(void* hdc, int x, int y);

class TDrawArea {
public:
    char pad_00[0x38];
    void* hdc;
    void Unlock(char* tag);
    int GetDc(char* tag);
    void ReleaseDc(char* tag);
    int Lock(char* tag, int flag);
};

class RGE_Map {
public:
    void get_point(short* out_x, short* out_y, float rx, float ry, float rz, int sx, int sy);
};

class RGE_Player { public: char pad_00[0x28]; RGE_Map* map; };
class RGE_Game { public: virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0c(); virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c(); virtual void v20(); virtual void v24(); virtual void v28(); virtual char* show_map(); };
class MasterObject { public: char pad_00[0xac]; float radius_x; float radius_y; };

class RGE_Static_Object {
public:
    virtual void v00();
    int id;
    MasterObject* master_obj;
    RGE_Player* owner;
    char pad_10[0x18];
    short screen_x;
    short screen_y;
    char pad_2c[0x4c];
    int selected_id;

    void draw_frame_3d_square_back(TDrawArea* area, short x, short y);
};

void RGE_Static_Object::draw_frame_3d_square_back(TDrawArea* area, short x, short y)
{
    RGE_Map* map = this->owner->map;
    float ry = this->master_obj->radius_x;
    float rx = this->master_obj->radius_y;
    char* view = ((RGE_Game*)rge_base_game)->show_map();
    if (view != 0) {
    TDrawArea* draw_area = area;
    draw_area->Unlock((char*)0x5871A4);
    if (draw_area->GetDc((char*)0x5871A4) == 0) {
        draw_area->Lock((char*)0x5871A4, 1);
        return;
    }

    SelectObject(draw_area->hdc, *(void**)(view + 0x88));
    if (dword_0062C50C == 1 && this->selected_id == this->id && this->id >= 0) {
        SelectObject(draw_area->hdc, GetStockObject(7));
    } else {
        SelectObject(draw_area->hdc, GetStockObject(6));
    }

    short x1, y1, x2, y2;
    float neg = -rx;
    int sx = x + this->screen_x;
    int sy = y + this->screen_y;
    map->get_point(&x1, &y1, neg, ry, 0.0f, sx, sy);
    map->get_point(&x2, &y2, rx, ry, 0.0f, sx, sy);
    MoveToEx(draw_area->hdc, x1, y1, 0);
    LineTo(draw_area->hdc, x2, y2);
    map->get_point(&x1, &y1, neg, -ry, 0.0f, sx, sy);
    map->get_point(&x2, &y2, rx, -ry, 0.0f, sx, sy);
    MoveToEx(draw_area->hdc, x1, y2, 0);
    LineTo(draw_area->hdc, x2, y2);
    SelectObject(draw_area->hdc, 0);
    draw_area->ReleaseDc((char*)0x5871A4);
    draw_area->Lock((char*)0x5871A4, 1);
    }
}
