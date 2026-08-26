// 004BC310 RGE_Sound::play
// Source: Sound.cpp lines 215-273
// Size: 346 bytes, large stack (0x100)
//
// Attempt log:
// Baseline: period Sound.cpp two-stage count guards, typed 0x24-byte
// RGE_Sound_Info/TDigital ownership, direct TDigital methods, and a bounded
// percent scan; 314 differing bytes from incorrect source shape/context.
// Probe 2: corrected helper linkage/return declarations; no emitted change.
// Probe 3: old indexed scan improved block coverage but lost the duplicate
// count gate and remained structurally short; rolled back.
// Probe 4: natural while((rand -= *percent)>0) with an in-loop count return
// recovered exact 346-byte size and saved-register set.
// Probe 5: named int sound_count plus direct member percent owner improved the
// arithmetic/count basin; this remained the best structural family.
// Probe 6: split percent into a narrow local recovered EBP's observed reload.
// Probe 7: valid-index continue/fallthrough return recovered cmp/jl polarity.
// Probe 8: typed RGE_Sound_Info running cursor was codegen-duplicate.
// Probe 9: hoisted scan locals were codegen-duplicate.
// Probe 10: moved char[256] to function scope and removed the long-lived
// digital pointer, restoring direct member reloads, stack homes, exact size,
// and the late call blocks.  Current blocker is broad register/base coloring
// plus remaining source-context drift; the original target keeps EDI=this and
// EBX=record base while this source keeps those roles reversed.  The direct
// write_draw_log2 target mismatch was corrected to its known C++ linkage.
// Main-agent audit removed the diagnostic +4 stack-window addressing from the
// log buffer; the living source now uses the declared character array directly.
// Probe 15 (new worker): initialized the scan index before the post-random
// positive-count guard, matching the oracle's xor-index before test-count
// ordering while retaining the typed count/base ownership.
// Probe 16 (new worker): changed the inner scan to a natural count-bounded
// while with one exhaustion return after the loop, testing the oracle's
// jl-backedge/fallthrough-return topology instead of the inverted continue.
// Probe 16 result: the bounded-header form changed the prologue and worsened
// positional drift; rolled back to the pre-guard index initialization.
// Probe 18 (new worker): used a natural do/while bottom count test for the
// scan and kept one post-loop exhaustion return, testing the oracle's jl
// backedge/fallthrough topology without a continue statement.
// Probe 18 result: the do/while added a 9-byte size overrun and a new first
// cursor-load hunk; rolled back to the pre-guard while form.
// Probe 20 (new worker): expressed the scan as a count-bounded for with the
// index/cursor updates in its increment and guarded the found-record body by
// idx < sound_count, testing the oracle's jl backedge and late success block.
// Probe 20 result: VC5 lowered this to the same broad 105-instruction basin as
// the bounded-header attempt; rolled back.
// Probe 22 (new worker): named the shared closing-log literal before its
// safe-draw dispatch to test whether VC5 hoists the common outgoing argument
// before the branch as in the oracle.
// Probe 22 result: the shared literal local was a codegen duplicate; rolled
// back without changing the late safe-draw call layout.
// Probe 24 (new worker): moved exhaustion return after the scan, using a
// break plus one post-loop count guard to seek the oracle's duplicated early
// return epilogue before the success block.
// Probe 24 result: post-loop return remained one-return/107-instruction code
// and was two bytes worse than the pre-guard index form; rolled back.
// Probe 26 (new worker): broke on count exhaustion and placed the success
// record body under a positive idx < sound_count guard, seeking a cold early
// return/fallthrough layout while keeping the matched scan setup.
// Probe 26 result: this was a codegen duplicate of the post-loop-return basin;
// rolled back.
// Probe 28 (new worker, diagnostic only): used an explicit found label for
// the rand-success edge, matching the oracle's late found block and distinct
// exhaustion epilogue; this form must be normalized away unless binary/source
// evidence justifies it.
// Probe 28 result: explicit label lowered identically to the current while
// form and supplied no late-epilogue lead; rolled back.
// Prior best source: the pre-guard idx initialization preserves the
// oracle's prefix through the scan setup and yields 346 bytes/235 positional
// differences.  Remaining drift is the oracle's distinct exhaustion epilogue
// before the found block (jl fallthrough versus VC5 jge/jmp) plus the shifted
// close-log call-site alignment; no missing calls or size/frame issue remains.
// Probe 27: same-TU get_file_name's indexed for with selected work inside the
// rand-success arm reproduced the target CFG, calls, size, and 21-byte drift.
// It is the current canonical source.  The residual is register coloring:
// VC5 keeps this in EBX and the record base in EDI instead of the oracle's
// EDI/EBX assignment.
// Probe 28: adding a running typed cursor to that for changed the frame and
// scan structure; rolled back.  Probe 30: a named array-base local caused a
// broad size and frame drift; rolled back.  Probe 32: combining the old while
// scan with the selected arm returned the prior 235-byte basin; rolled back.
// Probe 36: swapping natural scan-local declaration order was a codegen
// duplicate.  Probe 38: a per-iteration typed reference was also a duplicate.
// Worker tu-sound-BC310: exact donors and DirectSound declarations confirm
// typed Sound_Info ownership and declaration-only TDigital methods.  No
// evidence-backed natural lead remains for the final register-color drift.
// Probe 44: adding <stdio.h> as period Sound.cpp context was a codegen
// duplicate; rolled back.
// Probe 45: a 16-case standard-header context lab over stdio/string/stdlib/
// malloc produced one 346-byte group, all at the same 21-byte drift.
// Probe 46: replacing the stable sound_count local with direct member count
// uses changed size to 358 bytes and introduced a wrong log-call relocation;
// rolled back.
// Probe 47: a block-local typed records base for scan percent changed size to
// 354 bytes and 282 differing bytes; this duplicated an earlier bad basin and
// was rolled back.
// Probe 48: a selected-record pointer for the found arm changed size to 320
// bytes and 321 differing bytes; rolled back to the canonical indexed source.
// Probe 41 resumed: the interrupted same-TU declaration-only TDigital context
// probe is current; rebuild was a codegen duplicate at 346 bytes and 21
// differing bytes.  Retained the canonical typed source and closed the lead.
// Resume worker probes: a self reference, branch-local sound-list pointer,
// narrow count, pointer scan, const count, buffer declaration reorder, saved
// time local, and direct percent expression were tested.  The pointer scan
// reached 347/239; the sound-list pointer reached 354/282; narrow count
// reached 358/295.  Other forms were 346/21 duplicates.  All failed forms
// were restored.  Final clean validation remains 346 bytes with 21 differing
// bytes, matching owner, calls, frame, and boundary.

