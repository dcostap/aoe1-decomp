#include "../include/game_globals.h"
#include "../include/music.h"

#include <stdio.h>
#include <string.h>
#include <fcntl.h>

static const char MUSIC_WAV_FORMAT[] = "%smusic%d.wav";
static const char MUSIC_MID_FORMAT[] = "%smusic%d.mid";
static const char MUSIC_NAME_FORMAT[] = "%s%s";
static const char MUSIC_ERROR[] = "Unknow Error";
static const char READ_MODE[] = "r";
static const int MUSIC_MIN_VOLUME = -10000;

#define MUSIC_STREAM_END_MESSAGE 0x500

typedef MCIERROR(WINAPI* MCI_SEND_COMMAND_PROC)(MCIDEVICEID, UINT, DWORD, DWORD);

extern unsigned long debug_timeGetTime(char* file, int line);
extern "C" int __cdecl open(const char*, int);
extern "C" int __cdecl close(int);

TMusic_System::TMusic_System(
    unsigned char music_type_in, void* instance_in, void* window_in, TSound_Driver* sound_system_in, char* path_in
) {
    this->music_type = music_type_in;
    this->sound_system = sound_system_in;
    this->instance = instance_in;
    this->window = window_in;
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
    this->last_fade_time = 0;
    this->mixer_open = 0;
    this->mixer_handle = 0;
    this->midi_window = 0;
    this->file_name[0] = 0;

    if (path_in != 0) {
        strcpy(this->path, path_in);
    } else {
        this->path[0] = 0;
    }

    this->open_device();
}

TMusic_System::~TMusic_System() {
    this->close_device();
}

int TMusic_System::open_device() {
    MCI_STATUS_PARMS status_info;
    MCI_SET_PARMS set_info;
    MCI_OPEN_PARMSA open_info;
    char file_name[261];

    switch (this->music_type) {
        case 1: {
            MCI_SEND_COMMAND_PROC mci = mciSendCommandA;
            open_info.lpstrDeviceType = MAKEINTRESOURCEA(MCI_DEVTYPE_CD_AUDIO);
            if (mci(0, MCI_OPEN, MCI_OPEN_TYPE_ID | MCI_OPEN_TYPE | MCI_OPEN_SHAREABLE | MCI_WAIT, (DWORD) &open_info)
                == 0) {
                this->device_open = 1;
                this->device_id = open_info.wDeviceID;
                set_info.dwTimeFormat = MCI_FORMAT_TMSF;
                mci(this->device_id, MCI_SET, MCI_SET_TIME_FORMAT | MCI_WAIT, (DWORD) &set_info);

                status_info.dwItem = MCI_STATUS_NUMBER_OF_TRACKS;
                if (mci(this->device_id, MCI_STATUS, MCI_STATUS_ITEM | MCI_WAIT, (DWORD) &status_info) == 0) {
                    this->track_count = status_info.dwReturn;
                }

                if (this->open_mixer() != 0) {
                    this->start_volume = (this->mixer_volume_value.dwValue * 10000)
                                         / (unsigned int) (this->mixer_volume_control.Bounds.lMaximum
                                                           - this->mixer_volume_control.Bounds.lMinimum);
                    this->start_volume += MUSIC_MIN_VOLUME;
                    this->volume = this->start_volume;
                }
                return 1;
            }
            break;
        }

        case 2: {
            FILE* scan_file;
            if (this->open_mixer() != 0) {
                this->start_volume = (this->mixer_volume_value.dwValue * 10000)
                                     / (unsigned int) (this->mixer_volume_control.Bounds.lMaximum
                                                       - this->mixer_volume_control.Bounds.lMinimum);
                this->start_volume += MUSIC_MIN_VOLUME;
                this->volume = this->start_volume;
            }

            memset(&this->track_count, 0, sizeof(this->track_count));
            do {
                sprintf(file_name, MUSIC_MID_FORMAT, this->path, this->track_count + 1);
                scan_file = fopen(file_name, READ_MODE);
                if (scan_file) {
                    fclose(scan_file);
                    ++this->track_count;
                } else {
                    break;
                }
            } while (1);
            this->device_open = 1;
            return 1;
        }

        case 3: {
            FILE* scan_file;
            memset(&this->track_count, 0, sizeof(this->track_count));
            do {
                sprintf(file_name, MUSIC_WAV_FORMAT, this->path, this->track_count + 1);
                scan_file = fopen(file_name, READ_MODE);
                if (scan_file) {
                    fclose(scan_file);
                    ++this->track_count;
                } else {
                    break;
                }
            } while (1);
            this->volume = 0;
            this->device_open = 1;
            return 1;
        }
    }
    return 0;
}

