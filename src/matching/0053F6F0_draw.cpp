// 0053F6F0 RGE_Main_View::draw (vw_main.cpp:1310-1352, 260B)
// Virtual draw method with debug timing/display-logging wrapper.
//
// Attempt log:
// - Baseline had exact size/call/CFG parity but one fallback clear block lacked
//   the original byte-to-int promotion sequence, and computed elapsed time too
//   late. The canonical source now reuses the accumulator local for elapsed time.
// - Separate elapsed locals left the subtraction in EAX; reusing ac2 in place
//   (`ac2 -= at`) restored the original ESI live range and timing topology.
// - TDrawArea::Clear takes int, matching promotion of the unsigned-char panel
//   color and restoring the original `xor eax,eax; lea; mov al` sequence.
// - The fallback calls use the period TPanel draw_setup/draw_finish slots; the
//   remaining virtual declarations are padding for the proven ABI surface.
// - Grouped owner fix: qualify the fallback render area and clip rectangle
//   through TPanel. This keeps the panel-owned fields after shared inclusion.
// - Natural full TPanel/RGE_View declarations were codegen-duplicate except for
//   a two-byte post-call subtraction-order drift, so the minimal exact ABI stub
//   below is retained as the smallest exact source surface.

#ifndef RGE_MAIN_VIEW_SHARED_CONTEXT
struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

// TPanel virtual prefix; draw_setup/draw_finish are +0x28/+0x2C.
struct TPanel {
    virtual ~TPanel();
    virtual void setup() {}
    virtual void set_rect() {}
    virtual void set_rect_coords() {}
    virtual void set_color() {}
    virtual void set_active() {}
    virtual void set_positioning() {}
    virtual void set_fixed_position() {}
    virtual void set_redraw() {}
    virtual void set_overlapped_redraw() {}
    virtual void draw_setup(int) {}
    virtual void draw_finish() {}
    char gap_04[0x20 - 4];
    /* +0x20 */ void* render_area;
    /* +0x24 */ tagRECT clip_rect;
    char gap_34[0xEF - 0x34];
    /* +0xEF */ unsigned char color;
    char gap_F0[0xF4 - 0xF0];
};

// RGE_View extends TPanel: +0xFC = world, +0x100 = player
struct RGE_View : TPanel {
    char gap_F4[0xFC - 0xF4];
    /* +0xFC */ void* world;
    /* +0x100 */ void* player;
    virtual void draw();
};

struct RGE_Main_View : RGE_View {
    void draw();
};

struct TDrawArea_Local {
    char gap_00[0x20];
    void Clear(tagRECT* rect, int color);
};

// External functions
extern "C" unsigned long __cdecl debug_timeGetTime(char* file, int line);
extern void __cdecl write_draw_log2(char* text);
extern void __cdecl color_log(unsigned char a, unsigned char b, int c);

// RGE_Base_Game
struct RGE_Base_Game {
    virtual ~RGE_Base_Game();
    char gap_04[0x524];
    unsigned long get_accum_time(int i);
    void add_to_timing(int index, unsigned long value);
    void increment_view_update_count();
};
#endif

extern RGE_Base_Game* rge_base_game;
extern int do_draw_log;

// Main-agent audit restored canonical destructor/named TPanel slots and the
// base-game polymorphic surface; emitted code remains exact.

void RGE_Main_View::draw() {
    unsigned long start;
    unsigned long at;
    unsigned long et;
    unsigned long ac2;

    start = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\vw_main.cpp", 0x522);
    at = rge_base_game->get_accum_time(0xB);

    if (world != 0 && player != 0) {
        if (do_draw_log != 0) {
            write_draw_log2("<vs>");
        }
        color_log(0x4C, 0x4C, 1);
        RGE_View::draw();
        color_log(0x4C, 0x5F, 1);
        if (do_draw_log != 0) {
            write_draw_log2("<vf>\n");
        }
    } else {
        draw_setup(0);
        ((TDrawArea_Local*)this->TPanel::render_area)->Clear(
            &this->TPanel::clip_rect, color);
        draw_finish();
    }

    ac2 = rge_base_game->get_accum_time(0xB);
    ac2 -= at;
    et = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\vw_main.cpp", 0x542);
    rge_base_game->add_to_timing(6, (et - start) - ac2);
    rge_base_game->increment_view_update_count();
    rge_base_game->add_to_timing(0xC, ac2);
}
