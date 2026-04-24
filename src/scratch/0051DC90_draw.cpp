// first pass reconstructs the three top-level draw paths: refresh image-buffer if stale, blit cached image text when active, otherwise draw directly to the panel DC
// current expectation: field/layout facts are mostly right thanks to the matched ctor/set_rect/get_true_render_rect/handle_idle cluster; remaining drift will likely be string-build and rect-layout code shape

extern "C" int __cdecl sprintf(char* buffer, const char* format, ...);
extern "C" __declspec(dllimport) int __stdcall SelectClipRgn(void* hdc, void* hrgn);
extern "C" __declspec(dllimport) void* __stdcall SelectObject(void* hdc, void* obj);
extern "C" __declspec(dllimport) int __stdcall SetBkMode(void* hdc, int mode);
extern "C" __declspec(dllimport) unsigned int __stdcall SetTextColor(void* hdc, unsigned int color);
extern "C" __declspec(dllimport) int __stdcall DrawTextA(void* hdc, const char* text, int count, void* rect, unsigned int format);
extern "C" __declspec(dllimport) int __stdcall SetRect(void* rect, int left, int top, int right, int bottom);

struct tagRECT {
    int left;
    int top;
    int right;
    int bottom;
};

struct HRGN__;
struct IDirectDrawSurface;
struct TDrawSystem {
    char gap_00[0x3F4];
    void* world_ptr;
};

class TDrawArea {
public:
    TDrawSystem* DrawSystem;
    char gap_04[0x34];
    void* DrawDc;
    IDirectDrawSurface* DrawSurface;
    char gap_40[0x14];
    int Width;
    int Height;

    void* GetDc(char* unused);
    void ReleaseDc(char* unused);
    void SetTrans(int enabled, unsigned char color);
    void Copy(TDrawArea* src, long x, long y, tagRECT* rect, int mode);
};

class WorldLike {
public:
    char gap_00[0x118];
    float game_speed;
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
    int pnl_x;
    int pnl_y;
    int pnl_wid;
    int pnl_hgt;
    char gap_1C[0x04];
    TDrawArea* render_area;
    tagRECT clip_rect;
    int position_mode;
    int need_redraw;
    int field_3C;
    TPanel* parent_panel;
    char gap_44[0x24];
    int field_68;
    int field_6C;
    int field_70;
    char gap_74[0x14];
    void* clip_rgn;
    int fallback_left;
    int fallback_top;
    int fallback_right;
    int fallback_bottom;
    char gap_9C[0x44];
    int draw_depth;
    char gap_E4[0x0F];
    unsigned char need_restore;

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
    char gap_160[0x08];
    int image_text_active;
    long last_ib_width;
    long last_ib_height;

    int render_to_image_buffer();
    void draw();
};

void TRIBE_Panel_Time::draw() {
    if (this->render_area == 0 || this->field_70 == 0 || this->field_6C == 0) {
        return;
    }

    this->draw_depth++;
    this->vf28(0);

    if (this->clock_format == 1) {
        this->display_time = this->current_display_value;
    } else {
        this->display_time = ((this->current_display_value + 4) / 5) * 5;
    }

    if (this->image_buffer != 0) {
        if (this->display_time != (unsigned int)this->old_display_time || this->clock_type != this->old_clock_type || this->clock_format != this->player_id || this->need_restore) {
            this->render_to_image_buffer();
            if (this->need_restore) {
                this->need_restore = 0;
                this->finish_up();
                return;
            }
        }
    }

    if (this->image_text_active != 0 && this->image_buffer != 0) {
        this->image_buffer->SetTrans(1, 1);
        this->image_buffer->Copy(this->render_area, this->used_screen_rect.left, this->used_screen_rect.top, &this->used_image_rect, 1);
        this->image_buffer->SetTrans(0, 1);
        this->finish_up();
        return;
    }

    char str[256];
    void* old_font;
    tagRECT rect;
    int text_flags;

    old_font = this->render_area->GetDc((char*)s_tpnl_tim_draw);
    if (old_font == 0) {
        this->finish_up();
        return;
    }

    SelectClipRgn(this->render_area->DrawDc, this->clip_rgn);
    old_font = SelectObject(this->render_area->DrawDc, this->font);
    SetBkMode(this->render_area->DrawDc, 1);

    if (this->clock_format == 1) {
        unsigned int seconds = this->current_display_value;
        int minutes = 0;
        int hours = 0;
        if ((int)seconds > 0x3B) {
            minutes = seconds / 0x3C;
            seconds = seconds % 0x3C;
            if (minutes > 0x3B) {
                hours = minutes / 0x3C;
                minutes = minutes % 0x3C;
            }
        }
        sprintf(str, s_clock_hms_fmt, hours, minutes, seconds, ((WorldLike*)rge_base_game->world_ptr)->game_speed);
        text_flags = 0x20;
    } else {
        int rounded_time = ((this->current_display_value + 4) / 5) * 5;
        if (this->clock_type == 4) {
            sprintf(str, this->get_string(0x2C25), rounded_time);
        } else if (this->clock_type == 5) {
            sprintf(str, this->get_string(0x2C26), rounded_time);
        } else if (this->clock_type == 6) {
            sprintf(str, this->get_string(0x2C27), rounded_time);
        } else {
            sprintf(str, this->get_string(0x2C24), rounded_time);
        }
        text_flags = 0x22;
    }

    SetTextColor(this->render_area->DrawDc, this->color2);

    {
        int left = this->fallback_left + 1;
        int top = this->fallback_top + 1;
        int right = this->pnl_wid - 2 + left;
        int bottom = this->pnl_hgt - 2 + top;

        SetRect(&rect, left, top, right - 2, bottom - 2);
        DrawTextA(this->render_area->DrawDc, str, -1, &rect, text_flags);
        SetRect(&rect, left, top + 2, right - 2, bottom);
        DrawTextA(this->render_area->DrawDc, str, -1, &rect, text_flags);
        SetRect(&rect, left + 2, top, right, bottom - 2);
        DrawTextA(this->render_area->DrawDc, str, -1, &rect, text_flags);
        SetRect(&rect, left + 2, top + 2, right, bottom);
        DrawTextA(this->render_area->DrawDc, str, -1, &rect, text_flags);

        SetTextColor(this->render_area->DrawDc, this->color1);
        SetRect(&rect, left + 1, top + 1, right - 1, bottom - 1);
        DrawTextA(this->render_area->DrawDc, str, -1, &rect, text_flags);
    }

    SelectObject(this->render_area->DrawDc, old_font);
    SelectClipRgn(this->render_area->DrawDc, 0);
    this->render_area->ReleaseDc((char*)s_tpnl_tim_draw);
    this->finish_up();
}
