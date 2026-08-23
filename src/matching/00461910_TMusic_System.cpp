// VA: 00461910 TMusic_System constructor (265 bytes)
// PDB donor: music.cpp, lines 52-59
// Attempt log:
// Baseline candidate: period-plausible constructor with named fields, natural
// member initialization order, and strcpy for the optional path.
// Probe 2: early null-path return kept the call arms separate but retained the
// opposite branch layout (64 differing bytes).
// Probe 3: explicit nonnull-path arm matched the original late null arm (10
// differing bytes); pointer-store order remained the first mismatch.
// Probe 4: sound_system, instance, window store order reproduced all entry and
// initialization bytes; only intrinsic cleanup/call ordering differed (6 bytes).
// Probe 5: inverted path assignment with one common open_device call produced
// exact bytes under the default VC5 flags.

#include <string.h>
#include "../../include/music_context.h"

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
