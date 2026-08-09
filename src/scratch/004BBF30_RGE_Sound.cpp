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
// Best remaining drift: original compares [sound_num] before storing the
// calloc result to [this+4], while VC5 emits the same two operations reversed.
// Main-agent audit removed the diagnostic pointer alias for sound_num; direct
// member reads are the natural constructor source even though they return to a
// less favorable scheduling basin.

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
    char _gap_0D[3];
    long resource_id;            // +0x10
    short percent;               // +0x14
    char _gap_16[2];
    TDigital* digital_sound;     // +0x18
    char loaded;                 // +0x1C
    char _gap_1D[3];
    long time_field;              // +0x20
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
