// TSound_Driver::init
// Best attempt: correct frame size (0x88), correct struct sizes, has_secondary flag.
// Remaining gap: VC5 keeps hwnd in ebx instead of ecx (register allocation diff at offset 23).
// This cascading difference leads to ~75% positional mismatch.
// Suggested approach: variant_lab with register_pressure and hwnd_usage axes,
// or try reading hwnd from this->main_wnd via a volatile barrier.
#include <string.h>

extern "C" int __stdcall _DirectSoundCreate_12(void* a, void** b, void* c);
extern "C" void __cdecl ds_stream_init(void* main_wnd, void* direct_sound, void* primary_buffer);

struct TSound_Driver {
    unsigned char ready;
    unsigned char mute;
    char gap_02[2];
    void* main_wnd;
    void* direct_sound;
    void* primary_buffer;
    int dsrval;
    int start_volume;
    int volume;
    char path[260];
    int mixer_open;
    void* mixer_handle;

    void set_path(char* param_1);
    int init(void* hwnd, char* path);
    int open_mixer(void);
};

int TSound_Driver::init(void* hwnd, char* path) {
    struct {
        unsigned long dwSize;
        unsigned long dwFlags;
        unsigned long dwReserved[22];
    } dscaps;

    struct {
        unsigned long dwSize;
        unsigned long dwFlags;
        unsigned long dwBufferBytes;
        unsigned long dwReserved;
        void* lpwfxFormat;
    } dsbd;

    struct {
        unsigned short wFormatTag;
        unsigned short nChannels;
        unsigned long nSamplesPerSec;
        unsigned long nAvgBytesPerSec;
        unsigned short nBlockAlign;
        unsigned short wBitsPerSample;
        unsigned short cbSize;
    } fmt;

    int has_secondary;

    this->set_path(path);
    this->main_wnd = hwnd;
    this->ready = 0;

    this->dsrval = _DirectSoundCreate_12(0, (void**)&this->direct_sound, 0);
    if (this->dsrval != 0) {
        return 0;
    }

    dscaps.dwSize = 0x60;
    ((int (__stdcall*)(void*, void*))(*(void***)this->direct_sound)[4])(this->direct_sound, &dscaps);

    has_secondary = 0;
    if ((dscaps.dwFlags & 8) != 0) {
        this->dsrval = ((int (__stdcall*)(void*, void*, int))(*(void***)this->direct_sound)[6])(
            this->direct_sound, this->main_wnd, 2);
        if (this->dsrval == 0) {
            has_secondary = 1;
            goto check_result;
        }
    }

    this->dsrval = ((int (__stdcall*)(void*, void*, int))(*(void***)this->direct_sound)[6])(
        this->direct_sound, this->main_wnd, 1);

check_result:
    if (this->dsrval != 0) {
        ((int (__stdcall*)(void*))(*(void***)this->direct_sound)[2])(this->direct_sound);
        this->direct_sound = 0;
        return 0;
    }

    dsbd.dwSize = 0x14;
    dsbd.dwFlags = 1;
    this->dsrval = ((int (__stdcall*)(void*, void*, void**, void*))(*(void***)this->direct_sound)[3])(
        this->direct_sound, &dsbd, (void**)&this->primary_buffer, 0);
    if (this->dsrval != 0) {
        ((int (__stdcall*)(void*))(*(void***)this->direct_sound)[2])(this->direct_sound);
        this->direct_sound = 0;
        return 0;
    }

    if (has_secondary) {
        fmt.wFormatTag = 1;
        fmt.nChannels = 1;
        fmt.nSamplesPerSec = 22050;
        fmt.nAvgBytesPerSec = 44100;
        fmt.nBlockAlign = 2;
        fmt.wBitsPerSample = 16;
        fmt.cbSize = 0;
        this->dsrval = ((int (__stdcall*)(void*, void*))(*(void***)this->primary_buffer)[14])(
            this->primary_buffer, &fmt);
        if (this->dsrval != 0) {
            ((int (__stdcall*)(void*))(*(void***)this->direct_sound)[2])(this->direct_sound);
            this->direct_sound = 0;
            return 0;
        }
    }

    this->dsrval = ((int (__stdcall*)(void*, unsigned long, unsigned long, unsigned long))(*(void***)this->primary_buffer)[12])(
        this->primary_buffer, 0, 0, 1);
    if (this->dsrval != 0) {
        ((int (__stdcall*)(void*))(*(void***)this->direct_sound)[2])(this->direct_sound);
        this->direct_sound = 0;
        return 0;
    }

    this->ready = 1;
    ds_stream_init(this->main_wnd, this->direct_sound, this->primary_buffer);
    this->open_mixer();
    return this->ready;
}
