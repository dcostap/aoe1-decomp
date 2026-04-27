extern "C" int __cdecl sprintf(char* buffer, const char* format, ...);
extern "C" __declspec(dllimport) int __stdcall SelectClipRgn(void* hdc, void* hrgn);
extern "C" __declspec(dllimport) void* __stdcall SelectObject(void* hdc, void* obj);
extern "C" __declspec(dllimport) int __stdcall SetBkMode(void* hdc, int mode);
extern "C" __declspec(dllimport) unsigned int __stdcall SetTextColor(void* hdc, unsigned int color);
extern "C" __declspec(dllimport) int __stdcall DrawTextA(void* hdc, const char* text, int count, void* rect, unsigned int format);
extern "C" __declspec(dllimport) int __stdcall SetRect(void* rect, int left, int top, int right, int bottom);

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

struct HRGN__;

struct WorldLike {
    char gap_00[0x18];
    float game_speed;
};

struct TDrawSystem {
    char gap_00[0x3F4];
    void* world_ptr;
};

class TDrawArea {
public:
    TDrawSystem* DrawSystem;
    char gap_04[0x34];
    void* DrawDc;
    void* DrawSurface;
    char gap_40[0x14];
    long Width;
    long Height;

    void* GetDc(char* unused);
    void ReleaseDc(char* unused);
    void SetTrans(int enabled, unsigned char color);
    void Copy(TDrawArea* src, long x, long y, tagRECT* rect, int mode);
};

class TPanel {
public:
    virtual ~TPanel();
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual long set_redraw(int);
    virtual long handle_idle();
    virtual void vf28(int value);
    virtual void finish_up(void);

    char gap_00[0x08];
    long pnl_x;
    long pnl_y;
    long pnl_wid;
    long pnl_hgt;
    char gap_1C[0x04];
    TDrawArea* render_area;
    char gap_24[0x48];
    int field_6C;
    int field_70;
    char gap_74[0x14];
    void* clip_rgn;
    long fallback_left;
    long fallback_top;
    long fallback_right;
    long fallback_bottom;
    char gap_9C[0x44];
    long draw_depth;
    char gap_E4[0x0F];
    unsigned char field_F3;

    char* get_string(int string_id);
};

extern TDrawSystem* rge_base_game;
extern const char s_tpnl_tim_draw[];
extern const char s_clock_hms_fmt[];

class TRIBE_Panel_Time : public TPanel {
public:
    void* font;
    unsigned int color1;
    unsigned int color2;
    int clock_type;
    int old_clock_type;
    int clock_format;
    int player_id;
    int field_110;
    void* world;
    void* player;
    unsigned int start_real_time;
    unsigned int current_display_value;
    unsigned int last_display_value;
    unsigned int display_time;
    int old_display_time;
    HRGN__* image_clip_region;
    TDrawArea* image_buffer;
    tagRECT image_rect;
    tagRECT used_image_rect;
    tagRECT used_screen_rect;
    int image_text_active;
    long last_ib_width;
    long last_ib_height;

    int render_to_image_buffer();
    void draw();
};

