// Decompiled: Sounddrv.cpp
// SourceMap: C:/msdev/work/age1_x1/Sounddrv.cpp

#include "../include/TSound_Driver.h"
#include "../include/TDigital.h"
#include "../include/Dsutil.h"
#include "../include/Res_file.h"
#include "../include/globals.h"
#include "../include/debug_helpers.h"
#include <io.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

// ============================================================================
// TSound_Driver
// ============================================================================

// Offset: 0x004BC590
TSound_Driver::TSound_Driver() {
    this->init_vars();
}

// Offset: 0x004BC5A0
TSound_Driver::TSound_Driver(void* wnd, char* path) {
    this->init_vars();
    this->init(wnd, path);
}

// Offset: 0x004BC5C0
TSound_Driver::~TSound_Driver() {
    this->close_mixer();
    if (this->ready != 0) {
        ds_stream_exit();
        if (this->primary_buffer != nullptr) {
            this->primary_buffer->Stop();
            this->primary_buffer->Release();
            this->primary_buffer = nullptr;
        }
        if (this->direct_sound != nullptr) {
            this->direct_sound->Release();
            this->direct_sound = nullptr;
        }
        this->ready = 0;
    }
}

// Offset: 0x004BC5D0
void TSound_Driver::init_vars() {
    this->start_volume = 1;
    this->ready = 0;
    this->main_wnd = nullptr;
    this->direct_sound = nullptr;
    this->primary_buffer = nullptr;
    this->dsrval = 0;
    this->mute = 0;
    this->play_list_count = 0;
    this->volume = 0;
    this->mixer_open = 0;
    this->mixer_handle = nullptr;
    this->path[0] = '\0';
}

// Offset: 0x004BC610
int TSound_Driver::init(void* wnd, char* path) {
    DSBUFFERDESC dsBD;
    DSCAPS dscaps;
    WAVEFORMATEX fmt;
    bool bExclusive = false;

    this->set_path(path);
    this->main_wnd = wnd;
    this->ready = 0;

    this->dsrval = DirectSoundCreate(nullptr, &this->direct_sound, nullptr);
    if (this->dsrval != DS_OK) {
        return 0;
    }

    // Try to get caps and set cooperative level
    memset(&dscaps, 0, sizeof(dscaps));
    dscaps.dwSize = sizeof(dscaps);
    this->direct_sound->GetCaps(&dscaps);

    if (dscaps.dwFlags & DSCAPS_PRIMARYSTEREO) {
        this->dsrval = this->direct_sound->SetCooperativeLevel((HWND)this->main_wnd, DSSCL_PRIORITY);
        if (this->dsrval == DS_OK) {
            bExclusive = true;
            goto coop_ok;
        }
    }

    this->dsrval = this->direct_sound->SetCooperativeLevel((HWND)this->main_wnd, DSSCL_NORMAL);

coop_ok:
    if (this->dsrval != DS_OK) {
        this->direct_sound->Release();
        this->direct_sound = nullptr;
        return 0;
    }

    // Create primary buffer
    memset(&dsBD, 0, sizeof(dsBD));
    dsBD.dwSize = sizeof(DSBUFFERDESC);
    dsBD.dwFlags = DSBCAPS_PRIMARYBUFFER;

    this->dsrval = this->direct_sound->CreateSoundBuffer(&dsBD, &this->primary_buffer, nullptr);
    if (this->dsrval == DS_OK) {
        if (bExclusive) {
            // Set primary buffer format to 16-bit stereo
            memset(&fmt, 0, sizeof(fmt));
            fmt.wFormatTag = WAVE_FORMAT_PCM;
            fmt.nChannels = 1;
            fmt.nSamplesPerSec = 0x10001; // per ASM: 0x10001
            // TODO: The decomp shows 0x10001 being stored. This may be an artifact.
            // The original likely set 22050Hz or similar. Keeping ASM-parity for now.
            this->dsrval = this->primary_buffer->SetFormat(&fmt);
        }

        this->dsrval = this->primary_buffer->Play(0, 0, DSBPLAY_LOOPING);
        if (this->dsrval == DS_OK) {
            this->ready = 1;
            ds_stream_init(this->main_wnd, this->direct_sound, this->primary_buffer);
            this->open_mixer();
            return (int)this->ready;
        }
    }

    // Cleanup on failure
    this->direct_sound->Release();
    this->direct_sound = nullptr;
    return 0;
}

