// 004BC190 RGE_Sound::restart_sound
// Source: Sound.cpp lines 151-165
// Size: 215 bytes, EH-framed
//
// Attempt log:
// Probe 1: 176/215 bytes — the default-constructed TDigital stub emitted an
//   inline default construction path instead of the observed three-argument
//   constructor call.
// Baseline: use the binary-supported TDigital size and constructor surface;
//   the natural three-argument construction and explicit destructor/delete
//   calls should lower to the observed EH, allocation, and cleanup calls.
// Probe 2: switched to a count-up do/while, direct byte-record cursor, and
//   explicit destructor/operator-delete calls; size/CFG/call set became exact.
// Probe 3: reversed pointer-addition terms; VC5 emitted the same seven-byte
//   SIB-order drift (duplicate codegen).
// Probe 4: carried a local sound-array base; worsened to a frame/CFG mismatch;
//   rolled back.
// Probe 5: used direct raw byte-base accesses; returned to the seven-byte drift.
// Probe 6: corrected RGE_Sound_Info to its generated 0x24 layout/types; no
//   emitted change.
// Probe 7: address-expression lab without /GX was invalid context (no EH).
// Probe 8: /GX address-expression lab grouped all tested forms at the same
//   seven-byte drift.
// Probe 9: typed RGE_Sound_Info member accesses; duplicate codegen.
// Probe 10: opaque void* donor surface; duplicate codegen. Retain the typed
//   RGE_Sound_Info ownership below as the more plausible source model.
// Probe 11: canonical same-TU array indexing (`this->sounds[i]`) recovered the
//   original seven SIB base/index operand bytes; all metrics became exact.
// Probe 12: removed the now-unused decompiler offset cursor; emitted code stayed
//   exact, leaving the natural indexed loop as the living source.
// Exact: 215/215 bytes, 68/68 instructions, four calls, and full CFG/block
//   parity under /GX. The key source shape is the period-plausible indexed
//   RGE_Sound_Info array surface used by exact Sound.cpp donors.
// Main-agent audit replaced the explicit destructor/operator-delete pair with
// natural `delete digital`; VC5 emits identical exact code.

#include "..\..\include\game_globals.h"

#ifndef SOUND_CANONICAL_TU
class RGE_Sound_Info;

class TSound_Driver;

class RGE_Sound {
public:
    short play_at_update_count;  // +0x00
    short sound_num;             // +0x02
    RGE_Sound_Info* sounds;      // +0x04; 0x24-byte Sound_Info records
    int cache_time;              // +0x08
    short id;                    // +0x0C

    void restart_sound(TSound_Driver* driver);
};

// TDigital is a non-polymorphic 0x3C-byte object.  Keep the constructor and
// destructor declaration-only so calls resolve to the existing Sounddrv.cpp
// implementations without emitting unrelated local COMDATs.
class TDigital {
public:
    char bytes[0x3C];
    TDigital(TSound_Driver* driver, char* file, long resource_id);
    ~TDigital();
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

void RGE_Sound::restart_sound(TSound_Driver* driver)
{
    int i = 0;
    if (this->sound_num > 0) {
        do {
            TDigital* digital = this->sounds[i].digital_sound;
            if (digital != 0) {
                delete digital;
            }
            if (driver != 0) {
                digital = new TDigital(driver,
                    this->sounds[i].name,
                    this->sounds[i].resource_id);
                this->sounds[i].digital_sound = digital;
            } else {
                this->sounds[i].digital_sound = 0;
            }
            this->sounds[i].loaded = 2;
            ++i;
        } while (i < this->sound_num);
    }
}
