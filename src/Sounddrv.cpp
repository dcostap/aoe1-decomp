#include "../include/sounddrv.h"
#include "../include/Res_file.h"

#include <stdlib.h>
#include <string.h>

extern "C" void __cdecl ds_stream_init(void* main_wnd, void* direct_sound,
                                         void* primary_buffer);
extern "C" void __cdecl ds_stream_exit(void);
extern "C" int __cdecl ds_stream_file(char* file_name, int mode, long resource_id);
extern "C" int __cdecl ds_stream_volume(long volume);
extern "C" int __cdecl ds_stream_pause(void);
extern "C" int __cdecl ds_stream_resume(void);
extern "C" int __cdecl ds_stream_stop(void);
extern "C" unsigned int __cdecl ds_stream_messages(
    void* a, unsigned int b, unsigned int c, long d);
extern "C" long (__stdcall *__imp__mixerSetControlDetails)(
    void* mixer_handle, void* mixer_volume_details, unsigned long flags);

extern "C" int __cdecl sprintf(char* buffer, const char* format, ...);
extern "C" int __cdecl __open(const char* path, int flags, int mode);
extern "C" int __cdecl close(int fd);
extern "C" unsigned int __cdecl read(int fd, void* buffer, unsigned int count);
extern "C" int __cdecl strncmp(const char* left, const char* right,
                               unsigned int count);
extern void __cdecl color_log(unsigned char a, unsigned char b, int c);

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

TSound_Driver::TSound_Driver() {
    this->init_vars();
}

TSound_Driver::TSound_Driver(void* window, char* path) {
    this->init_vars();
    this->init(window, path);
}

TSound_Driver::~TSound_Driver() {
    this->exit();
}

void TSound_Driver::init_vars() {
    this->start_volume = 1;
    this->ready = 0;
    this->main_wnd = 0;
    this->direct_sound = 0;
    this->primary_buffer = 0;
    this->dsrval = 0;
    this->mute = 0;
    this->play_list_count = 0;
    this->volume = 0;
    this->mixer_open = 0;
    this->mixer_handle = 0;
    this->path[0] = 0;
}

