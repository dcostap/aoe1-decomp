#ifndef AOE1_PNL_SCR_CONTEXT_H
#define AOE1_PNL_SCR_CONTEXT_H

#include <windows.h>

// Authentic Pnl_scr.cpp context. The PDB class records identify TScreenPanel
// as the 0x478-byte TEasy_Panel derivative. Keep the full period virtual
// surface: slot 0x54 is TPanel/TEasy_Panel::handle_paint.

typedef unsigned char uchar;
typedef unsigned int uint;
typedef unsigned long ulong;
typedef int PositionMode;
typedef int RedrawMode;

typedef char pnl_scr_rect_size_check[(sizeof(tagRECT) == 0x10) ? 1 : -1];

class TDrawSystem;
class TDrawArea;
class TPanel;
class TButtonPanel;
class TTextPanel;
class TInputPanel;
class TEditPanel;
class TDropDownPanel;
class TListPanel;
class TScrollBarPanel;
class TVerticalSliderPanel;
class THorizontalSliderPanel;
class TShape;
class RGE_Color_Table;
class TSpan_List_Manager;
class BITMAPINFO256;
class IDirectDrawSurface;
class IDirectDrawPalette;
class IDirectDrawClipper;
class IDirectDraw;

typedef int FormatType;

struct PanelNode {
    TPanel* panel;
    PanelNode* prev_node;
    PanelNode* next_node;
};

struct _DDCOLORKEY {
    unsigned long dwColorSpaceLowValue;
    unsigned long dwColorSpaceHighValue;
};

struct _DDPIXELFORMAT {
    unsigned long dwSize;
    unsigned long dwFlags;
    unsigned long dwFourCC;
    unsigned long dwRGBBitCount;
    unsigned long dwRBitMask;
    unsigned long dwGBitMask;
    unsigned long dwBBitMask;
    unsigned long dwRGBAlphaBitMask;
};

struct _DDSCAPS {
    unsigned long dwCaps;
};

struct _DDSURFACEDESC {
    unsigned long dwSize;
    unsigned long dwFlags;
    unsigned long dwHeight;
    unsigned long dwWidth;
    long lPitch;
    unsigned long dwBackBufferCount;
    unsigned long dwMipMapCount;
    unsigned long dwAlphaBitDepth;
    unsigned long dwReserved;
    void* lpSurface;
    _DDCOLORKEY ddckCKDestOverlay;
    _DDCOLORKEY ddckCKDestBlt;
    _DDCOLORKEY ddckCKSrcOverlay;
    _DDCOLORKEY ddckCKSrcBlt;
    _DDPIXELFORMAT ddpfPixelFormat;
    _DDSCAPS ddsCaps;
};

typedef _DDSURFACEDESC DDSURFACEDESC;

struct DrawAreaNode {
    TDrawArea* DrawArea;
    DrawAreaNode* PrevNode;
    DrawAreaNode* NextNode;
};

class TDrawSystem {
public:
    void* Inst;
    void* Wnd;
    void* Pal;
    TDrawArea* DrawArea;
    TDrawArea* PrimaryArea;
    DrawAreaNode* DrawAreaList;
    IDirectDraw* DirDraw;
    IDirectDrawSurface* PrimarySurface;
    IDirectDrawClipper* Clipper;
    IDirectDrawPalette* DirDrawPal;
    unsigned long Flags;
    long ScreenWidth;
    long ScreenHeight;
    long ColorBits;
    long ErrorCode;
    long ChangedMode;
    long IsBanked;
    long CanSrcBlt;
    long Restored;
    long ModeAvail640;
    long ModeAvail800;
    long ModeAvail1024;
    long ModeAvail1280;
    long ModeAvail320_200;
    long ModeAvail320_240;
    long ModeAvail320_200_16;
    long ModeAvail320_240_16;
    long ModeAvail640_16;
    long ModeAvail800_16;
    long ModeAvail1024_16;
    PALETTEENTRY palette[256];
    unsigned char DrawType;
    unsigned char ScreenMode;

    void Paint(tagRECT*);
};

typedef char pnl_scr_draw_system_size_check[
    (sizeof(TDrawSystem) == 0x47C) ? 1 : -1];

