// VA 004C2DF0 RGE_Static_Object::draw_frame_3d_cube_back
// stat_obj.cpp:1385-1462
// Attempt log:
// 1: Natural source from packet/decompiler with local object/map/draw-area surfaces.
// 2: First helper-shaped source compiled far too small (672 bytes) because the repeated get_point/MoveToEx/LineTo pattern was factored into a helper; helper source was removed.
// 3: Inlined all six edge segments explicitly: each has two RGE_Map::get_point calls followed by MoveToEx/LineTo.
// 4: Inlined version default /O2 /Oy is still size-short: configured 994 exceeds .text 976. It also uses an EBP frame and many stack locals, unlike original FPO/sub esp 24h schedule.
// 5: Probed /Ob0: still 976 bytes. Probed /Og- and /Od: exact 994 bytes but broad mismatch, 83.4004% positional, first mismatch offset 0; flags removed.
// 6: Implemented broad behavior/calls: master outline radii setup, owner->world->map lookup, rge_base_game view test, Unlock/GetDc, SelectClipRgn, stock pen selection based on startLoggingAI/id/groupCommanderValue, six back-cube edge projections, ReleaseDc, and relock.
// 7: Restored the absolute game globals/rdata constants and IAT function-pointer ABI; all 34 calls now align, with the remaining drift localized to prologue/liveness and coordinate scheduling.
// 8: Mirrored the exact cube-front donor's function-scope output locals and declaration order; corrected the radius_y quarter field used by the final two edges. This reached 998B with 100% ordered-call parity and 79.6% resync similarity.
// 9: Compound-assignment radius probes introduced broad fmulp/liveness drift and were rolled back.
// 10: External/const/volatile rdata declaration probes and split coordinate assignments were codegen duplicates or lost absolute relocation identity; restored the natural absolute, direct-member source.
// 11: Reversed each projected segment to the binary's natural endpoint order: get_point x2/y2 first, then x1/y1, followed by MoveToEx(x2,y2) and LineTo(x1,y1).
// 12: Followed the first structural hunk by testing direct master-member radius expressions; emitted code was unchanged.
// 13: Moved view preparation before the radii; it changed scheduling but called get_view too early and worsened block alignment, so it was reverted.
// 14: Matched cube-front declaration topology and delayed map derivation; both emitted duplicates.
// 15: Restored master-before-owner declaration order; duplicate.
// 16: Added the proven virtual class surface, typed view ownership, and CRT header; all were codegen duplicates.
// 17: Tested int coordinate parameters against raw original stack loads; size improved by 2 bytes but structural drift worsened, so restored short ABI.
// 18: Query_abi confirmed RGE_Map::get_point uses short screen coordinates; the exact local ABI surface is retained, with no codegen change.
// 19: Binary decompiler assignment order places owner->world->map between full x and y/z radius loads; the positive view guard and this order are codegen duplicates.
// 20: Exact player/world virtual surfaces preserve proven offsets (+3C and +28); emitted code is unchanged.
// 21: A short coordinate-local diagnostic reached 994 bytes but emitted 16-bit additions, unlike the original 32-bit parameter-home additions; rolled back.
// 22-25: Re-tested widened parameters, reversed declaration order, master class surface,
//        and owner/map aliases. They did not improve the 994B / 105-byte-diff basin.
// 26: An ambient declaration sweep (64 samples) kept size, frame, calls, and the
//     same first mismatch. Translation-unit declaration count is not the blocker.
// 27: Split map declaration and assignment was a codegen duplicate. The best source
//     uses literal 0.25f/0.75f pools and mutates the short coordinate parameters.
// 28: Resumed from the clean checkpoint. A non-polymorphic master layout with
//     the same AC/B0/B4 radius offsets was a codegen duplicate.
// 29: A polymorphic view type with clip_rgn still at +88 was a codegen duplicate.
// 30: Replaced the absolute rge_base_game macro with the reviewed extern symbol.
//     This reached an exact 994B result with all 354 instructions aligned.
// Exact finish (2026-08-22):
// - First exact checkpoint: probe-032-context, 0 bytes different.
// - Decisive change: declare rge_base_game as an extern pointer symbol.
// - Walkback: restoring the absolute macro returned to 105 differing bytes;
//   the extern declaration is required for this VC5 codegen basin.
// - No accepted drift. The retained source is natural and policy-compliant.
// BINARY NOTE: The reviewed extern rge_base_game declaration is required here;
// the equivalent absolute-storage macro changes the early register schedule.
// Source-gate cleanup (2026-08-22):
// - Canonicalized the same-TU RGE_Base_Game/get_view_panel and TPanel surfaces.
// - Canonicalized RGE_Static_Object, RGE_Master_Static_Object, TDrawArea,
//   RGE_Map, RGE_World, and RGE_Player ownership and field names.
// - Replaced startLoggingAI and Win32 import macros with donor declarations.
// - Removed unused absolute constant macros and the unused stdlib include.
// - Completed TDrawArea with its donor-proven DrawSurface member.
// - Every cleanup check remains MATCH with 0.0000% difference.

