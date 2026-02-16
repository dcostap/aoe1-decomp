// Decompiled: music.cpp
// SourceMap: C:/msdev/work/age1_x1/music.cpp

#include "../include/TMusic_System.h"
#include "../include/TSound_Driver.h"
#include "../include/debug_helpers.h"
#include <io.h>
#include <stdio.h>
#include <string.h>

// Offset: 0x00461910
TMusic_System::TMusic_System(uchar mtype, void* inst, void* wnd, TSound_Driver* snd, char* p) {
    // Fully verified. Source of truth: music.cpp.decomp @ 0x00461910
    this->music_type = mtype;
    this->sound_system = snd;
    this->window = wnd;
    this->instance = inst;
    this->device_open = 0;
    this->device_id = 0;
    this->playing_track = 0;
    this->start_track = 0;
    this->end_track = 0;
    this->make_cur_track = 0;
    this->set_pos = 0;
    this->loop = 0;
    this->current_track = 0;
    this->track_count = 0;
    this->notify_waiting = 0;
    this->start_volume = 1;
    this->volume = 0;
    this->paused = 0;
    this->auto_paused = 0;
    this->inactivated = 0;
    this->fade_out = 0;
    this->fade_time = 2000;
    this->fading_track = 0;
    this->fade_volume = 0;
    this->last_fade_time = 0;
    this->mixer_open = 0;
    this->mixer_handle = nullptr;
    this->midi_window = nullptr;
    this->file_name[0] = '\0';
    this->last_check_time = 0;
    if (p == nullptr) {
        this->path[0] = '\0';
    } else {
        strcpy(this->path, p);
    }
    this->open_device();
}

// Offset: 0x00461A20
TMusic_System::~TMusic_System() {
    // Fully verified. Source of truth: music.cpp.decomp @ 0x00461A20
    this->close_device();
}

// Offset: 0x00461A30
int TMusic_System::open_device() {
    // Fully verified. Source of truth: music.cpp.decomp @ 0x00461A30
    char file_name[261];
    if (this->music_type == 1) {
        MCI_OPEN_PARMSA open_info;
        MCI_SET_PARMS set_info;
        MCI_STATUS_PARMS status_info;
        memset(&open_info, 0, sizeof(open_info));
        open_info.lpstrDeviceType = (LPCSTR)MCI_DEVTYPE_CD_AUDIO;
        int open_err = mciSendCommandA(0, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_TYPE_ID, (DWORD_PTR)&open_info);
        if (open_err == 0) {
            this->device_open = 1;
            this->device_id = open_info.wDeviceID;
            memset(&set_info, 0, sizeof(set_info));
            set_info.dwTimeFormat = MCI_FORMAT_TMSF;
            mciSendCommandA(open_info.wDeviceID, MCI_SET, MCI_SET_TIME_FORMAT | MCI_WAIT, (DWORD_PTR)&set_info);
            memset(&status_info, 0, sizeof(status_info));
            status_info.dwItem = MCI_STATUS_NUMBER_OF_TRACKS;
            if (mciSendCommandA(this->device_id, MCI_STATUS, MCI_STATUS_ITEM | MCI_WAIT, (DWORD_PTR)&status_info) == 0) {
                this->track_count = (int)status_info.dwReturn;
            }
            if (this->open_mixer() != 0) {
                int vol = (int)((this->mixer_volume_value.dwValue * 10000) /
                    (uint)(this->mixer_volume_control.Bounds.lMaximum - this->mixer_volume_control.Bounds.lMinimum)) - 10000;
                this->start_volume = vol;
                this->volume = vol;
            }
            return 1;
        }
    } else if (this->music_type == 2) {
        if (this->open_mixer() != 0) {
            int vol = (int)((this->mixer_volume_value.dwValue * 10000) /
                (uint)(this->mixer_volume_control.Bounds.lMaximum - this->mixer_volume_control.Bounds.lMinimum)) - 10000;
            this->start_volume = vol;
            this->volume = vol;
        }
        this->track_count = 0;
        while (true) {
            sprintf(file_name, "%smusic%d.mid", this->path, this->track_count + 1);
            FILE* f = fopen(file_name, "r");
            if (f == nullptr) {
                break;
            }
            fclose(f);
            this->track_count = this->track_count + 1;
        }
        this->device_open = 1;
        return 1;
    } else if (this->music_type == 3) {
        this->track_count = 0;
        while (true) {
            sprintf(file_name, "%smusic%d.wav", this->path, this->track_count + 1);
            FILE* f = fopen(file_name, "r");
            if (f == nullptr) {
                break;
            }
            fclose(f);
            this->track_count = this->track_count + 1;
        }
        this->volume = 0;
        this->device_open = 1;
        return 1;
    }
    return 0;
}