void TMusic_System::close_device() {
    if (this->device_open != 0) {
        this->stop_track();

        switch (this->music_type) {
            case 1:
                if (this->start_volume != 1) {
                    this->set_volume(this->start_volume, 0);
                    this->start_volume = 1;
                }
                this->close_mixer();
                mciSendCommandA(this->device_id, MCI_CLOSE, MCI_WAIT, 0);
                this->device_id = 0;
                this->device_open = 0;
                this->track_count = 0;
                break;

            case 2:
                if (this->start_volume != 1) {
                    this->set_volume(this->start_volume, 0);
                    this->start_volume = 1;
                }
                this->close_mixer();
                this->device_open = 0;
                this->track_count = 0;
                break;

            case 3:
                this->track_count = 0;
                this->device_open = 0;
                break;
        }
    }
}

int TMusic_System::open_mixer() {
    UINT num_dev = mixerGetNumDevs();
    if (num_dev <= 0) {
        return 0;
    }

    UINT mixer_id = 0;
    for (; mixer_id < num_dev; ++mixer_id) {
        if (mixerOpen(&this->mixer_handle, mixer_id, 0, 0, 0) == 0) {
            memset(&this->mixer_line_info, 0, sizeof(this->mixer_line_info));
            this->mixer_line_info.cbStruct = sizeof(this->mixer_line_info);
            if (this->music_type == 1) {
                this->mixer_line_info.dwComponentType = MIXERLINE_COMPONENTTYPE_SRC_COMPACTDISC;
            } else {
                this->mixer_line_info.dwComponentType = MIXERLINE_COMPONENTTYPE_SRC_SYNTHESIZER;
            }

            if (mixerGetLineInfoA(this->mixer_handle, &this->mixer_line_info, MIXER_GETLINEINFOF_COMPONENTTYPE) == 0) {
                memset(&this->mixer_line_controls, 0, sizeof(this->mixer_line_controls));
                memset(&this->mixer_volume_control, 0, sizeof(this->mixer_volume_control));
                this->mixer_line_controls.cbStruct = sizeof(this->mixer_line_controls);
                this->mixer_line_controls.dwLineID = this->mixer_line_info.dwLineID;
                this->mixer_line_controls.dwControlType = MIXERCONTROL_CONTROLTYPE_VOLUME;
                this->mixer_line_controls.cControls = 1;
                this->mixer_line_controls.cbmxctrl = sizeof(this->mixer_volume_control);
                this->mixer_line_controls.pamxctrl = &this->mixer_volume_control;

                if (mixerGetLineControlsA(
                        this->mixer_handle, &this->mixer_line_controls, MIXER_GETLINECONTROLSF_ONEBYTYPE
                    )
                    == 0) {
                    memset(&this->mixer_volume_details, 0, sizeof(this->mixer_volume_details));
                    memset(&this->mixer_volume_value, 0, sizeof(this->mixer_volume_value));
                    this->mixer_volume_details.cbStruct = sizeof(this->mixer_volume_details);
                    this->mixer_volume_details.dwControlID = this->mixer_volume_control.dwControlID;
                    this->mixer_volume_details.cChannels = 1;
                    this->mixer_volume_details.cbDetails = sizeof(this->mixer_volume_value);
                    this->mixer_volume_details.paDetails = &this->mixer_volume_value;

                    if (mixerGetControlDetailsA(
                            this->mixer_handle, &this->mixer_volume_details, MIXER_GETCONTROLDETAILSF_VALUE
                        )
                        == 0) {
                        this->mixer_open = 1;
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

void TMusic_System::close_mixer(void) {
    if (this->mixer_open != 0) {
        if (this->mixer_handle != 0) {
            mixerClose(this->mixer_handle);
            this->mixer_handle = 0;
        }
        this->mixer_open = 0;
    }
}

int TMusic_System::set_music_type(unsigned char music_type_in) {
    if (music_type_in == this->music_type) {
        return this->device_open;
    }
    this->close_device();
    this->music_type = music_type_in;
    return this->open_device();
}

void TMusic_System::set_fade_out(int fade_out_in, unsigned long fade_time_in) {
    this->fade_out = fade_out_in;
    this->fade_time = fade_time_in;
}

void TMusic_System::set_volume(long volume_in, int permanent) {
    if (volume_in < -10000) {
        volume_in = -10000;
    } else if (volume_in > 0) {
        volume_in = 0;
    }

    if (permanent) {
        this->volume = volume_in;
    }

    if (this->device_open == 0) {
        return;
    }

    switch (this->music_type) {
        case 1:
            if (this->mixer_open == 0) {
                return;
            }
            break;
        case 2:
            if (this->mixer_open == 0) {
                return;
            }
            break;
        case 3:
            if (this->sound_system == 0) {
                return;
            }
            this->sound_system->set_stream_volume(volume_in);
            return;
        default:
            return;
    }

    unsigned int delta = this->mixer_volume_control.Bounds.dwMaximum - this->mixer_volume_control.Bounds.dwMinimum;
    volume_in += 10000;
    delta = (delta * volume_in) / 10000;
    this->mixer_volume_value.dwValue = delta;
    mixerSetControlDetails(this->mixer_handle, &this->mixer_volume_details, MIXER_SETCONTROLDETAILSF_VALUE);
}

int TMusic_System::play_track(int track_in, int loop_in, unsigned long set_pos_in) {
    int was_playing = this->playing_track;
    this->file_name[0] = 0;
    this->start_track = track_in;
    this->end_track = track_in;
    this->make_cur_track = 0;
    this->set_pos = set_pos_in;
    this->loop = loop_in;

    if (was_playing && this->fade_out && this->fade_time > 0UL) {
        start_fade();
        return 1;
    }

    return play(track_in, track_in, 0, 0, set_pos_in);
}

int TMusic_System::play_file(char* file_name_in, int loop_in, unsigned long set_pos_in) {
    if (this->music_type == 1)
        return 0;

    strcpy(this->file_name, file_name_in);

    this->start_track = 0;
    this->end_track = 0;
    this->make_cur_track = 0;
    this->set_pos = set_pos_in;
    this->loop = loop_in;

    if (this->playing_track && this->fade_out && this->fade_time > 0UL) {
        start_fade();
        return 1;
    }

    return play(0, 0, this->file_name, 0, set_pos_in);
}

int TMusic_System::play_tracks(
    int start_track_in, int end_track_in, int loop_in, int make_cur_track_in, unsigned long set_pos_in
) {
    int count;

    this->loop = loop_in;
    count = this->track_count;
    this->file_name[0] = 0;
    this->start_track = start_track_in;
    this->end_track = end_track_in;
    this->make_cur_track = make_cur_track_in;
    this->set_pos = set_pos_in;

    if (count == 0)
        return count;

    if (start_track_in > count)
        this->start_track = count;

    start_track_in = this->start_track;
    if (end_track_in < start_track_in) {
        this->end_track = start_track_in;
    } else if (end_track_in > count) {
        this->end_track = count;
    }

    if (this->playing_track && this->fade_out && this->fade_time > 0UL) {
        this->start_fade();
        return 1;
    }

    return this->play(start_track_in, this->end_track, 0, make_cur_track_in, set_pos_in);
}

int TMusic_System::play(
    int start_track_in, int end_track_in, char* file_name_in, int make_cur_track_in, unsigned long set_pos_in
) {
    MCI_SEND_COMMAND_PROC mci;
    char track_name[261];
    char szErrorMsg[256];
    MCI_SEEK_PARMS seek_info;
    MCI_OPEN_PARMSA open_info;

    if (!this->device_open) {
        return 0;
    }

    if (this->playing_track != 0) {
        this->stop_playing();
    }

    if (!file_name_in || !*file_name_in) {
        int count = this->track_count;
        if (!count) {
            return 0;
        }
        if (start_track_in > count) {
            return 0;
        }
        if (!start_track_in) {
            return 0;
        }
        if (make_cur_track_in) {
            this->current_track = make_cur_track_in;
        } else {
            this->current_track = start_track_in;
        }
    }

    switch (this->music_type) {
        case 1: {
            MCIERROR result;
            mci = mciSendCommandA;
            this->play_info.dwCallback = (unsigned long) this->window;
            unsigned int flags = MCI_NOTIFY;

            if (set_pos_in > 0) {
                seek_info.dwCallback = 0;
                seek_info.dwTo = set_pos_in;
                mci(this->device_id, MCI_SEEK, MCI_TO | MCI_WAIT, (unsigned long) &seek_info);
            } else {
                flags = MCI_NOTIFY | MCI_FROM;
                this->play_info.dwFrom = (unsigned char) this->current_track;
            }

            if (start_track_in < this->track_count && end_track_in < this->track_count) {
                flags |= MCI_TO;
                this->play_info.dwTo = (unsigned char) (end_track_in + 1);
            }

            result = mci(this->device_id, MCI_PLAY, flags, (unsigned long) &this->play_info);
            if (!result) {
                this->playing_track = 1;
                ++this->notify_waiting;
            } else {
                if (!mciGetErrorStringA(result, szErrorMsg, sizeof(szErrorMsg))) {
                    strcpy(szErrorMsg, MUSIC_ERROR);
                }
            }
            break;
        }

        case 2: {
            MCIERROR result;
            if (!file_name_in || !*file_name_in) {
                sprintf(track_name, MUSIC_MID_FORMAT, this->path, this->current_track);
            } else {
                sprintf(track_name, MUSIC_NAME_FORMAT, this->path, file_name_in);
                if (strchr(track_name, '.') == 0) {
                    strcat(track_name, ".mid");
                }
            }

            int file_handle = open(track_name, _O_RDONLY);
            if (file_handle != -1) {
                close(file_handle);

                mci = mciSendCommandA;
                open_info.lpstrDeviceType = MAKEINTRESOURCEA(MCI_DEVTYPE_SEQUENCER);
                open_info.lpstrElementName = track_name;
                result =
                    mci(0, MCI_OPEN, MCI_OPEN_TYPE_ID | MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (unsigned long) &open_info);
                if (result) {
                    if (!mciGetErrorStringA(result, szErrorMsg, sizeof(szErrorMsg))) {
                        strcpy(szErrorMsg, MUSIC_ERROR);
                    }
                }
                if (result) {
                    goto finish;
                }

                this->device_id = (unsigned int) open_info.wDeviceID;
                if (set_pos_in > 0) {
                    seek_info.dwCallback = 0;
                    seek_info.dwTo = set_pos_in;
                    mci((unsigned int) open_info.wDeviceID, MCI_SEEK, MCI_TO, (unsigned long) &seek_info);
                }

                this->play_info.dwCallback = (unsigned long) this->window;
                result = mci(this->device_id, MCI_PLAY, MCI_NOTIFY, (unsigned long) &this->play_info);
                if (!result) {
                    this->playing_track = 1;
                    ++this->notify_waiting;
                }
            }
            break;
        }

        case 3:
            if (this->sound_system) {
                if (!file_name_in || !*file_name_in) {
                    sprintf(track_name, MUSIC_WAV_FORMAT, this->path, this->current_track);
                } else {
                    sprintf(track_name, MUSIC_NAME_FORMAT, this->path, file_name_in);
                }

                if (!this->sound_system->stream_file(track_name, 0, this->volume)) {
                    return 0;
                }
                this->playing_track = 1;
            }
            break;
    }

finish:
    if (this->playing_track) {
        this->paused = 0;
        this->auto_paused = 0;
        this->inactivated = 0;
        return 1;
    }
    return 0;
}

int TMusic_System::pause_play() {
    if (this->device_open == 0 || this->playing_track == 0) {
        return 0;
    }

    if (this->paused != 0) {
        this->auto_paused = 0;
        return 1;
    }

    int was_auto = this->auto_paused;
    this->paused = 1;
    if (was_auto != 0) {
        this->auto_paused = 0;
        return 1;
    }

    switch (this->music_type) {
        case 1:
            mciSendCommandA(this->device_id, MCI_PAUSE, MCI_WAIT, 0);
            break;
        case 2:
            mciSendCommandA(this->device_id, MCI_PAUSE, MCI_WAIT, 0);
            return 1;
        case 3:
            if (this->sound_system != 0) {
                this->sound_system->pause_stream();
                return 1;
            }
            break;
    }
    return 1;
}

int TMusic_System::resume_play() {
    if (this->device_open == 0 || this->playing_track == 0 || this->paused == 0) {
        return 0;
    }

    this->paused = 0;
    this->auto_paused = 0;

    if (this->fading_track != 0) {
        this->end_fade();
        return 1;
    }

    switch (this->music_type) {
        case 1: {
            int result = mciSendCommandA(this->device_id, MCI_PLAY, 0, (unsigned long) &this->play_info);
            if (result == 0) {
                this->notify_waiting++;
            }
            break;
        }
        case 2: {
            int result = mciSendCommandA(this->device_id, MCI_PLAY, 0, (unsigned long) &this->play_info);
            if (result == 0) {
                this->notify_waiting++;
            }
            break;
        }
        case 3:
            if (this->sound_system != 0) {
                this->sound_system->resume_stream();
                return 1;
            }
            break;
    }
    return 1;
}

int TMusic_System::stop_track(void) {
    this->loop = 0;
    this->start_track = 0;
    this->end_track = 0;
    this->file_name[0] = 0;
    this->fading_track = 0;
    return this->stop_playing();
}

int TMusic_System::stop_playing() {
    if (playing_track == 0) {
        return 1;
    }

    switch (music_type) {
        case 1:
            mciSendCommandA(device_id, MCI_STOP, MCI_WAIT, 0);
            playing_track = 0;
            break;
        case 2: {
            MCI_SEND_COMMAND_PROC mci = mciSendCommandA;
            mci(device_id, MCI_STOP, MCI_WAIT, 0);
            playing_track = 0;
            mci(device_id, MCI_CLOSE, MCI_WAIT, 0);
            device_id = 0;
            break;
        }
        case 3:
            if (sound_system != 0) {
                sound_system->stop_stream();
            }
            break;
    }

    playing_track = 0;
    paused = 0;
    auto_paused = 0;
    return 1;
}

int TMusic_System::fade_track(void) {
    unsigned char was_playing = this->playing_track;

    this->loop = 0;
    this->start_track = 0;
    this->end_track = 0;
    this->file_name[0] = 0;
    this->fading_track = 0;
    if (was_playing != 0) {
        this->start_fade();
    }
    return 1;
}

void TMusic_System::start_fade(void) {
    if (this->fading_track == 0) {
        this->fade_volume = this->volume;
        this->last_fade_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\music.cpp", 908);
        this->fading_track = 1;
    }
}

void TMusic_System::do_fade() {
    if (this->paused == 0) {
        float time = (float) (debug_timeGetTime("C:\\msdev\\work\\age1_x1\\music.cpp", 926) - this->last_fade_time);

        if (this->fade_volume <= -10000 && this->playing_track != 0) {
            this->stop_playing();
        }

        this->fade_volume = this->fade_volume + (long) (time / (float) this->fade_time * g_music_fade_volume_scale);
        if (this->fade_volume <= -10000 - (long) (250.0f / (float) this->fade_time * 10000.0f)) {
            if (this->playing_track != 0) {
                this->stop_playing();
            }
            if (this->fading_track != 0) {
                this->end_fade();
                return;
            }
        } else {
            this->set_volume(this->fade_volume, 0);
            this->last_fade_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\music.cpp", 952);
        }
    }
}

void TMusic_System::end_fade(void) {
    this->fading_track = 0;
    this->set_volume(this->volume, 0);
    if ((this->start_track > 0 && this->end_track > 0) || this->file_name[0] != 0) {
        this->play(this->start_track, this->end_track, this->file_name, this->make_cur_track, this->set_pos);
    }
}

unsigned int TMusic_System::handle_messages(void* wnd, unsigned int msg, unsigned int wparam, long lparam) {
    if (msg <= WM_TIMER) {
        if (msg != WM_TIMER) {
            if (msg == WM_ACTIVATEAPP) {
                if (wparam != 0) {
                    if (this->inactivated != 0 && this->auto_paused != 0) {
                        this->resume_play();
                        this->auto_paused = 0;
                        this->inactivated = 0;
                    }
                } else if (this->inactivated == 0) {
                    this->pause_play();
                    this->auto_paused = 1;
                    this->inactivated = 1;
                }
            }
        } else if (this->fading_track != 0) {
            this->do_fade();
        }
    } else if (msg != MM_MCINOTIFY) {
        if (msg == MUSIC_STREAM_END_MESSAGE && this->music_type == 3 && this->paused == 0) {
            this->playing_track = 0;
            this->after_end_track();
        }
    } else {
        unsigned char type = this->music_type;
        if (type == 1 || type == 2) {
            if (this->notify_waiting > 0) {
                --this->notify_waiting;
            }
            if (this->notify_waiting == 0 && this->paused == 0) {
                if (type == 1) {
                    this->playing_track = 0;
                }
                this->after_end_track();
            }
        }
    }

    return 0;
}

void TMusic_System::after_end_track() {
    switch (this->music_type) {
        case 1:
            if (this->fading_track == 0 && this->loop != 0) {
                this->play(this->start_track, this->end_track, 0, 0, 0);
            }
            break;
        case 2:
            if (this->fading_track != 0) {
                break;
            }
            if (this->file_name[0] == 0 && this->current_track < this->end_track) {
                this->play(this->current_track + 1, this->current_track + 1, 0, 0, 0);
                break;
            }
            if (this->loop != 0) {
                if (this->file_name[0] != 0) {
                    this->play(0, 0, this->file_name, 0, 0);
                } else {
                    this->play(this->start_track, this->end_track, 0, 0, 0);
                }
            }
            break;
        case 3:
            if (this->fading_track != 0) {
                break;
            }
            if (this->file_name[0] == 0 && this->current_track < this->end_track) {
                this->play(this->current_track + 1, this->current_track + 1, 0, 0, 0);
                break;
            }
            if (this->loop != 0) {
                if (this->file_name[0] != 0) {
                    this->play(0, 0, this->file_name, 0, 0);
                } else {
                    this->play(this->start_track, this->end_track, 0, 0, 0);
                }
            }
            break;
    }
}

int TMusic_System::get_play_info(
    unsigned char* music_type_in, int* track_from_in, int* track_to_in, int* cur_track_in, char* music_file_in,
    int* loop_in, unsigned long* pos_in
) {
    MCI_STATUS_PARMS status_info;
    *music_type_in = this->music_type;
    *track_from_in = 0;
    *track_to_in = 0;
    *cur_track_in = 0;
    *music_file_in = 0;
    *loop_in = 0;
    *pos_in = 0;

    if (this->device_open == 0) {
        return 0;
    }

    if (this->playing_track == 0) {
        return 1;
    }

    *track_from_in = this->start_track;
    *track_to_in = this->end_track;
    *cur_track_in = this->current_track;
    strcpy(music_file_in, this->file_name);
    *loop_in = this->loop;
    *pos_in = 0;

    switch (this->music_type) {
        case 2: {
            status_info.dwItem = MCI_STATUS_POSITION;
            int result =
                mciSendCommandA(this->device_id, MCI_STATUS, MCI_STATUS_ITEM | MCI_WAIT, (unsigned long) &status_info);
            if (result == 0)
                *pos_in = status_info.dwReturn;
            break;
        }
        case 1: {
            status_info.dwItem = MCI_STATUS_POSITION;
            int result =
                mciSendCommandA(this->device_id, MCI_STATUS, MCI_STATUS_ITEM | MCI_WAIT, (unsigned long) &status_info);
            if (result == 0)
                *pos_in = status_info.dwReturn;
            break;
        }
        default:
            return 1;
    }
    return 1;
}