extern "C" {
__declspec(dllimport) int __stdcall SelectClipRgn(void* hdc, void* rgn);
__declspec(dllimport) void* __stdcall GetStockObject(int id);
__declspec(dllimport) void* __stdcall SelectObject(void* hdc, void* object);
__declspec(dllimport) int __stdcall MoveToEx(void* hdc, int x, int y, void* point);
__declspec(dllimport) int __stdcall LineTo(void* hdc, int x, int y);
}


extern int startLoggingAI;

class TDrawArea {
public:
    void* DrawSystem;
    char gap_04[4];
    unsigned char* Bits;
    char gap_0C[0x2C];
    void* DrawDc;
    void* DrawSurface;
    void Unlock(char* name);
    void* GetDc(char* name);
    void ReleaseDc(char* name);
    unsigned char* Lock(char* name, int wait);
};

class RGE_Map {
public:
    void get_point(short* out_x, short* out_y, float rx, float ry, float rz,
                   short sx, short sy);
};

class RGE_World {
public:
    char gap_00[0x28];
    RGE_Map* map;
};
class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_World* world;
};
class RGE_Master_Static_Object {
public:
    char gap_00[0xAC];
    float outline_radius_x;
    float outline_radius_y;
    float outline_radius_z;
};
class TPanel {
public:
    virtual ~TPanel();
    char gap_04[0x84];
    void* clip_rgn;
};
class RGE_Scenario_Header;
class RGE_Scenario;
class RGE_Game_World;
struct tagMSG;

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
    virtual TPanel* get_view_panel();
    virtual TPanel* get_map_panel();
    virtual RGE_Scenario_Header* new_scenario_header(RGE_Scenario*);
    virtual RGE_Scenario_Header* new_scenario_header(int);
    virtual RGE_Scenario* new_scenario_info(int);
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
    virtual int setup_palette();
    virtual int setup_mouse();
    virtual int setup_registry();
    virtual int setup_debugging_log();
    virtual int setup_chat();
    virtual int setup_comm();
    virtual int setup_sound_system();
    virtual int setup_fonts();
    virtual int setup_sounds();
    virtual int setup_shapes();
    virtual int setup_blank_screen();
    virtual void setup_timings();
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void stop_music_system();
    virtual int restart_music_system();
    virtual RGE_Game_World* create_world();
    virtual int handle_message(tagMSG*);
    virtual int handle_idle();
    virtual int handle_mouse_move(void*, unsigned int, unsigned int, long);
    virtual int handle_key_down(void*, unsigned int, unsigned int, long);
    virtual int handle_user_command(void*, unsigned int, unsigned int, long);
    virtual int handle_command(void*, unsigned int, unsigned int, long);
    virtual int handle_music_done(void*, unsigned int, unsigned int, long);
    virtual int handle_paint(void*, unsigned int, unsigned int, long);
    virtual int handle_activate(void*, unsigned int, unsigned int, long);
    virtual int handle_init_menu(void*, unsigned int, unsigned int, long);
    virtual int handle_exit_menu(void*, unsigned int, unsigned int, long);
    virtual int handle_size(void*, unsigned int, unsigned int, long);
    virtual int handle_palette_changed(void*, unsigned int, unsigned int, long);
    virtual int handle_query_new_palette(void*, unsigned int, unsigned int, long);
    virtual int handle_close(void*, unsigned int, unsigned int, long);
    virtual int handle_destroy(void*, unsigned int, unsigned int, long);
    virtual int action_update();
    virtual int action_mouse_move(long, long, int, int, int, int);
    virtual int action_key_down(unsigned long, int, int, int, int);
    virtual int action_user_command(unsigned long, unsigned long);
    virtual int action_command(unsigned long, unsigned long);
    virtual int action_music_done();
    virtual int action_activate();
    virtual int action_deactivate();
    virtual int action_init_menu();
    virtual int action_exit_menu();
    virtual int action_size();
    virtual int action_close();
    virtual void calc_timings();
    virtual void calc_timing_text();
    virtual void show_timings();
    virtual void show_comm();
    virtual void show_ai();
    virtual int setup_map_save_area();
    virtual void set_interface_messages();
};
extern RGE_Base_Game* rge_base_game;

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    int id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x18];
    short screen_x_offset;
    short screen_y_offset;
    char gap_2C[0x4C];
    int groupCommanderValue;

    void draw_frame_3d_cube_back(TDrawArea* area, short sx, short sy);
};