// Offset: 0x004BC7C0
void TSound_Driver::exit() {
    this->close_mixer();
    if (this->ready != 0) {
        ds_stream_exit();
        if (this->primary_buffer != nullptr) {
            this->primary_buffer->Stop();
            this->primary_buffer->Release();
            this->primary_buffer = nullptr;
        }
        if (this->direct_sound != nullptr) {
            this->direct_sound->Release();
            this->direct_sound = nullptr;
        }
        this->ready = 0;
    }
}

// Offset: 0x004BC810
void TSound_Driver::set_path(char* p) {
    if (p == nullptr) {
        this->path[0] = '\0';
        return;
    }
    strcpy(this->path, p);
}

// Offset: 0x004BC850
int TSound_Driver::driver_active() {
    return (int)this->ready;
}

// Offset: 0x004BC860
long TSound_Driver::get_volume() {
    return this->volume;
}

// Offset: 0x004BC870
void TSound_Driver::set_volume(long vol, int save) {
    if (save != 0) {
        this->volume = vol;
    }
    if (this->mixer_open != 0) {
        long range = this->mixer_volume_control.Bounds.lMaximum - this->mixer_volume_control.Bounds.lMinimum;
        this->mixer_volume_value.dwValue = (unsigned long)(range * (vol + 10000)) / 10000;
        this->dsrval = mixerSetControlDetails(
            (HMIXEROBJ)this->mixer_handle,
            &this->mixer_volume_details, 0);
    }
}

// Offset: 0x004BC8D0
int TSound_Driver::stream_file(char* filename, int loop, long vol) {
    char file_name2[260];
    if (this->ready == 0) return 0;
    sprintf(file_name2, "%s%s", this->path, filename);
    int result = ds_stream_file(file_name2, loop, vol);
    return result;
}

// Offset: 0x004BC930
int TSound_Driver::set_stream_volume(long vol) {
    if (this->ready == 0) return 0;
    return ds_stream_volume(vol);
}

// Offset: 0x004BC950
int TSound_Driver::pause_stream() {
    if (this->ready == 0) return 0;
    ds_stream_pause();
    return 1;
}

// Offset: 0x004BC960
int TSound_Driver::resume_stream() {
    if (this->ready == 0) return 0;
    return ds_stream_resume();
}

// Offset: 0x004BC970
int TSound_Driver::stop_stream() {
    if (this->ready == 0) return 0;
    return ds_stream_stop();
}

// Offset: 0x004BC980
uint TSound_Driver::handle_messages(void* hwnd, uint msg, uint wParam, long lParam) {
    if (this->ready == 0) return 0;
    return ds_stream_messages(hwnd, msg, wParam, lParam);
}

// Offset: 0x004BC9B0
int TSound_Driver::add_to_play_list(TDigital* digital) {
    if (this->play_list_count != 255 && this->mute == 0) {
        this->sound_play_list[this->play_list_count] = digital;
        this->play_list_count++;
        return 1;
    }
    return 0;
}

// Offset: 0x004BC9F0
void TSound_Driver::play_list() {
    for (int i = 0; i < this->play_list_count; i++) {
        this->sound_play_list[i]->play();
    }
}

// Offset: 0x004BCA20
void TSound_Driver::reset_play_list() {
    this->play_list_count = 0;
}