#include "..\..\include\game_globals.h"

#ifndef SOUND_CANONICAL_TU
class RGE_Sound_Info;
class TSound_Driver;

class RGE_Sound {
public:
    short play_at_update_count;  // +0x00
    short sound_num;             // +0x02
    RGE_Sound_Info* sounds;      // +0x04
    int cache_time;              // +0x08
    short id;                    // +0x0C

    void play(int param);
};

class TDigital {
public:
    TSound_Driver* sound_system; // +0x00
    TDigital* owner;             // +0x04
    unsigned char loaded;        // +0x08
    unsigned char failed;        // +0x09
    char sound_file[13];         // +0x0A
    unsigned char pad_17;        // +0x17
    long resource_id;            // +0x18
    long volume;                 // +0x1C
    unsigned long pitch;         // +0x20
    long pan;                    // +0x24
    int loop;                    // +0x28
    unsigned char* wave_data;    // +0x2C
    void* wave_info;             // +0x30
    void* sound_buffer;          // +0x34
    char gap_38[4];              // +0x38
    int play();
    int add_to_play_list();
};

class RGE_Sound_Info {
public:
    char name[13];               // +0x00
    char _gap_0D[3];
    long resource_id;            // +0x10
    short percent;               // +0x14
    char _gap_16[2];
    TDigital* digital_sound;     // +0x18
    unsigned char loaded;        // +0x1C
    char _gap_1D[3];
    unsigned long time;          // +0x20
};
#endif

#ifndef SOUND_CANONICAL_TU
extern "C" int __cdecl debug_rand(char* file, int line);
extern "C" int __cdecl sprintf(char* buf, const char* fmt, ...);
extern "C" unsigned long __cdecl debug_timeGetTime(char* file, int line);

extern void __cdecl write_draw_log(char* msg);
extern void __cdecl write_draw_log2(char* msg);

// Globals (extern)
extern int do_draw_log;       // 0x62C498
extern int safe_draw_log;     // 0x592A5C
extern int debug_timeGetTime_on;  // 0x62C4E8
#endif

void RGE_Sound::play(int play_list_param)
{
    char s[256];
    int sound_count;
    int idx;

    if (this->sound_num > 0) {
        int rand_val = debug_rand("C:\\msdev\\work\\age1_x1\\Sound.cpp", 0xDD);
        rand_val = (rand_val * 100) / 0x7FFF;

        sound_count = this->sound_num;
        idx = 0;
        if (sound_count > 0) {
            for (; idx < sound_count; ++idx) {
                short percent = this->sounds[idx].percent;
                rand_val -= percent;
                if (rand_val <= 0) {
                    if (this->sounds[idx].digital_sound != 0) {
                        if (do_draw_log) {
                            sprintf(s, "{%s", this->sounds[idx].name);
                            if (safe_draw_log)
                                write_draw_log2(s);
                            else
                                write_draw_log(s);
                        }

                        if (play_list_param)
                            this->sounds[idx].digital_sound->add_to_play_list();
                        else
                            this->sounds[idx].digital_sound->play();

                        if (do_draw_log) {
                            if (safe_draw_log)
                                write_draw_log2("}");
                            else
                                write_draw_log("}");
                        }

                        this->sounds[idx].loaded = 1;
                        int saved_time_get = debug_timeGetTime_on;
                        debug_timeGetTime_on = 0;
                        unsigned long time_val = debug_timeGetTime(
                            "C:\\msdev\\work\\age1_x1\\Sound.cpp", 0x108);
                        this->sounds[idx].time = time_val;
                        debug_timeGetTime_on = saved_time_get;
                    }
                    return;
                }
            }
        }
    }
}
