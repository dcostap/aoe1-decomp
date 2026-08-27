#include "../include/game_globals.h"
#include "../include/music.h"

#include <stdio.h>
#include <string.h>

static const char MUSIC_WAV_FORMAT[] = "%smusic%d.wav";
static const char MUSIC_MID_FORMAT[] = "%smusic%d.mid";
static const char MUSIC_NAME_FORMAT[] = "%s%s";
static const char MUSIC_MID_SUFFIX[] = ".mid";
static const char MUSIC_ERROR[] = "Unknow Error";
static const char READ_MODE[] = "r";
static const int MUSIC_MIN_VOLUME = -10000;

typedef MCIERROR (WINAPI *MCI_SEND_COMMAND_PROC)(MCIDEVICEID, UINT, DWORD, DWORD);

extern unsigned long debug_timeGetTime(char* file, int line);
extern "C" int __cdecl open(const char*, int);
extern "C" int __cdecl close(int);

TMusic_System::TMusic_System(unsigned char type, void* instance_arg,
                             void* window_arg, TSound_Driver* sound_system_arg,
                             char* path_arg)
{
    this->music_type = type;
    this->sound_system = sound_system_arg;
    this->instance = instance_arg;
    this->window = window_arg;
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

    if (path_arg != 0) {
        strcpy(this->path, path_arg);
    } else {
        this->path[0] = 0;
    }

    this->open_device();
}

TMusic_System::~TMusic_System()
{
    this->close_device();
}

