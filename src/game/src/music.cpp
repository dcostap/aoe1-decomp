// Decompiled: music.cpp
// SourceMap: C:/msdev/work/age1_x1/music.cpp

#include "../include/TMusic_System.h"
#include "../include/TSound_Driver.h"
#include "../include/Dsutil.h"
#include "../include/debug_helpers.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// Offset: 0x00461910
TMusic_System::TMusic_System(uchar mtype, void* inst, void* wnd, TSound_Driver* snd, char* p) {
    this->music_type = mtype;
    this->sound_system = snd;
    this->instance = inst;
    this->window = wnd;
    this->device_open = 0;
    this->device_id = 0;
    this->playing_track = 0;
    this->file_name[0] = '\0';
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
    this->fade_time = 0;
    this->fading_track = 0;
    this->fade_volume = 0;
    this->last_fade_time = 0;
    this->mixer_open = 0;
    this->mixer_handle = nullptr;
    this->midi_window = nullptr;
    this->last_check_time = 0;

    if (p != nullptr) {
        strcpy(this->path, p);
    } else {
        this->path[0] = '\0';
    }

    this->open_device();
    this->open_mixer();
}

// Offset: 0x00461A20
TMusic_System::~TMusic_System() {
    this->stop_playing();
    this->close_mixer();
    this->close_device();
}

// Offset: 0x00461A30
int TMusic_System::open_device() {
    if (this->music_type == 1) {
        // CD Audio
        MCI_OPEN_PARMSA mciOpen;
        memset(&mciOpen, 0, sizeof(mciOpen));
        mciOpen.lpstrDeviceType = (LPCSTR)MCI_DEVTYPE_CD_AUDIO;
        DWORD flags = MCI_OPEN_TYPE | MCI_OPEN_TYPE_ID;
        MCIERROR err = mciSendCommandA(0, MCI_OPEN, flags, (DWORD_PTR)&mciOpen);
        if (err != 0) return 0;
        this->device_id = mciOpen.wDeviceID;
        this->device_open = 1;

        // Set time format
        MCI_SET_PARMS mciSet;
        memset(&mciSet, 0, sizeof(mciSet));
        mciSet.dwTimeFormat = MCI_FORMAT_TMSF;
        mciSendCommandA(this->device_id, MCI_SET, MCI_SET_TIME_FORMAT, (DWORD_PTR)&mciSet);

        // Get number of tracks
        MCI_STATUS_PARMS mciStatus;
        memset(&mciStatus, 0, sizeof(mciStatus));
        mciStatus.dwItem = MCI_STATUS_NUMBER_OF_TRACKS;
        err = mciSendCommandA(this->device_id, MCI_STATUS, MCI_STATUS_ITEM | MCI_WAIT, (DWORD_PTR)&mciStatus);
        if (err == 0) {
            this->track_count = (int)mciStatus.dwReturn;
        }
        return 1;
    }
    else if (this->music_type == 2) {
        // MIDI
        this->device_open = 1;
        return 1;
    }
    else if (this->music_type == 3) {
        // WAV streaming via TSound_Driver
        this->device_open = 1;
        return 1;
    }
    return 0;
}

// Offset: 0x00461C60
void TMusic_System::close_device() {
    if (this->device_open == 0) return;

    if (this->music_type == 1) {
        // CD Audio
        if (this->device_id != 0) {
            mciSendCommandA(this->device_id, MCI_CLOSE, MCI_WAIT, 0);
            this->device_id = 0;
        }
    }
    else if (this->music_type == 2) {
        // MIDI
        if (this->device_id != 0) {
            mciSendCommandA(this->device_id, MCI_CLOSE, MCI_WAIT, 0);
            this->device_id = 0;
        }
    }

    this->device_open = 0;
}