int TSound_Driver::init(void* window, char* path) {
    int has_secondary;
    DSCAPS dscaps;
    DSBUFFERDESC dsbd;
    WAVEFORMATEX fmt;

    this->set_path(path);
    this->main_wnd = window;
    this->ready = 0;

    this->dsrval = DirectSoundCreate(0, &this->direct_sound, 0);
    if (this->dsrval != 0) {
        return 0;
    }

    dscaps.dwSize = 0x60;
    this->direct_sound->GetCaps(&dscaps);

    has_secondary = 0;
    if ((dscaps.dwFlags & 8) != 0) {
        this->dsrval = this->direct_sound->SetCooperativeLevel(
            (HWND)this->main_wnd, 2);
        if (this->dsrval != 0) {
            this->dsrval = this->direct_sound->SetCooperativeLevel(
                (HWND)this->main_wnd, 1);
        } else {
            has_secondary = 1;
        }
    } else {
        this->dsrval = this->direct_sound->SetCooperativeLevel(
            (HWND)this->main_wnd, 1);
    }

    if (this->dsrval != 0) {
        this->direct_sound->Release();
        this->direct_sound = 0;
        return 0;
    }

    memset(&dsbd, 0, sizeof(dsbd));
    dsbd.dwSize = 0x14;
    dsbd.dwFlags = 1;
    this->dsrval = this->direct_sound->CreateSoundBuffer(
        &dsbd, &this->primary_buffer, 0);
    if (this->dsrval != 0) {
        this->direct_sound->Release();
        this->direct_sound = 0;
        return 0;
    }

    if (has_secondary != 0) {
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

void TSound_Driver::exit() {
    this->close_mixer();
    if (this->ready != 0) {
        ds_stream_exit();
        if (this->primary_buffer != 0) {
            this->primary_buffer->Stop();
            this->primary_buffer->Release();
            this->primary_buffer = 0;
        }
        if (this->direct_sound != 0) {
            this->direct_sound->Release();
            this->direct_sound = 0;
        }
        this->ready = 0;
    }
}

void TSound_Driver::set_path(char* path) {
    if (path != 0) {
        strcpy(this->path, path);
    } else {
        this->path[0] = 0;
    }
}

int TSound_Driver::driver_active() {
    return this->ready;
}

long TSound_Driver::get_volume() {
    return this->volume;
}

void TSound_Driver::set_volume(long volume, int update_driver) {
    unsigned long delta;
    unsigned long scaled;

    if (update_driver != 0) {
        this->volume = volume;
    }
    if (this->mixer_open == 0) {
        return;
    }

    delta = (unsigned long)(this->mixer_volume_control.Bounds.lMaximum -
                           this->mixer_volume_control.Bounds.lMinimum);
    scaled = (unsigned long)((delta * (volume + 10000)) / 10000);
    this->mixer_volume_value.dwValue = scaled;
    this->dsrval = __imp__mixerSetControlDetails(
        this->mixer_handle, &this->mixer_volume_details, 0);
}

int TSound_Driver::stream_file(char* file, int mode, long resource_id) {
    char file_name2[260];

    if (this->ready == 0) {
        return 0;
    }

    sprintf(file_name2, "%s%s", this->path, file);
    return ds_stream_file(file_name2, mode, resource_id);
}

int TSound_Driver::set_stream_volume(long volume) {
    if (this->ready == 0) {
        return 0;
    }
    return ds_stream_volume(volume);
}

int TSound_Driver::pause_stream() {
    if (this->ready == 0) {
        return 0;
    }
    return ds_stream_pause();
}

int TSound_Driver::resume_stream() {
    if (this->ready == 0) {
        return 0;
    }
    return ds_stream_resume();
}

int TSound_Driver::stop_stream() {
    if (this->ready == 0) {
        return 0;
    }
    return ds_stream_stop();
}

unsigned int TSound_Driver::handle_messages(
    void* a, unsigned int b, unsigned int c, long d) {
    if (this->ready == 0) {
        return 0;
    }
    return ds_stream_messages(a, b, c, d);
}

int TSound_Driver::add_to_play_list(TDigital* digital) {
    if ((this->play_list_count != 0xFF) && (this->mute == 0)) {
        this->sound_play_list[this->play_list_count] = digital;
        ++this->play_list_count;
        return 1;
    }
    return 0;
}

void TSound_Driver::play_list() {
    int i;
    TDigital** sound;

    i = 0;
    if (0 < this->play_list_count) {
        sound = this->sound_play_list;
        do {
            (*sound)->play();
            i = i + 1;
            sound = sound + 1;
        } while (i < this->play_list_count);
    }
}

void TSound_Driver::reset_play_list() {
    this->play_list_count = 0;
}

int TSound_Driver::open_mixer() {
    UINT num_dev = mixerGetNumDevs();
    if (num_dev <= 0) {
        return 0;
    }

    UINT mixer_id = 0;
    for (; mixer_id < num_dev; ++mixer_id) {
        if (mixerOpen(&this->mixer_handle, mixer_id, 0, 0, 0) == 0) {
            memset(&this->mixer_line_info, 0,
                   sizeof(this->mixer_line_info));
            this->mixer_line_info.cbStruct = sizeof(this->mixer_line_info);
            this->mixer_line_info.dwComponentType = 0x1008;

            if (mixerGetLineInfoA(this->mixer_handle,
                                  &this->mixer_line_info, 3) == 0) {
                memset(&this->mixer_line_controls, 0,
                       sizeof(this->mixer_line_controls));
                memset(&this->mixer_volume_control, 0,
                       sizeof(this->mixer_volume_control));
                this->mixer_line_controls.cbStruct =
                    sizeof(this->mixer_line_controls);
                this->mixer_line_controls.dwLineID =
                    this->mixer_line_info.dwLineID;
                this->mixer_line_controls.dwControlType = 0x50030001;
                this->mixer_line_controls.cControls = 1;
                this->mixer_line_controls.cbmxctrl =
                    sizeof(this->mixer_volume_control);
                this->mixer_line_controls.pamxctrl =
                    &this->mixer_volume_control;

                if (mixerGetLineControlsA(this->mixer_handle,
                                           &this->mixer_line_controls,
                                           2) == 0) {
                    memset(&this->mixer_volume_details, 0,
                           sizeof(this->mixer_volume_details));
                    memset(&this->mixer_volume_value, 0,
                           sizeof(this->mixer_volume_value));
                    this->mixer_volume_details.cbStruct =
                        sizeof(this->mixer_volume_details);
                    this->mixer_volume_details.dwControlID =
                        this->mixer_volume_control.dwControlID;
                    this->mixer_volume_details.cChannels = 1;
                    this->mixer_volume_details.cbDetails =
                        sizeof(this->mixer_volume_value);
                    this->mixer_volume_details.paDetails =
                        &this->mixer_volume_value;

                    if (mixerGetControlDetailsA(
                            this->mixer_handle, &this->mixer_volume_details,
                            0) == 0) {
                        this->mixer_open = 1;
                        this->start_volume =
                            (int)(((unsigned long)this->mixer_volume_value.dwValue *
                                   10000) /
                                  (unsigned long)(
                                      this->mixer_volume_control.Bounds.lMaximum -
                                      this->mixer_volume_control.Bounds.lMinimum)) -
                            10000;
                        this->volume = this->start_volume;
                        return 1;
                    }
                }
            }

            mixerClose(this->mixer_handle);
            this->mixer_handle = 0;
        }
    }

    return 0;
}

void TSound_Driver::close_mixer() {
    if (this->mixer_open != 0) {
        if (this->start_volume != 1) {
            this->set_volume(this->start_volume, 0);
            this->start_volume = 1;
        }
        if (this->mixer_handle != 0) {
            mixerClose(this->mixer_handle);
            this->mixer_handle = 0;
        }
        this->mixer_open = 0;
    }
}

TDigital::TDigital(TSound_Driver* driver, char* file, long resource_id) {
    this->init_vars();
    this->sound_system = driver;
    this->resource_id = resource_id;
    if (file != 0) {
        strncpy(this->sound_file, file, 0x0C);
        this->sound_file[0x0C] = 0;
    }
}

TDigital::TDigital(TDigital* owner) {
    this->init_vars();
    this->owner = owner;
    this->volume = owner->volume;
    this->pitch = owner->pitch;
    this->pan = owner->pan;
    this->loop = owner->loop;
}

TDigital::~TDigital() {
    this->exit();
}

void TDigital::init_vars() {
    this->sound_system = 0;
    this->owner = 0;
    this->loaded = 0;
    this->failed = 0;
    this->sound_file[0] = 0;
    this->wave_data = 0;
    this->wave_info = 0;
    this->sound_buffer = 0;
    this->data_size = 0;
    this->volume = 0;
    this->pitch = 0;
    this->pan = 0;
    this->loop = 0;
}

void TDigital::exit() {
    if (this->owner != 0) {
        this->owner->exit();
        this->init_vars();
        return;
    }
    if (this->loaded != 0) {
        this->stop();
        this->unload();
        this->init_vars();
    }
}

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
        sprintf(file_with_path, "%s%s", this->sound_system->path,
                this->sound_file);
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
            if (direct_sound->CreateSoundBuffer(
                    &buffer_desc, &this->sound_buffer, 0) != 0) {
                this->failed = 1;
                this->sound_buffer = 0;
                free(this->wave_info);
                this->wave_info = 0;
                free(this->wave_data);
                this->wave_data = 0;
                goto fail_return;
            }

            if (this->sound_buffer->Lock(
                    0, this->data_size, &mem1, &size1, &mem2, &size2, 0) == 0) {
                memcpy(mem1, this->wave_data, size1);
                if (size2 != 0) {
                    memcpy(mem2, this->wave_data + size1, size2);
                }
                this->sound_buffer->Unlock(mem1, size1, mem2, size2);
                free(this->wave_info);
                this->wave_info = 0;
                free(this->wave_data);
                this->wave_data = 0;
                goto success_return;
            }
            this->failed = 1;
            this->sound_buffer->Release();
            this->sound_buffer = 0;
            free(this->wave_info);
            this->wave_info = 0;
            free(this->wave_data);
            this->wave_data = 0;
            goto fail_return;
        }
    }

    if (param <= -1 || (resource_data = RESFILE_load(
                            0x77617620, param, load_type, resDataSize)) == 0) {
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
                if (load_type != 1) {
                    goto wave_info_fail;
                }
                /* The shipped path frees resource_data twice. */
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

                LPDIRECTSOUNDBUFFER* buffer_slot = &this->sound_buffer;
                buffer_desc.dwSize = 0x14;
                buffer_desc.dwFlags = 0xE2;
                buffer_desc.dwBufferBytes = this->data_size;
                buffer_desc.dwReserved = 0;
                buffer_desc.lpwfxFormat = this->wave_info;
                direct_sound = this->sound_system->direct_sound;
                if (direct_sound->CreateSoundBuffer(
                        &buffer_desc, buffer_slot, 0) != 0) {
                    this->failed = 1;
                } else {
                    if ((*buffer_slot)->Lock(
                            0, this->data_size, &mem1, &size1,
                            &mem2, &size2, 0) == 0) {
                        memcpy(mem1, this->wave_data, size1);
                        if (size2 != 0) {
                            memcpy(mem2, this->wave_data + size1, size2);
                        }
                        this->sound_buffer->Unlock(mem1, size1, mem2, size2);
                        free(this->wave_info);
                        this->wave_info = 0;
                        goto success_return;
                    }
                    this->failed = 1;
                    this->sound_buffer->Release();
                }
                this->sound_buffer = 0;
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

void TDigital::unload() {
    TDigital* p = this;

    while (p->owner != 0) {
        p = p->owner;
    }

    if (p->loaded == 0) {
        goto done;
    }

    p->stop();

    if (p->sound_buffer != 0) {
        p->sound_buffer->Release();
        p->sound_buffer = 0;
    }

    if (p->wave_data != 0) {
        free(p->wave_data);
        p->wave_data = 0;
    }

    if (p->wave_info != 0) {
        free(p->wave_info);
        p->wave_info = 0;
    }

    p->loaded = 0;

done:
    p->failed = 0;
}

int TDigital::play() {
    unsigned long status;
    int loop_flag;
    int hr;
    TDigital* target = this->owner;
    TDigital* original = this;
    TSound_Driver* driver;

    if (target == 0) {
        target = this;
    }

    driver = target->sound_system;
    if (driver == 0) {
        goto done;
    }
    if (driver->ready == 0) {
        goto done;
    }
    if (driver->mute != 0) {
        goto done;
    }

    if (target->loaded == 0) {
        int result = target->load(original->sound_file, -1);
        if (result == 0) {
            return 0;
        }
    }

    if (target->sound_buffer == 0) {
        target->failed = 1;
        return 0;
    }

    target->sound_buffer->GetStatus(&status);

    loop_flag = (target->loop != 0);
    target->sound_buffer->SetVolume(original->volume);
    target->sound_buffer->SetFrequency(original->pitch);
    target->sound_buffer->SetPan(original->pan);
    target->sound_buffer->SetCurrentPosition(0);

    hr = target->sound_buffer->Play(0, 0, loop_flag);

    if (hr == 0x88780096) {
        int result = target->load(0, -1);
        if (result == 0) {
            return 0;
        }

        target->sound_buffer->SetVolume(original->volume);
        target->sound_buffer->SetFrequency(original->pitch);
        target->sound_buffer->SetPan(original->pan);
        target->sound_buffer->SetCurrentPosition(0);
        target->sound_buffer->Play(0, 0, loop_flag);
    }

done:
    return 1;
}

void TDigital::stop() {
    TDigital* p = this;

    while (p->owner != 0) {
        p = p->owner;
    }
    if (p->sound_system == 0) {
        return;
    }
    if (p->sound_system->ready == 0) {
        return;
    }
    if (p->loaded == 0) {
        return;
    }
    if (p->sound_buffer == 0) {
        return;
    }
    p->sound_buffer->Stop();
}

void TDigital::set_loop(short value) {
    if (value == 0) {
        this->loop = 0;
        return;
    }
    this->loop = 1;
}

void TDigital::set_volume(long value) {
    TDigital* p = this->owner;

    this->volume = value;
    if (p == 0) {
        p = this;
    }
    if (p->loaded == 0) {
        return;
    }
    p->sound_buffer->SetVolume(value);
}

void TDigital::set_pitch(unsigned long value) {
    TDigital* p = this->owner;

    this->pitch = value;
    if (p == 0) {
        p = this;
    }
    if (p->loaded == 0) {
        return;
    }
    p->sound_buffer->SetFrequency(value);
}

void TDigital::set_pan(long value) {
    TDigital* p = this->owner;

    this->pan = value;
    if (p == 0) {
        p = this;
    }
    if (p->loaded == 0) {
        return;
    }
    p->sound_buffer->SetPan(value);
}

int TDigital::is_playing() {
    TDigital* target = this->owner;
    unsigned long status;

    if (target == 0) {
        target = this;
    }
    if (this->sound_system != 0 && target->loaded != 0 &&
        target->sound_buffer != 0) {
        if (target->sound_buffer->GetStatus(&status) == 0) {
            if (status == 1 || status == 4) {
                return 1;
            }
        }
    }
    return 0;
}

int TDigital::add_to_play_list() {
    TSound_Driver* sound_system;

    sound_system = this->sound_system;
    if (sound_system != 0) {
        if (sound_system->mute == 0) {
            return sound_system->add_to_play_list(this);
        }
    }
    return 0;
}