// Offset: 0x00461C60
void TMusic_System::close_device() {
    // Fully verified. Source of truth: music.cpp.decomp @ 0x00461C60
    if (this->device_open != 0) {
        this->stop_track();
        uchar uVar1 = this->music_type;
        if (uVar1 == 1) {
            if (this->start_volume != 1) {
                this->set_volume(this->start_volume, 0);
                this->start_volume = 1;
            }
            this->close_mixer();
            mciSendCommandA(this->device_id, MCI_CLOSE, MCI_WAIT, 0);
            this->device_id = 0;
            this->device_open = 0;
            this->track_count = 0;
        } else if (uVar1 == 2) {
            if (this->start_volume != 1) {
                this->set_volume(this->start_volume, 0);
                this->start_volume = 1;
            }
            this->close_mixer();
            this->device_open = 0;
            this->track_count = 0;
        } else if (uVar1 == 3) {
            this->track_count = 0;
            this->device_open = 0;
        }
    }
}

// Offset: 0x00461D20
int TMusic_System::open_mixer() {
    // Fully verified. Source of truth: music.cpp.decomp @ 0x00461D20
    uint num_dev = mixerGetNumDevs();
    if (num_dev == 0) {
        return 0;
    }
    for (uint mixer_id = 0; mixer_id < num_dev; mixer_id++) {
        if (mixerOpen((HMIXER*)&this->mixer_handle, mixer_id, 0, 0, 0) == MMSYSERR_NOERROR) {
            memset(&this->mixer_line_info, 0, sizeof(this->mixer_line_info));
            this->mixer_line_info.cbStruct = sizeof(MIXERLINEA);
            if (this->music_type == 1) {
                this->mixer_line_info.dwComponentType = MIXERLINE_COMPONENTTYPE_SRC_COMPACTDISC;
            } else {
                this->mixer_line_info.dwComponentType = MIXERLINE_COMPONENTTYPE_SRC_SYNTHESIZER;
            }
            if (mixerGetLineInfoA((HMIXEROBJ)this->mixer_handle, &this->mixer_line_info, MIXER_GETLINEINFOF_COMPONENTTYPE) == MMSYSERR_NOERROR) {
                memset(&this->mixer_line_controls, 0, sizeof(this->mixer_line_controls));
                memset(&this->mixer_volume_control, 0, sizeof(this->mixer_volume_control));
                this->mixer_line_controls.cbStruct = sizeof(MIXERLINECONTROLSA);
                this->mixer_line_controls.dwLineID = this->mixer_line_info.dwLineID;
                this->mixer_line_controls.dwControlType = MIXERCONTROL_CONTROLTYPE_VOLUME;
                this->mixer_line_controls.cControls = 1;
                this->mixer_line_controls.cbmxctrl = sizeof(MIXERCONTROLA);
                this->mixer_line_controls.pamxctrl = &this->mixer_volume_control;
                if (mixerGetLineControlsA((HMIXEROBJ)this->mixer_handle, &this->mixer_line_controls, MIXER_GETLINECONTROLSF_ONEBYTYPE) == MMSYSERR_NOERROR) {
                    memset(&this->mixer_volume_details, 0, sizeof(this->mixer_volume_details));
                    this->mixer_volume_value.dwValue = 0;
                    this->mixer_volume_details.cbStruct = sizeof(MIXERCONTROLDETAILS);
                    this->mixer_volume_details.dwControlID = this->mixer_volume_control.dwControlID;
                    this->mixer_volume_details.cChannels = 1;
                    this->mixer_volume_details.cbDetails = sizeof(MIXERCONTROLDETAILS_UNSIGNED);
                    this->mixer_volume_details.paDetails = &this->mixer_volume_value;
                    if (mixerGetControlDetailsA((HMIXEROBJ)this->mixer_handle, &this->mixer_volume_details, 0) == MMSYSERR_NOERROR) {
                        this->mixer_open = 1;
                        return 1;
                    }
                }
            }
            mixerClose((HMIXER)this->mixer_handle);
            this->mixer_handle = nullptr;
        }
    }
    return 0;
}

