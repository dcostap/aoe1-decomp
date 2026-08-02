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
// Paused: all 68 instructions, four call targets, size, frame, and CFG match;
//   remaining bytes are only VC5 SIB base/index operand-order choices at
//   direct byte-record accesses.

#include "..\..\include\game_globals.h"

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

extern void* __cdecl operator_new(unsigned int size);
extern void __cdecl operator_delete(void* ptr);

void RGE_Sound::restart_sound(TSound_Driver* driver)
{
    int i = 0;
    if (this->sound_num > 0) {
        int offset = 0;
        do {
            TDigital* digital =
                ((RGE_Sound_Info*)((char*)this->sounds + offset))->digital_sound;
            if (digital != 0) {
                digital->~TDigital();
                operator_delete(digital);
            }
            if (driver != 0) {
                digital = new TDigital(driver,
                    ((RGE_Sound_Info*)((char*)this->sounds + offset))->name,
                    ((RGE_Sound_Info*)((char*)this->sounds + offset))->resource_id);
                ((RGE_Sound_Info*)((char*)this->sounds + offset))->digital_sound = digital;
            } else {
                ((RGE_Sound_Info*)((char*)this->sounds + offset))->digital_sound = 0;
            }
            ((RGE_Sound_Info*)((char*)this->sounds + offset))->loaded = 2;
            ++i;
            offset += 0x24;
        } while (i < this->sound_num);
    }
}
