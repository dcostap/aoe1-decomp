// first pass: walk to the owner-chain tail, stop if not loaded, then release/free the tail resources
// if this is sticky, the remaining gap is likely just VC5 branch order or tail cleanup sequencing
#include "..\..\include\game_types.h"

extern "C" void __cdecl free(void* block);

class IDirectSoundBuffer {
public:
    virtual void QueryInterface();
    virtual void AddRef();
    virtual void Release();
};

class TSound_Driver {
public:
    char pad_00[0x48];
    int ready;
};

class TDigital {
public:
    TSound_Driver* sound_system;
    TDigital* owner;
    unsigned char loaded;
    unsigned char failed;
    char sound_file[13];
    unsigned char pad_17;
    long resource_id;
    long volume;
    unsigned long pitch;
    long pan;
    int loop;
    unsigned char* wave_data;
    void* wave_info;
    IDirectSoundBuffer* sound_buffer;

    void stop();
    void unload();
};

void TDigital::unload() {
    TDigital* digital = this;
    TDigital* next = digital->owner;

    while (next != 0) {
        digital = next;
        next = digital->owner;
    }

    if (digital->loaded != 0) {
        IDirectSoundBuffer* buffer;

        digital->stop();
        buffer = digital->sound_buffer;
        if (buffer != 0) {
            buffer->Release();
            digital->sound_buffer = 0;
        }

        if (digital->wave_data != 0) {
            free(digital->wave_data);
            digital->wave_data = 0;
        }

        if (digital->wave_info != 0) {
            free(digital->wave_info);
            digital->wave_info = 0;
        }

        digital->loaded = 0;
    }

    digital->failed = 0;
}