void RGE_Static_Object::draw_frame_3d_cube_back(TDrawArea* area, short sx, short sy)
{
    short y2, x2, y1, x1;
    float negRy;
    RGE_Master_Static_Object* m = this->master_obj;
    float ry1, rz2, rz3, rz4, rx2, ry2, rzFull;
    ry1 = m->outline_radius_x * 0.25f;
    rz2 = m->outline_radius_y * 0.25f;
    rz3 = m->outline_radius_z * 0.25f;
    rz4 = m->outline_radius_z * 0.75f;
    rx2 = m->outline_radius_x;
    RGE_Map* map = this->owner->world->map;
    ry2 = m->outline_radius_y;
    rzFull = m->outline_radius_z;
    TPanel* view = rge_base_game->get_view_panel();

    if (view != 0) {
        area->Unlock(0);
        void* dc = area->GetDc(0);
        if (dc != 0) {
        SelectClipRgn(area->DrawDc, view->clip_rgn);
        if (startLoggingAI == 1 && this->groupCommanderValue == this->id && this->id >= 0)
            SelectObject(area->DrawDc, GetStockObject(7));
        else
            SelectObject(area->DrawDc, GetStockObject(6));

        sx += this->screen_x_offset;
        sy += this->screen_y_offset;
        negRy = -ry2;

        map->get_point(&x2, &y2, rx2, negRy, 0.0f, sx, sy);
        map->get_point(&x1, &y1, rx2, negRy, rz3, sx, sy);
        MoveToEx(area->DrawDc, x2, y2, 0); LineTo(area->DrawDc, x1, y1);
        map->get_point(&x2, &y2, rx2, negRy, rz4, sx, sy);
        map->get_point(&x1, &y1, rx2, negRy, rzFull, sx, sy);
        MoveToEx(area->DrawDc, x2, y2, 0); LineTo(area->DrawDc, x1, y1);
        map->get_point(&x2, &y2, rx2, negRy, 0.0f, sx, sy);
        map->get_point(&x1, &y1, ry1, negRy, 0.0f, sx, sy);
        MoveToEx(area->DrawDc, x2, y2, 0); LineTo(area->DrawDc, x1, y1);
        map->get_point(&x2, &y2, -rx2, negRy, 0.0f, sx, sy);
        map->get_point(&x1, &y1, -ry1, negRy, 0.0f, sx, sy);
        MoveToEx(area->DrawDc, x2, y2, 0); LineTo(area->DrawDc, x1, y1);
        map->get_point(&x2, &y2, rx2, negRy, 0.0f, sx, sy);
        map->get_point(&x1, &y1, rx2, -rz2, 0.0f, sx, sy);
        MoveToEx(area->DrawDc, x2, y2, 0); LineTo(area->DrawDc, x1, y1);
        map->get_point(&x2, &y2, rx2, ry2, 0.0f, sx, sy);
        map->get_point(&x1, &y1, rx2, rz2, 0.0f, sx, sy);
        MoveToEx(area->DrawDc, x2, y2, 0); LineTo(area->DrawDc, x1, y1);

        SelectClipRgn(area->DrawDc, 0);
        area->ReleaseDc(0);
        }
        area->Lock(0, 1);
    }
}