// Offset: 0x00461D20
int TMusic_System::open_mixer() {
    uint numDevs = mixerGetNumDevs();
    if (numDevs == 0) return 0;

    for (uint i = 0; i < numDevs; i++) {
        MMRESULT mr = mixerOpen((HMIXER*)&this->mixer_handle, i, 0, 0, 0);
        if (mr != MMSYSERR_NOERROR) continue;

        memset(&this->mixer_line_info, 0, sizeof(this->mixer_line_info));
        this->mixer_line_info.cbStruct = sizeof(MIXERLINEA);
        this->mixer_line_info.dwComponentType = MIXERLINE_COMPONENTTYPE_SRC_COMPACTDISC;

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

// Offset: 0x00461EC0
void TMusic_System::close_mixer() {
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

// Offset: 0x00461F00
int TMusic_System::set_music_type(uchar type) {
    this->stop_playing();
    this->close_mixer();
    this->close_device();
    this->music_type = type;
    this->open_device();
    this->open_mixer();
    return 1;
}

// Offset: 0x00461F40
void TMusic_System::set_fade_out(int fo, ulong ft) {
    this->fade_out = fo;
    this->fade_time = ft;
}

// Offset: 0x00461F60
void TMusic_System::set_volume(long vol, int save) {
    if (save != 0) {
        this->volume = vol;
    }

    if (this->music_type == 3) {
        // WAV streaming
        if (this->sound_system != nullptr) {
            this->sound_system->set_stream_volume(vol);
        }
    }
    else if (this->mixer_open != 0) {
        long range = this->mixer_volume_control.Bounds.lMaximum - this->mixer_volume_control.Bounds.lMinimum;
        this->mixer_volume_value.dwValue = (unsigned long)(range * (vol + 10000)) / 10000;
        mixerSetControlDetails(
            (HMIXEROBJ)this->mixer_handle,
            &this->mixer_volume_details, 0);
    }
}

// Offset: 0x00462010
int TMusic_System::play_track(int track, int lp, ulong pos) {
    this->start_track = track;
    this->end_track = track;
    this->loop = lp;
    this->make_cur_track = 0;
    this->set_pos = pos;
    this->file_name[0] = '\0';
    return this->play(track, track, nullptr, lp, pos);
}

// Offset: 0x00462090
int TMusic_System::play_file(char* filename, int lp, ulong pos) {
    if (filename != nullptr) {
        strcpy(this->file_name, filename);
    } else {
        this->file_name[0] = '\0';
    }
    this->start_track = 0;
    this->end_track = 0;
    this->loop = lp;
    this->make_cur_track = 0;
    this->set_pos = pos;
    return this->play(0, 0, filename, lp, pos);
}

// Offset: 0x00462140
int TMusic_System::play_tracks(int st, int et, int lp, int make_cur, ulong pos) {
    this->start_track = st;
    this->end_track = et;
    this->loop = lp;
    this->make_cur_track = make_cur;
    this->set_pos = pos;
    this->file_name[0] = '\0';

    int track = st;
    if (make_cur != 0) {
        track = this->current_track;
        if (track < st || track > et) {
            track = st;
        }
    }

    return this->play(track, et, nullptr, lp, pos);
}

// Offset: 0x00462200
int TMusic_System::play(int st, int et, char* filename, int lp, ulong pos) {
    if (this->device_open == 0) return 0;

    if (this->playing_track != 0) {
        if (this->fade_out != 0 && this->fading_track == 0) {
            // Start fading instead of immediate stop
            this->fading_track = 1;
            this->start_fade();
            return 1;
        }
        this->stop_playing();
    }

    this->paused = 0;

    if (this->music_type == 1) {
        // CD Audio
        this->play_info.dwCallback = (DWORD_PTR)this->window;
        this->play_info.dwFrom = (DWORD)st;
        this->play_info.dwTo = (DWORD)(et + 1);

        MCIERROR err = mciSendCommandA(this->device_id, MCI_PLAY,
            MCI_FROM | MCI_TO | MCI_NOTIFY,
            (DWORD_PTR)&this->play_info);
        if (err != 0) return 0;

        this->playing_track = 1;
        this->current_track = st;
        this->notify_waiting = 1;
        return 1;
    }
    else if (this->music_type == 2) {
        // MIDI
        char midi_path[260];
        if (filename != nullptr && filename[0] != '\0') {
            sprintf(midi_path, "%s%s", this->path, filename);
        } else {
            sprintf(midi_path, "%sMUSIC%d.MID", this->path, st);
        }

        MCI_OPEN_PARMSA mciOpen;
        memset(&mciOpen, 0, sizeof(mciOpen));
        mciOpen.lpstrDeviceType = "sequencer";
        mciOpen.lpstrElementName = midi_path;

        MCIERROR err = mciSendCommandA(0, MCI_OPEN,
            MCI_OPEN_TYPE | MCI_OPEN_ELEMENT,
            (DWORD_PTR)&mciOpen);
        if (err != 0) return 0;

        this->device_id = mciOpen.wDeviceID;

        MCI_PLAY_PARMS mciPlay;
        memset(&mciPlay, 0, sizeof(mciPlay));
        mciPlay.dwCallback = (DWORD_PTR)this->window;

        err = mciSendCommandA(this->device_id, MCI_PLAY, MCI_NOTIFY, (DWORD_PTR)&mciPlay);
        if (err != 0) {
            mciSendCommandA(this->device_id, MCI_CLOSE, MCI_WAIT, 0);
            this->device_id = 0;
            return 0;
        }

        this->playing_track = 1;
        this->current_track = st;
        this->notify_waiting = 1;
        return 1;
    }
    else if (this->music_type == 3) {
        // WAV streaming
        if (this->sound_system == nullptr) return 0;

        char wav_path[260];
        if (filename != nullptr && filename[0] != '\0') {
            sprintf(wav_path, "%s", filename);
        } else {
            sprintf(wav_path, "xmusic%d.mid", st);
        }

        int result = this->sound_system->stream_file(wav_path, lp, this->volume);
        if (result == 0) return 0;

        this->playing_track = 1;
        this->current_track = st;
        this->notify_waiting = 1;
        return 1;
    }

    return 0;
}

// Offset: 0x004625C0
int TMusic_System::pause_play() {
    if (this->playing_track == 0) return 0;
    if (this->paused != 0) return 0;

    if (this->music_type == 1) {
        mciSendCommandA(this->device_id, MCI_PAUSE, MCI_WAIT, 0);
    }
    else if (this->music_type == 2) {
        mciSendCommandA(this->device_id, MCI_PAUSE, MCI_WAIT, 0);
    }
    else if (this->music_type == 3) {
        if (this->sound_system != nullptr) {
            this->sound_system->pause_stream();
        }
    }

    this->paused = 1;
    return 1;
}

// Offset: 0x00462670
int TMusic_System::resume_play() {
    if (this->playing_track == 0) return 0;
    if (this->paused == 0) return 0;

    if (this->music_type == 1) {
        // Resume CD
        MCIERROR err = mciSendCommandA(this->device_id, MCI_PLAY,
            MCI_NOTIFY, (DWORD_PTR)&this->play_info);
        if (err != 0) return 0;
        this->notify_waiting = 1;
    }
    else if (this->music_type == 2) {
        // Resume MIDI
        MCI_PLAY_PARMS mciPlay;
        memset(&mciPlay, 0, sizeof(mciPlay));
        mciPlay.dwCallback = (DWORD_PTR)this->window;
        MCIERROR err = mciSendCommandA(this->device_id, MCI_PLAY,
            MCI_NOTIFY, (DWORD_PTR)&mciPlay);
        if (err != 0) return 0;
        this->notify_waiting = 1;
    }
    else if (this->music_type == 3) {
        if (this->sound_system != nullptr) {
            this->sound_system->resume_stream();
        }
    }

    this->paused = 0;
    return 1;
}

// Offset: 0x00462740
int TMusic_System::stop_track() {
    if (this->playing_track == 0 || this->device_open == 0) return 0;

    if (this->music_type == 1 || this->music_type == 2) {
        mciSendCommandA(this->device_id, MCI_STOP, MCI_WAIT, 0);
    }
    return 1;
}

// Offset: 0x00462770
int TMusic_System::stop_playing() {
    if (this->device_open == 0) return 0;

    if (this->music_type == 1) {
        mciSendCommandA(this->device_id, MCI_STOP, MCI_WAIT, 0);
    }
    else if (this->music_type == 2) {
        if (this->device_id != 0) {
            mciSendCommandA(this->device_id, MCI_STOP, MCI_WAIT, 0);
            mciSendCommandA(this->device_id, MCI_CLOSE, MCI_WAIT, 0);
            this->device_id = 0;
        }
    }
    else if (this->music_type == 3) {
        if (this->sound_system != nullptr) {
            this->sound_system->stop_stream();
        }
    }

    this->playing_track = 0;
    this->notify_waiting = 0;
    this->fading_track = 0;
    return 1;
}

// Offset: 0x00462820
int TMusic_System::fade_track() {
    if (this->playing_track == 0 || this->fading_track != 0) return 0;
    this->fading_track = 1;
    this->start_fade();
    return 1;
}

// Offset: 0x00462860
void TMusic_System::start_fade() {
    this->fade_volume = this->volume;
    this->last_fade_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\music.cpp", 0x1B9);
}

// Offset: 0x004628A0
void TMusic_System::do_fade() {
    if (this->fading_track == 0) return;

    ulong now = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\music.cpp", 0x1C3);
    ulong elapsed = now - this->last_fade_time;
    this->last_fade_time = now;

    if (this->fade_time == 0) {
        this->end_fade();
        return;
    }

    // Compute volume step
    double step = (double)(this->volume + 10000) * (double)elapsed / (double)this->fade_time;
    this->fade_volume = this->fade_volume - (long)step;

    if (this->fade_volume <= -10000) {
        this->end_fade();
        return;
    }

    this->set_volume(this->fade_volume, 0);
}

// Offset: 0x004629B0
void TMusic_System::end_fade() {
    this->stop_playing();
    this->set_volume(this->volume, 0);
    this->fading_track = 0;

    // Play next tracks if needed
    this->after_end_track();
}

// Offset: 0x00462A10
uint TMusic_System::handle_messages(void* hwnd, uint msg, uint wParam, long lParam) {
    // 0x113 = WM_TIMER, 0x1C = WM_ACTIVATEAPP, 0x3B9 = MM_MCINOTIFY, 0x500 = custom stream end
    if (msg == 0x113) {
        // Timer: do fade
        this->do_fade();
        return 0;
    }

    if (msg == 0x1C) {
        // WM_ACTIVATEAPP
        if (wParam == 0) {
            // Deactivating
            if (this->playing_track != 0 && this->paused == 0) {
                this->pause_play();
                this->auto_paused = 1;
                this->inactivated = 1;
            }
        } else {
            // Activating
            if (this->auto_paused != 0) {
                this->resume_play();
                this->auto_paused = 0;
            }
            this->inactivated = 0;
        }
        return 0;
    }

    if (msg == 0x3B9) {
        // MM_MCINOTIFY
        if (this->notify_waiting != 0 && wParam == MCI_NOTIFY_SUCCESSFUL) {
            this->notify_waiting = 0;
            this->after_end_track();
        }
        return 0;
    }

    if (msg == 0x500) {
        // Stream end notification (from ds_stream)
        if (this->music_type == 3 && this->playing_track != 0) {
            this->playing_track = 0;
            this->after_end_track();
        }
        return 0;
    }

    return 0;
}

// Offset: 0x00462B40
void TMusic_System::after_end_track() {
    // Determine next track
    int next = this->current_track + 1;

    if (this->file_name[0] != '\0') {
        // Playing a specific file
        if (this->loop != 0) {
            this->play(0, 0, this->file_name, this->loop, this->set_pos);
        }
        return;
    }

    if (next <= this->end_track) {
        // More tracks in range
        this->current_track = next;
        this->play(next, this->end_track, nullptr, this->loop, this->set_pos);
    }
    else if (this->loop != 0) {
        // Loop back to start
        this->current_track = this->start_track;
        this->play(this->start_track, this->end_track, nullptr, this->loop, this->set_pos);
    }
    else {
        // Done
        this->playing_track = 0;
    }
}

// Offset: 0x00462C30
int TMusic_System::get_play_info(uchar* playing, int* track, int* start, int* end, char* filename, int* looping, ulong* pos) {
    *playing = this->playing_track;
    *track = this->current_track;
    *start = this->start_track;
    *end = this->end_track;
    if (this->file_name[0] != '\0') {
        strcpy(filename, this->file_name);
    } else {
        filename[0] = '\0';
    }
    *looping = this->loop;
    *pos = this->set_pos;
    return 1;
}
