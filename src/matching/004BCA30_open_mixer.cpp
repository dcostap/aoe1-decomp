// TSound_Driver::open_mixer (438 bytes)
// Attempt log:
// Baseline: typed WinMM mixer records and the canonical Sounddrv layout, adapted
// from the exact Sounddrv translation-unit donor shape.

#include <windows.h>
#include <mmsystem.h>
#include <string.h>

#ifndef SOUNDDRV_CANONICAL_TU
class TSound_Driver {
public:
    unsigned char ready;
    unsigned char mute;
    unsigned char _pad_02[2];
    void* main_wnd;
    void* direct_sound;
    void* primary_buffer;
    long dsrval;
    long start_volume;
    long volume;
    char path[260];
    int mixer_open;
    HMIXER mixer_handle;
    MIXERLINEA mixer_line_info;
    MIXERLINECONTROLSA mixer_line_controls;
    MIXERCONTROLA mixer_volume_control;
    MIXERCONTROLDETAILS mixer_volume_details;
    MIXERCONTROLDETAILS_UNSIGNED mixer_volume_value;

    int open_mixer();
};
#endif

int TSound_Driver::open_mixer()
{
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

                    if (mixerGetControlDetailsA(this->mixer_handle,
                                                 &this->mixer_volume_details,
                                                 0) == 0) {
                        this->mixer_open = 1;
                        this->start_volume =
                            (int)(((unsigned long)this->mixer_volume_value.dwValue *
                                   10000) /
                                  (unsigned long)(this->mixer_volume_control.Bounds.lMaximum -
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