class TDrawArea {
public:
    TDrawSystem* DrawSystem;
    void* Wnd;
    unsigned char* Bits;
    BITMAPINFO256* BitmapInfo;
    void* Bitmap;
    void* OldBitmap;
    int Width;
    int Height;
    int Pitch;
    int Orien;
    tagRECT ClipRect;
    void* DrawDc;
    IDirectDrawSurface* DrawSurface;
    _DDSURFACEDESC SurfaceDesc;
    DrawAreaNode* Node;
    char* Name;
    unsigned char* LastBits;
    int LastPitch;
    void** DisplayOffsets;
    void** CurDisplayOffsets;
    void** FloatOffsets;
    RGE_Color_Table* shadow_color_table;
    TSpan_List_Manager* SpanList;
    TSpan_List_Manager* CurSpanList;
    int Float_X_Delta;
    int Float_Y_Delta;
    int DisplayOffsetsSz;
    int FloatOffsetsSz;
    int SystemMemOnly;
    int UsingVidMem;
    int UseTrans;
    int IsPrimarySurface;
    int Restored;
    int ExtendedLines;
    unsigned char TransColor;
    unsigned char pad_end[3];

    void GetPalette(PALETTEENTRY*);
    void Clear(tagRECT*, int);
};

typedef char pnl_scr_draw_area_size_check[(sizeof(TDrawArea) == 0x100) ? 1 : -1];

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, uchar);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(uchar);
    virtual void set_active(int);
    virtual void set_positioning(PositionMode, long, long, long, long,
                                 long, long, long, long,
                                 TPanel*, TPanel*, TPanel*, TPanel*);
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
    virtual long wnd_proc(void*, uint, uint, long);
    virtual long handle_idle();
    virtual long handle_size(long, long);
    virtual long handle_paint();
    virtual long handle_key_down(long, short, int, int, int);
    virtual long handle_char(long, short);
    virtual long handle_command(uint, long);
    virtual long handle_user_command(uint, long);
    virtual long handle_timer_command(uint, long);
    virtual long handle_scroll(long, long);
    virtual long handle_mouse_down(uchar, long, long, int, int);
    virtual long handle_mouse_move(long, long, int, int);
    virtual long handle_mouse_up(uchar, long, long, int, int);
    virtual long handle_mouse_dbl_click(uchar, long, long, int, int);
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
    virtual long mouse_right_dbl_click_action(long, long, int, int);
    virtual long key_down_action(long, short, int, int, int);
    virtual long char_action(long, short);
    virtual long action(TPanel*, long, ulong, ulong);
    virtual void get_true_render_rect(tagRECT*);
    virtual int is_inside(long, long);
    virtual void set_focus(int);
    virtual void set_tab_order(TPanel*, TPanel*);
    virtual void set_tab_order(TPanel**, short);
    virtual uchar get_help_info(char**, long*, long, long);
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
    union {
        TDrawArea* render_area;
        TDrawArea* draw_area;
    };
    tagRECT clip_rect;
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
    void* clip_rgn;
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
    int mouse_down_ctrl;
    int mouse_down_shift;
    unsigned long mouse_down_time;
    int error_code;
    int z_order;
    int display_changed_count;
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
};

typedef char pnl_scr_tpanel_size_check[(sizeof(TPanel) == 0xF4) ? 1 : -1];

