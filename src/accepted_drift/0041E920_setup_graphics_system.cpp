// VA: 0041E920 RGE_Base_Game::setup_graphics_system (672 B)
// PDB source: basegame.cpp, lines 2294-2377
//
// Attempt log:
// baseline: packet-grounded free-function shims had the right broad behavior,
//   but no EH frame, imported Win32 calls, or typed member-call identities.
// probe 2 (behavior): restored the period typed RGE_Base_Game/RGE_Prog_Info,
//   TDrawSystem, TDrawArea, and TPanelSystem ownership, the real new-expression,
//   and the executable's fourth-mode probe bug.  The mode/fallback source stays
//   direct-member and naturally typed; exact metrics are recorded by the session.
// probe 3 (layout): int draw_type/draw_mode worsened the register basin; rolled back.
// probe 5 (control-flow): converging the 1280 rejection and Init failure through
//   one natural init_fail tail reduced the candidate from 719 to 678 bytes.
// probes 6-9 (liveness/layout/variant): split boolean increments, declaration
//   order, and operand-order variants were duplicates or farther; retained the
//   simple byte locals and combined `(condition != 0) + 1` form.
// probe 10 (variant lab): the lab's default-flag variants lacked /GX and were
//   rejected by size/frame gates; no generated variant was adopted.
// probes 11-12 (context/liveness): full base-game virtual declarations and
//   post-guard local scope were codegen duplicates.  Best current result is
//   678 bytes (+6), all 16 ordered calls aligned, with only the early boolean
//   materialization hunk unresolved (original full-register `inc` versus VC5's
//   byte `inc` plus zeroing).  Left in scratch as clean typed source.
// probe 17 (layout): changed the two byte mode locals to period-plausible
//   signed `char` declarations, matching the packet's byte stores.  VC5 emitted
//   identical code; retained the signed-byte source with the same unresolved
//   allocation hunk.
// probe 14 (control-flow): replaced the goto-based mode fallback with a natural
//   else-if chain and direct failure tail; emitted code was byte-identical, so
//   restored the clean typed source.  The first divergence remains allocation
//   setup at +006D, not a graphics call or fallback CFG issue.
// probe 19 (layout): removed the mode locals and passed direct predicates to Init;
//   lost the EH frame and fell to 650 bytes (diff 610), so restored.
// probe 21 (layout): cached raw use_dir_draw/use_sys_mem values and converted them
//   at Init; shape improved but the first hunk stayed at +006D (676 bytes, diff 536).
// probe 23 (layout): followed the decompiler's raw iVar2/iVar3/iVar5 cache through
//   Init; diff reached 513, but argument materialization moved to the call and
//   destroyed the structural block, so restored.
// probes 25/29 (liveness): int predicate temporaries produced the original full
//   register increments, but VC5 emitted dword stack stores and diff 552; explicit
//   unsigned-char casts were identical.  Raw int flag caches with byte locals were
//   a duplicate of the clean 678-byte source.  Restored clean typed source.
// follow-up lease (2026-08-17): revalidated the 678-byte typed source and tested
//   assignment-after-new (672 bytes but frame 8, diff 539), raw integer flag
//   caches (676 bytes, diff 513 but wrong allocation block), int mode locals
//   (676 bytes, diff 552), split/compound/reversed mode arithmetic, joined
//   declarations, scoped allocation pointer, explicit new parentheses, and
//   standard string/stdio headers.  The source-shape probes were duplicates or
//   worse.  A structured 48-variant mode/VC5 flag lab found no exact result;
//   /GX+/Ow reached size 672 but still diverged at +006D.  Assembly donor search
//   found no matching byte-mode arithmetic donor.  Clean typed source remains
//   the best policy-valid reconstruction; pause with the original full-register
//   inc versus VC5 byte-inc/zeroing hunk unresolved.
// Accepted-drift review: the executable applies setne to CL and DL, then
// increments the full register. Only each low byte is stored. The rebuild
// clears each register and increments the low byte, producing the same 1 or 2.
// All 16 calls, EH state, mode probes, fallbacks, stores, and returns match.

#include <new.h>
#include <windows.h>

class TDrawArea;

class RGE_Prog_Info {
public:
    char gap_000[0x410];
    void* instance;                         // +0x410
    char gap_414[0x66E - 0x414];
    char pal_file[0x100];                   // +0x66E
    char gap_76E[0x894 - 0x76E];
    long full_screen;                       // +0x894
    long gap_898;
    long use_dir_draw;                      // +0x89C
    long use_sys_mem;                       // +0x8A0
    char gap_8A4[0x8E0 - 0x8A4];
    long main_wid;                          // +0x8E0
    long main_hgt;                          // +0x8E4
};

