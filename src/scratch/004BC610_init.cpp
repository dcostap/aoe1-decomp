// Attempt log:
// - Baseline local COM/vtable reconstruction had exact size/frame but the
//   DirectSound import name was wrong and SetFormat failure was treated as a
//   cleanup edge not present in the executable.
// - Renamed the import to the period DirectSoundCreate WINAPI symbol.
// - Reconstructed the positive CreateSoundBuffer body: SetFormat's result is
//   overwritten by Play, and the two observed Release effects remain separate
//   source paths even though VC5 still merges their emitted call site.
// - Restored the VC5-era DSOUND.H interface surface and moved DSCAPS size
//   initialization to the GetCaps band; this moved the first mismatch to the
//   capability/priority flag and improved the structural diff substantially.
// - Binary evidence fixes the format to 22050 Hz / 44100 average bytes/sec.
// - The remaining blocker is VC5 commoning one of the two original indirect
//   Release sites and associated register/frame coloring; no productive lead
//   remains in this bounded pass.
#include <string.h>
#include <dsound.h>

extern "C" void __cdecl ds_stream_init(void* main_wnd, void* direct_sound, void* primary_buffer);
extern void __cdecl TSound_Driver_set_path(void*, char*);

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
    bool has_secondary;

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
        if (this->dsrval == 0) {
            has_secondary = 1;
            goto after_level;
        }
    }

    this->dsrval = this->direct_sound->SetCooperativeLevel((HWND)this->main_wnd, 1);

after_level:
    if (this->dsrval != 0) {
        this->direct_sound->Release();
        this->direct_sound = 0;
        return 0;
    }

    memset(&dsbd, 0, sizeof(dsbd));
    dsbd.dwSize = 0x14;
    dsbd.dwFlags = 1;
    this->dsrval = this->direct_sound->CreateSoundBuffer(&dsbd, &this->primary_buffer, 0);
    if (this->dsrval == 0) {
        if (has_secondary) {
            memset(&fmt, 0, sizeof(fmt));
            fmt.wFormatTag = 1;
            fmt.nChannels = 1;
            fmt.nSamplesPerSec = 0x5622;
            fmt.wBitsPerSample = 0x10;
            fmt.nBlockAlign = 2;
            fmt.nAvgBytesPerSec = 0xAC44;
            fmt.cbSize = 0;
            this->dsrval = this->primary_buffer->SetFormat(&fmt);
        }

        this->dsrval = this->primary_buffer->Play(0, 0, 1);
    }

    if (this->dsrval != 0) {
        this->direct_sound->Release();
        this->direct_sound = 0;
        return 0;
    }

    this->ready = 1;
    ds_stream_init(hwnd, this->direct_sound, this->primary_buffer);
    this->open_mixer();
    return this->ready;
}
