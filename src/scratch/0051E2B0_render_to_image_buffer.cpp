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
// Probe: direct typed pnl_wid/pnl_hgt bounds restored the 0x114 frame without
// padding, but made VC5 cache GDI imports and expanded the body; rolled back.
// Probe: unsigned int text_flags matched the DrawText format ABI but emitted
// duplicate 0x11c/931-byte code; restored the int local.
// Canonical-context probe: the full TPanel virtual/member surface, the derived
// draw slot, and protected IA ownership changed no emitted bytes; retain them.
// Exact-finish probes: TextStorage aggregates and an old-font/text union did
// not repair the frame or stack homes. A 248-byte buffer reached 0x114/436,
// but the binary local evidence requires char[256] and it is not retained.
// Exact-finish probes: binary-ordered Used-rectangle aliases improved the
// final scheduling basin to 434 bytes, but still required the unsupported
// 248-byte buffer. The PDB-order char[256] source is restored below.
// Managed reassessment: the clean source has 26/26 ordered calls and 8/8 CFG
// signals, but emits 931 bytes, a 0x11c frame, EDI/EBX bounds, and EBP flags;
// the oracle has 916 bytes, a 0x114 frame, EBP/EBX bounds, and EDI flags.
// Managed reassessment: direct bounds removed the extra frame bytes (917 or
// 923 bytes), but changed the quotient basin at +0xbc and raised the diff.
// Twenty source, ABI, layout, lifetime, and context probes found no better
// clean result. Keep the typed source and do not pad the frame.
// Fresh exact pass: windows.h GDI types, GetDc guard lifetime, exact-donor
// declaration order, bound scopes, register spelling, and value reuse were
// codegen duplicates. The centered-bound model grew to 955 bytes and 0x120.
// Fresh exact pass: char[256] with binary-ordered tail locals emitted 923
// bytes and a 0x11c frame. It improved tail shape but did not swap EBP/EDI.
// The two extra bound-argument spills occupy the eight bytes below old_font.
// PDB OWNER NOTE: cvdump and the original symbol table prove
// ?render_to_image_buffer@TRIBE_Panel_Time@@IAEHXZ at 0051E2B0. A Pop-owner
// compile kept the same bytes but failed the owner-symbol check. Do not rename
// this owner to TRIBE_Panel_Pop.
// Specialist finish: declaration order, register locals, canonical RGE world
// types, long bounds, direct member bounds, and the Pop-owner audit were tested.
// The canonical RGE type surface is retained when it emits duplicate bytes.
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

struct RGE_Game_World {
    char gap_00[0x18];
    float game_speed;
};

struct TDrawSystem;

struct RGE_Base_Game {
    char gap_00[0x3F4];
    RGE_Game_World* world;
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

typedef int PositionMode;
typedef int RedrawMode;
struct PanelNode;

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(PositionMode, long, long, long, long, long, long,
                                 long, long, TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(RedrawMode);
    virtual void set_overlapped_redraw(TPanel*, TPanel*, RedrawMode);
    virtual void draw_setup(int);
    virtual void draw_finish();
    virtual void draw();
    virtual void draw_rect(tagRECT*);
    virtual void draw_offset(long, long, tagRECT*);
    virtual void draw_rect2(tagRECT*);
    virtual void draw_offset2(long, long, tagRECT*);
    virtual void paint();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual long handle_idle();
    virtual long handle_size(long, long);
    virtual long handle_paint();
    virtual long handle_key_down(long, short, int, int, int);
    virtual long handle_char(long, short);
    virtual long handle_command(unsigned int, long);
    virtual long handle_user_command(unsigned int, long);
    virtual long handle_timer_command(unsigned int, long);
    virtual long handle_scroll(long, long);
    virtual long handle_mouse_down(unsigned char, long, long, int, int);
    virtual long handle_mouse_move(long, long, int, int);
    virtual long handle_mouse_up(unsigned char, long, long, int, int);
    virtual long handle_mouse_dbl_click(unsigned char, long, long, int, int);
    virtual long mouse_move_action(long, long, int, int);
    virtual long mouse_left_down_action(long, long, int, int);
    virtual long mouse_left_hold_action(long, long, int, int);
    virtual long mouse_left_move_action(long, long, int, int);
    virtual long mouse_left_up_action(long, long, int, int);
    virtual long mouse_left_dbl_click_action(long, long, int, int);
    virtual long mouse_right_down_action(long, long, int, int);
    virtual long mouse_right_hold_action(long, long, int, int);
    virtual long mouse_right_move_action(long, long, int, int);
    virtual long mouse_right_up_action(long, long, int, int);
    virtual long key_down_action(long, short, int, int, int);
    virtual long char_action(long, short);
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual void get_true_render_rect(tagRECT*);
    virtual int is_inside(long, long);
    virtual void set_focus(int);
    virtual void set_tab_order(TPanel*, TPanel*);
    virtual void set_tab_order(TPanel**, short);
    virtual unsigned char get_help_info(char**, long*, long, long);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void take_snapshot();
    virtual void handle_reactivate();

    TPanel* previousPanelValue;
    TPanel* previousModalPanelValue;
    long pnl_x;
    long pnl_y;
    long pnl_wid;
    long pnl_hgt;
    char* panelNameValue;
    TDrawArea* render_area;
    int clip_left;
    int clip_top;
    int clip_right;
    int clip_bottom;
    PositionMode position_mode;
    RedrawMode need_redraw;
    TPanel* curr_child;
    TPanel* parent_panel;
    TPanel* left_panel;
    TPanel* top_panel;
    TPanel* right_panel;
    TPanel* bottom_panel;
    PanelNode* node;
    PanelNode* first_child_node;
    PanelNode* last_child_node;
    TPanel* tab_prev_panel;
    TPanel* tab_next_panel;
    int mouse_captured;
    int active;
    int visible;
    int tab_stop;
    int have_focus;
    int overlapping_children;
    int handle_mouse_input;
    int just_drawn;
    HRGN__* clip_rgn;
    tagRECT render_rect;
    long left_border;
    long top_border;
    long right_border;
    long bottom_border;
    long min_wid;
    long max_wid;
    long min_hgt;
    long max_hgt;
    long mouse_hold_interval;
    long mouse_move_tolerance;
    long mouse_down_x;
    long mouse_down_y;
    long mouse_down_ctrl;
    long mouse_down_shift;
    unsigned long mouse_down_time;
    long error_code;
    long z_order;
    long display_changed_count;
    long help_string_id;
    long help_page_id;
    unsigned char mouse_action;
    unsigned char mouse_down_button;
    unsigned char panel_type;
    unsigned char color;
    unsigned char fill_in_background;
    unsigned char clip_to_parent;
    unsigned char draw_rect2_flag;
    unsigned char need_restore;

    char* get_string(int string_id);
};

extern RGE_Base_Game* rge_base_game;
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
    int old_clock_format;
    int player_id;
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

    virtual void draw();

protected:
    int render_to_image_buffer();
};

int TRIBE_Panel_Time::render_to_image_buffer() {
    void* old_font;
    char str[256];
    tagRECT rect;
    long width;
    long height;
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
        sprintf(str, s_clock_hms_fmt, hours, minutes, seconds, rge_base_game->world->game_speed);
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
    this->old_clock_format = this->clock_format;
    this->image_text_active = 1;

    return 1;
}
