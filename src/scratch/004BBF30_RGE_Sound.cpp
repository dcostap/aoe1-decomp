// 004BBF30 RGE_Sound::RGE_Sound (rge_read-based ctor, EH-framed)
// Source: Sound.cpp lines 64-89
// Size: 306 bytes, EH-framed
//
// Attempt log:
// Baseline: period-plausible two-stage sound-count guards, typed 0x24-byte
// RGE_Sound_Info records, and the declaration-only TDigital construction
// surface used by matching restart_sound; 206 differing bytes.
// Probe 2: nested duplicate positive guard moved the cold else/loop topology
// into place but added three bytes from a register-held count reload.
// Probe 3: a named short* sound_count (also used as the rge_read destination)
// recovered exact size, calls, frame, and all but six bytes; it preserves the
// proven field address and direct post-calloc compare.  This is the best
// canonical source reconstruction.
// Probes 4-5: calloc result temporaries and explicit false-arm assignments
// added structural branches/bytes; rolled back.
// Probe 7: mixed pointer/member count guards returned to the three-byte drift.
// Probe 8: separate allocation/initialization guards were optimized back to
// the baseline topology; rolled back.
// Probe 9: focused guard variant lab was invalid as a full-source context
// experiment (relative include caused appended-context artifacts); no lead.
// Probe 10: moved sound_count declaration to its natural post-header location
// and reused it for rge_read; emitted code duplicated the six-byte best.
// Probe 14: scoped calloc result with the member store only in the positive
// arm reproduced the earlier 315-byte duplicated-compare basin; rolled back.
// Probe 16: a focused header/source variant lab was invalid without the
// function's /GX context and produced appended-context artifacts; no lead.
// Probe 18: standard <stdlib.h> calloc declaration with direct members was a
// codegen duplicate of the broad direct-member mismatch; rolled back.
// Probe 19: same-TU <stdio.h>/<string.h> context from the text constructor
// donor was a codegen duplicate; rolled back.
// Probe 20 (new worker): aligned the local Sound_Info declaration with the
// generated 0x24-byte source-of-truth types (unsigned padding/loaded/time).
// Probe 20 result: declaration alignment was a codegen duplicate and is kept
// as the canonical typed layout.
// Best remaining drift: original compares [sound_num] before storing the
// calloc result to [this+4], while VC5 emits the same two operations reversed.
// Main-agent audit removed the diagnostic pointer alias for sound_num; direct
// member reads are the natural constructor source even though they return to a
// less favorable scheduling basin.
// Paused: direct-member source is structurally clean as source but VC5 reloads
// sound_num after calloc, producing a 3-byte post-call expansion and broad
// shifted drift.  The near-match member-pointer alias is retained only as
// evidence, not as living source.
// Probe 22: restoring the short* sound_count alias returned the prior 306-byte
// basin (6 differing bytes); it emits the calloc result store before the
// post-call count compare, opposite the oracle, so it remains diagnostic.
// Probe 23: a local calloc result assigned inside the repeated positive guard
// produced a 315-byte/extra-CFG basin; rolled back.
// Probe 24: a narrow volatile post-calloc reread duplicated that 315-byte
// basin; no source-plausible lead, rolled back.
// Probe 25: pointer-only post-calloc guard returned to the 6-byte basin with
// the same store/compare reversal; no improvement.
// Probe 26: raw +2 sound_num reread reproduced the 309-byte direct-member
// basin; rolled back as decompiler-shaped and nonproductive.
// Probe 27: a short reference alias reproduced the 6-byte basin; no change.
// Probe 28: volatile sound_num changed the early rge_read scheduling and fell
// to 303 bytes/216 differing bytes; rolled back.
// Probe 29: generated unsigned-long cache_time layout was a codegen duplicate.
// Probe 30: void rge_read ABI from exact same-TU donors was a duplicate.
// Probe 31: a value sound_count local was a duplicate of the 309-byte basin.
// Fresh probe 34: reversed the inner alias predicate; it was a codegen
// duplicate of the six-byte allocator hunk.
// Fresh probe 35: matched the decompiler's negative outer guard; VC5 emitted
// a cmp-to-one, an extra branch, and a 320-byte structural mismatch.
// Fresh probe 37: made the count alias const; it was a codegen duplicate.
// Final clean source: restored direct typed member reconstruction; best
// diagnostic codegen remains the 306-byte pointer-alias variant at 6 bytes,
// while the living source stays canonical and period-plausible.
// Worker audit: Sound.cpp donors 004BBE40 and 004BC190 use named typed
// RGE_Sound_Info arrays and direct member access.  The six-byte alias changes
// only the calloc compare/store order; it does not change constructor behavior.
// Keep it as diagnostic evidence only.  The direct-member source is the
// canonical policy-compliant reconstruction despite its 309-byte basin.
// Worker tu-sound-BBF30: dossier, ABI, same-TU donors, and localized assembly
// donors confirm this ownership.  The only near-match needs a short* alias
// for compiler scheduling, so no natural source lead remains.  Preserve the
// direct typed member source and pause at the structural compare/store hunk.

#include "..\..\include\game_globals.h"

class RGE_Sound_Info;

class TSound_Driver;

class RGE_Sound {
public:
    short play_at_update_count;  // +0x00
    short sound_num;             // +0x02
    RGE_Sound_Info* sounds;      // +0x04
    int cache_time;              // +0x08
    short id;                    // +0x0C

    RGE_Sound(int handle, TSound_Driver* driver);
};

class TDigital {
public:
    char bytes[0x3C];
    TDigital(TSound_Driver* driver, char* file, long resource_id);
    ~TDigital();
};

class RGE_Sound_Info {
public:
    char name[13];               // +0x00
    unsigned char _gap_0D[3];
    long resource_id;            // +0x10
    short percent;               // +0x14
    unsigned char _gap_16[2];
    TDigital* digital_sound;     // +0x18
    unsigned char loaded;         // +0x1C
    unsigned char _gap_1D[3];
    unsigned long time;           // +0x20
};

extern int __cdecl rge_read(int handle, void* buf, int size);
extern void* __cdecl calloc(int num, int size);

RGE_Sound::RGE_Sound(int handle, TSound_Driver* driver)
{
    rge_read(handle, &this->id, 2);
    rge_read(handle, this, 2);
    rge_read(handle, &this->sound_num, 2);
    rge_read(handle, &this->cache_time, 4);

    if (this->sound_num > 0) {
        this->sounds = (RGE_Sound_Info*)calloc(this->sound_num, 0x24);
        if (this->sound_num > 0) {
            for (int i = 0; i < this->sound_num; i++) {
                rge_read(handle, this->sounds[i].name, 0x0D);
                rge_read(handle, &this->sounds[i].resource_id, 4);
                rge_read(handle, &this->sounds[i].percent, 2);
                this->sounds[i].digital_sound = new TDigital(
                    driver, this->sounds[i].name, this->sounds[i].resource_id);
                this->sounds[i].loaded = 2;
            }
        }
    } else {
        this->sounds = 0;
    }
}
