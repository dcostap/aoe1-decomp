// TSound_Driver::open_mixer (438 bytes)
// KEY INSIGHT: Original uses sub esp,8 because mixer structs are stored
// in class-embedded buffers at +0x124 (mixer_handle), +0x128 (MIXERLINE),
// +0x140 (flags), +0x1D0 (MIXERLINECONTROLS), +0x1E8 (MIXERCONTROLDETAILS).
// Need to extend TSound_Driver class with these buffers.
extern "C" unsigned int __stdcall mixerGetNumDevs(void);
extern "C" int __stdcall mixerOpen(void** handle, unsigned int dev_id, void* a, void* b, unsigned int c);
extern "C" int __stdcall mixerClose(void* handle);
extern "C" int __stdcall mixerGetLineInfoA(void* handle, void* info, unsigned int flags);
extern "C" int __stdcall mixerGetLineControlsA(void* handle, void* controls, unsigned int flags);
extern "C" int __stdcall mixerGetControlDetailsA(void* handle, void* details, unsigned int flags);

class TSound_Driver {
public:
    unsigned char ready;
    unsigned char mute;
    char gap_02[2];
    void* main_wnd;
    void* direct_sound;
    void* primary_buffer;
    int dsrval;
    int start_volume;
    int volume;
    char path[260];
    int mixer_open;         // +0x120
    void* mixer_handle;     // +0x124
    // Real class has gap[0x570] from +0x128 to +0x698

    int open_mixer(void);
};

int TSound_Driver::open_mixer(void) {
    unsigned int num_devs;
    unsigned int dev_id;

    num_devs = mixerGetNumDevs();
    if (num_devs == 0) {
        return 0;
    }

    for (dev_id = 0; dev_id < num_devs; dev_id++) {
        int result;
        result = mixerOpen(&this->mixer_handle, dev_id, 0, 0, 0);
        if (result == 0) {
            char* ml = (char*)this + 0x128;
            char* mc = (char*)this + 0x1D0;
            char* mv = (char*)this + 0x1E8;
            char* md = (char*)this + 0x27C;
            unsigned long* val = (unsigned long*)((char*)this + 0x294);

            // Zero mixer_line_info (42 DWORDs at +0x128)
            { unsigned long* p = (unsigned long*)ml; int i = 0x2A; do { *p++ = 0; } while (--i != 0); }

            *(unsigned long*)ml = 0xA8;
            *(unsigned long*)(ml + 0x18) = 0x1008;

            result = mixerGetLineInfoA(this->mixer_handle, ml, 3);
            if (result == 0) {
                unsigned long line_id = *(unsigned long*)(ml + 0x0C);

                // Zero mixer_line_controls (6 DWORDs)
                { unsigned long* p = (unsigned long*)mc; int i = 6; do { *p++ = 0; } while (--i != 0); }
                // Zero mixer_volume_control (37 DWORDs)
                { unsigned long* p = (unsigned long*)mv; int i = 0x25; do { *p++ = 0; } while (--i != 0); }

                *(unsigned long*)mc = 0x18;
                *(unsigned long*)(mc + 4) = line_id;
                *(unsigned long*)(mc + 8) = 0x50030001;
                *(unsigned long*)(mc + 0x0C) = 1;
                *(unsigned long*)(mc + 0x10) = 0x94;
                *(void**)(mc + 0x14) = mv;

                result = mixerGetLineControlsA(this->mixer_handle, mc, 2);
                if (result == 0) {
                    // Zero mixer_volume_details (6 DWORDs)
                    { unsigned long* p = (unsigned long*)md; int i = 6; do { *p++ = 0; } while (--i != 0); }

                    *val = 0;

                    unsigned long control_id = *(unsigned long*)(mv + 4);

                    *(unsigned long*)md = 0x18;
                    *(unsigned long*)(md + 4) = control_id;
                    *(unsigned long*)(md + 8) = 1;
                    *(unsigned long*)(md + 0x10) = 4;
                    *(void**)(md + 0x14) = val;

                    result = mixerGetControlDetailsA(this->mixer_handle, md, 0);
                    if (result == 0) {
                        long value = (long)*val;
                        long max_val = *(long*)(mv + 0x68);
                        long min_val = *(long*)(mv + 0x64);

                        this->mixer_open = 1;
                        this->start_volume = (int)(((unsigned long)value * 10000) / (unsigned long)(max_val - min_val)) - 10000;
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
