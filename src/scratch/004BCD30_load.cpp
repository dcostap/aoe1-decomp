// TDigital::load
// Large function (1475 bytes) - handles loading WAV files from disk or resources
// TODO: Use variant_lab for exact match - has two major paths (file-based and resource-based)
#include <string.h>
#include <stdlib.h>

extern "C" int __cdecl __open(const char* path, int flags, int mode);
extern "C" int __cdecl close(int fd);
extern "C" int __cdecl read(int fd, void* buf, unsigned int count);
extern "C" int __cdecl strncmp(const char* s1, const char* s2, unsigned int n);
extern "C" int __cdecl sprintf(char* buf, const char* fmt, ...);
extern "C" void __cdecl color_log(unsigned char a, unsigned char b, int c);
extern "C" unsigned char* __cdecl RESFILE_load(unsigned long type, int id, int* size_out, int* extra);

struct DSBUFFERDESC {
    unsigned long dwSize;
    unsigned long dwFlags;
    unsigned long dwBufferBytes;
    unsigned long dwReserved;
    void* lpwfxFormat;
};

struct WAVHEADER {
    unsigned long riff_id;
    unsigned long riff_size;
    unsigned long wave_id;
    unsigned long fmt_id;
    unsigned long fmt_size;
    unsigned short wFormatTag;
    unsigned short nChannels;
    unsigned long nSamplesPerSec;
    unsigned long nAvgBytesPerSec;
    unsigned short nBlockAlign;
    unsigned short wBitsPerSample;
    unsigned long data_id;
    unsigned long data_size;
};

extern unsigned char sound_file_first;

class TSound_Driver;

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
    struct WAVEFORMATEX* wave_info;
    void* sound_buffer;

    int load(char* name, long param);
    void unload(void);
};