// Offset: 0x00461EC0
void TMusic_System::close_mixer() {
    // Fully verified. Source of truth: music.cpp.decomp @ 0x00461EC0
    if (this->mixer_open != 0) {
        if (this->mixer_handle != nullptr) {
            mixerClose((HMIXER)this->mixer_handle);
            this->mixer_handle = nullptr;
        }
        this->mixer_open = 0;
    }
}

// Offset: 0x00461F00
int TMusic_System::set_music_type(uchar type) {
    // Fully verified. Source of truth: music.cpp.decomp @ 0x00461F00
    if (type == this->music_type) {
        return this->device_open;
    }
    this->close_device();
    this->music_type = type;
    return this->open_device();
}

// Offset: 0x00461F40
void TMusic_System::set_fade_out(int fade_out, ulong fade_time) {
    // Fully verified. Source of truth: music.cpp.decomp @ 0x00461F40
    this->fade_out = fade_out;
    this->fade_time = fade_time;
}

// Offset: 0x00461F60
void TMusic_System::set_volume(long vol, int save) {
    // Fully verified. Source of truth: music.cpp.decomp @ 0x00461F60
    if (vol < -10000) {
        vol = -10000;
    } else if (vol > 0) {
        vol = 0;
    }
    if (save != 0) {
        this->volume = vol;
    }
    if (this->device_open != 0) {
        if (this->music_type == 1 || this->music_type == 2) {
            if (this->mixer_open != 0) {
                this->mixer_volume_value.dwValue =
                    (uint)(((this->mixer_volume_control.Bounds.lMaximum - this->mixer_volume_control.Bounds.lMinimum) * (vol + 10000)) / 10000);
                mixerSetControlDetails((HMIXEROBJ)this->mixer_handle, &this->mixer_volume_details, 0);
            }
        } else if (this->music_type == 3) {
            if (this->sound_system != nullptr) {
                this->sound_system->set_stream_volume(vol);
            }
        }
    }
}

// Offset: 0x00462010
int TMusic_System::play_track(int track, int loop, ulong set_pos) {
    // Fully verified. Source of truth: music.cpp.decomp @ 0x00462010
    this->file_name[0] = '\0';
    this->start_track = track;
    this->end_track = track;
    this->make_cur_track = 0;
    this->set_pos = set_pos;
    this->loop = loop;
    if ((this->playing_track != 0) && (this->fade_out != 0) && (this->fade_time != 0)) {
        this->start_fade();
        return 1;
    }
    return this->play(track, track, nullptr, 0, set_pos);
}

// Offset: 0x00462090
int TMusic_System::play_file(char* filename, int loop, ulong set_pos) {
    // Fully verified. Source of truth: music.cpp.decomp @ 0x00462090
    if (this->music_type == 1) {
        return 0;
    }
    if (filename != nullptr) {
        strcpy(this->file_name, filename);
    } else {
        this->file_name[0] = '\0';
    }
    this->start_track = 0;
    this->end_track = 0;
    this->make_cur_track = 0;
    this->set_pos = set_pos;
    this->loop = loop;
    if ((this->playing_track != 0) && (this->fade_out != 0) && (this->fade_time != 0)) {
        this->start_fade();
        return 1;
    }
    return this->play(0, 0, this->file_name, 0, set_pos);
}

// Offset: 0x00462140
int TMusic_System::play_tracks(int start_track, int end_track, int loop, int make_cur_track, ulong set_pos) {
    // Fully verified. Source of truth: music.cpp.decomp @ 0x00462140
    this->loop = loop;
    int tracks = this->track_count;
    this->file_name[0] = '\0';
    this->start_track = start_track;
    this->end_track = end_track;
    this->make_cur_track = make_cur_track;
    this->set_pos = set_pos;
    if (tracks == 0) {
        return 0;
    }
    if (this->start_track > tracks) {
        this->start_track = tracks;
    }
    if (this->end_track < this->start_track) {
        this->end_track = this->start_track;
    } else if (this->end_track > tracks) {
        this->end_track = tracks;
    }
    if ((this->playing_track != 0) && (this->fade_out != 0) && (this->fade_time != 0)) {
        this->start_fade();
        return 1;
    }
    return this->play(this->start_track, this->end_track, nullptr, make_cur_track, set_pos);
}

