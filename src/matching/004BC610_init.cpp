// Exact reconstruction notes:
// - Use the VC5 DirectSound interfaces and the period DirectSoundCreate import.
// - SetFormat failure does not cause cleanup. Play overwrites its result.
// - The executable sets a 22050 Hz, 16-bit mono primary-buffer format.
// - It writes each WAVEFORMATEX field, but it clears DSBUFFERDESC with memset.
// - BINARY NOTE: CreateSoundBuffer and Play have separate early failure paths.
//   VC5 merges their final Release, clear, and return body.
// - BINARY NOTE: The success path reloads main_wnd from the object before
//   ds_stream_init. It does not reuse the incoming hwnd parameter.
// - Exact walkback removed receiver aliases without changing the output.
//   Nesting the CreateSoundBuffer success body lost one Release call and no
//   longer matched. The separate Create failure return is required.
#include <string.h>
#ifndef SOUNDDRV_CANONICAL_TU
#include <dsound.h>
#endif

extern "C" void __cdecl ds_stream_init(void* main_wnd, void* direct_sound, void* primary_buffer);
extern void __cdecl TSound_Driver_set_path(void*, char*);

#ifndef SOUNDDRV_CANONICAL_TU
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
#endif

int TSound_Driver::init(void* hwnd, char* path) {
    int has_secondary;
    DSCAPS dscaps;
    DSBUFFERDESC dsbd;
    WAVEFORMATEX fmt;

    this->set_path(path);
    this->main_wnd = hwnd;
    this->ready = 0;

    this->dsrval = DirectSoundCreate(0, &this->direct_sound, 0);
    if (this->dsrval != 0) return 0;

    dscaps.dwSize = 0x60;
    this->direct_sound->GetCaps(&dscaps);

    has_secondary = 0;

    if ((dscaps.dwFlags & 8) != 0) {
        this->dsrval = this->direct_sound->SetCooperativeLevel((HWND)this->main_wnd, 2);
        if (this->dsrval != 0) {
            this->dsrval = this->direct_sound->SetCooperativeLevel((HWND)this->main_wnd, 1);
        } else {
            has_secondary = 1;
        }
    } else {
        this->dsrval = this->direct_sound->SetCooperativeLevel((HWND)this->main_wnd, 1);
    }

    if (this->dsrval != 0) {
        this->direct_sound->Release();
        this->direct_sound = 0;
        return 0;
    }

    memset(&dsbd, 0, sizeof(dsbd));
    dsbd.dwSize = 0x14;
    dsbd.dwFlags = 1;
    this->dsrval = this->direct_sound->CreateSoundBuffer(&dsbd, &this->primary_buffer, 0);
    if (this->dsrval != 0) {
        this->direct_sound->Release();
        this->direct_sound = 0;
        return 0;
    }

    if (has_secondary) {
        fmt.wFormatTag = 1;
        fmt.nChannels = 1;
        fmt.nSamplesPerSec = 0x5622;
        fmt.nAvgBytesPerSec = 0xAC44;
        fmt.nBlockAlign = 2;
        fmt.wBitsPerSample = 0x10;
        fmt.cbSize = 0;
        this->dsrval = this->primary_buffer->SetFormat(&fmt);
    }

    this->dsrval = this->primary_buffer->Play(0, 0, 1);
    if (this->dsrval != 0) {
        this->direct_sound->Release();
        this->direct_sound = 0;
        return 0;
    }

    this->ready = 1;
    ds_stream_init(this->main_wnd, this->direct_sound, this->primary_buffer);
    this->open_mixer();
    return this->ready;
}