// tried matching type model to set_rect cluster (gap arrays for TPanel); same mismatch at offset 2
// tried direct field access for rect block instead of named locals; still 0x12C vs 0x134
// tried adding explicit draw_depth local declared early; no change
// tried carrying clock_format in ecx across display_time block; no compile change
// tried aligning TDrawArea / TDrawSystem / WorldLike to original asm offsets; fld still at [eax+118h] instead of [edx+18h]
// tried /GX (other tpnl_tim.cpp cluster functions need it); no prolog change
// tried #include <new> (set_rect needs it); no change
// tried function-scope locals (classic C style); no change
// tried separate guard checks; no change
// tried caching this->render_area into pArea; no change
// removed pArea cache again; direct render_area keeps source closer to original guard/reload shape but prolog still pushes all saved regs at entry
// quick probe char str[264] gets desired 0x134 frame but shifts str lea to [esp+44] instead of original [esp+4c]; rolled back
// quick probe unused two-int pad near str did not grow frame and still shifted str layout; rolled back
// pArea cache probe gives 0x130 frame and early EDI render_area guard, worse than direct member access; rolled back
// tried explicit vtable-local + indirect calls to mimic original iStack_114; VC5 cannot express free __thiscall function pointers cleanly, rolled back
// tried dead/volatile stack pad locals; VC5 removed them unless used, no frame change; rolled back
// replaced LocalText with raw str after rect-argument correction; raw str now keeps frame 0x134 and str at [esp+4c]
// adjusted shadow rect SetRect calls to use left/top minus one; this matches original rectangle semantics and vtable spill slot [esp+38]
// moving LocalText declarations after early guards preserves frame/str address but does not affect upfront saved-register pushes, rolled back
// tested small flag additions (/Ow,/Oa,/Og,/Oi,/Gs,/Gf); none fixed saved-register prolog, /Oa even grew frame to 0x138
// variant_lab finish-shape axis found all three finish_up paths as goto finish recovers original shrinkwrapped prolog through first guards; kept it, first mismatch now branch displacement at offset 16
// lab showed partial goto variants do not recover prolog; all three finish paths must share the final label
// follow-up local order/pad probes could not move old_font/vtable spill from [esp+34]/[esp+38] to original [esp+38]/[esp+40] without breaking frame
// current near-match is exact size 1102; first mismatch is early fail-branch target 2 bytes short because rect setup uses lea [ecx+ebx-2] / lea [eax+edi-2] where original used sub/sub/add/add
// tried splitting right/bottom calculation statements plus long/unsigned/const/declare-early variants; VC5 still folded to lea
// random variant_lab over 96 rect_calc/rect_call/tail_nudge/flag combos collapsed to only two groups: current shifted-call family or bad 0x12c direct-call family; no new lead
// exhaustive lifetime/inline lab over named/recompute/inline rect blocks: named/recompute variants stayed in current LEA family; inlining right/bottom destroyed frame to 0x124; no match
// declaration-order lab over top locals, old_font/rect late birth, HMS/rounded_time orders: most variants identical; hms_hours_first only changed an internal group; rounded_preadd overshot tail to +4; no match
// volatile size locals force sub/add but destroy frame/register family; volatile tail read shifts epilogue but adds wrong behavior/too many bytes; rolled back
// tried width/height split with ++left/++top source order; VC5 still folded right/bottom into lea family, no improvement
// tried pointer-to-local size updates; got desired sub/add shape locally but destroyed register allocation and made early fail target much too long; rolled back
// variant_lab 386 rect-local shapes across int/long/unsigned, load order, inc spelling, dec spelling, add order: only two near-match groups, both LEA families; no sub/sub/add/add island
// variant_lab 30 rect+flag shapes across default,/Og-,/Oi-,/Ob0,/Os,/Ot,/O1,/Ox,/GX: no match; nondefault optimizer families break prolog/size badly
// TU-context lab with stdlib/stdio/string/new includes, ctor/dtor declarations, after-target destructor stubs, and /GX: no target-body change; still same LEA family
// tried windows.h/real RECT/HRGN surface instead of local tagRECT/import decls; compiled after HRGN adjustment but target body still same LEA family
// fixed local TRIBE_Panel_Time layout by removing bogus gap before image_text_active; field now sits at original +168 instead of wrong +170
// rect lab over split right/bottom add-assign, load order, plus-equal, long vs int: all collapsed to current LEA family
// volatile rect lab produced distinct larger families but none close; volatile right/bottom also broke frame back to 0x12C
// current near-match is exact target behavior/size except two-byte-short rect setup: VC5 folds original sub/sub/add/add into two LEAs
// BLOCKER: remaining mismatch is codegen-family drift in rect right/bottom calculation, causing early fail branches to target 0051E0D4 instead of 0051E0D6

