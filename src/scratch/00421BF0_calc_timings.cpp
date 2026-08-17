// VA: 00421BF0 RGE_Base_Game::calc_timings (934 B)
// PDB source: basegame.cpp:4767-4914
// Attempt log:
// - Baseline used a packet-grounded raw-offset scaffold.  It omitted the real
//   profiler fprintf/fflush path and duplicated two time probes, producing a
//   476-byte structural mismatch.
// - Probe 2: restored the period typed timing/world/player surfaces, the three
//   single debug_timeGetTime calls, the virtual calc_timing_text call, and the
//   binary-observed giant conditional fprintf argument list.  The source keeps
//   timing ownership named while preserving the original zero-count behavior.
// - Probe 4: explicit pre-loop and post-load player-pointer increments recovered
//   the original add/dec/load scan topology and reduced the positional drift to
//   the timer-update block plus relocations.
// - Probe 7: donor-era stdlib/string/windows header context preserved the late
//   profiler argument and cleanup blocks; the remaining drift is localized to
//   VC5 scheduling around the first timer reset call.
// - Variant lab (probe 8): six plausible timer-field statement orders produced
//   no exact group.  The natural last/last-max/zero/zero/start order is retained.
// - Probes 9-10: restoring the known 0xA24 object size and testing the int
//   debug-time return ABI did not improve emitted bytes.  Final best source is
//   the typed reconstruction; exact gap is the timer block's first branch.
// - Probe 12: a natural per-iteration reference alias for the timing record
//   produced identical code; the typed pointer form remains the clean source.
// - Probe 13: snapshot max_time after storing last_time to follow the
//   original load/store order; emitted code was unchanged, so it was rolled back.
// - Current pass: the clean typed source keeps exact size (934), frame (0x18),
//   saved registers, CFG counts, and all six ordered calls.  Its only behavior
//   gap is the first timing-record block: the original pushes 0x12B5 before
//   the last/max stores and delays stack cleanup until after the include test.
// - Current pass: raw int-pointer access, signed timing fields, declaration
//   order, loop spelling, address aliases, filename forms, targeted volatile
//   fields, and local optimizer pragmas did not improve the 44-byte gap.
// - Current pass: a four-way timer statement-order lab kept size, frame, and
//   calls but produced no exact group.  A 512-variant ambient declaration lab
//   also produced no exact group; its best context was still nonexact.
// - Behavior audit: the original only accumulates include_in_total for
//   non-summary records, and emits view_update_fps before world_update_fps.
//   Restoring both facts reduced the clean mismatch from 44 to 30 bytes in
//   four spans; the remaining gap is the first timer block's instruction order.
// - Object/ABI audit: the original PDB names this method as protected
//   (?calc_timings@RGE_Base_Game@@MAEXXZ) and names debug_timeGetTime with C++
//   linkage (?debug_timeGetTime@@YAKPADH@Z).  The local declarations now emit
//   those exact COFF symbols; these ABI changes were byte-neutral.
// - Object audit: the original basegame module records VC5 11.00, Pentium,
//   hardware floating point, near code/data, a 0x3A6 function range, and no
//   inline-line records.  The /Z7 VC5 probe emits the same function range and
//   compile record.  No object evidence supports omitted locals or a stale
//   PDB boundary.
// - PDB type audit: canonical RGE_Object_List is 12 bytes with one virtual
//   load slot and list at +4.  A local canonical test worsened the body to
//   46 bytes by reversing two late logger loads, so the narrow +8 field stub
//   remains.  This target proves only number_of_objects at +8.
// - Current pass: a natural indexed timing scan with a per-iteration indexed
//   member access reproduces the timer block and reduces the gap from 30 to 6.
// - Current pass: incrementing the player-list pointer before decrementing its
//   remaining count reproduces the observed setup order and reduces the gap to
//   2 bytes.  The remaining two bytes are the quotient sum load order.
// - Specialist audit: PDB line 4900 and the Ghidra stack locals support the
//   seven quotient results as outgoing homes.  Reverse-order named quotient
//   locals, a named denominator, and a sequential sum all emit the same
//   2-byte mismatch.  A guarded named sum changes the CFG and is rejected.
// - Specialist audit: the original hunk loads timing[10] at +0x221 and
//   timing[12] at +0x227.  Natural direct and reversed `+` expressions both
//   load timing[12] first under this VC5 context.  The exact calc_timing_text
//   donor confirms that the surrounding use changes this commutative schedule.
// BINARY NOTE: The executable reloads include_in_total after the first timer
//   probe and performs the 8-byte cleanup after that reload.
// LIKELY INTENT: The timer record is a typed 0x20-byte array.  The remaining
//   difference is compiler scheduling or original translation-unit context.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