// Offset: 0x004BCA30
int TSound_Driver::open_mixer() {
    uint numDevs = mixerGetNumDevs();
    if (numDevs == 0) return 0;

    for (uint i = 0; i < numDevs; i++) {
        MMRESULT mr = mixerOpen((HMIXER*)&this->mixer_handle, i, 0, 0, 0);
        if (mr != MMSYSERR_NOERROR) continue;

        memset(&this->mixer_line_info, 0, sizeof(this->mixer_line_info));
        this->mixer_line_info.cbStruct = sizeof(MIXERLINEA);
        this->mixer_line_info.dwComponentType = MIXERLINE_COMPONENTTYPE_DST_SPEAKERS;

        mr = mixerGetLineInfoA((HMIXEROBJ)this->mixer_handle, &this->mixer_line_info, MIXER_GETLINEINFOF_COMPONENTTYPE);
        if (mr != MMSYSERR_NOERROR) {
            mixerClose((HMIXER)this->mixer_handle);
            this->mixer_handle = nullptr;
            continue;
        }

        memset(&this->mixer_line_controls, 0, sizeof(this->mixer_line_controls));
        memset(&this->mixer_volume_control, 0, sizeof(this->mixer_volume_control));

        this->mixer_line_controls.cbStruct = sizeof(MIXERLINECONTROLSA);
        this->mixer_line_controls.dwLineID = this->mixer_line_info.dwLineID;
        this->mixer_line_controls.dwControlType = MIXERCONTROL_CONTROLTYPE_VOLUME;
        this->mixer_line_controls.cControls = 1;
        this->mixer_line_controls.cbmxctrl = sizeof(MIXERCONTROLA);
        this->mixer_line_controls.pamxctrl = &this->mixer_volume_control;

        mr = mixerGetLineControlsA((HMIXEROBJ)this->mixer_handle, &this->mixer_line_controls, MIXER_GETLINECONTROLSF_ONEBYTYPE);
        if (mr != MMSYSERR_NOERROR) {
            mixerClose((HMIXER)this->mixer_handle);
            this->mixer_handle = nullptr;
            continue;
        }

        memset(&this->mixer_volume_details, 0, sizeof(this->mixer_volume_details));
        this->mixer_volume_value.dwValue = 0;

        this->mixer_volume_details.cbStruct = sizeof(MIXERCONTROLDETAILS);
        this->mixer_volume_details.dwControlID = this->mixer_volume_control.dwControlID;
        this->mixer_volume_details.cChannels = 1;
        this->mixer_volume_details.cbDetails = sizeof(MIXERCONTROLDETAILS_UNSIGNED);
        this->mixer_volume_details.paDetails = &this->mixer_volume_value;

        mr = mixerGetControlDetailsA((HMIXEROBJ)this->mixer_handle, &this->mixer_volume_details, 0);
        if (mr == MMSYSERR_NOERROR) {
            long range = this->mixer_volume_control.Bounds.lMaximum - this->mixer_volume_control.Bounds.lMinimum;
            this->mixer_open = 1;
            long vol = (long)((this->mixer_volume_value.dwValue * 10000) / (uint)range) - 10000;
            this->start_volume = vol;
            this->volume = vol;
            return 1;
        }

        mixerClose((HMIXER)this->mixer_handle);
        this->mixer_handle = nullptr;
    }
    return 0;
}

// Offset: 0x004BCBF0
void TSound_Driver::close_mixer() {
    if (this->mixer_open != 0) {
        if (this->start_volume != 1) {
            this->set_volume(this->start_volume, 0);
            this->start_volume = 1;
        }
        if (this->mixer_handle != nullptr) {
            mixerClose((HMIXER)this->mixer_handle);
            this->mixer_handle = nullptr;
        }
        this->mixer_open = 0;
    }
}

// ============================================================================
// TDigital
// ============================================================================

// Offset: 0x004BCC40
TDigital::TDigital(TSound_Driver* driver, char* file, long resId) {
    this->init_vars();
    this->sound_system = driver;
    this->resource_id = resId;
    if (file != nullptr) {
        strncpy(this->sound_file, file, 12);
        this->sound_file[12] = '\0';
    }
}

// Offset: 0x004BCC80
TDigital::TDigital(TDigital* src) {
    this->init_vars();
    this->owner = src;
    this->volume = src->volume;
    this->pitch = src->pitch;
    this->pan = src->pan;
    this->loop = src->loop;
}