void TRIBE_Panel_Time::draw() {
    char str[256];
    void* old_font;
    tagRECT rect;
    int text_flags;
    int right, bottom;

    if (this->render_area == 0) return;
    if (this->field_70 == 0) return;
    if (this->field_6C == 0) return;

    this->draw_depth++;
    this->vf28(0);

    if (this->clock_format == 1) {
        this->display_time = this->current_display_value;
    } else {
        this->display_time = ((this->current_display_value + 4) / 5) * 5;
    }

    if (this->image_buffer != 0) {
        if (this->display_time != (unsigned int)this->old_display_time || this->clock_type != this->old_clock_type || this->clock_format != this->player_id || this->field_F3) {
            this->render_to_image_buffer();
            if (this->field_F3) {
                this->field_F3 = 0;
                goto finish;
            }
        }
    }

    if (this->image_text_active != 0 && this->image_buffer != 0) {
        this->image_buffer->SetTrans(1, 1);
        this->image_buffer->Copy(this->render_area, this->used_screen_rect.left, this->used_screen_rect.top, &this->used_image_rect, 1);
        this->image_buffer->SetTrans(0, 1);
        goto finish;
    }

    old_font = this->render_area->GetDc((char*)s_tpnl_tim_draw);
    if (old_font == 0) {
        goto finish;
    }

    SelectClipRgn(this->render_area->DrawDc, this->clip_rgn);
    old_font = SelectObject(this->render_area->DrawDc, this->font);
    SetBkMode(this->render_area->DrawDc, 1);

    if (this->clock_format == 1) {
        int seconds = this->current_display_value;
        int minutes = 0;
        int hours = 0;
        if (seconds > 0x3B) {
            minutes = seconds / 0x3C;
            seconds = seconds - minutes * 0x3C;
            if (minutes > 0x3B) {
                hours = minutes / 0x3C;
                minutes = minutes - hours * 0x3C;
            }
        }
        {
            float gs = *((float*)((char*)rge_base_game->world_ptr + 0x18));
            sprintf(str, s_clock_hms_fmt, hours, minutes, seconds, gs);
        }
        text_flags = 0x20;
    } else {
        int rounded_time = ((this->current_display_value + 4) / 5) * 5;
        switch (this->clock_type) {
        case 4:
            sprintf(str, this->get_string(0x2C25), rounded_time);
            break;
        case 5:
            sprintf(str, this->get_string(0x2C26), rounded_time);
            break;
        case 6:
            sprintf(str, this->get_string(0x2C27), rounded_time);
            break;
        default:
            sprintf(str, this->get_string(0x2C24), rounded_time);
            break;
        }
        text_flags = 0x22;
    }

    SetTextColor(this->render_area->DrawDc, this->color2);

    {
        int left = this->fallback_left;
        int top = this->fallback_top;
        int width = this->pnl_wid;
        int height = this->pnl_hgt;
        ++left;
        ++top;
        width -= 2;
        height -= 2;
        right = width + left;
        bottom = height + top;

        SetRect(&rect, left - 1, top - 1, right - 2, bottom - 2);
        DrawTextA(this->render_area->DrawDc, str, -1, &rect, text_flags);
        SetRect(&rect, left - 1, top + 1, right - 2, bottom);
        DrawTextA(this->render_area->DrawDc, str, -1, &rect, text_flags);
        SetRect(&rect, left + 1, top - 1, right, bottom - 2);
        DrawTextA(this->render_area->DrawDc, str, -1, &rect, text_flags);
        SetRect(&rect, left + 1, top + 1, right, bottom);
        DrawTextA(this->render_area->DrawDc, str, -1, &rect, text_flags);

        SetTextColor(this->render_area->DrawDc, this->color1);
        SetRect(&rect, left, top, right - 1, bottom - 1);
        DrawTextA(this->render_area->DrawDc, str, -1, &rect, text_flags);
    }

    SelectObject(this->render_area->DrawDc, old_font);
    SelectClipRgn(this->render_area->DrawDc, 0);
    this->render_area->ReleaseDc((char*)s_tpnl_tim_draw);
finish:
    this->finish_up();
}
