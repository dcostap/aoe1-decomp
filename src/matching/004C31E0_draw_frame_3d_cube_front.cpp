// VA 004C31E0 RGE_Static_Object::draw_frame_3d_cube_front
// PDB source: stat_obj.cpp lines 1466-1620
// Baseline: natural period-plausible reconstruction of the front cube outline.
// Attempt log:
// - baseline initially omitted one front-cube edge pair: 2264 bytes and 78 calls.
// - restored all 18 explicit get_point/MoveToEx/LineTo pairs: exact size/call set,
//   but VC5 selected a 0x2C frame instead of the original 0x28.
// - inlined the repeated negative quarter-radius expression and reordered output
//   locals; emitted code was unchanged. A short-output union diagnostic was also
//   unchanged and was reverted to ordinary short locals.
// - reusing the incoming x/y parameter homes as moving offsets regressed broadly;
//   reverted. Short sx/sy temporaries recovered the closest basin (737/736 strict
//   diff bytes) but still eagerly save EDI and retain the 0x2C frame.
// - reversing y-then-x coordinate initialization moved one byte closer; final
//   output-local declaration ordering was a duplicate. Calls, cleanup, and all
//   18 edge behaviors are aligned; remaining drift is prologue/local topology.
// r1 (2026-08-06):
// - geometry audit: edge-5 FIRST point (line 1527) passes the Z radius (rx1),
//   not 0.0f; original loads [esp+1Ch]. Fixed. (The 0.0f was a decompiler
//   artifact that coincidentally offset the +3 size of the 0x2C frame.)
// - inline-vs-named negations are codegen-neutral (VC5 CSEs both into the same
//   dead parameter slots: neg_ry->x-slot, neg_ry2->area-slot, -ry*0.25->y-slot).
// - KEY: declaring the four get_point output shorts (y2/x2/y1/x1) at the
//   FUNCTION TOP (before the radius locals) fixes both the frame (0x2C -> 0x28)
//   and the float slot layout (rz*0.25@F20, rz*0.75@F24 now match original).
// - with shorts-at-top, int sy/sx recovers exact size 2375 and diff 791
//   (best correct-geometry state); short sy/sx keeps 872 instructions but is
//   +3 size (movsx form).
// - remaining drift: register basin (rebuilt keeps `this` in esi/edi, original
//   in ebx with delayed push edi) and the screen-offset arithmetic form
//   (original: 16-bit member loads into ax/dx + 32-bit param loads + adds with
//   garbage-high bits; rebuilt: movsx-based). Frame, FPU prologue, output LEAs,
//   all 82 calls, and all 36 get_point float args now match the original.
// r2 (2026-08-13):
// - mirrored the neighboring cube-back render guard with an early return for
//   a null view; CFG, size, calls, and all emitted bytes were unchanged.
// Exact finish (2026-08-17):
// - First exact checkpoint: probe-024-liveness, 0 bytes different.
// - Decisive changes: use short get_point screen arguments; update x before y;
//   update the incoming coordinates in place; delay neg_local_10 after the
//   first neg_ry2 projection call.
// - Required group: coordinate mutation and short get_point arguments select
//   the original register and stack basin. The negation order removes one
//   extra x87 load and store.
// - Walkbacks kept MATCH: stdlib, handle typedefs, the absolute global macro,
//   the expanded draw-area layout, virtual player/master variants, the self
//   alias, map/view declaration order, and split radius declarations.
// - Reusable lesson candidate: VC5 can require a delayed unary-float assignment
//   after a call to preserve the next call's x87 setup.
// Policy cleanup (2026-08-17):
// - Class evidence gives RGE_Base_Game no base, size 0xA24, and named virtual
//   methods through slot +0x140. Slot +0x2C is get_view_panel().
// - The fake v00-v28 surface is removed. The canonical replacement stays exact.
// - TPanel is polymorphic and owns clip_rgn at +0x88. No fake TPanel slots are
//   needed because this function does not dispatch through the panel.
// - A named prefix through get_view_panel also matched. The full donor surface
//   is retained because class evidence proves the complete canonical surface.

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
    char gap_00[0x38];
    void* DrawDc;
    void Unlock(char* name);
    void* GetDc(char* name);
    void ReleaseDc(char* name);
    unsigned char* Lock(char* name, int wait);
};

class RGE_Map {
public:
    void get_point(short* out_x, short* out_y,
                   float rx, float ry, float rz, short sx, short sy);
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

    void draw_frame_3d_cube_front(TDrawArea* area, short x, short y);
};

