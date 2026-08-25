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
//   46 bytes by reversing two late logger loads, so the narrow +8 field view
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
// - Specialist follow-up: natural unsigned `a - (0 - b)` preserved the same
//   two-byte hunk, while the donor-supported timings union worsened two late
//   logger displacements.  Both probes were restored.
// - Context gate: config/translation_units.json registers basegame_prefix only
//   through 0041EBF0; 00421BF0 is not registered.  No config edit was used.
// - Later-module audit: src/basegame_late_tu.cpp records the PDB owner order
//   from 0041ED00 through 00421FA0 and groups the real 00421FA0 next owner;
//   0041E7A0 remains an independently checked prefix anchor.  Its default and
//   /GX grouped builds preserve size, frame, six calls, publication, rollover,
//   and fault order, but retain the two quotient-load bytes.  Authentic later
//   owner context therefore does not resolve the gap.
// - Fresh grouped checks: 0041E7A0 and 00421FA0 both report MATCH with their
//   PDB-qualified owners; 00421BF0 still reports MISMATCH at two bytes.  The
//   later owner wrapper is an evidence boundary test, not an exact claim.
// BLOCKER: Owners after 0041EBF0 use incompatible local RGE_Base_Game
//   declarations. Including them all would require unsupported ABI substitution
//   or broad source edits. Keep the registered prefix and config unchanged until
//   a canonical shared basegame declaration is proved.
// ACCEPTED DRIFT: The only two differing bytes swap the source displacements
//   of two adjacent MOV instructions. The original loads timings[10] into EAX
//   and timings[12] into EDX. The rebuild reverses those two loads. Both loads
//   precede the same unsigned ADD. EDX is then cleared before DIV. No call,
//   write, branch, or observable operation occurs between the loads and ADD.
//   Thus, the sum, divisor, quotient, calls, writes, predicates, and faults are
//   equal for the valid nonvolatile RGE_Base_Game object required by the ABI.
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


class RGE_Player;





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