unsigned long __cdecl debug_timeGetTime(char* file, int line);
extern int do_fps_log;
extern FILE* fps_log;
extern unsigned long start_mem_total;
extern unsigned long start_mem_high;
extern unsigned long cur_mem_total;
extern unsigned long cur_mem_high;

class RGE_Object_List {
public:
    char gap_00[8];
    short number_of_objects;
};

class RGE_Player;

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    unsigned long world_time;
    char gap_08[0x34];
    short player_num;
    char gap_3E[2];
    RGE_Player** players;
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x24];
    RGE_Object_List* objects;
    RGE_Object_List* sleeping_objects;
};

class RGE_Timing_Info {
public:
    unsigned long accum_time;
    unsigned long last_time;
    unsigned long start_time;
    int include_in_total;
    int is_summary;
    unsigned long last_single_time;
    unsigned long max_time;
    unsigned long last_max_time;
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual int run();
    virtual long wnd_proc(void* hwnd, unsigned int msg, unsigned int wp, long lp);
    virtual void set_prog_mode(int mode);
    virtual void set_game_mode(int mode, int sub_mode);
    virtual void set_player(short player);
    virtual int get_error_code();
    virtual char* get_string(int a, long b, char* out, int size);
    virtual char* get_string(long a, char* out, int size);
    virtual char* get_string(long a);
    virtual char* get_string2(int a, long b, long c, char* out, int size);
    virtual void* get_view_panel();
    virtual void* get_map_panel();
    virtual void* new_scenario_header(void* scenario);
    virtual void* new_scenario_header(int value);
    virtual void* new_scenario_info(int value);
    virtual void notification(int a, long b, long c, long d, long e);
    virtual int reset_comm();
    virtual void send_game_options();
    virtual void receive_game_options();
    virtual char* gameSummary();
    virtual int processCheatCode(int value, char* text);
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
    virtual int handle_message(void* msg);
    virtual int handle_idle();
    virtual int handle_mouse_move(void* a, unsigned int b, unsigned int c, long d);
    virtual int handle_key_down(void* a, unsigned int b, unsigned int c, long d);
    virtual int handle_user_command(void* a, unsigned int b, unsigned int c, long d);
    virtual int handle_command(void* a, unsigned int b, unsigned int c, long d);
    virtual int handle_music_done(void* a, unsigned int b, unsigned int c, long d);
    virtual int handle_paint(void* a, unsigned int b, unsigned int c, long d);
    virtual int handle_activate(void* a, unsigned int b, unsigned int c, long d);
    virtual int handle_init_menu(void* a, unsigned int b, unsigned int c, long d);
    virtual int handle_exit_menu(void* a, unsigned int b, unsigned int c, long d);
    virtual int handle_size(void* hwnd, unsigned int msg, unsigned int wp, long lp);
    virtual int handle_palette_changed(void* a, unsigned int b, unsigned int c, long d);
    virtual int handle_query_new_palette(void* a, unsigned int b, unsigned int c, long d);
    virtual int handle_close(void* a, unsigned int b, unsigned int c, long d);
    virtual int handle_destroy(void* a, unsigned int b, unsigned int c, long d);
    virtual int action_update();
    virtual int action_mouse_move(long a, long b, int c, int d, int e, int f);
    virtual int action_key_down(unsigned long a, int b, int c, int d, int e);
    virtual int action_user_command(unsigned long a, unsigned long b);
    virtual int action_command(unsigned long a, unsigned long b);
    virtual int action_music_done();
    virtual int action_activate();
    virtual int action_deactivate();
    virtual int action_init_menu();
    virtual int action_exit_menu();
    virtual int action_size();
    virtual int action_close();

protected:
    virtual void calc_timings();
    virtual void calc_timing_text();
    virtual void show_timings();
    virtual void show_comm();
    virtual void show_ai();
    virtual int setup_map_save_area();
    virtual void set_interface_messages();

    char gap_04[0x1B0 - 4];
    int prog_mode;                         // +0x1B0
    char gap_1B4[0x3F4 - 0x1B4];
    RGE_Game_World* world;                 // +0x3F4
    int render_all;
    short master_obj_id;
    short terrain_id;
    short elevation_height;
    short brush_size;
    char timing_text[0x100];               // +0x404
    unsigned long frame_count;             // +0x504
    unsigned long world_update_count;      // +0x508
    unsigned long view_update_count;       // +0x50C
    unsigned long last_frame_count;        // +0x510
    unsigned long last_world_update_count; // +0x514
    unsigned long last_view_update_count;  // +0x518
    unsigned long fps;                     // +0x51C
    unsigned long world_update_fps;         // +0x520
    unsigned long view_update_fps;          // +0x524
    RGE_Timing_Info timings[30];           // +0x528
    char gap_8E8[0xA24 - 0x8E8];            // remaining RGE_Base_Game layout
};

