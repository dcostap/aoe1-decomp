// TDigital::load
// Period-plausible WAV file/resource loading with the VC5 DirectSound ABI.
// Attempt log:
// - Rebuilt the file and resource paths from the original call order and stack homes.
// - Kept the five-field DSBUFFERDESC and named DirectSound vtable slots.
// - Separate cleanup branches recover all 42 original calls and the 0x15C frame.
// - An unsigned result local around both read calls reproduces cmp/ja lowering.
// - The explicit <= -1 resource gate reproduces the original cmp/jle boundary.
// - The resource Lock path tests size2. This matches its proven stack-local test.
// - A function-scope sound_buffer slot alias reduces the strict diff from 874 to 845.
// - Rejected direct positive read guards, signed read/result types, direct Create
//   guards, branch-local aliases, delayed aliases, and explicit recursive return 0.
// - Final validation: 1475-byte output, 42 calls, 0x15C frame, 845-byte strict diff.
// - Remaining drift is resource descriptor register coloring and cleanup-tail
//   layout, plus the recursive-call relocation identity.
// Claim sa-0f3d8299 probes (2026-08-22):
// - Removing the branch-local failure log did not change codegen.
// - Assigning the slot alias at each Create site worsened the diff to 872 bytes.
// - PDB local declaration order, windows.h context, and alias declaration order
//   were neutral. The full dsound.h surface worsened frame and shape.
// - Passing load_type as the branch-local log value improved strict diff to 838,
//   but added five bytes and worsened resynchronization; the natural clean source
//   remains the 1475-byte, 845-byte-diff form.
// TU captain notes (phase4):
// - Context gate proved Sounddrv.cpp, lines 507-826, TDigital ownership, and
//   the ordered 36-owner address sequence. The wrapper uses the same sequence.
// - Removed grouped-only alternate bodies from the 13 observed exact candidates.
//   Their canonical declarations remain guarded for standalone source checks.
// - Direct sound_buffer member calls reduced the grouped load diff from 986 to
//   430. A local failure label reduced the standalone diff to 385.
// - The resource buffer-slot alias reduced the final grouped diff to 383.
// - Final grouped candidate: 22 exact owners MATCH; 13 observed owners MATCH;
//   load is 1488 bytes, 383 bytes different, with one boundary escape.
// - UNRESOLVED: resource-path field scheduling, zero-register coloring, and the
//   self-recursion call identity still differ from the original.
#include <string.h>
#include <stdlib.h>

#ifndef SOUNDDRV_CANONICAL_TU
typedef unsigned char uchar;

typedef int (__stdcall *DSCreateSoundBufferFn)(void*, void*, void**, void*);
typedef int (__stdcall *DSLockFn)(void*, unsigned long, unsigned long,
    void**, unsigned long*, void**, unsigned long*, unsigned long);
typedef int (__stdcall *DSUnlockFn)(void*, void*, unsigned long, void*, unsigned long);
typedef int (__stdcall *DSReleaseFn)(void*);

struct IDirectSoundVtbl {
    char gap_00[0x0C];
    DSCreateSoundBufferFn CreateSoundBuffer;
};

struct IDirectSound {
    IDirectSoundVtbl* vtable;
};

struct IDirectSoundBufferVtbl {
    char gap_00[0x08];
    DSReleaseFn Release;
    char gap_0C[0x20];
    DSLockFn Lock;
    char gap_30[0x1C];
    DSUnlockFn Unlock;
};

struct IDirectSoundBuffer {
    IDirectSoundBufferVtbl* vtable;
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

struct WAVHEADER {
    unsigned char szRIFF[4];
    unsigned long dwFormatLength;
    unsigned char szWAVE[4];
    unsigned char szFMT[4];
    unsigned long dwWaveFormatLength;
    unsigned short wFormatTag;
    unsigned short nChannels;
    unsigned long nSamplesPerSec;
    unsigned long nAvgBytesPerSec;
    unsigned short nBlockAlign;
    unsigned short wBitsPerSample;
    unsigned char szDATA[4];
    unsigned long dwDataLength;
};
#endif

extern "C" int __cdecl __open(const char* path, int flags, int mode);
extern "C" int __cdecl close(int fd);
extern "C" unsigned int __cdecl read(int fd, void* buf, unsigned int count);
extern "C" int __cdecl strncmp(const char* s1, const char* s2, unsigned int n);
extern "C" int __cdecl sprintf(char* buf, const char* fmt, ...);
extern "C" void __cdecl color_log(unsigned char a, unsigned char b, int c);
extern "C" uchar* __cdecl RESFILE_load(unsigned long type, int id, int* load_type, int* data_size);
extern uchar sound_file_first;

#ifndef SOUNDDRV_CANONICAL_TU
class TSound_Driver {
public:
    uchar ready;
    uchar mute;
    char gap_02[2];
    void* main_wnd;
    IDirectSound* direct_sound;
    IDirectSoundBuffer* primary_buffer;
    int dsrval;
    int start_volume;
    int volume;
    char path[260];
};

class TDigital {
public:
    TSound_Driver* sound_system;
    TDigital* owner;
    uchar loaded;
    uchar failed;
    char sound_file[13];
    uchar gap_17;
    long resource_id;
    long volume;
    unsigned long pitch;
    long pan;
    int loop;
    uchar* wave_data;
    WAVEFORMATEX* wave_info;
    IDirectSoundBuffer* sound_buffer;
    unsigned long data_size;