int TMusic_System::open_device()
{
    MCI_STATUS_PARMS status_info;
    MCI_SET_PARMS set_info;
    MCI_OPEN_PARMSA open_info;
    char file_name[261];

    switch (this->music_type) {
    case 1: {
        MCI_SEND_COMMAND_PROC mci = mciSendCommandA;
        open_info.lpstrElementName = MAKEINTRESOURCEA(0x204);
        if (mci(0, 0x803, 0x3102,
                (DWORD)&open_info.wDeviceID) == 0) {
            this->device_open = 1;
            this->device_id = open_info.lpstrDeviceType != 0
                                ? (unsigned int)open_info.lpstrDeviceType : 0;
            set_info.dwAudio = 10;
            mci(this->device_id, 0x80D, 0x402,
                (DWORD)&set_info.dwTimeFormat);

            status_info.dwTrack = 3;
            if (mci(this->device_id, 0x814, 0x102,
                    (DWORD)&status_info.dwReturn) == 0) {
                this->track_count = status_info.dwItem;
            }

            if (this->open_mixer() != 0) {
                this->start_volume =
                    (this->mixer_volume_value.dwValue * 10000) /
                    (unsigned int)(this->mixer_volume_control.Bounds.lMaximum -
                                   this->mixer_volume_control.Bounds.lMinimum);
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
            this->start_volume =
                (this->mixer_volume_value.dwValue * 10000) /
                (unsigned int)(this->mixer_volume_control.Bounds.lMaximum -
                               this->mixer_volume_control.Bounds.lMinimum);
            this->start_volume += MUSIC_MIN_VOLUME;
            this->volume = this->start_volume;
        }

        memset(&this->track_count, 0, sizeof(this->track_count));
        do {
            sprintf(file_name, MUSIC_MID_FORMAT, this->path,
                    this->track_count + 1);
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
            sprintf(file_name, MUSIC_WAV_FORMAT, this->path,
                    this->track_count + 1);
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

void TMusic_System::close_device()
{
    if (this->device_open != 0) {
        this->stop_track();

        switch (this->music_type) {
        case 1:
            if (this->start_volume != 1) {
                this->set_volume(this->start_volume, 0);
                this->start_volume = 1;
            }
            this->close_mixer();
            mciSendCommandA(this->device_id, 0x804, 2, 0);
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

int TMusic_System::open_mixer()
{
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
                this->mixer_line_info.dwComponentType = 0x1005;
            } else {
                this->mixer_line_info.dwComponentType = 0x1004;
            }

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

                    if (mixerGetControlDetailsA(this->mixer_handle,
                                                 &this->mixer_volume_details,
                                                 0) == 0) {
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

void TMusic_System::close_mixer(void)
{
    if (this->mixer_open != 0) {
        if (this->mixer_handle != 0) {
            mixerClose(this->mixer_handle);
            this->mixer_handle = 0;
        }
        this->mixer_open = 0;
    }
}

int TMusic_System::set_music_type(unsigned char type)
{
    if (type == this->music_type) {
        return this->device_open;
    }
    this->close_device();
    this->music_type = type;
    return this->open_device();
}

void TMusic_System::set_fade_out(int fade_out, unsigned long fade_time)
{
    this->fade_out = fade_out;
    this->fade_time = fade_time;
}

void TMusic_System::set_volume(long volume, int save)
{
    if (volume < -10000) {
        volume = -10000;
    } else if (volume > 0) {
        volume = 0;
    }

    if (save) {
        this->volume = volume;
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
        this->sound_system->set_stream_volume(volume);
        return;
    default:
        return;
    }

    unsigned int delta = this->mixer_volume_control.Bounds.dwMaximum -
                         this->mixer_volume_control.Bounds.dwMinimum;
    volume += 10000;
    delta = (delta * volume) / 10000;
    this->mixer_volume_value.dwValue = delta;
    mixerSetControlDetails(this->mixer_handle,
                           &this->mixer_volume_details, 0);
}

int TMusic_System::play_track(int track, int loop, unsigned long position)
{
    int was_playing = this->playing_track;
    this->file_name[0] = 0;
    this->start_track = track;
    this->end_track = track;
    this->make_cur_track = 0;
    this->set_pos = position;
    this->loop = loop;

    if (was_playing && this->fade_out && this->fade_time > 0UL) {
        start_fade();
        return 1;
    }

    return play(track, track, 0, 0, position);
}

int TMusic_System::play_file(char* file_name, int loop, unsigned long position)
{
    if (this->music_type == 1)
        return 0;

    strcpy(this->file_name, file_name);

    this->start_track = 0;
    this->end_track = 0;
    this->make_cur_track = 0;
    this->set_pos = position;
    this->loop = loop;

    if (this->playing_track && this->fade_out && this->fade_time > 0UL) {
        start_fade();
        return 1;
    }

    return play(0, 0, this->file_name, 0, position);
}

int TMusic_System::play_tracks(int first, int last, int loop, int current,
                                unsigned long position)
{
    int count;

    this->loop = loop;
    count = this->track_count;
    this->file_name[0] = 0;
    this->start_track = first;
    this->end_track = last;
    this->make_cur_track = current;
    this->set_pos = position;

    if (count == 0)
        return count;

    if (first > count)
        this->start_track = count;

    first = this->start_track;
    if (last < first) {
        this->end_track = first;
    } else if (last > count) {
        this->end_track = count;
    }

    if (this->playing_track && this->fade_out && this->fade_time > 0UL) {
        this->start_fade();
        return 1;
    }

    return this->play(first, this->end_track, 0, current, position);
}

int TMusic_System::play(int first, int last, char* file_name, int current,
                        unsigned long position)
{
    MCI_SEND_COMMAND_PROC mci;
    char track_name[261];
    char error_message[256];
    MCI_SEEK_PARMS seek_info;
    MCI_OPEN_PARMSA open_info;

    if (!this->device_open) {
        return 0;
    }

    if (this->playing_track != 0) {
        this->stop_playing();
    }

    if (!file_name || !*file_name) {
        int count = this->track_count;
        if (!count) {
            return 0;
        }
        if (first > count) {
            return 0;
        }
        if (!first) {
            return 0;
        }
        if (current) {
            this->current_track = current;
        } else {
            this->current_track = first;
        }
    }

    switch (this->music_type) {
    case 1: {
        MCIERROR result;
        mci = mciSendCommandA;
        this->play_info.dwCallback = (unsigned long)this->window;
        unsigned int flags = 1;

        if (position > 0) {
            seek_info.dwCallback = 0;
            seek_info.dwTo = position;
            mci(this->device_id, 0x807, 10,
                (unsigned long)&seek_info);
        } else {
            flags = 5;
            this->play_info.dwFrom = (unsigned char)this->current_track;
        }

        if (first < this->track_count && last < this->track_count) {
            flags |= 8;
            this->play_info.dwTo = (unsigned char)(last + 1);
        }

        result = mci(this->device_id, 0x806, flags,
                     (unsigned long)&this->play_info);
        if (!result) {
            this->playing_track = 1;
            ++this->notify_waiting;
        } else {
            if (!mciGetErrorStringA(result, error_message, 0x100)) {
                strcpy(error_message, MUSIC_ERROR);
            }
        }
        break;
    }

    case 2: {
        MCIERROR result;
        if (!file_name || !*file_name) {
            sprintf(track_name, MUSIC_MID_FORMAT,
                    this->path, this->current_track);
        } else {
            sprintf(track_name, MUSIC_NAME_FORMAT,
                    this->path, file_name);
            if (strchr(track_name, '.') == 0) {
                strcat(track_name, MUSIC_MID_SUFFIX);
            }
        }

        int file_handle = open(track_name, 0);
        if (file_handle != -1) {
            close(file_handle);

            mci = mciSendCommandA;
            open_info.lpstrDeviceType = MAKEINTRESOURCEA(0x20B);
            open_info.lpstrElementName = track_name;
            result = mci(0, 0x803, 0x3200,
                         (unsigned long)&open_info);
            if (result) {
                if (!mciGetErrorStringA(result, error_message, 0x100)) {
                    strcpy(error_message, MUSIC_ERROR);
                }
            }
            if (result) {
                goto finish;
            }

            this->device_id = (unsigned int)open_info.wDeviceID;
            if (position > 0) {
                seek_info.dwCallback = 0;
                seek_info.dwTo = position;
                mci((unsigned int)open_info.wDeviceID, 0x807, 8,
                    (unsigned long)&seek_info);
            }

            this->play_info.dwCallback = (unsigned long)this->window;
            result = mci(this->device_id, 0x806, 1,
                         (unsigned long)&this->play_info);
            if (!result) {
                this->playing_track = 1;
                ++this->notify_waiting;
            }
        }
        break;
    }

    case 3:
        if (this->sound_system) {
            if (!file_name || !*file_name) {
                sprintf(track_name, MUSIC_WAV_FORMAT,
                        this->path, this->current_track);
            } else {
                sprintf(track_name, MUSIC_NAME_FORMAT,
                        this->path, file_name);
            }

            if (!this->sound_system->stream_file(track_name, 0,
                                                  this->volume)) {
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

int TMusic_System::pause_play()
{
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
        mciSendCommandA(this->device_id, 0x809, 2, 0);
        break;
    case 2:
        mciSendCommandA(this->device_id, 0x809, 2, 0);
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

int TMusic_System::resume_play()
{
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
        int result = mciSendCommandA(this->device_id, 0x806, 0,
                                     (unsigned long)&this->play_info);
        if (result == 0) {
            this->notify_waiting++;
        }
        break;
    }
    case 2: {
        int result = mciSendCommandA(this->device_id, 0x806, 0,
                                     (unsigned long)&this->play_info);
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

int TMusic_System::stop_track(void)
{
    this->loop = 0;
    this->start_track = 0;
    this->end_track = 0;
    this->file_name[0] = 0;
    this->fading_track = 0;
    return this->stop_playing();
}

int TMusic_System::stop_playing()
{
    if (playing_track == 0) {
        return 1;
    }

    switch (music_type) {
    case 1:
        mciSendCommandA(device_id, 0x808, 2, 0);
        playing_track = 0;
        break;
    case 2: {
        MCI_SEND_COMMAND_PROC mci = mciSendCommandA;
        mci(device_id, 0x808, 2, 0);
        playing_track = 0;
        mci(device_id, 0x804, 2, 0);
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

int TMusic_System::fade_track(void)
{
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

void TMusic_System::start_fade(void)
{
    if (this->fading_track == 0) {
        this->fade_volume = this->volume;
        this->last_fade_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\music.cpp", 0x38C);
        this->fading_track = 1;
    }
}

void TMusic_System::do_fade()
{
    if (this->paused == 0) {
        float time = (float)(debug_timeGetTime("C:\\msdev\\work\\age1_x1\\music.cpp", 0x39E) - this->last_fade_time);

        if (this->fade_volume <= -10000 && this->playing_track != 0) {
            this->stop_playing();
        }

        this->fade_volume = this->fade_volume + (long)(time / (float)this->fade_time * DAT_00570c20);
        if (this->fade_volume <= -10000 - (long)(250.0f / (float)this->fade_time * 10000.0f)) {
            if (this->playing_track != 0) {
                this->stop_playing();
            }
            if (this->fading_track != 0) {
                this->end_fade();
                return;
            }
        } else {
            this->set_volume(this->fade_volume, 0);
            this->last_fade_time = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\music.cpp", 0x3B8);
        }
    }
}

void TMusic_System::end_fade(void)
{
    this->fading_track = 0;
    this->set_volume(this->volume, 0);
    if ((this->start_track > 0 && this->end_track > 0) || this->file_name[0] != 0) {
        this->play(this->start_track, this->end_track, this->file_name,
                   this->make_cur_track, this->set_pos);
    }
}

unsigned int TMusic_System::handle_messages(void* window, unsigned int message,
                                            unsigned int value, long data)
{
    if (message <= 0x113) {
        if (message != 0x113) {
            if (message == 0x1c) {
                if (value != 0) {
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
    } else if (message != 0x3b9) {
        if (message == 0x500 && this->music_type == 3 && this->paused == 0) {
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

void TMusic_System::after_end_track()
{
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

int TMusic_System::get_play_info(unsigned char* music_type,
                                 int* first_track,
                                 int* last_track,
                                 int* current_track,
                                 char* file_name,
                                 int* loop,
                                 unsigned long* position)
{
    MCI_STATUS_PARMS status_info;
    *music_type = this->music_type;
    *first_track = 0;
    *last_track = 0;
    *current_track = 0;
    *file_name = 0;
    *loop = 0;
    *position = 0;

    if (this->device_open == 0) {
        return 0;
    }

    if (this->playing_track == 0) {
        return 1;
    }

    *first_track = this->start_track;
    *last_track = this->end_track;
    *current_track = this->current_track;
    strcpy(file_name, this->file_name);
    *loop = this->loop;
    *position = 0;

    switch (this->music_type) {
    case 2: {
        status_info.dwTrack = 2;
        int result = mciSendCommandA(this->device_id, 0x814, 0x102,
                                     (unsigned long)&status_info.dwReturn);
        if (result == 0)
            *position = status_info.dwItem;
        break;
    }
    case 1: {
        status_info.dwTrack = 2;
        int result = mciSendCommandA(this->device_id, 0x814, 0x102,
                                     (unsigned long)&status_info.dwReturn);
        if (result == 0)
            *position = status_info.dwItem;
        break;
    }
    default:
        return 1;
    }
    return 1;
}
