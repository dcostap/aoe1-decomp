// Attempt: use getchar-style hwnd retrieval, bool_flag, early_dwsize
#include <string.h>

extern "C" int __stdcall _DirectSoundCreate_12(void* a, void** b, void* c);
extern "C" void __cdecl ds_stream_init(void* main_wnd, void* direct_sound, void* primary_buffer);
extern void __cdecl TSound_Driver_set_path(void*, char*);

struct DSCAPS {
    unsigned long dwSize;
    unsigned long dwFlags;
    unsigned long dwMinSecondarySampleRate;
    unsigned long dwMaxSecondarySampleRate;
    unsigned long dwPrimaryBuffers;
    unsigned long dwMaxHwMixingAllBuffers;
    unsigned long dwMaxHwMixingStaticBuffers;
    unsigned long dwMaxHwMixingStreamingBuffers;
    unsigned long dwFreeHwMixingAllBuffers;
    unsigned long dwFreeHwMixingStaticBuffers;
    unsigned long dwFreeHwMixingStreamingBuffers;
    unsigned long dwMaxHw3DAllBuffers;
    unsigned long dwMaxHw3DStaticBuffers;
    unsigned long dwMaxHw3DStreamingBuffers;
    unsigned long dwFreeHw3DAllBuffers;
    unsigned long dwFreeHw3DStaticBuffers;
    unsigned long dwFreeHw3DStreamingBuffers;
    unsigned long dwTotalHwMemBytes;
    unsigned long dwFreeHwMemBytes;
    unsigned long dwMaxContigFreeHwMemBytes;
    unsigned long dwUnlockTransferRateHwBuffers;
    unsigned long dwPlayCpuOverheadSwBuffers;
    unsigned long dwReserved1;
    unsigned long dwReserved2;
};

struct DSBUFFERDESC {
    unsigned long dwSize;
    unsigned long dwFlags;
    unsigned long dwBufferBytes;
    unsigned long dwReserved;
    void* lpwfxFormat;
};

struct WAVEFORMATEX {
    unsigned short wFormatTag;
    unsigned short nChannels;
    unsigned long nSamplesPerSec;
    unsigned long nAvgBytesPerSec;
    unsigned short nBlockAlign;
    unsigned short wBitsPerSample;
    unsigned short cbSize;
};

struct IDirectSoundVtbl {
    char gap_00[8];
    int (__stdcall *Release)(void* thisptr);
    int (__stdcall *CreateSoundBuffer)(void* thisptr, DSBUFFERDESC* desc, void** buffer, void* unk);
    int (__stdcall *GetCaps)(void* thisptr, DSCAPS* caps);
    char gap_14[4];
    int (__stdcall *SetCooperativeLevel)(void* thisptr, void* hwnd, int level);
};

struct IDirectSound { IDirectSoundVtbl* vtbl; };
struct IDirectSoundBufferVtbl {
    char gap_00[8];
    int (__stdcall *Release)(void* thisptr);
    char gap_0C[0x24];
    int (__stdcall *Play)(void* thisptr, unsigned long a, unsigned long b, unsigned long flags);
    int (__stdcall *SetCurrentPosition)(void* thisptr, unsigned long pos);
    int (__stdcall *SetFormat)(void* thisptr, WAVEFORMATEX* fmt);
};
struct IDirectSoundBuffer { IDirectSoundBufferVtbl* vtbl; };

class TSound_Driver {
public:
    unsigned char ready;
    unsigned char mute;
    unsigned char gap_02[2];
    void* main_wnd;
    IDirectSound* direct_sound;
    IDirectSoundBuffer* primary_buffer;
    int dsrval;
    char gap_14[0x04];
    int volume;
    char path[260];
    int mixer_open;
    void* mixer_handle;
    void set_path(char*);
    int init(void* hwnd, char* path);
    int open_mixer(void);
};

int TSound_Driver::init(void* hwnd, char* path) {
    DSCAPS dscaps;
    DSBUFFERDESC dsbd;
    WAVEFORMATEX fmt;
    int has_secondary;

    dscaps.dwSize = 0x60;

    this->set_path(path);
    this->main_wnd = hwnd;
    this->ready = 0;

    this->dsrval = _DirectSoundCreate_12(0, (void**)&this->direct_sound, 0);
    if (this->dsrval != 0) return 0;

    this->direct_sound->vtbl->GetCaps(this->direct_sound, &dscaps);

    has_secondary = (dscaps.dwFlags & 8) != 0;

    if (has_secondary) {
        this->dsrval = this->direct_sound->vtbl->SetCooperativeLevel(this->direct_sound, this->main_wnd, 2);
        if (this->dsrval == 0) goto after_level;
    }

    this->dsrval = this->direct_sound->vtbl->SetCooperativeLevel(this->direct_sound, this->main_wnd, 1);

after_level:
    if (this->dsrval != 0) {
        this->direct_sound->vtbl->Release(this->direct_sound);
        this->direct_sound = 0;
        return 0;
    }

    memset(&dsbd, 0, sizeof(dsbd));
    dsbd.dwSize = 0x14;
    dsbd.dwFlags = 1;
    this->dsrval = this->direct_sound->vtbl->CreateSoundBuffer(this->direct_sound, &dsbd, (void**)&this->primary_buffer, 0);
    if (this->dsrval != 0) goto fail;

    if (has_secondary) {
        memset(&fmt, 0, sizeof(fmt));
        fmt.wFormatTag = 1;
        fmt.nChannels = 1;
        fmt.nSamplesPerSec = 0xAC44;
        fmt.wBitsPerSample = 0x10;
        fmt.nBlockAlign = 2;
        fmt.nAvgBytesPerSec = 0xAC44 * 2;
        fmt.cbSize = 0;
        this->dsrval = this->primary_buffer->vtbl->SetFormat(this->primary_buffer, &fmt);
        if (this->dsrval != 0) goto fail;
    }

    this->dsrval = this->primary_buffer->vtbl->Play(this->primary_buffer, 0, 0, 1);
    if (this->dsrval != 0) goto fail;

    this->ready = 1;
    ds_stream_init(hwnd, this->direct_sound, this->primary_buffer);
    this->open_mixer();
    return this->ready;

fail:
    this->direct_sound->vtbl->Release(this->direct_sound);
    this->direct_sound = 0;
    return 0;
}