    int load(char* name, long param);
    void unload(void);
};
#endif

int TDigital::load(char* name, long param) {
    unsigned long size1;
    unsigned long size2;
    void* mem2;
    void* mem1;
    int load_type;
    DSBUFFERDESC buffer_desc = {0};
    WAVHEADER wave_hdr;
    char file_with_path[260];
    int resDataSize;
    unsigned int result;
    IDirectSound* direct_sound;
    uchar* resource_data;
    int fd;

    if (this->failed != 0) {
        return 0;
    }

    if (this->owner != 0) {
        return this->owner->load(name, -1);
    }

    if (this->sound_system == 0) {
        return 0;
    }

    color_log(0xBA, 0xBA, 1);

    if (this->loaded != 0) {
        this->unload();
    }

    if (name != 0) {
        strncpy(this->sound_file, name, 12);
        this->sound_file[12] = 0;
    }

    if (this->sound_file[0] == 0) {
        goto fail_return;
    }

    if (param <= -1) {
        param = this->resource_id;
    }

    if (sound_file_first != 0 || param < 0) {
        sprintf(file_with_path, "%s%s", this->sound_system->path, this->sound_file);
        fd = __open(file_with_path, 0, 0);
        if (fd != -1) {
            result = read(fd, &wave_hdr.szRIFF, 0x2C);
            if (result <= 0) {
                this->failed = 1;
                close(fd);
                goto fail_return;
            }

            if (strncmp((char*)wave_hdr.szRIFF, "RIFF", 4) != 0 ||
                wave_hdr.wFormatTag != 1) {
                this->failed = 1;
                close(fd);
                goto fail_return;
            }

            this->data_size = wave_hdr.dwDataLength;
            this->wave_data = (uchar*)malloc(this->data_size);
            if (this->wave_data == 0) {
                this->failed = 1;
                close(fd);
                goto fail_return;
            }

            result = read(fd, this->wave_data, this->data_size);
            if (result <= 0) {
                this->failed = 1;
                free(this->wave_data);
                this->wave_data = 0;
                close(fd);
                goto fail_return;
            }

            close(fd);
            this->wave_info = (WAVEFORMATEX*)malloc(0x12);
            if (this->wave_info == 0) {
                this->failed = 1;
                free(this->wave_data);
                this->wave_data = 0;
                goto fail_return;
            }

            this->wave_info->wFormatTag = wave_hdr.wFormatTag;
            this->wave_info->nChannels = wave_hdr.nChannels;
            this->wave_info->nSamplesPerSec = wave_hdr.nSamplesPerSec;
            this->wave_info->nAvgBytesPerSec = wave_hdr.nAvgBytesPerSec;
            this->wave_info->nBlockAlign = wave_hdr.nBlockAlign;
            this->wave_info->wBitsPerSample = wave_hdr.wBitsPerSample;
            this->wave_info->cbSize = 0;

            buffer_desc.dwSize = 0x14;
            buffer_desc.dwFlags = 0xE2;
            buffer_desc.dwBufferBytes = this->data_size;
            buffer_desc.dwReserved = 0;
            buffer_desc.lpwfxFormat = this->wave_info;
            direct_sound = this->sound_system->direct_sound;
#ifdef SOUNDDRV_CANONICAL_TU
            result = direct_sound->CreateSoundBuffer(
#else
            result = direct_sound->vtable->CreateSoundBuffer(
#endif
#ifndef SOUNDDRV_CANONICAL_TU
                direct_sound,
#endif
                &buffer_desc,
#ifdef SOUNDDRV_CANONICAL_TU
                    &this->sound_buffer, 0);
#else
                (void**)&this->sound_buffer, 0);
#endif
            if (result != 0) {
                this->failed = 1;
                this->sound_buffer = 0;
                free(this->wave_info);
                this->wave_info = 0;
                free(this->wave_data);
                this->wave_data = 0;
                goto fail_return;
            }

#ifdef SOUNDDRV_CANONICAL_TU
            result = this->sound_buffer->Lock(
#else
            result = this->sound_buffer->vtable->Lock(
#endif
#ifndef SOUNDDRV_CANONICAL_TU
                this->sound_buffer,
#endif
                0, this->data_size, &mem1, &size1,
                &mem2, &size2, 0);
            if (result == 0) {
                memcpy(mem1, this->wave_data, size1);
                if (size2 != 0) {
                    memcpy(mem2, this->wave_data + size1, size2);
                }
#ifdef SOUNDDRV_CANONICAL_TU
                this->sound_buffer->Unlock(
#else
                this->sound_buffer->vtable->Unlock(
#endif
#ifndef SOUNDDRV_CANONICAL_TU
                    this->sound_buffer,
#endif
                    mem1, size1, mem2, size2);
                free(this->wave_info);
                this->wave_info = 0;
                free(this->wave_data);
                this->wave_data = 0;
                goto success_return;
            }
            this->failed = 1;
#ifdef SOUNDDRV_CANONICAL_TU
            this->sound_buffer->Release();
#else
            this->sound_buffer->vtable->Release(this->sound_buffer);
#endif
            this->sound_buffer = 0;
            free(this->wave_info);
            this->wave_info = 0;
            free(this->wave_data);
            this->wave_data = 0;
            goto fail_return;
        }
    }

    if (param <= -1 || (resource_data = RESFILE_load(0x77617620, param,
            &load_type, &resDataSize)) == 0) {
        this->failed = 1;
    } else {
        memcpy(&wave_hdr.szRIFF, resource_data, 0x2C);
        this->data_size = wave_hdr.dwDataLength;
        this->wave_data = (uchar*)malloc(this->data_size);
        if (this->wave_data == 0) {
            this->failed = 1;
            if (load_type == 1) {
                free(resource_data);
            }
        } else {
            memcpy(this->wave_data, resource_data + 0x2C, this->data_size);
            if (load_type == 1) {
                free(resource_data);
            }
            this->wave_info = (WAVEFORMATEX*)malloc(0x12);
            if (this->wave_info == 0) {
                this->failed = 1;
                if (load_type != 1)
                    goto wave_info_fail;
                // ORIGINAL BUG: The shipped path frees resource_data twice when load_type is 1.
                free(resource_data);
wave_info_fail:
                color_log(0xBA, 0x5F, 1);
                return 0;
            } else {
                this->wave_info->wFormatTag = wave_hdr.wFormatTag;
                this->wave_info->nChannels = wave_hdr.nChannels;
                this->wave_info->nSamplesPerSec = wave_hdr.nSamplesPerSec;
                this->wave_info->nAvgBytesPerSec = wave_hdr.nAvgBytesPerSec;
                this->wave_info->nBlockAlign = wave_hdr.nBlockAlign;
                this->wave_info->wBitsPerSample = wave_hdr.wBitsPerSample;
                this->wave_info->cbSize = 0;

                buffer_desc.dwSize = 0x14;
                buffer_desc.dwFlags = 0xE2;
                buffer_desc.dwBufferBytes = this->data_size;
                buffer_desc.dwReserved = 0;
                buffer_desc.lpwfxFormat = this->wave_info;
                direct_sound = this->sound_system->direct_sound;
                IDirectSoundBuffer** buffer_slot = &this->sound_buffer;
#ifdef SOUNDDRV_CANONICAL_TU
                result = direct_sound->CreateSoundBuffer(
#else
                result = direct_sound->vtable->CreateSoundBuffer(
#endif
#ifndef SOUNDDRV_CANONICAL_TU
                    direct_sound,
#endif
                    &buffer_desc,
#ifdef SOUNDDRV_CANONICAL_TU
                    buffer_slot, 0);
#else
                    (void**)&this->sound_buffer, 0);
#endif
                if (result == 0) {
#ifdef SOUNDDRV_CANONICAL_TU
                    result = (*buffer_slot)->Lock(
#else
                    result = this->sound_buffer->vtable->Lock(
#endif
#ifndef SOUNDDRV_CANONICAL_TU
                        this->sound_buffer,
#endif
                        0, this->data_size, &mem1, &size1,
                        &mem2, &size2, 0);
                    if (result == 0) {
                        memcpy(mem1, this->wave_data, size1);
                        if (size2 != 0) {
                            memcpy(mem2, this->wave_data + size1, size2);
                        }
#ifdef SOUNDDRV_CANONICAL_TU
                        (*buffer_slot)->Unlock(
#else
                        this->sound_buffer->vtable->Unlock(
#endif
#ifndef SOUNDDRV_CANONICAL_TU
                            this->sound_buffer,
#endif
                            mem1, size1, mem2, size2);
                        free(this->wave_info);
                        this->wave_info = 0;
                        goto success_return;
                    }
                    this->failed = 1;
#ifdef SOUNDDRV_CANONICAL_TU
                    (*buffer_slot)->Release();
#else
                    this->sound_buffer->vtable->Release(this->sound_buffer);
#endif
                } else {
                    this->failed = 1;
                }
                *buffer_slot = 0;
                free(this->wave_info);
                this->wave_info = 0;
            }
        }
    }

fail_return:
    color_log(0xBA, 0x5F, 1);
    return 0;

success_return:
    this->loaded = 1;
    color_log(0xBA, 0x5F, 1);
    return 1;
}