class TDrawSystem {
public:
    char gap_000[0x0C];
    TDrawArea* DrawArea;                    // +0x0C
    char gap_010[0x468];
    unsigned char DrawType;                 // +0x478
    unsigned char ScreenMode;               // +0x479
    char gap_47A[2];

    TDrawSystem();
    void CheckAvailModes(int full_screen);
    int IsModeAvail(long width, long height, int bpp);
    int Init(void* instance, void* window, void* palette,
             unsigned char draw_type, unsigned char screen_mode,
             long width, long height, unsigned long flags);
    void Paint(RECT* rect);
};

class TDrawArea {
public:
    void Clear(RECT* rect, int color);
};

class TPanelSystem {
public:
    void release_palette(void* palette);
    void* get_palette(char* name, long id);
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual int run();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual void set_prog_mode(int);
    virtual void set_game_mode(int, int);
    virtual void set_player(short);
    virtual int get_error_code();
    virtual char* get_string(int, long, char*, int);
    virtual char* get_string(long, char*, int);
    virtual char* get_string(long);
    virtual char* get_string2(int, long, long, char*, int);
    virtual void* get_view_panel();
    virtual void* get_map_panel();
    virtual void* new_scenario_header(void*);
    virtual void* new_scenario_header(int);
    virtual void* new_scenario_info(int);
    virtual void notification(int, long, long, long, long);
    virtual int reset_comm();
    virtual void send_game_options();
    virtual void receive_game_options();
    virtual char* gameSummary();
    virtual int processCheatCode(int, char*);
    virtual int setup_music_system();
    virtual void shutdown_music_system();
    virtual int setup();
    virtual int setup_cmd_options();
    virtual int setup_class();
    virtual int setup_main_window();
    virtual int setup_graphics_system();

    char gap_004[0x08];
    RGE_Prog_Info* prog_info;              // +0x0C
    void* prog_window;                     // +0x10
    char gap_014[0x08];
    void* prog_palette;                    // +0x1C
    char gap_020[0x20];
    int error_code;                        // +0x40
    char gap_044[0x04];
    TDrawSystem* draw_system;              // +0x48
    TDrawArea* draw_area;                  // +0x4C
};

extern TPanelSystem panel_system;

int RGE_Base_Game::setup_graphics_system()
{
    TDrawSystem* draw_system;

    if (this->prog_info->use_dir_draw != 0) {
        HDC dc = GetDC(0);
        int bits = GetDeviceCaps(dc, 0x0C);
        ReleaseDC(0, dc);
        if (bits < 8) {
            this->error_code = 0x13;
            return 0;
        }
    }

    char draw_mode;
    char draw_type;
    int use_sys_mem;

    draw_type = (this->prog_info->use_dir_draw != 0) + 1;
    draw_mode = (this->prog_info->full_screen != 0) + 1;
    use_sys_mem = this->prog_info->use_sys_mem != 0;

    draw_system = new TDrawSystem;
    this->draw_system = draw_system;
    if (draw_system == 0)
        return 0;

    draw_system->CheckAvailModes(this->prog_info->full_screen);

    if (!this->draw_system->IsModeAvail(this->prog_info->main_wid, 0, 8)) {
        if (this->prog_info->main_wid != 0x280) {
            if (this->draw_system->IsModeAvail(0x280, 0, 8)) {
                this->prog_info->main_wid = 0x280;
                this->prog_info->main_hgt = 0x1E0;
                goto init_step;
            }
        }

        if (this->prog_info->main_wid != 800) {
            if (this->draw_system->IsModeAvail(800, 0, 8)) {
                this->prog_info->main_wid = 800;
                this->prog_info->main_hgt = 600;
                goto init_step;
            }
        }

        if (this->prog_info->main_wid != 0x400) {
            if (this->draw_system->IsModeAvail(0x400, 0, 8)) {
                this->prog_info->main_wid = 0x400;
                this->prog_info->main_hgt = 0x300;
                goto init_step;
            }
        }

        if (this->prog_info->main_wid == 0x500)
            goto init_fail;

        // The original checks 1024x0x0 here before storing 1280x1024.
        if (!this->draw_system->IsModeAvail(0x400, 0, 8))
            goto init_fail;

        this->prog_info->main_wid = 0x500;
        this->prog_info->main_hgt = 0x400;
    }

init_step:
    if (this->draw_system->Init(
            this->prog_info->instance,
            this->prog_window,
            this->prog_palette,
            draw_type,
            draw_mode,
            this->prog_info->main_wid,
            this->prog_info->main_hgt,
            use_sys_mem) == 0)
        goto init_fail;

    panel_system.release_palette(this->prog_palette);
    this->prog_palette = panel_system.get_palette(
        this->prog_info->pal_file, 0xC544);

    this->draw_area = this->draw_system->DrawArea;
    this->draw_area->Clear(0, 0);
    this->draw_system->Paint(0);

    return 1;

init_fail:
    return 0;
}