void RGE_Base_Game::calc_timings()
{
    unsigned long total_time = 0;
    for (int i = 0; i < 30; ++i) {
        if (this->timings[i].is_summary == 0) {
            this->timings[i].last_time = this->timings[i].accum_time;
            this->timings[i].last_max_time = this->timings[i].max_time;
            this->timings[i].accum_time = 0;
            this->timings[i].max_time = 0;
            this->timings[i].start_time = debug_timeGetTime(
                (char*)0x57FB08, 0x12B5);

            if (this->timings[i].include_in_total != 0)
                total_time += this->timings[i].last_time;
        }
    }

    if (this->timings[0].start_time > 0) {
        this->timings[0].last_time = debug_timeGetTime(
            (char*)0x57FB08, 0x12BE) - this->timings[0].start_time;
    } else {
        this->timings[0].last_time = total_time;
    }

    this->timings[0].start_time = debug_timeGetTime(
        (char*)0x57FB08, 0x12C1);

    if (this->timings[0].last_time > total_time)
        this->timings[4].last_time =
            this->timings[0].last_time - total_time;
    else
        this->timings[4].last_time = 0;

    if (this->timings[2].last_time >
        this->timings[6].last_time + this->timings[7].last_time)
        this->timings[9].last_time =
            this->timings[2].last_time - this->timings[6].last_time -
            this->timings[7].last_time;
    else
        this->timings[9].last_time = 0;

    unsigned long total = this->timings[0].last_time;
    if (total == 0 || this->frame_count == 0 ||
        total / this->frame_count == 0) {
        this->fps = 1000;
    } else {
        this->fps = 1000 / (total / this->frame_count);
    }

    if (total == 0 || this->view_update_count == 0 ||
        total / this->view_update_count == 0) {
        this->view_update_fps = 0;
    } else {
        this->view_update_fps =
            1000 / (total / this->view_update_count);
    }

    if (total == 0 || this->world_update_count == 0 ||
        total / this->world_update_count == 0) {
        this->world_update_fps = 0;
    } else {
        this->world_update_fps =
            1000 / (total / this->world_update_count);
    }

    this->calc_timing_text();

    if (do_fps_log != 0 && this->prog_mode == 4) {
        int object_count = 0;
        int sleeping_object_count = 0;
        int player_count = this->world->player_num;

        if (player_count > 1) {
            RGE_Player** players = this->world->players;
            ++players;
            --player_count;
            do {
                RGE_Player* player = *players;
                ++players;
                object_count += player->objects->number_of_objects;
                sleeping_object_count +=
                    player->sleeping_objects->number_of_objects;
                --player_count;
            } while (player_count != 0);
        }

        fprintf(
            fps_log,
            (const char*)0x580284,
            this->world->world_time,
            start_mem_total,
            start_mem_high,
            cur_mem_total,
            cur_mem_high,
            (*this->world->players)->objects->number_of_objects,
            (*this->world->players)->sleeping_objects->number_of_objects,
            object_count,
            sleeping_object_count,
            this->world_update_count,
            this->view_update_count,
            this->world_update_fps,
            this->view_update_fps,
            this->world_update_count == 0
                ? 0 : this->timings[6].last_time / this->world_update_count,
            this->timings[6].last_max_time,
            this->world_update_count == 0
                ? 0 : this->timings[7].last_time / this->world_update_count,
            this->timings[7].last_max_time,
            this->world_update_count == 0
                ? 0 : this->timings[3].last_time / this->world_update_count,
            this->timings[3].last_max_time,
            this->world_update_count == 0
                ? 0 : this->timings[1].last_time / this->world_update_count,
            this->timings[1].last_max_time,
            this->world_update_count == 0
                ? 0 : (this->timings[10].last_time +
                       this->timings[12].last_time) /
                      this->world_update_count,
            this->timings[10].last_max_time +
                this->timings[12].last_max_time,
            this->world_update_count == 0
                ? 0 : this->timings[13].last_time / this->world_update_count,
            this->timings[13].last_max_time,
            this->world_update_count == 0
                ? 0 : this->timings[4].last_time / this->world_update_count,
            this->timings[4].last_max_time,
            0,
            -1,
            -1);
        fflush(fps_log);
    }

    this->last_frame_count = this->frame_count;
    this->last_world_update_count = this->world_update_count;
    this->last_view_update_count = this->view_update_count;
    this->frame_count = 0;
    this->world_update_count = 0;
    this->view_update_count = 0;
}