// Offset: 0x00462200
int TMusic_System::play(int start_track, int end_track, char* filename, int make_cur_track, ulong set_pos) {
    // Fully verified. Source of truth: music.cpp.decomp @ 0x00462200
    char track_name[261];
    char szErrorMsg[256];
    if (this->device_open == 0) {
        return 0;
    }
    if (this->playing_track != 0) {
        this->stop_playing();
    }
    if ((filename == nullptr) || (*filename == '\0')) {
        if (this->track_count == 0) {
            return 0;
        }
        if (this->track_count < start_track) {
            return 0;
        }
        if (start_track == 0) {
            return 0;
        }
        if (make_cur_track == 0) {
            this->current_track = start_track;
        } else {
            this->current_track = make_cur_track;
        }
    }
    if (this->music_type == 1) {
        this->play_info.dwCallback = (DWORD_PTR)this->window;
        uint flags = MCI_NOTIFY;
        if (set_pos == 0) {
            flags = flags | MCI_FROM;
            this->play_info.dwFrom = (uint)(byte)this->current_track;
        } else {
            MCI_SEEK_PARMS seek_info;
            memset(&seek_info, 0, sizeof(seek_info));
            seek_info.dwTo = set_pos;
            mciSendCommandA(this->device_id, MCI_SEEK, MCI_TO | MCI_WAIT, (DWORD_PTR)&seek_info);
        }
        if ((start_track < this->track_count) && (end_track < this->track_count)) {
            flags = flags | MCI_TO;
            this->play_info.dwTo = (uint)(byte)(end_track + 1);
        }
        int err = mciSendCommandA(this->device_id, MCI_PLAY, flags, (DWORD_PTR)&this->play_info);
        if (err == 0) {
            this->playing_track = 1;
            this->notify_waiting = this->notify_waiting + 1;
        }
    } else if (this->music_type == 2) {
        if ((filename == nullptr) || (*filename == '\0')) {
            sprintf(track_name, "%smusic%d.mid", this->path, this->current_track);
        } else {
            sprintf(track_name, "%s%s", this->path, filename);
            if (strchr(track_name, '.') == nullptr) {
                strcat(track_name, ".mid");
            }
        }
        int fd = _open(track_name, 0);
        if (fd != -1) {
            _close(fd);
            MCI_OPEN_PARMSA open_info;
            memset(&open_info, 0, sizeof(open_info));
            open_info.lpstrElementName = track_name;
            open_info.lpstrDeviceType = (LPCSTR)MCI_DEVTYPE_SEQUENCER;
            int err = mciSendCommandA(0, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_TYPE_ID | MCI_OPEN_ELEMENT, (DWORD_PTR)&open_info);
            if (err != 0) {
                if (mciGetErrorStringA(err, szErrorMsg, sizeof(szErrorMsg)) == 0) {
                    strcpy(szErrorMsg, "Unknow Error");
                }
            }
            if (err == 0) {
                this->device_id = open_info.wDeviceID;
                if (set_pos != 0) {
                    MCI_SEEK_PARMS seek_info;
                    memset(&seek_info, 0, sizeof(seek_info));
                    seek_info.dwTo = set_pos;
                    mciSendCommandA(this->device_id, MCI_SEEK, MCI_TO, (DWORD_PTR)&seek_info);
                }
                this->play_info.dwCallback = (DWORD_PTR)this->window;
                err = mciSendCommandA(this->device_id, MCI_PLAY, MCI_NOTIFY, (DWORD_PTR)&this->play_info);
                if (err == 0) {
                    this->playing_track = 1;
                    this->notify_waiting = this->notify_waiting + 1;
                } else {
                    if (mciGetErrorStringA(err, szErrorMsg, sizeof(szErrorMsg)) == 0) {
                        strcpy(szErrorMsg, "Unknow Error");
                    }
                }
            }
        }
    } else if ((this->music_type == 3) && (this->sound_system != nullptr)) {
        if ((filename == nullptr) || (*filename == '\0')) {
            sprintf(track_name, "%smusic%d.wav", this->path, this->current_track);
        } else {
            sprintf(track_name, "%s%s", this->path, filename);
        }
        int ok = this->sound_system->stream_file(track_name, 0, this->volume);
        if (ok == 0) {
            return 0;
        }
        this->playing_track = 1;
    }
    if (this->playing_track == 0) {
        return 0;
    }
    this->paused = 0;
    this->auto_paused = 0;
    this->inactivated = 0;
    return 1;
}

