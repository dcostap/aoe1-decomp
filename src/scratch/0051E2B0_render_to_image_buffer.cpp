// Fresh typed reconstruction: TDrawArea::PtrClear/SetClipRect, typed image
// rects, direct panel fields, and the ordered GDI calls match the donor family.
// Probe: natural /60 remainder operators introduced idiv and were rolled back.
// Probe: direct quotient and subtraction spelling retained the original magic
// divide, but did not move the quotient into the original ECX basin.
// Probe: named width/height bounds improved the body to 911 bytes and 436
// positional diff bytes. The frame grew to 0x11c and GDI argument stores remain.
// Probe: declaration order, register locals, and width-minus-two spelling were
// duplicates or slightly worse. The clean named-bounds form is retained.
// Probe: UsedScreenRect uses the TPanel render_rect origin, not panel size;
// this is required by the original +8c/+90 reads. Store order was also aligned.
// BLOCKER: original frame is 0x114 with EBP/EBX bounds and EDI flags; current
// typed source uses a 0x11c frame with a different local/register basin.

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

    void PtrClear(tagRECT* rect, int color);
    void* GetDc(char* unused);
    void SetClipRect(tagRECT* rect);
    void ReleaseDc(char* unused);
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
    tagRECT render_rect;
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
    tagRECT image_rect;
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
    int width;
    int height;
    int text_flags;


    if (this->image_buffer == 0) {
        return 0;
    }

    this->image_buffer->PtrClear(&this->image_rect, 1);
    old_font = this->image_buffer->GetDc((char*)s_tpnl_tim_render_to_image_buffer);
    if (old_font == 0) {
        return 0;
    }

    this->image_buffer->SetClipRect(&this->image_rect);
    SelectClipRgn(this->image_buffer->DrawDc, this->image_clip_region);
    old_font = SelectObject(this->image_buffer->DrawDc, this->font);
    SetBkMode(this->image_buffer->DrawDc, 1);

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

    width = this->pnl_wid - 1;
    height = this->pnl_hgt - 1;

    SetRect(&rect, 0, 0, width - 2, height - 2);
    DrawTextA(this->image_buffer->DrawDc, str, -1, &rect, text_flags);
    SetRect(&rect, 0, 2, width - 2, height);
    DrawTextA(this->image_buffer->DrawDc, str, -1, &rect, text_flags);
    SetRect(&rect, 2, 0, width, height - 2);
    DrawTextA(this->image_buffer->DrawDc, str, -1, &rect, text_flags);
    SetRect(&rect, 2, 2, width, height);
    DrawTextA(this->image_buffer->DrawDc, str, -1, &rect, text_flags);

    SetTextColor(this->image_buffer->DrawDc, this->color1);
    --width;
    --height;
    SetRect(&rect, 1, 1, width, height);
    DrawTextA(this->image_buffer->DrawDc, str, -1, &rect, text_flags);

    SelectObject(this->image_buffer->DrawDc, old_font);
    SelectClipRgn(this->image_buffer->DrawDc, 0);
    this->image_buffer->ReleaseDc((char*)s_tpnl_tim_render_to_image_buffer);

    this->used_image_rect.left = 0;
    this->used_image_rect.top = 0;
    this->used_screen_rect.left = this->render_rect.left;
    this->used_screen_rect.top = this->render_rect.top;
    this->used_image_rect.right = this->pnl_wid - 1;
    this->used_image_rect.bottom = this->pnl_hgt - 1;
    this->used_screen_rect.right = this->render_rect.left + this->pnl_wid - 1;
    this->used_screen_rect.bottom = this->render_rect.top + this->pnl_hgt - 1;
    this->old_display_time = this->display_time;
    this->old_clock_type = this->clock_type;
    this->player_id = this->clock_format;
    this->image_text_active = 1;

    return 1;
}