void RGE_Static_Object::draw_frame_3d_cube_front(TDrawArea* area, short x, short y)
{
    short y2, x2, y1, x1;
    float neg_ry;
    float neg_ry2, neg_local_10;
    RGE_Master_Static_Object* master = this->master_obj;
    float local_10 = master->outline_radius_x * 0.25f;
    float rx2 = master->outline_radius_y * 0.25f;
    float rz3 = master->outline_radius_z * 0.25f;
    float local_4 = master->outline_radius_z * 0.75f;
    float ry2 = master->outline_radius_x;
    float rz4 = master->outline_radius_y;
    float rx1 = master->outline_radius_z;
    RGE_Map* map = this->owner->world->map;
    TPanel* view = rge_base_game->get_view_panel();

    // BINARY NOTE: A null view returns before the draw-area lock sequence.
    if (view == 0)
        return;

    area->Unlock(0);
        if (area->GetDc(0) != 0) {
            SelectClipRgn(area->DrawDc, view->clip_rgn);
            if (startLoggingAI == 1 && this->groupCommanderValue == this->id && this->id >= 0) {
                SelectObject(area->DrawDc, GetStockObject(7));
            } else {
                SelectObject(area->DrawDc, GetStockObject(6));
            }

            // BINARY NOTE: Update x before y and keep both incoming short homes.
            x += this->screen_x_offset;
            y += this->screen_y_offset - 0x10;
            neg_ry = -rz4;

            map->get_point(&x2, &y2, ry2, neg_ry, rx1, x, y);
            map->get_point(&x1, &y1, local_10, neg_ry, rx1, x, y);
            MoveToEx(area->DrawDc, x2, y2, 0);
            LineTo(area->DrawDc, x1, y1);

            neg_ry2 = -ry2;
            map->get_point(&x2, &y2, neg_ry2, neg_ry, rx1, x, y);
            // BINARY NOTE: Delay this negation until the first projection ends.
            neg_local_10 = -local_10;
            map->get_point(&x1, &y1, neg_local_10, neg_ry, rx1, x, y);
            MoveToEx(area->DrawDc, x2, y2, 0);
            LineTo(area->DrawDc, x1, y1);

            map->get_point(&x2, &y2, ry2, rz4, rx1, x, y);
            map->get_point(&x1, &y1, local_10, rz4, rx1, x, y);
            MoveToEx(area->DrawDc, x2, y2, 0);
            LineTo(area->DrawDc, x1, y1);

            map->get_point(&x2, &y2, neg_ry2, rz4, rx1, x, y);
            map->get_point(&x1, &y1, neg_local_10, rz4, rx1, x, y);
            MoveToEx(area->DrawDc, x2, y2, 0);
            LineTo(area->DrawDc, x1, y1);

            map->get_point(&x2, &y2, ry2, rz4, rx1, x, y);
            map->get_point(&x1, &y1, ry2, rx2, rx1, x, y);
            MoveToEx(area->DrawDc, x2, y2, 0);
            LineTo(area->DrawDc, x1, y1);

            map->get_point(&x2, &y2, ry2, neg_ry, rx1, x, y);
            map->get_point(&x1, &y1, ry2, -rx2, rx1, x, y);
            MoveToEx(area->DrawDc, x2, y2, 0);
            LineTo(area->DrawDc, x1, y1);

            map->get_point(&x2, &y2, neg_ry2, rz4, rx1, x, y);
            map->get_point(&x1, &y1, neg_ry2, rx2, rx1, x, y);
            MoveToEx(area->DrawDc, x2, y2, 0);
            LineTo(area->DrawDc, x1, y1);

            map->get_point(&x2, &y2, neg_ry2, neg_ry, rx1, x, y);
            map->get_point(&x1, &y1, neg_ry2, -rx2, rx1, x, y);
            MoveToEx(area->DrawDc, x2, y2, 0);
            LineTo(area->DrawDc, x1, y1);

            map->get_point(&x2, &y2, neg_ry2, neg_ry, 0.0f, x, y);
            map->get_point(&x1, &y1, neg_ry2, -rx2, 0.0f, x, y);
            MoveToEx(area->DrawDc, x2, y2, 0);
            LineTo(area->DrawDc, x1, y1);

            map->get_point(&x2, &y2, neg_ry2, rz4, 0.0f, x, y);
            map->get_point(&x1, &y1, neg_ry2, rx2, 0.0f, x, y);
            MoveToEx(area->DrawDc, x2, y2, 0);
            LineTo(area->DrawDc, x1, y1);

            map->get_point(&x2, &y2, ry2, rz4, 0.0f, x, y);
            map->get_point(&x1, &y1, local_10, rz4, 0.0f, x, y);
            MoveToEx(area->DrawDc, x2, y2, 0);
            LineTo(area->DrawDc, x1, y1);

            map->get_point(&x2, &y2, neg_ry2, rz4, 0.0f, x, y);
            map->get_point(&x1, &y1, neg_local_10, rz4, 0.0f, x, y);
            MoveToEx(area->DrawDc, x2, y2, 0);
            LineTo(area->DrawDc, x1, y1);

            map->get_point(&x2, &y2, neg_ry2, rz4, 0.0f, x, y);
            map->get_point(&x1, &y1, neg_ry2, rz4, rz3, x, y);
            MoveToEx(area->DrawDc, x2, y2, 0);
            LineTo(area->DrawDc, x1, y1);

            map->get_point(&x2, &y2, neg_ry2, rz4, local_4, x, y);
            map->get_point(&x1, &y1, neg_ry2, rz4, rx1, x, y);
            MoveToEx(area->DrawDc, x2, y2, 0);
            LineTo(area->DrawDc, x1, y1);

            map->get_point(&x2, &y2, neg_ry2, neg_ry, 0.0f, x, y);
            map->get_point(&x1, &y1, neg_ry2, neg_ry, rz3, x, y);
            MoveToEx(area->DrawDc, x2, y2, 0);
            LineTo(area->DrawDc, x1, y1);

            map->get_point(&x2, &y2, neg_ry2, neg_ry, local_4, x, y);
            map->get_point(&x1, &y1, neg_ry2, neg_ry, rx1, x, y);
            MoveToEx(area->DrawDc, x2, y2, 0);
            LineTo(area->DrawDc, x1, y1);

            map->get_point(&x2, &y2, ry2, rz4, 0.0f, x, y);
            map->get_point(&x1, &y1, ry2, rz4, rz3, x, y);
            MoveToEx(area->DrawDc, x2, y2, 0);
            LineTo(area->DrawDc, x1, y1);

            map->get_point(&x2, &y2, ry2, rz4, local_4, x, y);
            map->get_point(&x1, &y1, ry2, rz4, rx1, x, y);
            MoveToEx(area->DrawDc, x2, y2, 0);
            LineTo(area->DrawDc, x1, y1);

            SelectClipRgn(area->DrawDc, 0);
            area->ReleaseDc(0);
        }
    area->Lock(0, 1);
}