int TDigital::load(char* name, long param) {
    DSBUFFERDESC buffer_desc;
    WAVHEADER wave_hdr;
    int resDataSize;
    char file_with_path[260];

    buffer_desc.dwBufferBytes = 0;
    buffer_desc.dwReserved = 0;
    buffer_desc.lpwfxFormat = 0;
    wave_hdr.riff_id = 0;
    buffer_desc.dwFlags = 0;

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

    if (param < 0) {
        param = this->resource_id;
    }

    if (sound_file_first != 0 || param < 0) {
        // File-based load
        sprintf(file_with_path + 4, "%s%s", this->sound_system->path, this->sound_file);
        int fd = __open(file_with_path + 4, 0, 0);
        if (fd != -1) {
            int n = read(fd, &wave_hdr.dwFormatLength, 0x2C);
            if (n != 0) {
                if (strncmp((char*)&wave_hdr.dwFormatLength, "RIFF", 4) != 0 || wave_hdr.wFormatTag != 1) {
                    this->failed = 1;
                    close(fd);
                    goto fail_return;
                }
                this->data_size = resDataSize;
                this->wave_data = (unsigned char*)malloc(resDataSize);
                if (this->wave_data == 0) {
                    this->failed = 1;
                    close(fd);
                    goto fail_return;
                }
                n = read(fd, this->wave_data, this->data_size);
                if (n == 0) {
                    this->failed = 1;
                    free(this->wave_data);
                    this->wave_data = 0;
                    close(fd);
                    goto fail_return;
                }
                close(fd);

                // Create WAVEFORMATEX
                this->wave_info = (struct WAVEFORMATEX*)malloc(18);
                if (this->wave_info == 0) {
                    this->failed = 1;
                    free(this->wave_data);
                    this->wave_data = 0;
                    goto fail_return;
                }
                this->wave_info->wFormatTag = wave_hdr.wFormatTag;
                this->wave_info->nChannels = *(unsigned short*)((char*)&wave_hdr + 0x1A);
                this->wave_info->nSamplesPerSec = wave_hdr.nAvgBytesPerSec;
                this->wave_info->nAvgBytesPerSec = *(unsigned long*)((char*)&wave_hdr + 0x20);
                this->wave_info->nBlockAlign = *(unsigned short*)((char*)&wave_hdr + 0x24);
                this->wave_info->wBitsPerSample = *(unsigned short*)((char*)&wave_hdr + 0x26);
                this->wave_info->cbSize = 0;

                buffer_desc.dwFlags = 0x14;
                buffer_desc.dwBufferBytes = 0xE2;
                buffer_desc.dwReserved = this->data_size;
                buffer_desc.lpwfxFormat = 0;

                // Create sound buffer
                int hr = ((int (__stdcall*)(void*, void*, void**, void*))(*(void***)this->sound_system->direct_sound)[3])(
                    this->sound_system->direct_sound, &buffer_desc, &this->sound_buffer, 0);
                if (hr != 0) {
                    this->failed = 1;
                    this->sound_buffer = 0;
                    free(this->wave_info);
                    this->wave_info = 0;
                    free(this->wave_data);
                    this->wave_data = 0;
                    goto fail_return;
                }

                // Lock buffer and copy data
                void* mem1;
                void* mem2;
                unsigned long size1;
                unsigned long size2;
                hr = ((int (__stdcall*)(void*, unsigned long, unsigned long, void**, void**, unsigned long*))(*(void***)this->sound_buffer)[11])(
                    this->sound_buffer, 0, this->data_size, &mem1, &mem2, &size2);
                if (hr != 0) {
                    this->failed = 1;
                    ((int (__stdcall*)(void*))(*(void***)this->sound_buffer)[2])(this->sound_buffer);
                    this->sound_buffer = 0;
                    free(this->wave_info);
                    this->wave_info = 0;
                    free(this->wave_data);
                    this->wave_data = 0;
                    goto fail_return;
                }

                // Copy wave data into locked buffer
                // (memcpy pattern)
                unsigned long copy_size = (unsigned long)size2;
                if (copy_size > 0) {
                    unsigned long i;
                    for (i = 0; i < copy_size / 4; i++) {
                        ((unsigned long*)mem1)[i] = ((unsigned long*)this->wave_data)[i];
                    }
                    for (i = copy_size / 4 * 4; i < copy_size; i++) {
                        ((unsigned char*)mem1)[i] = this->wave_data[i];
                    }
                }

                unsigned long extra_size = (unsigned long)mem2;
                if (extra_size > 0) {
                    unsigned long i;
                    unsigned char* src = this->wave_data + (unsigned long)size2;
                    for (i = 0; i < extra_size / 4; i++) {
                        ((unsigned long*)mem2)[i] = ((unsigned long*)src)[i];
                    }
                    for (i = extra_size / 4 * 4; i < extra_size; i++) {
                        ((unsigned char*)mem2)[i] = src[i];
                    }
                }

                ((int (__stdcall*)(void*, void*, unsigned long, void*, unsigned long))(*(void***)this->sound_buffer)[19])(
                    this->sound_buffer, mem1, size2, mem2, (unsigned long)mem2);

                free(this->wave_info);
                this->wave_info = 0;
                free(this->wave_data);
                this->wave_data = 0;

                goto success_return;
            }
            this->failed = 1;
            close(fd);
            goto fail_return;
        }
    }

    // Resource-based load
    if (param >= 0) {
        int size_out;
        int extra;
        unsigned char* res_data = RESFILE_load(0x77617620, param, &size_out, &extra);
        if (res_data != 0) {
            // Copy header from resource data
            unsigned long i;
            unsigned long* src = (unsigned long*)res_data;
            unsigned long* dst = (unsigned long*)&wave_hdr;
            for (i = 0; i < 11; i++) {
                dst[i] = src[i];
            }

            this->data_size = resDataSize;
            this->wave_data = (unsigned char*)malloc(resDataSize);
            if (this->wave_data != 0) {
                // Copy wave data
                unsigned char* data_src = res_data + 0x2C;
                unsigned char* data_dst = this->wave_data;
                unsigned long data_sz = this->data_size;
                for (i = 0; i < data_sz / 4; i++) {
                    ((unsigned long*)data_dst)[i] = ((unsigned long*)data_src)[i];
                }
                for (i = data_sz / 4 * 4; i < data_sz; i++) {
                    data_dst[i] = data_src[i];
                }

                if (size_out == 1) {
                    free(res_data);
                }

                // Create WAVEFORMATEX
                this->wave_info = (struct WAVEFORMATEX*)malloc(18);
                if (this->wave_info != 0) {
                    this->wave_info->wFormatTag = wave_hdr.wFormatTag;
                    this->wave_info->nChannels = *(unsigned short*)((char*)&wave_hdr + 0x1A);
                    this->wave_info->nSamplesPerSec = wave_hdr.nAvgBytesPerSec;
                    this->wave_info->nAvgBytesPerSec = *(unsigned long*)((char*)&wave_hdr + 0x20);
                    this->wave_info->nBlockAlign = *(unsigned short*)((char*)&wave_hdr + 0x24);
                    this->wave_info->wBitsPerSample = *(unsigned short*)((char*)&wave_hdr + 0x26);
                    this->wave_info->cbSize = 0;

                    buffer_desc.dwFlags = 0x14;
                    buffer_desc.dwBufferBytes = 0xE2;
                    buffer_desc.dwReserved = this->data_size;
                    buffer_desc.lpwfxFormat = 0;

                    int hr = ((int (__stdcall*)(void*, void*, void**, void*))(*(void***)this->sound_system->direct_sound)[3])(
                        this->sound_system->direct_sound, &buffer_desc, &this->sound_buffer, 0);
                    if (hr == 0) {
                        void* mem1;
                        void* mem2;
                        unsigned long size2;
                        hr = ((int (__stdcall*)(void*, unsigned long, unsigned long, void**, void**, unsigned long*))(*(void***)this->sound_buffer)[11])(
                            this->sound_buffer, 0, this->data_size, &mem1, &mem2, &size2);
                        if (hr == 0) {
                            // Copy data into locked buffer
                            unsigned long copy_sz = (unsigned long)size2;
                            if (copy_sz > 0) {
                                unsigned long i;
                                for (i = 0; i < copy_sz / 4; i++) {
                                    ((unsigned long*)mem1)[i] = ((unsigned long*)this->wave_data)[i];
                                }
                                for (i = copy_sz / 4 * 4; i < copy_sz; i++) {
                                    ((unsigned char*)mem1)[i] = this->wave_data[i];
                                }
                            }

                            unsigned long extra_sz = (unsigned long)mem2;
                            if (extra_sz > 0) {
                                unsigned long i;
                                unsigned char* src = this->wave_data + (unsigned long)size2;
                                for (i = 0; i < extra_sz / 4; i++) {
                                    ((unsigned long*)mem2)[i] = ((unsigned long*)src)[i];
                                }
                                for (i = extra_sz / 4 * 4; i < extra_sz; i++) {
                                    ((unsigned char*)mem2)[i] = src[i];
                                }
                            }

                            ((int (__stdcall*)(void*, void*, unsigned long, void*, unsigned long))(*(void***)this->sound_buffer)[19])(
                                this->sound_buffer, mem1, size2, mem2, (unsigned long)mem2);

                            free(this->wave_info);
                            this->wave_info = 0;
                            free(this->wave_data);
                            this->wave_data = 0;

                            goto success_return;
                        }

                        this->failed = 1;
                        ((int (__stdcall*)(void*))(*(void***)this->sound_buffer)[2])(this->sound_buffer);
                    } else {
                        this->failed = 1;
                    }

                    this->sound_buffer = 0;
                    free(this->wave_info);
                    this->wave_info = 0;
                } else {
                    this->failed = 1;
                    if (size_out == 1) {
                        free(res_data);
                    }
                }
            } else {
                this->failed = 1;
                if (size_out == 1) {
                    free(res_data);
                }
            }
        } else {
            this->failed = 1;
        }
    } else {
        this->failed = 1;
    }

fail_return:
    color_log(0xBA, 0x5F, 1);
    return 0;

success_return:
    this->loaded = 1;
    color_log(0xBA, 0x5F, 1);
    return 1;
}
