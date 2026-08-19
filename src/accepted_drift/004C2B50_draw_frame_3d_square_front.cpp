// Attempt log for 004C2B50 RGE_Static_Object::draw_frame_3d_square_front
// Prior attempts matched the 668-byte size but used an approximate geometry
// surface. The owner, master, and health-bar fields were not canonical.
// Fresh reconstruction: use the period class fields and the neighboring
// square-frame source shape before testing code-generation variants.
// Probe summary: short draw parameters plus direct coordinate mutation now
// reach the best 671B / 83-byte mismatch. Remaining mismatch is the health
// rectangle argument schedule and final padding; calls, frame, and CFG align.
// Probe 15: assign the canonical x outline radius before y, matching the
// neighboring square-frame geometry source order; test the original B0/AC
// load order without changing the typed ownership model.
// Result: geometry prologue now matches through the panel guard; 671B / 100
// bytes, up from 104. The remaining structural hunk is the front-face
// coordinate-offset expression and its 16-bit VC5 scheduling.
// Probe 17: short draw parameters improved the central offset block to 83B;
// direct x/y use preserved it. Unsigned offsets, aliases, cached offsets, and
// alternate health-bar spellings did not improve the clean source.
// The panel clip region is a named field. The prior raw offset expression was
// only a diagnostic form.
// Probe r1: executable y-2..y-1 and x-12..x+12 health rectangles were tested;
// direct forms emitted 674B and did not improve the structural basin.
// Probe r1: int bar-left/bar-bottom bases, declared bottom before left, reduced
// the mismatch to 56B / 670B. The bases are retained as the best clean source.
// Probe r1: x2/y2 output aliases and reused bar bases regressed the CFG or
// stack layout. A six-case health-bar variant lab found no eligible winner.
// Probe r1 final: compound base updates regressed to 64B; restored the 56B
// integer-base form. Calls, frame, and CFG align; final drift is health-bar
// register/opcode scheduling and two bytes of tail size.
// Revisit r2: revalidated the clean source at 670B with 56 differing bytes.
// The Ghidra x2/y2 health-local form regressed to 72B; direct health rectangle
// forms regressed to 88B. Output-local swaps and equivalent arithmetic forms
// duplicated the 56B basin. Restored the pinned typed source for final pause.
// Revisit r3: completed 10 more evidence-led hypotheses before this pause.
// Same-TU mutable short bounds caused a 0x20 frame and 142 differing bytes.
// Unsigned-char FillRect, mutable int bases, long bases, stdlib.h, and the
// combined donor context all duplicated the 670B / 56-byte basin.
// A short denominator caused 674B / 99 bytes. Separate mutable rectangle
// arguments kept 668B but caused 122 bytes and broad block drift.
// The full RGE_Base_Game virtual surface also duplicated the 56-byte basin.
// A 12-case lab found nine variants in the 670B basin and three at 674B.
// No variant passed the size, frame, and call-set gates. The typed source is
// restored and remains the best clean reconstruction.
// ACCEPTED DRIFT: Code through the guarded health tail matches. The first
// rectangle only uses ADD -12 instead of SUB 12. The second rectangle schedules
// private x/y loads and argument pushes around a proved nonfaulting signed
// divide. The positive denominator excludes zero and signed overflow. Both
// calls receive identical bounds, colors, and receivers. Frame, all 22 calls,
// FPU work, memory effects, branches, fault order, and cleanup match. No SEH
// applies. The two extra bytes only change branch displacements and tail size.

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

class RGE_Panel {
public:
    virtual ~RGE_Panel();
    char gap_04[0x84];
    void* clip_region;
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

    void draw_frame_3d_square_front(TDrawArea* area, short x, short y);
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
    TDrawArea* area, short x, short y)
{
    short y1;
    short x1;
    short y2;
    short x2;
    float outline_y;
    float outline_x;
    float radius_z;
    RGE_Panel* panel;

    RGE_Map* map = this->owner->world->map;
    outline_x = this->master_obj->outline_radius_x;
    outline_y = this->master_obj->outline_radius_y;
    radius_z = this->master_obj->radius_z;
    panel = (RGE_Panel*)rge_base_game->get_panel();
    if (panel != 0) {
        area->Unlock(tag);
        x += this->screen_x_offset;
        y += this->screen_y_offset;
        if (area->GetDc(tag) != 0) {
            SelectClipRgn(area->DrawDc, panel->clip_region);
            if (startLoggingAI == 1 &&
                this->groupCommanderValue == this->id && this->id >= 0) {
                SelectObject(area->DrawDc, GetStockObject(7));
            } else {
                SelectObject(area->DrawDc, GetStockObject(6));
            }

            map->get_point(&x1, &y1, -outline_x, -outline_y, 0.0f,
                          x, y);
            map->get_point(&x2, &y2, -outline_x, outline_y, 0.0f,
                          x, y);
            MoveToEx(area->DrawDc, x1, y1, 0);
            LineTo(area->DrawDc, x2, y2);

            map->get_point(&x1, &y1, outline_x, outline_y, 0.0f,
                          x, y);
            map->get_point(&x2, &y2, -outline_x, outline_y, 0.0f,
                          x, y);
            MoveToEx(area->DrawDc, x1, y1, 0);
            LineTo(area->DrawDc, x2, y2);
            SelectClipRgn(area->DrawDc, 0);
            area->ReleaseDc(tag);
        }

        area->Lock(tag, 1);
        int value = (int)this->hp;
        if (value > 0) {
            map->get_point(&x1, &y1, outline_x, -outline_y, radius_z,
                          x, y);
            if (value < 1)
                value = 0;
            int denom = this->master_obj->hp;
            if (denom > 0) {
                int bar_bottom = (-1) + y1;
                int bar_left = (-12) + x1;
                area->FillRect(bar_left, bar_bottom - 1,
                               bar_left + 24, bar_bottom, 0x97);
                int fill_height = (value * 24) / denom;
                int fill_right = fill_height + x1 - 12;
                area->FillRect(x1 - 12, y1 - 2, fill_right,
                               y1 - 1, 0x4a);
            }
        }
    }
}