class TEasy_Panel : public TPanel {
public:
    virtual ~TEasy_Panel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, uchar);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(uchar);
    virtual void set_active(int);
    virtual void set_positioning(PositionMode, long, long, long, long,
                                 long, long, long, long,
                                 TPanel*, TPanel*, TPanel*, TPanel*);
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
    virtual long wnd_proc(void*, uint, uint, long);
    virtual long handle_idle();
    virtual long handle_size(long, long);
    virtual long handle_paint();
    virtual long handle_key_down(long, short, int, int, int);
    virtual long handle_char(long, short);
    virtual long handle_command(uint, long);
    virtual long handle_user_command(uint, long);
    virtual long handle_timer_command(uint, long);
    virtual long handle_scroll(long, long);
    virtual long handle_mouse_down(uchar, long, long, int, int);
    virtual long handle_mouse_move(long, long, int, int);
    virtual long handle_mouse_up(uchar, long, long, int, int);
    virtual long handle_mouse_dbl_click(uchar, long, long, int, int);
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
    virtual long mouse_right_dbl_click_action(long, long, int, int);
    virtual long key_down_action(long, short, int, int, int);
    virtual long char_action(long, short);
    virtual long action(TPanel*, long, ulong, ulong);
    virtual void get_true_render_rect(tagRECT*);
    virtual int is_inside(long, long);
    virtual void set_focus(int);
    virtual void set_tab_order(TPanel*, TPanel*);
    virtual void set_tab_order(TPanel**, short);
    virtual uchar get_help_info(char**, long*, long, long);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void take_snapshot();
    virtual void handle_reactivate();
    virtual void draw_background(int);
    virtual void set_ideal_size(long, long);
    virtual int create_button(TPanel*, TButtonPanel**, long, long, long, long,
                             long, long, long, long, long);
    virtual int create_button(TPanel*, TButtonPanel**, char*, char*, long, long,
                             long, long, long, long, long);
    virtual int create_check_box(TPanel*, TButtonPanel**, long, long, long, long,
                                 long, long);
    virtual int create_radio_button(TPanel*, TButtonPanel**, long, long, long,
                                    long, long, long);
    virtual int create_text(TPanel*, TTextPanel**, int, long, long, long, long,
                            long, int, int, int);
    virtual int create_text(TPanel*, TTextPanel**, char**, long, long, long,
                            long, long, long, int, int);
    virtual int create_text(TPanel*, TTextPanel**, char*, long, long, long,
                            long, long, int, int, int);
    virtual int create_input(TPanel*, TInputPanel**, char*, short, FormatType,
                             long, long, long, long, long);
    virtual int create_edit(TPanel*, TEditPanel**, char*, short, FormatType,
                            long, long, long, long, long, int, int);
    virtual int create_drop_down(TPanel*, TDropDownPanel**, long, long, long,
                                 long, long, long, long);
    virtual int create_list(TPanel*, TListPanel**, long, long, long, long, long);
    virtual int create_scrollbar(TPanel*, TScrollBarPanel**, TTextPanel*, long,
                                 long, long, long, long);
    virtual int create_auto_scrollbar(TScrollBarPanel**, TTextPanel*, long);
    virtual int create_vert_slider(TPanel*, TVerticalSliderPanel**, long, long,
                                  long, long, long, long, long);
    virtual int create_horz_slider(TPanel*, THorizontalSliderPanel**, long, long,
                                  long, long, long, long, long);
    virtual void position_panel(TPanel*, long, long, long, long);

    TEasy_Panel();
    TEasy_Panel(char*);
    long setup(TDrawArea*, TPanel*, char*, long, int, long, long, long, long, int);

    long ideal_width;
    long ideal_height;
    char info_file_name[260];
    long info_id;
    TShape* background_pic;
    TShape* background_pic2;
    union {
        void* palette;
        void* palette_handle;
    };
    char cursor_file[260];
    long cursor_id;
    int background_pos;
    int use_bevels;
    unsigned char bevel_color1;
    unsigned char bevel_color2;
    unsigned char bevel_color3;
    unsigned char bevel_color4;
    unsigned char bevel_color5;
    unsigned char bevel_color6;
    unsigned long text_color1;
    unsigned long text_color2;
    unsigned long focus_color1;
    unsigned long focus_color2;
    unsigned long state_color1;
    unsigned long state_color2;
    char popup_info_file_name[260];
    long popup_info_id;
    TShape* button_pics;
    RGE_Color_Table* shadow_color_table;
    long shadow_amount;
    unsigned char background_color1;
    unsigned char background_color2;
    int enable_ime;
    unsigned char help_mode;
    int stock_brush;
    void* brush;
    unsigned long brush_color;
    TDrawArea* shadow_area;
    int allow_shadow_area;
    int saved_mouse_mode;
};

typedef char pnl_scr_teasy_size_check[(sizeof(TEasy_Panel) == 0x478) ? 1 : -1];

class TScreenPanel : public TEasy_Panel {
public:
    TScreenPanel();
    TScreenPanel(char*);
    virtual ~TScreenPanel();
    long setup(TDrawArea*, char*, long, int);
    long setup(TDrawArea*, char*, long, uchar, int);
    virtual void draw();
    virtual long handle_paint();
    virtual void set_focus(int);
};

typedef char pnl_scr_tscreen_size_check[(sizeof(TScreenPanel) == 0x478) ? 1 : -1];

// Pnl_scr.cpp's private current-screen receiver. It occupies DAT_0086B248
// in the linked image and is not a replacement class or ABI shim.
static TScreenPanel* last_screen;

extern void RGE_fade_palette(TDrawArea*, PALETTEENTRY, float, uchar,
                             PALETTEENTRY*, int, int);

#endif
