// tried default flags (no /GX); 880 bytes, 38 diff regions
// tried /GX (other tpnl_tim.cpp cluster functions need it); 896 bytes, still diff regions
// tried SetTrans param order swap; push order matches but register choice still EAX vs EDI
// tried context local variable; no size change
// tried s_tpnl_tim_render as class member; worse, restored extern string
// found missing TDrawArea::SetClip(&image_rect) call before GDI SelectClipRgn; kept it
// changed clock formatting to signed seconds and explicit remainder arithmetic; removed idiv basin
// switched type-string ladder to switch; recovered original sub/dec compare chain
// current near-match is 912 vs 916 bytes; first mismatch is the first /60 quotient register shape in the HH:MM:SS path
// variant_lab hms axis (direct/tmp/reordered/long/cast/volatile) collapsed to same 912-byte family except unsigned/idiv and volatile stack-growth variants
// variant_lab /GX and small opt toggles: /GX no effect; /Og- destroys prolog; /Ot-/Ob0 no useful change
// variant_lab game-speed/sprintf call topology (inline, flag-first, named float/world/system) still same first mismatch
// variant_lab image_buffer function-local cache is much worse (832 bytes, early ECX/EDI mismatch); keep direct member access
// variant_lab include context (<stdlib.h>, <new>) no codegen change; <windows.h> conflicts with local imports
// variant_lab remainder spellings mostly same; explicit shift remainder is worse/too long
// tried Ghidra-style old_font overlay in str[0..3] with sprintf/DrawText on str+4; no quotient/register improvement, rolled back
// tried assign-in-if and modulo/rem-after-cmp variants; either dropped required remainder-before-compare shape or introduced idiv/wrong behavior, rolled back
// tested /Oa briefly: it produces the desired ECX quotient family but collapses function to 848 bytes and is not a viable flag fix
// BLOCKER: render_to_image_buffer wants quotient formed in ECX (mov ecx,edx/add ecx,edi/...), current source keeps the shorter EDX quotient family

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
    void SetClip(tagRECT* rect);
    void ReleaseDc(char* unused);
    void SetTrans(void* context, int enabled);
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
extern const char s_tpnl_tim_render_to_image_buffer[];
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
    char gap_138[0x10];
    tagRECT used_image_rect;
    tagRECT used_screen_rect;
    int image_text_active;
    long last_ib_width;
    long last_ib_height;

    int render_to_image_buffer();
};

int TRIBE_Panel_Time::render_to_image_buffer() {
    char str[256];
    void* old_font;
    tagRECT rect;
    int text_flags;


    if (this->image_buffer == 0) {
        return 0;
    }

    this->image_buffer->SetTrans(&this->gap_138, 1);
    old_font = this->image_buffer->GetDc((char*)s_tpnl_tim_render_to_image_buffer);
    if (old_font == 0) {
        return 0;
    }

    this->image_buffer->SetClip((tagRECT*)&this->gap_138);
    SelectClipRgn(this->image_buffer->DrawDc, this->image_clip_region);
    old_font = SelectObject(this->image_buffer->DrawDc, this->font);
    SetBkMode(this->image_buffer->DrawDc, 1);

    if (this->clock_format == 1) {
        int seconds = this->current_display_value;
        int minutes = 0;
        int hours = 0;
        if (seconds > 0x3B) {
            int quotient = seconds / 0x3C;
            minutes = quotient;
            seconds = seconds + quotient * -0x3C;
            if (minutes > 0x3B) {
                quotient = minutes / 0x3C;
                hours = quotient;
                minutes = minutes + quotient * -0x3C;
            }
        }
        sprintf(str, s_clock_hms_fmt, hours, minutes, seconds, ((WorldLike*)rge_base_game->world_ptr)->game_speed);
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

    SetTextColor(this->image_buffer->DrawDc, this->color2);

    SetRect(&rect, 0, 0, this->pnl_wid - 3, this->pnl_hgt - 3);
    DrawTextA(this->image_buffer->DrawDc, str, -1, &rect, text_flags);
    SetRect(&rect, 0, 2, this->pnl_wid - 3, this->pnl_hgt - 1);
    DrawTextA(this->image_buffer->DrawDc, str, -1, &rect, text_flags);
    SetRect(&rect, 2, 0, this->pnl_wid - 1, this->pnl_hgt - 3);
    DrawTextA(this->image_buffer->DrawDc, str, -1, &rect, text_flags);
    SetRect(&rect, 2, 2, this->pnl_wid - 1, this->pnl_hgt - 1);
    DrawTextA(this->image_buffer->DrawDc, str, -1, &rect, text_flags);

    SetTextColor(this->image_buffer->DrawDc, this->color1);
    SetRect(&rect, 1, 1, this->pnl_wid - 2, this->pnl_hgt - 2);
    DrawTextA(this->image_buffer->DrawDc, str, -1, &rect, text_flags);

    SelectObject(this->image_buffer->DrawDc, old_font);
    SelectClipRgn(this->image_buffer->DrawDc, 0);
    this->image_buffer->ReleaseDc((char*)s_tpnl_tim_render_to_image_buffer);

    this->used_image_rect.left = 0;
    this->used_image_rect.top = 0;
    this->used_image_rect.right = this->pnl_wid - 1;
    this->used_image_rect.bottom = this->pnl_hgt - 1;
    this->used_screen_rect.left = this->pnl_wid;
    this->used_screen_rect.top = this->pnl_hgt;
    this->used_screen_rect.right = this->pnl_wid - 1;
    this->used_screen_rect.bottom = this->pnl_hgt - 1;
    this->old_display_time = this->display_time;
    this->old_clock_type = this->clock_type;
    this->player_id = this->clock_format;
    this->image_text_active = 1;

    return 1;
}
