// VA: 00461D20 TMusic_System::open_mixer (406B)
// PDB source: music.cpp lines 294-353
// Attempt log:
// Baseline: canonical non-polymorphic TMusic_System mixer layout, VC5 WinMM API
// declarations, typed mixer records, natural fixed-size clears, and nested cleanup.
// Probe 2: <=0 count guard plus reordered value initialization worsened the localized
// details tail; the guard alone later recovered the original first jbe.
// Probe 3: a value-record pointer local extended EBP liveness and was rolled back.
// Probes 5-7: direct paDetails/value ordering and early value initialization did not
// reproduce the original details argument/store schedule.
// Probe 8: fixed-size memset of the proven 4-byte mixer value record, with <=0 retained,
// reproduced the original LEA/store/push ordering and exact bytes.
// Main-agent audit confirmed canonical non-polymorphic music/mixer SDK ownership;
// exact bytes were revalidated after promotion.

#include <windows.h>
#include <mmsystem.h>
#include <string.h>

class TMusic_System {
public:
    char path[260];
    unsigned char music_type;
    unsigned char _pad_0[3];
    void* sound_system;
    void* instance;
    void* window;
    int device_open;
    unsigned int device_id;
    char play_info[12];
    unsigned char playing_track;
    char file_name[261];
    unsigned char _pad_1[2];
    int start_track;
    int end_track;
    int make_cur_track;
    unsigned long set_pos;
    int loop;
    int current_track;
    int track_count;
    int notify_waiting;
    long start_volume;
    long volume;
    int paused;
    int auto_paused;
    int inactivated;
    int fade_out;
    unsigned long fade_time;
    int fading_track;
    unsigned long fade_volume;
    unsigned long last_fade_time;
    int mixer_open;
    HMIXER mixer_handle;
    MIXERLINEA mixer_line_info;
    MIXERLINECONTROLSA mixer_line_controls;
    MIXERCONTROLA mixer_volume_control;
    MIXERCONTROLDETAILS mixer_volume_details;
    MIXERCONTROLDETAILS_UNSIGNED mixer_volume_value;
    void* midi_window;

    int open_mixer();
};

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