// Offset: 0x004BCCB0
TDigital::~TDigital() {
    if (this->owner != nullptr) {
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

// Offset: 0x004BCCC0
void TDigital::init_vars() {
    this->sound_system = nullptr;
    this->owner = nullptr;
    this->loaded = 0;
    this->failed = 0;
    this->sound_file[0] = '\0';
    this->wave_data = nullptr;
    this->wave_info = nullptr;
    this->sound_buffer = nullptr;
    this->data_size = 0;
    this->volume = 0;
    this->pitch = 0;
    this->pan = 0;
    this->loop = 0;
}

// Offset: 0x004BCCF0
void TDigital::exit() {
    if (this->owner != nullptr) {
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

// Offset: 0x004BCD30
int TDigital::load(char* file, long resId) {
    char file_with_path[260];
    _tag_wavheader wave_hdr;
    DSBUFFERDESC buffer_desc;
    int load_type = 0;
    int resDataSize = 0;

    memset(&buffer_desc, 0, sizeof(buffer_desc));
    memset(&wave_hdr, 0, sizeof(wave_hdr));

    if (this->failed != 0) return 0;

    if (this->owner != nullptr) {
        return this->owner->load(file, -1);
    }

    if (this->sound_system == nullptr) return 0;

    color_log(0xBA, 0xBA, 1);

    if (this->loaded != 0) {
        this->unload();
    }

    if (file != nullptr) {
        strncpy(this->sound_file, file, 12);
        this->sound_file[12] = '\0';
    }

    if (this->sound_file[0] == '\0') {
        color_log(0xBA, '_', 1);
        return 0;
    }

    if ((unsigned long)resId > 0x7FFFFFFF) {
        resId = this->resource_id;
    }

    // Try file first, or if resource_id < 0
    if (sound_file_first != 0 || resId < 0) {
        sprintf(file_with_path, "%s%s", this->sound_system->path, this->sound_file);
        int fd = _open(file_with_path, _O_RDONLY | _O_BINARY);
        if (fd != -1) {
            int bytesRead = _read(fd, &wave_hdr, 0x2C);
            if (bytesRead != 0) {
                // Validate RIFF header
                if (strncmp(wave_hdr.szRIFF, "RIFF", 4) != 0 || (unsigned short)(wave_hdr.fmtTagChannels & 0xFFFF) != 1) {
                    // Not a valid wav or wrong format
                    this->failed = 1;
                    _close(fd);
                    color_log(0xBA, '_', 1);
                    return 0;
                }
                this->data_size = wave_hdr.dwDataSize;
                this->wave_data = (uchar*)malloc(this->data_size);
                if (this->wave_data == nullptr) {
                    this->failed = 1;
                    _close(fd);
                    color_log(0xBA, '_', 1);
                    return 0;
                }
                int readResult = _read(fd, this->wave_data, this->data_size);
                if (readResult == 0) {
                    this->failed = 1;
                    free(this->wave_data);
                    this->wave_data = nullptr;
                    _close(fd);
                    color_log(0xBA, '_', 1);
                    return 0;
                }
                _close(fd);

                this->wave_info = (tWAVEFORMATEX*)malloc(sizeof(tWAVEFORMATEX));
                if (this->wave_info == nullptr) {
                    this->failed = 1;
                    free(this->wave_data);
                    this->wave_data = nullptr;
                    color_log(0xBA, '_', 1);
                    return 0;
                }

                // Copy wave format from header fields into WAVEFORMATEX
                this->wave_info->wFormatTag = (unsigned short)(wave_hdr.fmtTagChannels & 0xFFFF);
                this->wave_info->nChannels = (unsigned short)((wave_hdr.fmtTagChannels >> 16) & 0xFFFF);
                this->wave_info->nSamplesPerSec = wave_hdr.nSamplesPerSec;
                this->wave_info->nAvgBytesPerSec = wave_hdr.nAvgBytesPerSec;
                this->wave_info->nBlockAlign = (unsigned short)(wave_hdr.blkAlignBPS & 0xFFFF);
                this->wave_info->wBitsPerSample = (unsigned short)((wave_hdr.blkAlignBPS >> 16) & 0xFFFF);
                this->wave_info->cbSize = 0;

                // Create DirectSound buffer
                memset(&buffer_desc, 0, sizeof(buffer_desc));
                buffer_desc.dwSize = sizeof(DSBUFFERDESC);
                buffer_desc.dwFlags = DSBCAPS_STATIC | DSBCAPS_CTRLVOLUME;
                buffer_desc.dwBufferBytes = this->data_size;
                buffer_desc.lpwfxFormat = this->wave_info;

                HRESULT hr = this->sound_system->direct_sound->CreateSoundBuffer(
                    &buffer_desc, &this->sound_buffer, nullptr);
                if (FAILED(hr)) {
                    this->failed = 1;
                    this->sound_buffer = nullptr;
                    free(this->wave_info);
                    this->wave_info = nullptr;
                    free(this->wave_data);
                    this->wave_data = nullptr;
                    color_log(0xBA, '_', 1);
                    return 0;
                }

                // Lock and fill
                void* mem1 = nullptr;
                void* mem2 = nullptr;
                unsigned long size1 = 0, size2 = 0;
                hr = this->sound_buffer->Lock(0, this->data_size, &mem1, &size1, &mem2, &size2, 0);
                if (FAILED(hr)) {
                    this->failed = 1;
                    this->sound_buffer->Release();
                    this->sound_buffer = nullptr;
                    free(this->wave_info);
                    this->wave_info = nullptr;
                    free(this->wave_data);
                    this->wave_data = nullptr;
                    color_log(0xBA, '_', 1);
                    return 0;
                }

                memcpy(mem1, this->wave_data, size1);
                if (mem2 != nullptr) {
                    memcpy(mem2, this->wave_data + size1, size2);
                }
                this->sound_buffer->Unlock(mem1, size1, mem2, size2);

                free(this->wave_info);
                this->wave_info = nullptr;
                free(this->wave_data);
                this->wave_data = nullptr;

                this->loaded = 1;
                color_log(0xBA, '_', 1);
                return 1;
            }
            this->failed = 1;
            _close(fd);
            color_log(0xBA, '_', 1);
            return 0;
        }
    }

    // Try loading from DRS resource
    if (resId < 0) {
        this->failed = 1;
        color_log(0xBA, '_', 1);
        return 0;
    }

    int resSize = 0;
    int resType = 0;
    unsigned char* resData = RESFILE_load(0x77617620, resId, &resSize, &resType);
    if (resData == nullptr) {
        this->failed = 1;
        color_log(0xBA, '_', 1);
        return 0;
    }

    // Copy wave header from resource
    memcpy(&wave_hdr, resData, sizeof(wave_hdr));

    this->data_size = wave_hdr.dwDataSize;
    this->wave_data = (uchar*)malloc(wave_hdr.dwDataSize);
    if (this->wave_data == nullptr) {
        this->failed = 1;
        if (resType == 1) free(resData);
        color_log(0xBA, '_', 1);
        return 0;
    }

    // Copy PCM data (after the header)
    memcpy(this->wave_data, resData + sizeof(wave_hdr), this->data_size);
    if (resType == 1) {
        free(resData);
    }

    this->wave_info = (tWAVEFORMATEX*)malloc(sizeof(tWAVEFORMATEX));
    if (this->wave_info == nullptr) {
        this->failed = 1;
        free(this->wave_data);
        this->wave_data = nullptr;
        color_log(0xBA, '_', 1);
        return 0;
    }

    this->wave_info->wFormatTag = (unsigned short)(wave_hdr.fmtTagChannels & 0xFFFF);
    this->wave_info->nChannels = (unsigned short)((wave_hdr.fmtTagChannels >> 16) & 0xFFFF);
    this->wave_info->nSamplesPerSec = wave_hdr.nSamplesPerSec;
    this->wave_info->nAvgBytesPerSec = wave_hdr.nAvgBytesPerSec;
    this->wave_info->nBlockAlign = (unsigned short)(wave_hdr.blkAlignBPS & 0xFFFF);
    this->wave_info->wBitsPerSample = (unsigned short)((wave_hdr.blkAlignBPS >> 16) & 0xFFFF);
    this->wave_info->cbSize = 0;

    memset(&buffer_desc, 0, sizeof(buffer_desc));
    buffer_desc.dwSize = sizeof(DSBUFFERDESC);
    buffer_desc.dwFlags = DSBCAPS_STATIC | DSBCAPS_CTRLVOLUME;
    buffer_desc.dwBufferBytes = this->data_size;
    buffer_desc.lpwfxFormat = this->wave_info;

    HRESULT hr = this->sound_system->direct_sound->CreateSoundBuffer(
        &buffer_desc, &this->sound_buffer, nullptr);
    if (SUCCEEDED(hr)) {
        void* mem1 = nullptr;
        void* mem2 = nullptr;
        unsigned long size1 = 0, size2 = 0;
        hr = this->sound_buffer->Lock(0, this->data_size, &mem1, &size1, &mem2, &size2, 0);
        if (SUCCEEDED(hr)) {
            memcpy(mem1, this->wave_data, size1);
            if (mem2 != nullptr) {
                memcpy(mem2, this->wave_data + size1, size2);
            }
            this->sound_buffer->Unlock(mem1, size1, mem2, size2);
            free(this->wave_info);
            this->wave_info = nullptr;
            free(this->wave_data);
            this->wave_data = nullptr;

            this->loaded = 1;
            color_log(0xBA, '_', 1);
            return 1;
        }
        this->failed = 1;
        this->sound_buffer->Release();
    } else {
        this->failed = 1;
    }
    this->sound_buffer = nullptr;
    free(this->wave_info);
    this->wave_info = nullptr;
    free(this->wave_data);
    this->wave_data = nullptr;
    color_log(0xBA, '_', 1);
    return 0;
}

// Offset: 0x004BD300
void TDigital::unload() {
    TDigital* cur = this;
    while (cur->owner != nullptr) {
        cur = cur->owner;
    }
    if (cur->loaded != 0) {
        cur->stop();
        if (cur->sound_buffer != nullptr) {
            cur->sound_buffer->Release();
            cur->sound_buffer = nullptr;
        }
        if (cur->wave_data != nullptr) {
            free(cur->wave_data);
            cur->wave_data = nullptr;
        }
        if (cur->wave_info != nullptr) {
            free(cur->wave_info);
            cur->wave_info = nullptr;
        }
        cur->loaded = 0;
    }
    cur->failed = 0;
}

// Offset: 0x004BD370
int TDigital::play() {
    TDigital* actual = this->owner;
    if (actual == nullptr) actual = this;

    TSound_Driver* drv = actual->sound_system;
    if (drv == nullptr || drv->ready == 0 || drv->mute != 0) {
        return 1;
    }

    if (actual->loaded == 0) {
        int r = actual->load(this->sound_file, -1);
        if (r == 0) return 0;
    }

    if (actual->sound_buffer == nullptr) {
        actual->failed = 1;
        return 0;
    }

    bool bLoop = (actual->loop != 0);

    actual->sound_buffer->SetVolume(this->volume);
    actual->sound_buffer->SetFrequency(this->pitch);
    actual->sound_buffer->SetPan(this->pan);
    actual->sound_buffer->SetCurrentPosition(0);

    HRESULT hr = actual->sound_buffer->Play(0, 0, bLoop ? DSBPLAY_LOOPING : 0);

    // DSERR_BUFFERLOST = 0x88780096
    if (hr == DSERR_BUFFERLOST) {
        int r = actual->load(nullptr, -1);
        if (r == 0) return 0;
        actual->sound_buffer->SetVolume(this->volume);
        actual->sound_buffer->SetFrequency(this->pitch);
        actual->sound_buffer->SetPan(this->pan);
        actual->sound_buffer->SetCurrentPosition(0);
        actual->sound_buffer->Play(0, 0, bLoop ? DSBPLAY_LOOPING : 0);
    }

    return 1;
}

// Offset: 0x004BD490
void TDigital::stop() {
    TDigital* cur = this;
    while (cur->owner != nullptr) {
        cur = cur->owner;
    }
    if (cur->sound_system != nullptr && cur->sound_system->ready != 0 &&
        cur->loaded != 0 && cur->sound_buffer != nullptr) {
        cur->sound_buffer->Stop();
    }
}

// Offset: 0x004BD4C0
void TDigital::set_loop(short val) {
    if (val == 0) {
        this->loop = 0;
    } else {
        this->loop = 1;
    }
}

// Offset: 0x004BD4E0
void TDigital::set_volume(long vol) {
    this->volume = vol;
    TDigital* actual = this->owner;
    if (actual == nullptr) actual = this;
    if (actual->loaded != 0) {
        actual->sound_buffer->SetVolume(vol);
    }
}

// Offset: 0x004BD510
void TDigital::set_pitch(ulong p) {
    this->pitch = p;
    TDigital* actual = this->owner;
    if (actual == nullptr) actual = this;
    if (actual->loaded != 0) {
        actual->sound_buffer->SetFrequency(p);
    }
}

// Offset: 0x004BD540
void TDigital::set_pan(long p) {
    this->pan = p;
    TDigital* actual = this->owner;
    if (actual == nullptr) actual = this;
    if (actual->loaded != 0) {
        actual->sound_buffer->SetPan(p);
    }
}

// Offset: 0x004BD570
int TDigital::is_playing() {
    TDigital* actual = this->owner;
    if (actual == nullptr) actual = this;

    if (this->sound_system != nullptr && actual->loaded != 0 && actual->sound_buffer != nullptr) {
        DWORD status = 0;
        HRESULT hr = actual->sound_buffer->GetStatus(&status);
        if (SUCCEEDED(hr) && (status & DSBSTATUS_PLAYING)) {
            return 1;
        }
    }
    return 0;
}

// Offset: 0x004BD5C0
int TDigital::add_to_play_list() {
    TSound_Driver* drv = this->sound_system;
    if (drv != nullptr && drv->mute == 0) {
        return drv->add_to_play_list(this);
    }
    return 0;
}
