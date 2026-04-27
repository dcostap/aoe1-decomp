// first pass: keep the early store and the mixer-volume math in the packet's natural order
// if this is sticky, the remaining gap is likely just the exact unsigned-multiply basin for the division by 10000
extern "C" long (__stdcall *__imp__mixerSetControlDetails)(void* mixer_handle, void* mixer_volume_details, unsigned long flags);

class TSound_Driver {
public:
    unsigned char ready;
    unsigned char mute;
    char pad_02[0xE];
    long dsrval;
    char pad_14[0x4];
    long volume;
    char path[260];
    int mixer_open;
    void* mixer_handle;
    char pad_128[0x24C - 0x128];
    long mixer_volume_control_min;
    long mixer_volume_control_max;
    char pad_254[0x27C - 0x254];
    char mixer_volume_details[0x18];
    unsigned long mixer_volume_value;

    void set_volume(long param_1, int param_2);
};

void TSound_Driver::set_volume(long param_1, int param_2) {
    unsigned long delta;
    unsigned long scaled;

    if (param_2 != 0) {
        this->volume = param_1;
    }
    if (this->mixer_open == 0) {
        return;
    }

    delta = (unsigned long)(this->mixer_volume_control_max - this->mixer_volume_control_min);
    scaled = (unsigned long)((delta * (param_1 + 10000)) / 10000);
    this->mixer_volume_value = scaled;
    this->dsrval = __imp__mixerSetControlDetails(this->mixer_handle, this->mixer_volume_details, 0);
}