// Offset: 0x004625C0
int TMusic_System::pause_play() {
    // Fully verified. Source of truth: music.cpp.decomp @ 0x004625C0
    if ((this->device_open == 0) || (this->playing_track == 0)) {
        return 0;
    }
    if (this->paused != 0) {
        this->auto_paused = 0;
        return 1;
    }
    this->paused = 1;
    if (this->auto_paused != 0) {
        this->auto_paused = 0;
        return 1;
    }
    if (this->music_type == 1) {
        mciSendCommandA(this->device_id, MCI_PAUSE, MCI_WAIT, 0);
    } else if (this->music_type == 2) {
        mciSendCommandA(this->device_id, MCI_PAUSE, MCI_WAIT, 0);
    } else if ((this->music_type == 3) && (this->sound_system != nullptr)) {
        this->sound_system->pause_stream();
    }
    return 1;
}

// Offset: 0x00462670
int TMusic_System::resume_play() {
    // Fully verified. Source of truth: music.cpp.decomp @ 0x00462670
    if ((this->device_open == 0) || (this->playing_track == 0) || (this->paused == 0)) {
        return 0;
    }
    this->paused = 0;
    this->auto_paused = 0;
    if (this->fading_track != 0) {
        this->end_fade();
        return 1;
    }
    int iVar2 = 0;
    if (this->music_type == 1) {
        iVar2 = mciSendCommandA(this->device_id, MCI_PLAY, 0, (DWORD_PTR)&this->play_info);
    } else if (this->music_type == 2) {
        iVar2 = mciSendCommandA(this->device_id, MCI_PLAY, 0, (DWORD_PTR)&this->play_info);
    } else if (this->music_type == 3) {
        if (this->sound_system != nullptr) {
            this->sound_system->resume_stream();
        }
        return 1;
    }
    if (iVar2 == 0) {
        this->notify_waiting = this->notify_waiting + 1;
    }
    return 1;
}

// Offset: 0x00462740
int TMusic_System::stop_track() {
    // Fully verified. Source of truth: music.cpp.decomp @ 0x00462740
    this->loop = 0;
    this->start_track = 0;
    this->end_track = 0;
    this->file_name[0] = '\0';
    this->fading_track = 0;
    return this->stop_playing();
}

// Offset: 0x00462770
int TMusic_System::stop_playing() {
    // Fully verified. Source of truth: music.cpp.decomp @ 0x00462770
    if (this->playing_track == 0) {
        return 1;
    }
    uchar uVar1 = this->music_type;
    if (uVar1 == 1) {
        mciSendCommandA(this->device_id, MCI_STOP, MCI_WAIT, 0);
        this->playing_track = 0;
    } else if (uVar1 == 2) {
        mciSendCommandA(this->device_id, MCI_STOP, MCI_WAIT, 0);
        this->playing_track = 0;
        mciSendCommandA(this->device_id, MCI_CLOSE, MCI_WAIT, 0);
        this->device_id = 0;
    } else if ((uVar1 == 3) && (this->sound_system != nullptr)) {
        this->sound_system->stop_stream();
    }
    this->playing_track = 0;
    this->paused = 0;
    this->auto_paused = 0;
    return 1;
}

// Offset: 0x00462820
int TMusic_System::fade_track() {
    // Fully verified. Source of truth: music.cpp.decomp @ 0x00462820
    this->loop = 0;
    this->start_track = 0;
    this->end_track = 0;
    this->file_name[0] = '\0';
    this->fading_track = 0;
    if (this->playing_track != 0) {
        this->start_fade();
    }
    return 1;
}

// Offset: 0x00462860
void TMusic_System::start_fade() {
    // Fully verified. Source of truth: music.cpp.decomp @ 0x00462860
    if (this->fading_track == 0) {
        this->fade_volume = this->volume;
        this->last_fade_time = debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\music.cpp", 0x38c);
        this->fading_track = 1;
    }
}

