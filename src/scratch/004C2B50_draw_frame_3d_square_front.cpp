// Attempt log for 004C2B50 RGE_Static_Object::draw_frame_3d_square_front
// Prior attempts matched the 668-byte size but used an approximate geometry
// surface. The owner, master, and health-bar fields were not canonical.
// Fresh reconstruction: use the period class fields and the neighboring
// square-frame source shape before testing code-generation variants.
// Probe summary: int draw parameters plus short get_point coordinates and
// parameter mutation reached the best 671B / 104-byte mismatch. The ABI-clean
// short-parameter form widened the result to 675B / 552 bytes and was rolled
// back. Remaining mismatch starts in VC5 geometry-load order and register
// allocation; calls, frame, CFG, and the central draw block are aligned.
// Probe 15: assign the canonical x outline radius before y, matching the
// neighboring square-frame geometry source order; test the original B0/AC
// load order without changing the typed ownership model.
// Result: geometry prologue now matches through the panel guard; 671B / 100
// bytes, up from 104. The remaining structural hunk is the front-face
// coordinate-offset expression and its 16-bit VC5 scheduling.

class TDrawArea {
public:
    char gap_00[0x38];
    void* DrawDc;
    void Unlock(char* tag);
    void* GetDc(char* tag);
    void ReleaseDc(char* tag);
    unsigned char Lock(char* tag, int wait);
    void FillRect(long left, long top, long right, long bottom, long color);
};

class RGE_Map {
public:
    void get_point(short* out_x, short* out_y, float x, float y, float z,
                   short screen_x, short screen_y);
};

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

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x22];
    short hp;
    float los;
    char gap_2c[4];
    float radius_x;
    float radius_y;
    float radius_z;
    char gap_3c[0x70];
    float outline_radius_x;
    float outline_radius_y;
    float outline_radius_z;
};

class RGE_Base_Game {
public:
    virtual void f00();
    virtual void f04();
    virtual void f08();
    virtual void f0c();
    virtual void f10();
    virtual void f14();
    virtual void f18();
    virtual void f1c();
    virtual void f20();
    virtual void f24();
    virtual void f28();
    virtual void* get_panel();
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x18];
    short screen_x_offset;
    short screen_y_offset;
    char gap_2c[4];
    float hp;
    char gap_34[0x44];
    int groupCommanderValue;

    void draw_frame_3d_square_front(TDrawArea* area, int x, int y);
};

extern RGE_Base_Game* rge_base_game;
extern int startLoggingAI;

extern "C" int (__stdcall* const SelectClipRgn)(void*, void*);
extern "C" void* (__stdcall* const GetStockObject)(int);
extern "C" void* (__stdcall* const SelectObject)(void*, void*);
extern "C" int (__stdcall* const MoveToEx)(void*, int, int, void*);
extern "C" int (__stdcall* const LineTo)(void*, int, int);

static char tag[] = "stat_obj::draw_frame_3d_square_front";

void RGE_Static_Object::draw_frame_3d_square_front(
    TDrawArea* area, int x, int y)
{
    short y1;
    short x1;
    short y2;
    short x2;
    float outline_y;
    float outline_x;
    float radius_z;
    void* panel;
    short screen_x;
    short screen_y;

    RGE_Map* map = this->owner->world->map;
    outline_x = this->master_obj->outline_radius_x;
    outline_y = this->master_obj->outline_radius_y;
    radius_z = this->master_obj->radius_z;
    panel = rge_base_game->get_panel();
    if (panel != 0) {
        area->Unlock(tag);
        x += this->screen_x_offset;
        y += this->screen_y_offset;
        screen_x = x;
        screen_y = y;
        if (area->GetDc(tag) != 0) {
            SelectClipRgn(area->DrawDc, *(void**)((char*)panel + 0x88));
            if (startLoggingAI == 1 &&
                this->groupCommanderValue == this->id && this->id >= 0) {
                SelectObject(area->DrawDc, GetStockObject(7));
            } else {
                SelectObject(area->DrawDc, GetStockObject(6));
            }

            map->get_point(&x1, &y1, -outline_x, -outline_y, 0.0f,
                          screen_x, screen_y);
            map->get_point(&x2, &y2, -outline_x, outline_y, 0.0f,
                          screen_x, screen_y);
            MoveToEx(area->DrawDc, x1, y1, 0);
            LineTo(area->DrawDc, x2, y2);

            map->get_point(&x1, &y1, outline_x, outline_y, 0.0f,
                          screen_x, screen_y);
            map->get_point(&x2, &y2, -outline_x, outline_y, 0.0f,
                          screen_x, screen_y);
            MoveToEx(area->DrawDc, x1, y1, 0);
            LineTo(area->DrawDc, x2, y2);
            SelectClipRgn(area->DrawDc, 0);
            area->ReleaseDc(tag);
        }

        area->Lock(tag, 1);
        int value = (int)this->hp;
        if (value > 0) {
            map->get_point(&x1, &y1, outline_x, -outline_y, radius_z,
                          screen_x, screen_y);
            if (value < 1)
                value = 0;
            int denom = this->master_obj->hp;
            if (denom > 0) {
                area->FillRect(x1 - 12, y1 - 12 + 24, x1 - 1,
                               y1 - 12 + 24, 0x97);
                area->FillRect(x1 - 12, y1 - 12,
                               ((value * 24) / denom) + x1 - 12,
                               y1 - 1, 0x4a);
            }
        }
    }
}
