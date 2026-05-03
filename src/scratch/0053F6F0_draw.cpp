// 0053F6F0 RGE_Main_View::draw (vw_main.cpp:1310-1352, 260B)
// Virtual draw method with debug timing/display-logging wrapper.
//
// Attempt log:
// - Remaining diff is instruction scheduling within basic blocks (~16% edit diff):
//   * xor eax,eax before byte load: orig has it (33 c0), rebuilt does mov al directly
//   * vtable in edi vs ebx (same-size register choice)
//   * lea ecx,[esi+24h] vs mov al,[esi+0EFh] instruction order swapped
//   * sub esi,ebp (ae = at2-at) scheduled before vs after debug_timeGetTime call
//   * All behaviors and 260-byte size are correct
// - Tried: d10 returning int instead of void (no change to xor)
// - Tried: explicit unsigned char temp variable (added push ecx frame slot)
// - Tried: explicit pointer local for clip_rect (no change)
// - Tried: reordering computation (ac2-ae split) — corrects timing computation order
// - Registers: ebx=start, ebp=at, esi=this (matches original allocation)
// - Suggest variant_lab for remaining instruction scheduling tweaks

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

// TPanel Base with dummy virtuals to provide slots 0-11
struct TPanel_Base {
    virtual void d0() {}
    virtual void d1() {}
    virtual void d2() {}
    virtual void d3() {}
    virtual void d4() {}
    virtual void d5() {}
    virtual void d6() {}
    virtual void d7() {}
    virtual void d8() {}
    virtual void d9() {}
    virtual int d10(int a) { return 0; }
    virtual void d11() {}
    char gap_04[0x20 - 4];
    /* +0x20 */ void* render_area;
    /* +0x24 */ tagRECT clip_rect;
    char gap_34[0xEF - 0x34];
    /* +0xEF */ unsigned char color;
    char gap_F0[0xF4 - 0xF0];
};

// RGE_View extends TPanel: +0xFC = world, +0x100 = player
struct RGE_View_Base : TPanel_Base {
    char gap_F4[0xFC - 0xF4];
    /* +0xFC */ void* world;
    /* +0x100 */ void* player;
    void draw();
};

struct RGE_Main_View : RGE_View_Base {
    void draw();
};

struct TDrawArea_Local {
    char gap_00[0x20];
    void Clear(tagRECT* rect, unsigned char color);
};

// External functions
extern "C" unsigned long __cdecl debug_timeGetTime(char* file, int line);
extern void __cdecl write_draw_log2(char* text);
extern void __cdecl color_log(unsigned char a, unsigned char b, int c);

// RGE_Base_Game
struct RGE_Base_Game {
    char gap_00[0x528];
    unsigned long get_accum_time(int i);
    void add_to_timing(int index, unsigned long value);
    void increment_view_update_count();
};

extern RGE_Base_Game* rge_base_game;
extern int do_draw_log;

void RGE_Main_View::draw() {
    unsigned long start;
    unsigned long at;
    unsigned long ae;
    unsigned long et;
    unsigned long ac2;

    start = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\vw_main.cpp", 0x522);
    at = rge_base_game->get_accum_time(0xB);

    if (world != 0 && player != 0) {
        if (do_draw_log != 0) {
            write_draw_log2("<vs>");
        }
        color_log(0x4C, 0x4C, 1);
        RGE_View_Base::draw();
        color_log(0x4C, 0x5F, 1);
        if (do_draw_log != 0) {
            write_draw_log2("<vf>\n");
        }
    } else {
        d10(0);
        ((TDrawArea_Local*)render_area)->Clear(&clip_rect, color);
        d11();
    }

    ac2 = rge_base_game->get_accum_time(0xB);
    et = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\vw_main.cpp", 0x542);
    ae = ac2 - at;
    rge_base_game->add_to_timing(6, (et - start) - ae);
    rge_base_game->increment_view_update_count();
    rge_base_game->add_to_timing(0xC, ae);
}