// Offset: 0x004628A0
void TMusic_System::do_fade() {
    // Fully verified. Source of truth: music.cpp.decomp @ 0x004628A0
    if (this->paused == 0) {
        float time = (float)(debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\music.cpp", 0x39e) - this->last_fade_time);
        if ((this->fade_volume < -9999) && (this->playing_track != 0)) {
            this->stop_playing();
        }
        int step = (int)((time / (float)this->fade_time) * -10000.0f);
        int new_fade = this->fade_volume + step;
        this->fade_volume = new_fade;
        int margin = (int)((250.0f / (float)this->fade_time) * 10000.0f);
        if (new_fade > (-10000 - margin)) {
            this->set_volume(new_fade, 0);
            this->last_fade_time = debug_timeGetTime((char*)"C:\\msdev\\work\\age1_x1\\music.cpp", 0x3b8);
        } else {
            if (this->playing_track != 0) {
                this->stop_playing();
            }
            if (this->fading_track != 0) {
                this->end_fade();
                return;
            }
        }
    }
}

// Offset: 0x004629B0
void TMusic_System::end_fade() {
    // Fully verified. Source of truth: music.cpp.decomp @ 0x004629B0
    this->fading_track = 0;
    this->set_volume(this->volume, 0);
    if (((0 < this->start_track) && (0 < this->end_track)) || (this->file_name[0] != '\0')) {
        this->play(this->start_track, this->end_track, this->file_name, this->make_cur_track, this->set_pos);
    }
}

// Offset: 0x00462A10
uint TMusic_System::handle_messages(void* hwnd, uint msg, uint wParam, long lParam) {
    // Fully verified. Source of truth: music.cpp.decomp @ 0x00462A10
    (void)hwnd;
    (void)lParam;
    if (msg < 0x114) {
        if (msg == 0x113) {
            if (this->fading_track != 0) {
                this->do_fade();
                return 0;
            }
        } else if (msg == 0x1c) {
            if (wParam == 0) {
                if (this->inactivated == 0) {
                    this->pause_play();
                    this->auto_paused = 1;
                    this->inactivated = 1;
                    return 0;
                }
            } else if ((this->inactivated != 0) && (this->auto_paused != 0)) {
                this->resume_play();
                this->auto_paused = 0;
                this->inactivated = 0;
                return 0;
            }
        }
    } else if (msg == 0x3b9) {
        uchar uVar1 = this->music_type;
        if ((uVar1 == 1) || (uVar1 == 2)) {
            if (0 < this->notify_waiting) {
                this->notify_waiting = this->notify_waiting - 1;
            }
            if ((this->notify_waiting == 0) && (this->paused == 0)) {
                if (uVar1 == 1) {
                    this->playing_track = 0;
                }
                this->after_end_track();
            }
        }
    } else if ((msg == 0x500) && (this->music_type == 3) && (this->paused == 0)) {
        this->playing_track = 0;
        this->after_end_track();
        return 0;
    }
    return 0;
}

// Offset: 0x00462B40
void TMusic_System::after_end_track() {
    // Fully verified. Source of truth: music.cpp.decomp @ 0x00462B40
    uchar uVar1 = this->music_type;
    if (uVar1 == 1) {
        if (this->fading_track != 0) {
            return;
        }
        if (this->loop == 0) {
            return;
        }
    } else {
        char cVar3 = 0;
        if (uVar1 == 2) {
            if (this->fading_track != 0) {
                return;
            }
            cVar3 = this->file_name[0];
            if ((cVar3 == '\0') && (this->current_track < this->end_track)) {
                int next = this->current_track + 1;
                this->play(next, next, nullptr, 0, 0);
                return;
            }
        } else {
            if (uVar1 != 3) {
                return;
            }
            if (this->fading_track != 0) {
                return;
            }
            cVar3 = this->file_name[0];
            if ((cVar3 == '\0') && (this->current_track < this->end_track)) {
                int next = this->current_track + 1;
                this->play(next, next, nullptr, 0, 0);
                return;
            }
        }
        if (this->loop == 0) {
            return;
        }
        if (cVar3 != '\0') {
            this->play(0, 0, this->file_name, 0, 0);
            return;
        }
    }
    this->play(this->start_track, this->end_track, nullptr, 0, 0);
}

// Offset: 0x00462C30
int TMusic_System::get_play_info(uchar* music_type, int* track_from, int* track_to, int* cur_track, char* filename, int* looping, ulong* pos) {
    // Fully verified. Source of truth: music.cpp.decomp @ 0x00462C30
    MCI_STATUS_PARMS status_info;
    *music_type = this->music_type;
    *track_from = 0;
    *track_to = 0;
    *cur_track = 0;
    *filename = '\0';
    *looping = 0;
    *pos = 0;
    if (this->device_open == 0) {
        return 0;
    }
    if (this->playing_track != 0) {
        *track_from = this->start_track;
        *track_to = this->end_track;
        *cur_track = this->current_track;
        strcpy(filename, this->file_name);
        *looping = this->loop;
        *pos = 0;
        if ((this->music_type == 1) || (this->music_type == 2)) {
            memset(&status_info, 0, sizeof(status_info));
            status_info.dwItem = MCI_STATUS_POSITION;
            if (mciSendCommandA(this->device_id, MCI_STATUS, MCI_STATUS_ITEM | MCI_WAIT, (DWORD_PTR)&status_info) == 0) {
                *pos = status_info.dwReturn;
            }
        }
    }
    return 1;
}
